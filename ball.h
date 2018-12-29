#ifndef BALL_H
#define BALL_H
#include "idrawable.h"
#include <QPoint>
#include <QPainter>

/** \brief A ball
 *
 *  A ball to be draw on the screen. it can only be moved
 *  by calling the nextPos() methods after setting an angle 
 *  and a velocity.
 *
 *  It has a fixed diameter of 25 pixels.
 */
class Ball : public IDrawable
{
public:
    /** \brief Constructor
     *
     *  The initPos and velocity parameters will be reused 
     *  when calling reset()
     *
     *  \param initPos Where the ball starts
     *  \param velocity initial speed of the ball
     *  \param angle the initial angle of the ball
     */
    Ball(QPointF initPos, double velocity, double angle);

    /**
     * \return The current position of the ball upper left corner
     * (if you think of it as a square with rounded corner)
     */
    QPointF getPos();
    
    /**
     *  \return The current position of the ball center
     */
    QPointF getPosCenter();
    
    /**
     * \return The current velocity in pixel per seconds
     */
    double getVelocity();

    /**
     * \return The next angle to be used when calling nextPos()
     */
    double getAngle();

    /**
     * Set the next angle to be used when calling nextPos()
     *
     * \param angle the angle in radian
     */
    void setAngle(double angle);

    /**
     * Place the ball to the location it was initialy placed on.
     * With the initial angle but the current velocity.
     */
    void reset();

    /**
     * Set the speed of the ball used for the nexts calls of nextPos()
     *
     * \param v speed in pixels per second
     */
    void setVelocity(double v);

    /**
     *	Move the ball according to it's current speed and target angle.
     *
     *	To ensure the ball moves at the right speed, the caller must provide
     *	the time elapsed betwin each call.
     *
     *  \param time_elapsed time in miliseconds
     *	\todo store the time in the object itself to ensure the speed
     */
    void nextPos(qint64 time_elapsed);

    /**
     * Set the color to draw the ball with
     *
     * \param color the color of the ball
     */
    void setColor(QColor color);

    /**
     * Draw the ball on the QPainter
     *
     * \param paint QPainter to draw on
     */
    void draw(QPainter* paint);
private:
    QPointF initPos;  /**< Starting position of the ball, used by reset() */
    double initAngle; /**< Starting angle for the ball next position, used by reset() */
    QPointF pos;      /**< Current position of the ball */
    double velocity;  /**< Current velocity of the ball in pixels per second */
    double angle;     /**< Current angle for the ball next position */
    QColor color;     /** The color of the ball */
};

#endif // BALL_H
