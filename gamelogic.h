#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "ball.h"
#include "player.h"
#include "brique.h"
#include "scoreboard.h"
#include "gamewidget.h"
#include "constantes.h"
#include <QTimer>
#include <vector>

class GameLogic : public QObject
{
public:
    Player* p1;
    Player* p2;
    Ball* b1;
    Ball* b2;
    std::vector<Brique*> briques;
    ScoreBoard* score_board;
    GameLogic(QSize);
    std::vector<IDrawable>* getDrawable();
    ~GameLogic();

private:
    QTimer* timer;
    QSize window_size;
    void checkCollisionBallPlayer();
    void checkCollisionBallWall();
    void checkCollisionBallVoid();
    void checkCollisionBallBrique(Brique*);
    std::vector<Brique*> initBriques();

private slots:
    void tick();
};

#endif // GAMELOGIC_H
