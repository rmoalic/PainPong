#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include "imageexception.h"
#include <QImage>
#include <QPixmap>

/**
 * Loads an image from the ressources or the filesystem.
 * Precede with ':' if your file comes from the ressources
 *
 * \param path the path to the desired image
 */
QImage* loadImage(QString path);

#endif // IMAGELOADER_H
