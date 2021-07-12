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
    void clear_image();
    void set_pixel(const unsigned int x, const unsigned int y, const uchar value);

    void resize_image(const unsigned int new_width, const unsigned int new_height);
    void fill_image(const uchar value);


private:
    unsigned int _width;
    unsigned int _height;
    GraySclaeMatrix _matrix;

};

