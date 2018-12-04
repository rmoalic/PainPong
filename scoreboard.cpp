#include "scoreboard.h"

ScoreBoard::ScoreBoard() : QObject()
{
    this->score1 = 0;
    this->score2 = 0;
}

void ScoreBoard::setScore1(int score) {
    this->score1 = score;
    emit score1Changed(score);
}

void ScoreBoard::setScore2(int score) {
    this->score2 = score;
    emit score2Changed(score);
}

int ScoreBoard::getScore1() {
    return this->score1;
}


int ScoreBoard::getScore2() {
    return this->score2;
}
