#include "ball.h"
#include "constantes.h"
#include <QRect>
#include <QDebug>

Ball::Ball(QPointF initPos, double velocity, double angle): IDrawable ()
{
    this->initPos = initPos;
    this->initAngle = angle;
    this->pos = initPos;
    this->velocity = velocity;
    this->angle = angle;
    this->color = Qt::black;
}

QPointF Ball::getPos()
{
    return pos;
}

QPointF Ball::getPosCenter()
{
    return QPointF(pos.rx() + 25/2, pos.ry() + 25/2);
}

double Ball::getAngle() {
    return angle;
}

void Ball::setAngle(double angle) {
    qDebug() << "ball angle " << angle;
    if (angle < 0) {
        angle = 2*M_PI + angle;
    }
    this->angle = angle;
}

void Ball::reset() {
    this->pos = QPointF(this->initPos);
    this->angle = this->initAngle;
}

double Ball::getVelocity() {
    return velocity;
}

void Ball::setVelocity(double v)
{
    this->velocity = v;
}

void Ball::nextPos() {
    this->pos.setX(pos.x() + (getVelocity() * cos(getAngle())));
    this->pos.setY(pos.y() + (getVelocity() * -sin(getAngle())));
}

void Ball::setColor(QColor color) {
    this->color = color;
}

void Ball::draw(QPainter* paint) {
    QPainterPath path;
    path.addEllipse(pos.x(), pos.y(), 25, 25);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(this->color));
}
