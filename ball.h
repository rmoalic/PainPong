#ifndef BALL_H
#define BALL_H
#include "idrawable.h"
#include <QPoint>
#include <QPainter>

class Ball : public IDrawable
{
public:
    Ball(QPoint initPos, int velocity, double angle);
    QPoint getPos();
    int getVelocity();
    double getAngle();
    void setAngle(double angle);
    void setVelocity(int v);
    void nextPos();
    void draw(QPainter* paint);
private:
    QPoint pos;
    int velocity;
    double angle;
};

#endif // BALL_H
