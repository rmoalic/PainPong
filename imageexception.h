#ifndef IMAGEEXCEPTION_H
#define IMAGEEXCEPTION_H
#include <exception>

using namespace std;

class ImageException : public exception
{
public:
    ImageException();
    const char * what() const throw();
};

#endif // IMAGEEXCEPTION_H
