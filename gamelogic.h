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
#include <QObject>

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameLogic(QSize, GameModel*);
    ~GameLogic();

private:
    QTimer* timer;
    QThread* somethread;
    QSize window_size;
    GameModel* gm;
    void checkCollisionBallPlayer();
    void checkCollisionBallWall();
    void checkCollisionBallVoid();
    void checkCollisionBallBrique(Brique*);
    bool collideBallPlayer(Ball* b, Player* p);
    void move();
private slots:
    void tick();
};

#endif // GAMELOGIC_H
