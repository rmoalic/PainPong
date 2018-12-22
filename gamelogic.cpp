#include "gamelogic.h"
#include "unistd.h"
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

    this->last_time = QDateTime::currentMSecsSinceEpoch();
    this->time_acc = 0;
}

GameLogic::~GameLogic()
{
    this->timer->stop();
    this->somethread->exit();
    delete this->somethread;
    delete this->timer;
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
    const int SCORE = 100;
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
    return (b->getPosCenter().ry() - 25/2 >= brique->getRepr().y() || b->getPosCenter().ry() + 25/2 >= brique->getRepr().y()) &&
            (b->getPosCenter().ry() - 25/2 <= brique->getRepr().y() + brique->getRepr().height() || b->getPosCenter().ry() + 25/2 <= brique->getRepr().y() + brique->getRepr().height()) &&
            (b->getPosCenter().rx() - 25/2 >= brique->getRepr().x() || b->getPosCenter().rx() + 25/2 >= brique->getRepr().x()) &&
            (b->getPosCenter().rx() - 25/2 <= brique->getRepr().x() + brique->getRepr().width() || b->getPosCenter().rx() + 25/2 <= brique->getRepr().x() + brique->getRepr().width());
}

double nextAngle(Ball* b, Brique* br) {
    double ballAngle = atan((br->getRepr().center().ry() - b->getPosCenter().ry()) / (b->getPosCenter().rx() - br->getRepr().center().rx()));
    ballAngle = (ballAngle < 0) ? 2*M_PI - ballAngle : ballAngle;
    if(b->getPosCenter().rx() - br->getRepr().center().rx() < 0) {
        if(b->getPosCenter().ry() - br->getRepr().center().ry() > 0) ballAngle = M_PI + ballAngle;
        else ballAngle = M_PI - ballAngle;
    }
    else {
        if(b->getPosCenter().ry() - br->getRepr().center().ry() > 0) ballAngle = 2*M_PI - ballAngle;
    }
    qDebug() << ballAngle;
    double angle = b->getAngle();
    if(angle < 0) angle = 2*M_PI + angle;
    if(ballAngle < br->getCornerAngle(0)) {
        qDebug() << "getCornerAngle(0) " << br->getCornerAngle(0);
        if(cos(angle) < 0)
        {
            qDebug() << "droite";
            return M_PI - angle;
        }
        else return angle;
    }
    else if(ballAngle < br->getCornerAngle(1)) {
        qDebug() << "getCornerAngle(1) " << br->getCornerAngle(1);
        if(sin(angle) > 0)
        {
            qDebug() << "haut";
            return 2*M_PI - angle;
        }
        else return angle;
    }
    else if(ballAngle < br->getCornerAngle(2)) {
        qDebug() << "getCornerAngle(2) " << br->getCornerAngle(2);
        if(cos(angle) > 0)
        {
            qDebug() << "gauche";
            return M_PI - angle;
        }
        else return angle;
    }
    else {
         qDebug() << "getCornerAngle(2) " << br->getCornerAngle(3);
        if(sin(angle) > 0)
        {
            qDebug() << "bas";
            return 2*M_PI - angle;
        }
        else
        {
            qDebug() << "droite";
            return M_PI - angle;
        }
    }
}

void GameLogic::checkCollisionBallBrique(Brique* brique)
{
    //pb: collision sur le côté ou au-dessus/en-dessous
    if(collisionBrique(gm->b1, brique))
    {
        double angle = nextAngle(gm->b1, brique);
        qDebug() << "nextangle";
        qDebug() << angle;
        gm->b1->setAngle(angle);
        gm->score_board->setScore1(gm->score_board->getScore1() + brique->getValue());
    }
    if(collisionBrique(gm->b2, brique))
    {
        double angle = nextAngle(gm->b2, brique);
        qDebug() << "nextangle";
        qDebug() << angle;
        gm->b2->setAngle(angle);
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
        for(it = gm->briques.begin(); it != gm->briques.end(); it++)
        {
            GameLogic::checkCollisionBallBrique(*it);
        }
        time_acc -= FIXED_TIMEDELTA;
    }
}
