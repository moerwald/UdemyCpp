#include "Image.h"
#include <iostream>

using std::cout;
using std::endl;


Image::Image()
{
    cout << "Default CTOR" << endl;
    
    _width = 0;
    _height = 0;
    _matrix = GraySclaeMatrix(_width, std::vector<uchar>(_height, 0));
}

Image::Image(const unsigned int& width, const unsigned int& height)
{
    cout << "Param CTOR" << endl;
    _width = width;
    _height = height;
    _matrix = GraySclaeMatrix(_width, std::vector<uchar>(_height, 0));
}

Image::~Image()
{
    cout << "DTOR" << endl;
}
