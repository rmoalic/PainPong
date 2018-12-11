#ifndef BRIQUE_H
#define BRIQUE_H
#include "idrawable.h"
#include <QRect>
#include <QString>
#include <QColor>
#include <QPainter>
#include <vector>

class Brique : public IDrawable
{
public:
    Brique(double, double, int, int, int);
    const QRectF getRepr();
    int getValue();
    virtual QString getDestroyedText();
    double getCornerAngle(unsigned int angleNb);
    void draw(QPainter* paint);
    virtual ~Brique();
protected:
    QRectF repr;
    int value;
    std::vector<double> corners;
};

#endif // BRIQUE_H
