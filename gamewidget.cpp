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
#include <QDebug>
#include <array>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    this->setFocus();
    this->ball = new Ball(QPoint(240,250), 2, M_PI/2);
    this->briques = new std::array<Brique*, 3>({new Brique(20,20,80,25,3),new Brique(51,51,80,25,5), new ColoredBrique(81,81,80,25,1,Qt::red)});

    this->p1 = new Player(Player::TOP, this->geometry().size());
    this->p2 = new Player(Player::BOTTOM, this->geometry().size());


    QThread* somethread = new QThread();
    QTimer *timer = new QTimer();
    timer->setInterval(10);
    timer->moveToThread(somethread);

    connect(somethread, SIGNAL(started()), timer, SLOT(start()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    somethread->start();
}

void GameWidget::keyPressEvent(QKeyEvent* event) {
    keys[event->key()] = true;
}

void GameWidget::keyReleaseEvent(QKeyEvent* event) {
    keys[event->key()] = false;
}

void GameWidget::move() {
    if (keys[Qt::Key_A]) {
        p1->moveLeft();
    }
    if (keys[Qt::Key_E]) {
        p1->moveRight();
    }
    if (keys[Qt::Key_I]) {
        p2->moveLeft();
    }
    if (keys[Qt::Key_P]) {
        p2->moveRight();
    }
}

void GameWidget::paintEvent(QPaintEvent * )
{
    move(); // move the players
    qDebug() << this->size();
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

