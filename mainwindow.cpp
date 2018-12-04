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
    this->score = new ScoreBoardWidget(this);
    this->logic = new GameLogic(ui->widget->size(), model);
    ui->widget->setModel(model);

    connect(this->model->score_board, SIGNAL(score1Changed(int)), this->ui->score, SLOT(setScore1(int)));
    connect(this->model->score_board, SIGNAL(score2Changed(int)), this->ui->score, SLOT(setScore2(int)));
}

MainWindow::~MainWindow()
{
    delete ui->widget;
    delete ui;
    delete model;
    delete logic;
}
