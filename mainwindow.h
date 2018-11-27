#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gamemodel.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void start();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameModel* model;
};

#endif // MAINWINDOW_H
