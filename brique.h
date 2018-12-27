#ifndef BRIQUE_H
#define BRIQUE_H
#include "idrawable.h"
#include <QRect>
#include <QString>
#include <QColor>
#include <QPainter>

class Brique : public IDrawable
{
public:
    Brique(double, double, int, int, int);
    const QRectF getRepr();
    int getValue();
    virtual QString getDestroyedText();
    void draw(QPainter* paint);
    void operator--();
protected:
    QRectF repr;
    int value;
};

#endif // BRIQUE_H
