#ifndef PLAYER_H
#define PLAYER_H
#include "idrawable.h"

class Player : public IDrawable
{
public:
    enum Position {TOP, BOTTOM};
    Player(Position boardPosition, QSize window_size);

    void moveLeft();
    void moveRight();

    void draw(QPainter* paint);
    Position getBoardPosition();
    int getRacketPosition();
    QSize getRacketSize();

private:
    int score;
    Position boardPosition;
    int racketPosition;
    QSize window_size;
};

#endif // PLAYER_H
