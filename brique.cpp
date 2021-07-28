#include "brique.h"
#include <math.h>
#include <QPainterPath>

Brique::Brique(double x, double y, int size_x, int size_y, int points)
{
    this->repr = QRectF(x, y, size_x, size_y);
    this->value = points;
    this->destroyed_state = 2;
}

const QRectF Brique::getRepr()
{
    return this->repr;
}

int Brique::getValue()
{
    return this->value;
}

void Brique::draw(QPainter* paint) {
    QPainterPath path;
    path.addRect(repr);
    paint->setPen(Qt::NoPen);
    paint->fillPath(path, QBrush(QColor(Qt::black)));
    if (destroyed_state == 1)
    	paint->drawImage(repr, *brique1);
}

bool Brique::isAlive() {
    return destroyed_state > 0;
}

QString Brique::getDestroyedText()
{
    return "Brique destroyed";
}

Brique Brique::operator--(int)
{
    this->destroyed_state--;
    return *this;
}
