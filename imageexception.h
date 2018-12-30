#ifndef IMAGEEXCEPTION_H
#define IMAGEEXCEPTION_H
#include <exception>

using namespace std;

/**
 * This exception expresses an error that occured 
 * while loading an image.
 */
class ImageException : public exception
{
public:
    ImageException();
    const char * what() const throw();
};

#endif // IMAGEEXCEPTION_H
