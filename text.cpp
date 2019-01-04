#include "text.h"
#include <QFont>

Text::Text(QString s, qint64 time, int x, int y, int size, QColor color) {
    this->text = s;
    this->setRemainingTime(time);
    this->point = QPoint(x, y);
    this->color = QColor(color);
    this->size = size;
}

void Text::draw(QPainter *paint) {
   paint->setPen(color);
   paint->setFont(QFont("Helvetica [Cronyx]", size));
   paint->drawText(point, text);
}
