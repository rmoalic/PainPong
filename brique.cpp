#include "brique.h"

Brique::Brique(int x, int y, int size_x, int size_y, int points)
{
    this->repr = QRect(x, y, size_x, size_y);
    this->value= points;
}

const QRect Brique::getRepr()
{
    return this->repr;
}

int Brique::getValue()
{
    return this->value;
}

QString Brique::getDestroyedText()
{
    return "Brique destroyed";
}

Brique::~Brique()
{
}
