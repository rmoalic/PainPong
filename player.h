#ifndef PLAYER_H
#define PLAYER_H
#include "idrawable.h"

class Player : public IDrawable
{
public:
    enum Position {TOP, BOTTOM};
    Player(Position boardPosition);

    void moveLeft();
    void moveRight();

    void draw(QPainter* paint);
    Position getBoardPosition();
    int getRacketPosition();
    QSize getRaketSize();

private:
    int score;
    Position boardPosition;
    int racketPosition;
};

#endif // PLAYER_H
