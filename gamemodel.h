#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include "ball.h"
#include "player.h"
#include "brique.h"
#include "coloredbrique.h"
#include "scoreboard.h"
#include <vector>
#include <QMap>

class GameModel
{
public:
    GameModel(QSize);
    ~GameModel();
    Player* p1;
    Player* p2;
    Ball* b1;
    Ball* b2;
    std::vector<Brique*> briques;
    ScoreBoard* score_board;
    QMap<int, bool> keys;
    QSize window_size;
private:
    std::vector<Brique*> initBriques();
};

#endif // GAMEMODEL_H
