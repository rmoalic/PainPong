#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "ball.h"
#include "player.h"
#include "brique.h"
#include "scoreboard.h"
#include "constantes.h"
#include "gamemodel.h"
#include <QTimer>
#include <vector>

class GameLogic : public QObject
{
public:
    GameLogic(QSize, GameModel*);
    ~GameLogic();

private:
    QTimer* timer;
    QSize window_size;
    GameModel* gm;
    void checkCollisionBallPlayer();
    void checkCollisionBallWall();
    void checkCollisionBallVoid();
    void checkCollisionBallBrique(Brique*);
private slots:
    void tick();
};

#endif // GAMELOGIC_H
