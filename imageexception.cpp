#include "imageexception.h"

ImageException::ImageException() : exception()
{

}
const char * ImageException::what() const throw() {
   return "Image not found";
}
