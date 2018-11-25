#include "ball.h"
#include "constantes.h"
#include <QRect>

Ball::Ball(QPoint initPos, int velocity, double angle): IDrawable ()
{
    this->pos = initPos;
    this->velocity = velocity;
    this->angle = -angle;
}

QPoint Ball::getPos()
{
    return pos;
}

double Ball::getAngle() {
    return angle;
}

void Ball::setAngle(double angle) {
    this->angle = -angle;
}

int Ball::getVelocity() {
    return velocity;
}

void Ball::setVelocity(int v)
{
    this->velocity = v;
}

void Ball::nextPos() {
    this->pos.setX(pos.x() + int(round(getVelocity() * cos(getAngle()))));
    this->pos.setY(pos.y() + int(round(getVelocity() * sin(getAngle()))));
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
