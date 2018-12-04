#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QObject>

class ScoreBoard : public QObject
{
    Q_OBJECT
public:
    ScoreBoard();
    void setScore1(int score);
    void setScore2(int score);
    int getScore1();
    int getScore2();
private:
    int score1;
    int score2;
signals:
    void score1Changed(int);
    void score2Changed(int);
};

#endif // SCOREBOARD_H
