#include "coloredbrique.h"
#include "brique.h"

ColoredBrique::ColoredBrique(double x, double y, int size_x, int size_y, int points, QColor color)
    : Brique(x, y, size_x, size_y, points)
{
    this->color = color;
    this->random = false;
}

ColoredBrique::ColoredBrique(double x, double y, int size_x, int size_y, int points)
    : Brique(x, y, size_x, size_y, points)
{
    this->random = true;
}

QColor ColoredBrique::getColor()
{
    if (this->random)
   	color.setRgb((color.red() + 1) % 254, (color.green() + 2) % 254 , (color.blue() + 3) % 254);
    return color;
}

void ColoredBrique::draw(QPainter* paint) {
    QPainterPath path;
    path.addRect(repr);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(getColor()));
    if (destroyed_state == 1)
    	paint->drawImage(repr, *brique1);
}


QString ColoredBrique::getDestroyedText()
{
    return "ColorBrique destroyed";
}
