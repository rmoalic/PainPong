#include "gamewidget.h"
#include "brique.h"
#include "coloredbrique.h"
#include "player.h"
#include <QPainter>
#include <QPaintEvent>
#include <QtDebug>
#include <QTimer>
#include <QThread>
#include <QKeyEvent>
#include <array>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    this->setFocus();
    this->ball = new Ball(QPoint(4,5), 0.2, 0.55);
    this->briques = new std::array<Brique*, 3>({new Brique(20,20,80,25,3),new Brique(51,51,80,25,5), new ColoredBrique(81,81,80,25,1,Qt::red)});

    this->p1 = new Player(Player::TOP);
    this->p2 = new Player(Player::BOTTOM);

    QThread* somethread = new QThread();
    QTimer *timer = new QTimer();
    timer->setInterval(10);
    timer->moveToThread(somethread);

    connect(somethread, SIGNAL(started()), timer, SLOT(start()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    somethread->start();
}

void GameWidget::keyPressEvent(QKeyEvent * event ) {
    qDebug() << event;
    if (event->key() == Qt::Key_A) {
        p1->moveLeft();
    }
    if (event->key() == Qt::Key_E) {
        p1->moveRight();
    }
    if (event->key() == Qt::Key_Z) {
        p2->moveLeft();
    }
    if (event->key() == Qt::Key_R) {
        p2->moveRight();
    }
}

void GameWidget::paintEvent(QPaintEvent * )
{
    QPainter painter(this);
    this->ball->nextPos();
    this->ball->draw(&painter);

    std::array<Brique*,3>::iterator myit;
    for(myit = briques->begin();
            myit != briques->end();
            myit++)
    {
        (*myit)->draw(&painter);
        //qDebug() << (*myit)->getDestroyedText();
    }

    this->p1->draw(&painter);
    this->p2->draw(&painter);

    //qDebug() << "Draw";
}

