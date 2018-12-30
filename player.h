#ifndef PLAYER_H
#define PLAYER_H
#include "idrawable.h"

/**
 * One player of our game PainPong.
 * It has a racket that can be moved left or right at 
 * the speed of 500 pixels per seconds.
 */
class Player : public IDrawable
{
public:
    /**
     * An enum describing the position of a player
     * in the game.
     */
    enum Position {
	    TOP,    /**< The player is at the top of the screen */
	    BOTTOM  /**< The player is at the bottom of the screen */
    };

    /**
     * Constructor
     *
     * \param boardPosition the position of the player in the game
     * \param window_size the size of the game's board
     */
    Player(Position boardPosition, QSize window_size);
    ~Player();

    /**
     * Move the racket to the left of the screen.
     * The caller must provide the time elapsed betwin each calls
     * to ensure the movement speed.
     *
     * \param time_elapsed the time betwin each call in miliseconds
     */
    void moveLeft(qint64 time_elapsed);
    
    /**
     * Move the racket to the right of the screen.
     * The caller must provide the time elapsed betwin each calls
     * to ensure the movement speed.
     *
     * \param time_elapsed the time betwin each call in miliseconds
     */
    void moveRight(qint64 time_elapsed);

    void draw(QPainter* paint);

    /**
     * \return the position on the player on the board {TOP, BOTTOM}
     */
    Position getBoardPosition();

    /**
     * \return the X coordinate of the racket
     */
    double getRacketPosition();

    /**
     * \return the size of the racket
     */
    QSize getRacketSize();

private:
    Position boardPosition; /**< The player possition on the board */
    double racketPosition; /**< The x axis position of the racket */
    QSize window_size; /**< The size of the game pannel (board) */
    QSize player_size; /**< The size of the racket */
    QImage* player_sprite; /**< The images drawn on the board for the racket */
};

#endif // PLAYER_H
