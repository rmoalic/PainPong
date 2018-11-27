#include "gamelogic.h"
#include <algorithm>
#include <QtDebug>
#include <QThread>
#include <vector>

GameLogic::GameLogic(QSize window_size, GameModel* gm) : QObject ()
{
    this->window_size = window_size;
    this->gm = gm;
    this->timer = new QTimer();
    QThread* somethread = new QThread();
    this->timer->setInterval(100);
    timer->moveToThread(somethread);
    connect(somethread, SIGNAL(started()), timer, SLOT(start()));
    connect(timer, &QTimer::timeout, this, &GameLogic::tick);
    somethread->start();
}

GameLogic::~GameLogic()
{
    this->timer->stop();
    delete timer;
}

bool collideBallPlayer(Ball* b, Player* p)
{
    return b->getPos().ry() >= 0 &&
           b->getPos().ry() <= p->getRacketSize().rheight() &&
           b->getPos().rx() >= p->getRacketPosition() &&
           b->getPos().rx() <= p->getRacketPosition() + p->getRacketSize().rwidth();
}

void GameLogic::checkCollisionBallPlayer()
{
    //Collision b1 p1
    if(collideBallPlayer(gm->b1, gm->p1))
    {

    }
    //Collision b2 p1
    if(collideBallPlayer(gm->b2, gm->p1))
    {

    }
    //Collision b1 p2
    if(collideBallPlayer(gm->b1, gm->p2))
    {

    }
    //Collision b2 p2
    if(collideBallPlayer(gm->b2, gm->p2))
    {

    }
}

void GameLogic::checkCollisionBallWall()
{
    const int wall_width = 5;

    if(gm->b1->getPos().rx() <= wall_width || gm->b1->getPos().rx() >= window_size.height() - wall_width)
    {
        gm->b1->setAngle(M_PI - gm->b1->getAngle());
    }
    if(gm->b2->getPos().rx() <= wall_width || gm->b2->getPos().rx() >= window_size.height() - wall_width)
    {
        gm->b2->setAngle(M_PI - gm->b2->getAngle());
    }
}

void GameLogic::checkCollisionBallVoid()
{
    if(gm->b1->getPos().ry() <= 0 || gm->b2->getPos().ry() <= 0)
    {

    }
    if(gm->b1->getPos().ry() >= window_size.height() || gm->b2->getPos().ry() >= window_size.height())
    {

    }
}

void GameLogic::checkCollisionBallBrique(Brique* brique)
{

}

void GameLogic::tick()
{
    GameLogic::checkCollisionBallPlayer();
    GameLogic::checkCollisionBallWall();
    GameLogic::checkCollisionBallVoid();
    std::vector<Brique*>::iterator it;
    for(it = gm->briques.begin(); it != gm->briques.end(); it++)
    {
        GameLogic::checkCollisionBallBrique(*it);
    }
    qDebug() << "check";
}
