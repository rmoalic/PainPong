#include "gamewidget.h"
#include "brique.h"
#include "coloredbrique.h"
#include <QPainter>
#include <QPaintEvent>
#include <QtDebug>
#include <QTimer>
#include <array>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    this->ball = new Ball(QPoint(4,5), 0.2, 0.55);
    this->briques = new std::array<Brique*, 3>({new Brique(20,20,30,30,3),new Brique(51,51,30,30,5), new ColoredBrique(81,81,30,30,1,Qt::red)});
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(20);
}


void GameWidget::paintEvent(QPaintEvent * )
{
    QPainter painter(this);
    painter.translate(QPoint(100,100));
    painter.setPen(Qt::red);

    this->ball->nextPos();
    this->ball->draw(&painter);

    painter.rotate(rotate++);
    std::array<Brique*,3>::iterator myit;
    for(myit = briques->begin();
            myit != briques->end();
            myit++)
    {
        (*myit)->draw(&painter);
        qDebug() << (*myit)->getDestroyedText();
    }
    qDebug() << "Draw";
}
