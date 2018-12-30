#ifndef COLOREDBRIQUE_H
#define COLOREDBRIQUE_H
#include "brique.h"
#include <QColor>

/**
 * A colored version of the Brique
 * @copydoc Brique
 */
class ColoredBrique : public Brique
{
public:
    /**
     * @copydoc Brique::Brique(double, double, int, int, int)
     * \param color the color of the brick
     */
    ColoredBrique(double pos_x, double pos_y, int size_w, int size_h, int value, QColor color);
    
    /**
     * @copydoc Brique::Brique(double, double, int, int, int)
     * The brick will change colors
     */
    ColoredBrique(double pos_x, double pos_y, int size_w, int size_h, int value);
    
    /**
     * If a color was specified when the brick was created,
     * it returns that color. Otherwise it returns a random
     * new color.
     *
     * \return the current color of the brick
     */
    QColor getColor();

    QString getDestroyedText();
    void draw(QPainter* paint);

private:
    QColor color; /**< The current color of the brique */
    bool random; /**< True if the color is randomized each time you call getColor() */
};

#endif // COLOREDBRIQUE_H
