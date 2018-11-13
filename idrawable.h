#ifndef IDRAWABLE_H
#define IDRAWABLE_H
#include <QPainter>

class IDrawable {
public:
    virtual ~IDrawable() {}
    virtual void draw(QPainter* paint) = 0;
};

#endif // IDRAWABLE_H
