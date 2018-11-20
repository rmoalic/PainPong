#include "gamelogic.h"

GameLogic::GameLogic()
{
    this->timer = new QTimer();
    this->p1 = new Player(Player::TOP);
    this->p2 = new Player(Player::BOTTOM);
    this->b1 = new Ball(QPoint(1,1), 1.0, 90.0);
    this->b2 = new Ball(QPoint(1,2), 1.0, 90.0);
    this->score_board = new ScoreBoard();
    this->timer->setInterval()
}

void GameLogic::tick()
{
    GameLogic::checkCollisionBallPlayer();
    GameLogic::checkCollisionBallBrique();
    GameLogic::checkCollisionBallWall();
    GameLogic::checkCollisionBallVoid();
}

void GameLogic::checkCollisionBallPlayer()
{
    //Collision b1 p1
    if(b1->getPos().ry() >= 0 && b1->getPos().ry() <= 5)
    {
        if(b1->getPos().rx() >= p1->getRacketPosition() && b1->getPos().rx() <= p1->getRacketPosition() + p1->getRacketSize())
    }
}

void GameLogic::checkCollisionBallBrique()
{

}

void GameLogic::checkCollisionBallWall()
{
    if(b1->getPos().rx() <= 5 || b2->getPos().rx() <= 5)
    {

    }
    if(b1->getPos().rx() >= WINDOW_WIDTH - 5 || b2->getPos().rx() >= WINDOW_WIDTH - 5)
    {

    }
}

void GameLogic::checkCollisionBallVoid()
{
    if(b1->getPos().ry() <= 0 || b2->getPos().ry() <= 0)
    {

    }
    if(b1->getPos().ry() >= WINDOW_HEIGHT || b2->getPos().ry() >= WINDOW_HEIGHT)
    {

    }
}
