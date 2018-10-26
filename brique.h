#ifndef BRIQUE_H
#define BRIQUE_H
#include <QRect>
#include <QString>
#include <QColor>

class Brique
{
public:
    Brique(int, int, int, int, int);
    const QRect getRepr();
    int getValue();
    virtual QString getDestroyedText();
    virtual ~Brique();
private:
    QRect repr;
    int value;
};

#endif // BRIQUE_H
