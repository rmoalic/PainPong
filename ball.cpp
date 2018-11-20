#include "ball.h"

Ball::Ball(QPoint initPos, double velocity, double angle): IDrawable ()
{
    this->pos = initPos;
    this->velocity = velocity;
    this->angle = angle;
}

QPoint Ball::getPos()
{
    return pos;
}

double Ball::getAngle() {
    return angle;
}

double Ball::getVelocity() {
    return velocity;
}

void Ball::setVelocity(double v)
{
    this->velocity = v;
}

void Ball::nextPos() {
    this->pos.setX((pos.x() + 2) % 200);
}

void Ball::draw(QPainter* paint) {
    QPainterPath path;
    path.addEllipse(pos.x(), pos.y(), 25, 25);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(QColor(155,0,0)));

    path.addEllipse(pos.x()+5, pos.y()+5, 8, 8);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(QColor(255,0,0)));
}
