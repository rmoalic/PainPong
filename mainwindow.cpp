#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamelogic.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::start() {
    this->model = new GameModel(ui->widget->size());
    GameLogic gl(ui->widget->size(), model);
    ui->widget->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}
