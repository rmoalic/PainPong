#ifndef BRIQUE_H
#define BRIQUE_H
#include "idrawable.h"
#include "imageloader.h"
#include <QRect>
#include <QString>
#include <QColor>
#include <QPainter>

/**
 * A brick to be drawn on the screen for a break out 
 * type of game. It has 3 states:
 *  - new
 *  - broken
 *  - dead
 * The brick changes states when using the -- operator.
 * A new brick will be drawn as plain black square.
 * A broken brick will have some texture on top of it.
 * A dead brick is the same as the broken brick, the
 * user must remove it from the game himself.
 *
 * The brick gets assign a value, this value can be 
 * used for a scoring system for exemple.
 */
class Brique : public IDrawable
{
public:
    /**
     * Constructor
     * 
     * \param pos_x the x axis to position the brick on
     * \param pos_y the y axis to position the brick on
     * \param size_w the width of the brick
     * \param size_h the height of the brick
     * \param value the value to assign at that brick
     */
    Brique(double pos_x, double pos_y, int size_w, int size_h, int value);

    /**
     * A Qt representation of the brick as a rectangle.
     * It can be used to get the position and size of 
     * the brick.
     *
     * \return The representation of the brick
     */
    const QRectF getRepr();

    /**
     * \return The value of the brique
     */
    int getValue();

    /**
     * A textual representation of the brick's death !!
     *
     * \deprecated They don't realy die =)
     */
    virtual QString getDestroyedText();

    /**
     * Draw the brick on the Painter.
     *
     * \param paint The Painter to draw the brick on
     */
    void draw(QPainter* paint);

    /**
     * \return true if the brick is in the new or broken state, false otherwise
     */
    bool isAlive();

    /**
     * Change the state of the brick.
     * new -> broken -> dead.
     * Does nothing when the brick is dead.
     */
    Brique operator--(int);
protected:
    QRectF repr; /**< the brick representation (position and size) */
    int value; /**< a value to be used for scoring type things */
    int destroyed_state; /**< the current state holder 2=new, 1=broken, 0=dead */
    /**
     * The image to be drawn over the brick in the broken state.
     * It is best if the image uses transparency to keep the color of the brick.
     *
     * \todo free the data
     */
    const QImage* brique1 = loadImage(":/brique1.png");
};

#endif // BRIQUE_H
