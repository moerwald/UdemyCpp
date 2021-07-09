#include "Image.h"
#include <iostream>

using std::cout;
using std::endl;


Image::Image()
    : _width (0)
    , _height (0)
    , _matrix(GraySclaeMatrix(_width, std::vector<uchar>(_height, 0)))
{
    cout << "Default CTOR" << endl;
}

Image::Image(const unsigned int& width, const unsigned int& height)
    : _width(width)
    , _height(height)
    , _matrix(GraySclaeMatrix(_width, std::vector<uchar>(_height, 0)))
{
    cout << "Param CTOR" << endl;

    cout << "Created image object with shape=(" << _width << "," << _height << ")!" << endl;
}

Image::~Image()
{
    cout << "DTOR" << endl;
}
