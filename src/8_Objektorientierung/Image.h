#pragma once

#include <vector>


using uchar = unsigned char;
using GraySclaeMatrix = std::vector<std::vector<uchar>>;

class Image
{
public:
    Image();
    Image(const unsigned int &width, const unsigned int &height);
    ~Image();
    void save_image(const char* file_name) const;


private:
    unsigned int _width;
    unsigned int _height;
    GraySclaeMatrix _matrix;
};

