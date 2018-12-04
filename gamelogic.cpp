#include "gamelogic.h"
#include "unistd.h"
#include <algorithm>
#include <QtDebug>
#include <QThread>
#include <vector>


GameLogic::GameLogic(QSize window_size, GameModel* gm) : QObject ()
{
    this->window_size = window_size;
    this->gm = gm;
    this->timer = new QTimer();
    this->somethread = new QThread(this);
    this->somethread->setParent(this);
    this->timer->setParent(this->somethread);
    this->timer->setInterval(35);
    connect(this->somethread, SIGNAL(started()), this->timer, SLOT(start()));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(tick()));
    this->somethread->start();
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
        return b->getPos().ry() >= p->getRacketSize().rheight() / 2 &&
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

    if(gm->b1->getPos().rx() <= wall_width || gm->b1->getPos().rx() + 25 >= window_size.width() - wall_width)
    {
        gm->b1->setAngle(M_PI - gm->b1->getAngle());
    }
    if(gm->b2->getPos().rx() <= wall_width || gm->b2->getPos().rx() + 25 >= window_size.width() - wall_width)
    {
        gm->b2->setAngle(M_PI - gm->b2->getAngle());
    }
}

void GameLogic::checkCollisionBallVoid()
{
    if(gm->b1->getPosCenter().ry() <= 0 || gm->b2->getPosCenter().ry() <= 0)
    {

    }
    if(gm->b1->getPosCenter().ry() >= window_size.height() || gm->b2->getPosCenter().ry() >= window_size.height())
    {

    }
}

bool collisionBrique(Ball* b, Brique* brique)
{
    return b->getPosCenter().rx() >= brique->getRepr().x() &&
            b->getPosCenter().rx() <= brique->getRepr().x() + brique->getRepr().width() &&
            b->getPos().ry() >= brique->getRepr().y() &&
            b->getPos().ry() <= brique->getRepr().y() + brique->getRepr().height();
}

void GameLogic::checkCollisionBallBrique(Brique* brique)
{
    if(collisionBrique(gm->b1, brique))
    {

    }
}

void GameLogic::tick()
{
    GameLogic::checkCollisionBallPlayer();
    GameLogic::checkCollisionBallWall();
    GameLogic::checkCollisionBallVoid();
    gm->score_board->setScore1(gm->score_board->getScore1() + 1);
    std::vector<Brique*>::iterator it;
    for(it = gm->briques.begin(); it != gm->briques.end(); it++)
    {
        GameLogic::checkCollisionBallBrique(*it);
    }
}
