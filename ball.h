#ifndef BALL_H
#define BALL_H
#include "idrawable.h"
#include <QPoint>
#include <QPainter>

class Ball : public IDrawable
{
public:
    Ball(QPoint initPos, double velocity, double angle);
    QPoint getPos();
    double getVelocity();
    double getAngle();
    void setVelocity(double v);
    void nextPos();
    void draw(QPainter* paint);
private:
    QPoint pos;
    double velocity;
    double angle;
};

#endif // BALL_H
