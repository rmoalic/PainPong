#include "gamemodel.h"

GameModel::GameModel(QSize window_size)
{
    this->b1 = new Ball(QPoint(240,250), 200, M_PI);
    this->b1->setColor(Qt::green);
    this->b2 = new Ball(QPoint(240,250), 200, M_PI/5);
    this->b2->setColor(Qt::red);
    this->p1 = new Player(Player::TOP, window_size);
    this->p2 = new Player(Player::BOTTOM, window_size);
    this->score_board = new ScoreBoard();
    this->briques = initBriques();
}

std::vector<Brique*> GameModel::initBriques() {
    return std::vector<Brique*>{
        new Brique(154,44,24,24, 222),
        new ColoredBrique(200, 145, 30, 44, 22, Qt::red),
        new Brique(250, 100, 30, 20, 44),
        new Brique(30, 250, 50, 30, 2)
    };
}
