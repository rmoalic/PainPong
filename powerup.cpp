#include "powerup.h"

PowerUp::PowerUp(double velocity, PlayerModifier pm, BallModifier bm)
{
    this->velocityModifier = velocity;
    this->playerModifier = pm;
    this->ballModifier = bm;
}

double PowerUp::getVelocityModifier()
{
    return this->velocityModifier;
}

BallModifier PowerUp::getBallModifier()
{
    return this->ballModifier;
}

PlayerModifier PowerUp::getPlayerModifier()
{
    return this->playerModifier;
}
