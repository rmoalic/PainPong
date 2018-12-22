#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include "brique.h"
#include "ball.h"
#include "player.h"
#include "gamemodel.h"
#include <QWidget>
#include <QPainter>
#include <vector>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    void setModel(GameModel* gm);
    QPainter painter();
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *);
    void drawBackground();
private:
    GameModel* gm;
    QThread* somethread;
    QTimer *timer;
    QImage* backgroundImage;

protected:
  virtual void  keyPressEvent(QKeyEvent *event);
  virtual void  keyReleaseEvent(QKeyEvent *event);
signals:

public slots:
};

#endif // GAMEWIDGET_H
