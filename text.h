#ifndef TEXT_H
#define TEXT_H
#include "idrawabletemp.h"
#include <QString>
#include <QColor>

/**
 * Draw text on the screen for a fixed amount of time
 */
class Text : public IDrawableTemp
{
public:
    /**
     * Constructor
     *
     * \param s text to display
     * \param time time to display the text for
     * \param x x axis position
     * \param y y axis position
     * \param size font size
     * \param color color of the text
     */
    Text(QString s, qint64 time, int x, int y, int size, QColor color);
    void draw(QPainter *paint);
private:
    QString text; /**< Text to display */
    QPoint point; /**< Position of the text to be displayed */
    QColor color; /**< color of the text */
    int size; /**< font size */
};

#endif // TEXT_H
