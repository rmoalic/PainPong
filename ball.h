#ifndef BALL_H
#define BALL_H
#include "idrawable.h"
#include <QPoint>
#include <QPainter>

class Ball : public IDrawable
{
public:
    Ball(QPointF initPos, double velocity, double angle);
    QPointF getPos();
    QPointF getPosCenter();
    double getVelocity();
    double getAngle();
    void setAngle(double angle);
    void setVelocity(double v);
    void nextPos();
    void draw(QPainter* paint);
private:
    QPointF pos;
    double velocity;
    double angle;
};

#endif // BALL_H
