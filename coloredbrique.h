#ifndef COLOREDBRIQUE_H
#define COLOREDBRIQUE_H
#include "brique.h"
#include <QColor>

class ColoredBrique : public Brique
{
public:
    ColoredBrique(int x, int y, int size_x, int size_y, int points, QColor color);
    QColor getColor();
    QString getDestroyedText();

private:
    QColor color;
};

#endif // COLOREDBRIQUE_H
