#include "ball.h"

Ball::Ball(QPoint initPos, double velocity, double angle): IDrawable ()
{
    this->pos = initPos;
    this->velocity = velocity;
    this->angle = angle;
}

double Ball::getAngle() {
    return angle;
}

double Ball::getVelocity() {
    return velocity;
}

void Ball::nextPos() {
    this->pos.setX((pos.x() + 2) % 200);
}

void Ball::draw(QPainter* paint) {
    QPainterPath path;
    path.addEllipse(pos.x(), pos.y(), 15, 15);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(Qt::green));
}
