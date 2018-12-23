#include "brique.h"
#include <math.h>
#include <vector>

std::vector<double> computeCornerAngle(QRectF repr) {
    double angleUR, angleUL, angleDL, angleDR;
    angleUR = atan((repr.height()/2) / (repr.width()/2));
    angleUL = M_PI - angleUR;
    angleDL = M_PI + angleUR;
    angleDR = 2*M_PI - angleUR;
    return std::vector<double>{angleUR, angleUL, angleDL, angleDR};
}

Brique::Brique(double x, double y, int size_x, int size_y, int points)
{
    this->repr = QRectF(x, y, size_x, size_y);
    this->value = points;
    this->corners = computeCornerAngle(this->repr);
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
    paint->fillPath(path, QBrush(Qt::black));
}

QString Brique::getDestroyedText()
{
    return "Brique destroyed";
}

double Brique::getCornerAngle(unsigned int angleNb) {
    return this->corners[angleNb];
}
