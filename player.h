#ifndef PLAYER_H
#define PLAYER_H
#include "idrawable.h"

class Player : public IDrawable
{
public:
    enum Position {TOP, BOTTOM};
    Player(Position boardPosition);

    void draw(QPainter* paint);
    Position getBoardPosition();
    int getRacketPosition();

private:
    int score;
    Position boardPosition;
    int racketPosition;
};

#endif // PLAYER_H
