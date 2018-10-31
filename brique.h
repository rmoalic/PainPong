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
    Brique(int, int, int, int, int);
    const QRect getRepr();
    int getValue();
    virtual QString getDestroyedText();
    void draw(QPainter* paint);
    virtual ~Brique();
protected:
    QRect repr;
    int value;
};

#endif // BRIQUE_H
