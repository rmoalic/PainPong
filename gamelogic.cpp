#include "gamelogic.h"
#include <algorithm>
#include <QtDebug>
#include <QThread>
#include <vector>

GameLogic::GameLogic(QSize window_size) : QObject ()
{
    this->window_size = window_size;
    this->timer = new QTimer();
    this->b1 = new Ball(QPoint(240,250), 1.0, 2*M_PI/8);
    this->b2 = new Ball(QPoint(240,250), 1.0, 10*M_PI/8);
    this->p1 = new Player(Player::TOP, window_size);
    this->p2 = new Player(Player::BOTTOM, window_size);
    this->score_board = new ScoreBoard();
    this->briques = GameLogic::initBriques();
    QThread* somethread = new QThread();
    this->timer->setInterval(100);
    timer->moveToThread(somethread);
    connect(somethread, SIGNAL(started()), timer, SLOT(start()));
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    somethread->start();
}

GameLogic::~GameLogic()
{
    this->timer->stop();
    delete timer;
    delete p1;
    delete p2;
    delete b1;
    delete b2;
    delete score_board;
}

void GameLogic::checkCollisionBallPlayer()
{
    //Collision b1 p1
    if(b1->getPos().ry() >= 0 && b1->getPos().ry() <= p1->getRacketSize().rheight())
    {
        if(b1->getPos().rx() >= p1->getRacketPosition() && b1->getPos().rx() <= p1->getRacketPosition() + p1->getRacketSize().rwidth())
        {

        }
    }
    //Collision b2 p1
    if(b2->getPos().ry() >= 0 && b2->getPos().ry() <= p1->getRacketSize().rheight())
    {
        if(b2->getPos().rx() >= p1->getRacketPosition() && b2->getPos().rx() <= p1->getRacketPosition() + p1->getRacketSize().rwidth())
        {

        }
    }
    //Collision b1 p2
    if(b1->getPos().ry() <= window_size.height() && b1->getPos().ry() >= p2->getRacketSize().rheight())
    {
        if(b1->getPos().rx() >= p2->getRacketPosition() && b1->getPos().rx() <= p2->getRacketPosition() + p2->getRacketSize().rwidth())
        {

        }
    }
    //Collision b2 p2
    if(b2->getPos().ry() <= window_size.height() && b2->getPos().ry() >= p2->getRacketSize().rheight())
    {
        if(b2->getPos().rx() >= p2->getRacketPosition() && b2->getPos().rx() <= p2->getRacketPosition() + p2->getRacketSize().rwidth())
        {

        }
    }
}

void GameLogic::checkCollisionBallWall()
{
    if(b1->getPos().rx() <= 5 || b1->getPos().rx() >= window_size.height() - 5)
    {
        this->b1->setAngle(M_PI - this->b1->getAngle());
    }
    if(b2->getPos().rx() <= 5 || b2->getPos().rx() >= window_size.height() - 5)
    {
        this->b2->setAngle(M_PI - this->b2->getAngle());
    }
}

void GameLogic::checkCollisionBallVoid()
{
    if(b1->getPos().ry() <= 0 || b2->getPos().ry() <= 0)
    {

    }
    if(b1->getPos().ry() >= window_size.height() || b2->getPos().ry() >= window_size.height())
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
    for(it = this->briques.begin(); it != this->briques.end(); it++)
    {
        GameLogic::checkCollisionBallBrique(*it);
    }
    qDebug() << "check";
}
