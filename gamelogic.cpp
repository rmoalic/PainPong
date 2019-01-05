#include "gamelogic.h"
#include "text.h"
#include "unistd.h"
#include <math.h>
#include <algorithm>
#include <QtDebug>
#include <QThread>
#include <QDateTime>

#define FIXED_TIMEDELTA 5

GameLogic::GameLogic(QSize window_size, GameModel* gm) : QObject ()
{
    this->window_size = window_size;
    this->gm = gm;
    this->timer = new QTimer();
    this->somethread = new QThread(this);
    this->somethread->setParent(this);
    this->timer->setParent(this->somethread);
    this->timer->setInterval(FIXED_TIMEDELTA);
    connect(this->somethread, SIGNAL(started()), this->timer, SLOT(start()));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(tick()));
    this->somethread->start();

    this->gm->toDraw(new Text("Player 1: A and E",3000, 120, 140, 20, Qt::blue));
    this->gm->toDraw(new Text("Player 2: I and P",3000, 120, 180, 20, Qt::blue));

    this->last_time = QDateTime::currentMSecsSinceEpoch();
    this->time_acc = 0;
}

GameLogic::~GameLogic()
{
    this->timer->stop();
    this->somethread->exit();
    while (this->somethread->isRunning()) {}
    delete this->timer;
    delete this->somethread;
}

void GameLogic::endGame() {
    int score1 = this->gm->score_board->getScore1();
    int score2 = this->gm->score_board->getScore2();
    this->timer->stop();
    if (score1 > score2) {
        this->gm->toDraw(new Text("Player 1 WIN",10000, 70, 150, 35, Qt::green));
    } else if (score2 > score1) {
        this->gm->toDraw(new Text("Player 2 WIN",10000, 70, 150, 35, Qt::red));
    } else {
        this->gm->toDraw(new Text("It's a draw",10000, 70, 150, 35, Qt::gray));
    }
}

bool GameLogic::collideBallPlayer(Ball* b, Player* p)
{
    switch (p->getBoardPosition()) {
    case Player::TOP:
        return b->getPos().ry() >= p->getRacketSize().rheight() - p->getRacketSize().rheight()/2 &&
             b->getPos().ry() <= p->getRacketSize().rheight() &&
             b->getPosCenter().rx() >= p->getRacketPosition() &&
             b->getPosCenter().rx() <= p->getRacketPosition() + p->getRacketSize().rwidth();
    case Player::BOTTOM:
        return b->getPos().ry() + 25 >= this->window_size.rheight() - p->getRacketSize().rheight() &&
             b->getPos().ry() + 25 <= this->window_size.rheight() - p->getRacketSize().rheight() + p->getRacketSize().rheight()/2 &&
             b->getPosCenter().rx() >= p->getRacketPosition() &&
             b->getPosCenter().rx() <= p->getRacketPosition() + p->getRacketSize().rwidth();
    }
    return false;
}

qreal computeAngle(Ball* b, Player* p)
{
    qreal z = b->getPosCenter().rx() - (p->getRacketPosition() + p->getRacketSize().rwidth() / 2);
    qreal y = p->getRacketSize().rwidth()/sqrt(3);
    return acos(z/y);
}

void GameLogic::checkCollisionBallPlayer()
{
    //Collision b1 p1
    if(collideBallPlayer(gm->b1, gm->p1))
    {
        gm->b1->setAngle(-computeAngle(gm->b1, gm->p1));
    }
    //Collision b2 p1
    if(collideBallPlayer(gm->b2, gm->p1))
    {
        gm->b2->setAngle(-computeAngle(gm->b2, gm->p1));
    }
    //Collision b1 p2
    if(collideBallPlayer(gm->b1, gm->p2))
    {
        gm->b1->setAngle(computeAngle(gm->b1, gm->p2));
    }
    //Collision b2 p2
    if(collideBallPlayer(gm->b2, gm->p2))
    {
        gm->b2->setAngle(computeAngle(gm->b2, gm->p2));
    }
}

void GameLogic::checkCollisionBallWall()
{
    const int wall_width = 5;

    if(gm->b1->getPos().rx() <= wall_width && cos(gm->b1->getAngle()) < 0)
    {
        gm->b1->setAngle(M_PI - gm->b1->getAngle());
    }
    else if(gm->b1->getPos().rx() + 25 >= window_size.width() - wall_width && cos(gm->b1->getAngle()) > 0)
    {
        gm->b1->setAngle(M_PI - gm->b1->getAngle());
    }
    if(gm->b2->getPos().rx() <= wall_width && cos(gm->b2->getAngle()) < 0)
    {
        gm->b2->setAngle(M_PI - gm->b2->getAngle());
    }
    else if(gm->b2->getPos().rx() + 25 >= window_size.width() - wall_width && cos(gm->b2->getAngle()) > 0)
    {
        gm->b2->setAngle(M_PI - gm->b2->getAngle());
    }
}

void GameLogic::checkCollisionBallVoid()
{
    const int SCORE = 15;
    if(gm->b1->getPosCenter().ry() <= 0)
    {
        gm->b1->reset();
        gm->score_board->setScore1(gm->score_board->getScore1() - SCORE);
    } else if (gm->b1->getPosCenter().ry() >= window_size.height()) {
        gm->b1->reset();
        gm->score_board->setScore2(gm->score_board->getScore2() - SCORE);
    }
    if(gm->b2->getPosCenter().ry() <= 0)
    {
        gm->b2->reset();
        gm->score_board->setScore1(gm->score_board->getScore1() - SCORE);
    } else if (gm->b2->getPosCenter().ry() >= window_size.height()) {
        gm->b2->reset();
        gm->score_board->setScore2(gm->score_board->getScore2() - SCORE);
    }
}

bool collisionBrique(Ball* b, Brique* brique)
{
    double r = 25/2;
    double bc_y = b->getPosCenter().ry();
    double bc_x = b->getPosCenter().rx();
    QRectF brique_r = brique->getRepr();
    return (bc_y - r >= brique_r.y() || bc_y + r >= brique_r.y()) &&
           (bc_y - r <= brique_r.y() + brique_r.height() || bc_y + r <= brique_r.y() + brique_r.height()) &&
           (bc_x - r >= brique_r.x() || bc_x + r >= brique_r.x()) &&
           (bc_x - r <= brique_r.x() + brique_r.width() || bc_x + r <= brique_r.x() + brique_r.width());
}

double nextAngle(Ball* b, Brique* br) {
    double angle = b->getAngle();
    angle = (angle < 0) ? 2*M_PI + angle : angle;
    if(sin(angle) > 0) { //bas, droite ou gauche
        if(cos(angle) > 0) { //bas ou gauche
            if(b->getPos().rx() + 25 - br->getRepr().left() > br->getRepr().bottom() - b->getPos().ry()) { //bas
                return 2*M_PI - angle;
            }
            else { //gauche
                return M_PI - angle;
            }
        }
        else { //bas ou droite
            if(br->getRepr().right() - b->getPos().rx() > br->getRepr().bottom() - b->getPos().ry()) { //bas
                return 2*M_PI - angle;
            }
            else { //droite
                return M_PI - angle;
            }
        }
    }
    else { //haut, droite ou gauche
        if(cos(angle) > 0) { //haut ou gauche
            if(b->getPos().rx() + 25 - br->getRepr().left() > b->getPos().ry() + 25 - br->getRepr().top()) { //haut
                return 2*M_PI - angle;
            }
            else { //gauche
                return M_PI - angle;
            }
        }
        else { // haut ou droite
            if(br->getRepr().right() - b->getPos().rx() > b->getPos().ry() + 25 - br->getRepr().top()) { //haut
                return 2*M_PI - angle;
            }
            else { //droite
                return M_PI - angle;
            }
        }
    }
}

void GameLogic::checkCollisionBallBrique(Brique* brique)
{
    if(collisionBrique(gm->b1, brique))
    {
        double angle = nextAngle(gm->b1, brique);
        //qDebug() << "nextangle";
        //qDebug() << angle;
        (*brique)--;
        gm->b1->setAngle(angle);
	if (!brique->isAlive())
            gm->score_board->setScore1(gm->score_board->getScore1() + brique->getValue());
    }
    if(collisionBrique(gm->b2, brique))
    {
        double angle = nextAngle(gm->b2, brique);
        //qDebug() << "nextangle";
        //qDebug() << angle;
        (*brique)--;
        gm->b2->setAngle(angle);
	if (!brique->isAlive())
            gm->score_board->setScore2(gm->score_board->getScore2() + brique->getValue());
    }
}

void GameLogic::move() {
    gm->b1->nextPos(FIXED_TIMEDELTA);
    gm->b2->nextPos(FIXED_TIMEDELTA);

    if (this->gm->keys[Qt::Key_A]) {
        gm->p1->moveLeft(FIXED_TIMEDELTA);
    }
    if (this->gm->keys[Qt::Key_E]) {
        gm->p1->moveRight(FIXED_TIMEDELTA);
    }
    if (this->gm->keys[Qt::Key_I]) {
        gm->p2->moveLeft(FIXED_TIMEDELTA);
    }
    if (this->gm->keys[Qt::Key_P]) {
        gm->p2->moveRight(FIXED_TIMEDELTA);
    }
}

void GameLogic::tick()
{
    qint64 time = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsed = time - last_time;
    time_acc += elapsed;
    last_time = time;
    while (time_acc >= FIXED_TIMEDELTA) {
        GameLogic::move();
        GameLogic::checkCollisionBallPlayer();
        GameLogic::checkCollisionBallWall();
        GameLogic::checkCollisionBallVoid();
        std::vector<Brique*>::iterator it;
        for(it = gm->briques.begin(); it != gm->briques.end(); )
        {
            GameLogic::checkCollisionBallBrique(*it);
            if (! (*it)->isAlive()) {
                it = gm->briques.erase(it);
	    } else {
		++it;
	    }
        }
	if (gm->briques.empty()) {
	    endGame();
	}
        time_acc -= FIXED_TIMEDELTA;
    }
}
