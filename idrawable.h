#ifndef IDRAWABLE_H
#define IDRAWABLE_H
#include <QPainter>

/**
 * Interface for things that can be drawn on a canvas.
 * With a QPainter from Qt.
 */
class IDrawable {
public:
    virtual ~IDrawable() {}

    /**
     * Draw itself with the Painter.
     * \param paint an initialised painter
     */
    virtual void draw(QPainter* paint) = 0;
};

#endif // IDRAWABLE_H
