#include "Image.h"


Image::Image(const unsigned int& width, const unsigned int& height)
{

    _width = width;
    _height = height;
    _matrix = GraySclaeMatrix(_width, std::vector<uchar>(_height, 0));
}
