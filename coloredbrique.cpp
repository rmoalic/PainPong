#include "coloredbrique.h"
#include "brique.h"

ColoredBrique::ColoredBrique(int x, int y, int size_x, int size_y, int points, QColor color)
    : Brique(x, y, size_x, size_y, points)
{
    this->color = color;
}

QColor ColoredBrique::getColor()
{
    return this->color;
}

QString ColoredBrique::getDestroyedText()
{
    return "ColorBrique destroyed";
}
