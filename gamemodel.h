#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include "ball.h"
#include "player.h"
#include "brique.h"
#include "coloredbrique.h"
#include "scoreboard.h"
#include <vector>

class GameModel
{
public:
    GameModel(QSize);
    Player* p1;
    Player* p2;
    Ball* b1;
    Ball* b2;
    std::vector<Brique*> briques;
    ScoreBoard* score_board;
private:
    std::vector<Brique*> initBriques();
};

#endif // GAMEMODEL_H
