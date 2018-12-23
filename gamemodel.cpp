#include "gamemodel.h"
#include <QDebug>

GameModel::GameModel(QSize window_size)
{
    this->b1 = new Ball(QPoint(240,12), 200, 7*M_PI/6);
    this->b1->setColor(Qt::green);
    this->b2 = new Ball(QPoint(240,window_size.height() - 22), 200, 5*M_PI/6);
    this->b2->setColor(Qt::red);
    this->p1 = new Player(Player::TOP, window_size);
    this->p2 = new Player(Player::BOTTOM, window_size);
    this->score_board = new ScoreBoard();
    this->window_size = window_size;
    this->briques = initBriques();
}

std::vector<Brique*> GameModel::initBriques() {
    static int nb = 15;
    std::vector<Brique*> brique;
    qsrand(uint(time(NULL)));
    for (int i = 0; i < nb; i++) {
        int x = (qrand() % (window_size.width() - 70)) + 35;
        int y = (qrand() % (window_size.height() - 150)) + 50;
        if (qrand() % 5 == 0)
            brique.push_back(new ColoredBrique(x,y,50,35,5, Qt::red));
        else
            brique.push_back(new Brique(x,y,50,35,5));
    }
    return brique;
}
