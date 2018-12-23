#ifndef SCOREBOARDWIDGET_H
#define SCOREBOARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ScoreBoardWidget : public QWidget
{
    Q_OBJECT
public:
    ScoreBoardWidget(QWidget *parent);
    ~ScoreBoardWidget();
private:
    QHBoxLayout* layout;
    QLabel* score1;
    QLabel* score2;

public slots:
    void setScore1(int score);
    void setScore2(int score);
};

#endif // SCOREBOARDWIDGET_H
