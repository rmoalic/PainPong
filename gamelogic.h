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
    qint64 last_time;
    qint64 time_acc;
    void checkCollisionBallPlayer();
    void checkCollisionBallWall();
    void checkCollisionBallVoid();
    void checkCollisionBallBrique(Brique*);
    bool collideBallPlayer(Ball* b, Player* p);
    void move();
    void endGame();
private slots:
    void tick();
};

#endif // GAMELOGIC_H
