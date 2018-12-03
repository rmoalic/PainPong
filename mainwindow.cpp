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
    this->logic = new GameLogic(ui->widget->size(), model);
    ui->widget->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete logic;
    delete ui->widget;
}
