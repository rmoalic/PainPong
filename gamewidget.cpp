#include "gamewidget.h"
#include "brique.h"
#include "coloredbrique.h"
#include "player.h"
#include "unistd.h"
#include <QPainter>
#include <QPaintEvent>
#include <QtDebug>
#include <QTimer>
#include <QThread>
#include <QKeyEvent>
#include <QDebug>

QImage* loadImage(QString path);

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    this->setFocus();
    this->somethread = new QThread(this);
    this->timer = new QTimer(this->somethread);
    this->timer->setInterval(10);
    this->backgroundImage = loadImage(":/background.png");

    connect(this->somethread, SIGNAL(started()), this->timer, SLOT(start()));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(update()));
}

GameWidget::~GameWidget()
{
    this->timer->stop();
    this->somethread->exit();
    delete this->somethread;
    delete this->timer;
    delete this->backgroundImage;
}

QImage* loadImage(QString path) {
    QPixmap img(path);
    return new QImage(img.toImage());
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
    keys[event->key()] = true;
}

void GameWidget::keyReleaseEvent(QKeyEvent* event) {
    keys[event->key()] = false;
}

void GameWidget::move() {
    gm->b1->nextPos();
    gm->b2->nextPos();

    if (keys[Qt::Key_A]) {
        gm->p1->moveLeft();
    }
    if (keys[Qt::Key_E]) {
        gm->p1->moveRight();
    }
    if (keys[Qt::Key_I]) {
        gm->p2->moveLeft();
    }
    if (keys[Qt::Key_P]) {
        gm->p2->moveRight();
    }
}

void GameWidget::paintEvent(QPaintEvent * )
{
    move(); // move the players and balls
    drawBackground();
    QPainter painter(this);

    gm->p1->draw(&painter);
    gm->p2->draw(&painter);

    gm->b1->draw(&painter);
    gm->b2->draw(&painter);
    std::vector<Brique*>::iterator myit;
    for(myit = gm->briques.begin();
            myit != gm->briques.end();
            myit++)
    {
        (*myit)->draw(&painter);
    }
}

