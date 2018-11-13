#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "ball.h"
#include "player.h"
#include "brique.h"
#include "scoreboard.h"
#include <vector>

class GameLogic
{
public:
    GameLogic();

private:
    std::vector<Brique*> briques;
    Player* p1;
    Player* p2;
    Ball* b1;
    Ball* b2;
    ScoreBoard* score_board;
    QTimer* timer;
    void tick();
    void checkCollision();
    void checkCollisionBallPlayer();
    void checkCollisionBallBrique();
    void checkCollisionBallWall();
    void checkCollisionBallVoid();
};

#endif // GAMELOGIC_H
