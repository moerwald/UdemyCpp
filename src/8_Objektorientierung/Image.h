#pragma once

#include <vector>


using uchar = unsigned char;
using GraySclaeMatrix = std::vector<std::vector<uchar>>;

class Image
{
public:
    Image(const unsigned int &width, const unsigned int &height);
    ~Image() {};


private:
    unsigned int _width;
    unsigned int _height;
    GraySclaeMatrix _matrix;
};

