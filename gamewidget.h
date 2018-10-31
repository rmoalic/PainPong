#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include "brique.h"
#include "ball.h"
#include <QWidget>
#include <QPainter>
#include <array>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    int rotate = 0;
    std::array<Brique*,3>* briques;
    Ball* ball;
    explicit GameWidget(QWidget *parent = nullptr);
    QPainter painter();
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // GAMEWIDGET_H
