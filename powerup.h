#ifndef POWERUP_H
#define POWERUP_H

enum BallModifier {
    DoubleDamage

};

enum PlayerModifier {
    Slow,
    Reversed
};

class PowerUp
{
public:
    PowerUp(double velocity, PlayerModifier pm, BallModifier bm);
    double getVelocityModifier();
    BallModifier getBallModifier();
    PlayerModifier getPlayerModifier();

private:
    double velocityModifier;
    BallModifier ballModifier;
    PlayerModifier playerModifier;
};

#endif // POWERUP_H
