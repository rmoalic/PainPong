#include "gamewidget.h"
#include "brique.h"
#include "coloredbrique.h"
#include "player.h"
#include "imageloader.h"
#include "unistd.h"
#include <QPainter>
#include <QPaintEvent>
#include <QtDebug>
#include <QTimer>
#include <QThread>
#include <QKeyEvent>
#include <QDebug>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    this->setFocus();
    this->somethread = new QThread(this);
    this->timer = new QTimer(this->somethread);
    this->timer->setInterval(10);
    try {
        this->backgroundImage = loadImage(":/background.png");
    } catch(ImageException* e) {
        qDebug() << e->what();
    }
    connect(this->somethread, SIGNAL(started()), this->timer, SLOT(start()));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(update()));
}

GameWidget::~GameWidget()
{
    this->timer->stop();
    this->somethread->exit();
    while (this->somethread->isRunning()) {}
    delete this->timer;
    delete this->somethread;
    delete this->backgroundImage;
}

void GameWidget::drawBackground() {
    QPainter painter(this);
    QRectF r(0,0,this->size().width(), this->size().height());
    painter.drawImage(r, *this->backgroundImage);
}

void GameWidget::setModel(GameModel* gm) {
    this->gm = gm;
    if (! this->somethread->isRunning())
        this->somethread->start();
}

void GameWidget::keyPressEvent(QKeyEvent* event) {
    this->gm->keys[event->key()] = true;
}

void GameWidget::keyReleaseEvent(QKeyEvent* event) {
    this->gm->keys[event->key()] = false;
}

void GameWidget::paintEvent(QPaintEvent * )
{
    drawBackground();
    QPainter painter(this);

    std::vector<Brique*>::iterator myit;
    for(myit = gm->briques.begin();
            myit != gm->briques.end();
            myit++)
    {
        (*myit)->draw(&painter);
    }
    gm->p1->draw(&painter);
    gm->p2->draw(&painter);

    gm->b1->draw(&painter);
    gm->b2->draw(&painter);
}

