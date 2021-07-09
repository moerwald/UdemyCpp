#include "Image.h"
#include <iostream>

using std::cout;
using std::endl;


Image::Image()
    : _width (1)
    , _height (1)
    , _matrix(GraySclaeMatrix(_width, std::vector<uchar>(_height, 0)))
{
    cout << "Default CTOR" << endl;
    cout << "Matrix size: " << _matrix.size() << " ," << _matrix[0].size() << endl;
}

Image::Image(const unsigned int& width, const unsigned int& height)
    : _width(width)
    , _height(height)
    , _matrix(GraySclaeMatrix(_width, std::vector<uchar>(_height, 0)))
{
    cout << "Param CTOR" << endl;

    cout << "Created image object with shape=(" << _width << "," << _height << ")!" << endl;
    cout << "Matrix size: " << _matrix.size() << " ," << _matrix[0].size() << endl;
}

Image::~Image()
{
    cout << "DTOR" << endl;
}
