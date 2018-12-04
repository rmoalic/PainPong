#include "scoreboardwidget.h"
#include <QString>
ScoreBoardWidget::ScoreBoardWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setMargin(0);

    this->score1 = new QLabel("score1");
    this->score1->setAlignment(Qt::AlignHCenter);
    this->score1->setStyleSheet("background-color:red;");
    this->score2 = new QLabel("score2");
    this->score2->setAlignment(Qt::AlignHCenter);
    this->score2->setStyleSheet("background-color:yellow;");

    layout->addWidget(this->score1);
    layout->addWidget(this->score2);
    this->setStyleSheet("background-color:black;");
}

void ScoreBoardWidget::setScore1(int score) {
    this->score1->setText("Player 1:" + QString::number(score));
}

void ScoreBoardWidget::setScore2(int score) {
    this->score1->setText("Player 2:" + QString::number(score));
}

void setScore1(int score);
