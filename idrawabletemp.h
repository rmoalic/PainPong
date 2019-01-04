#ifndef IDRAWABLETEMP_H
#define IDRAWABLETEMP_H
#include "idrawable.h"
#include <QPainter>

/**
 * Interface for things that can be drawn on a canvas for a
 * certain amount of time (in ms).
 * With a QPainter from Qt.
 */
class IDrawableTemp : public IDrawable {
public:
    /**
     * Set the remaining time for the element to
     * be displayed, the caller must ensure that
     * the element is no longer drawn after the
     * time is bellow 0.
     */
    void setRemainingTime(qint64 time) {
	this->time = time;
    }
    
    /**
     * Get the remaining time for the element to
     * be displayed, the caller must ensure that
     * the element is no longer drawn after the
     * time is bellow 0.
     */
    qint64 getRemainingTime() {
        return time;
    }

protected:
    qint64 time;
};

#endif // IDRAWABLETEMP_H
