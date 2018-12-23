#ifndef PLAYER_H
#define PLAYER_H
#include "idrawable.h"

class Player : public IDrawable
{
public:
    enum Position {TOP, BOTTOM};
    Player(Position boardPosition, QSize window_size);
    ~Player();

    void moveLeft(qint64 time_elapsed);
    void moveRight(qint64 time_elapsed);

    void draw(QPainter* paint);
    Position getBoardPosition();
    double getRacketPosition();
    QSize getRacketSize();

private:
    int score;
    Position boardPosition;
    double racketPosition;
    QSize window_size;
    QSize player_size;
    QImage* player_sprite;
};

#endif // PLAYER_H
