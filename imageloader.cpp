#include "imageloader.h"

QImage* loadImage(QString path) {
    QPixmap img(path);
    if (img.isNull()) {
        throw ImageException();
    }
    return new QImage(img.toImage());
}
