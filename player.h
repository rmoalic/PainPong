#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    enum Position {TOP, BOTTOM};
    Player(Position boardPosition);

    Position getBoardPosition();
    int getRacketPosition();

private:
    int score;
    Position boardPosition;
    int racketPosition;
};

#endif // PLAYER_H
