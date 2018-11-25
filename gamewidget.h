#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include "brique.h"
#include "ball.h"
#include "player.h"
#include <QWidget>
#include <QPainter>
#include <QMap>
#include <array>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    int rotate = 0;
    std::array<Brique*,3>* briques;
    Ball* ball;
    Player* p1;
    Player* p2;
    QMap<int, bool> keys;

    explicit GameWidget(QWidget *parent = nullptr);
    QPainter painter();
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *);
    void move();

protected:
  virtual void  keyPressEvent(QKeyEvent *event);
  virtual void  keyReleaseEvent(QKeyEvent *event);
signals:

public slots:
};

#endif // GAMEWIDGET_H
