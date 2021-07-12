
#pragma warning(disable : 4996) // Allow fopen usage
#include "Image.h"
#include <iostream>

using std::cout;
using std::endl;


Image::Image()
    : _width(1)
    , _height(1)
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

void Image::save_image(const char* file_name) const
{
    FILE* f;

    unsigned int num_bytes = 3 * _width * _height;
    uchar* img = (uchar*)(malloc(num_bytes));
    memset(img, 0, num_bytes);

    int filesize = 54 + 3 * _width * _height;

    for (unsigned int x = 0; x < _width; ++x)
    {
        for (unsigned int y = 0; y < _height; y++)
        {
            img[(x + y * _width) * 3 + 2] = _matrix[x][y] % 256;
            img[(x + y * _width) * 3 + 1] = _matrix[x][y] % 256;
            img[(x + y * _width) * 3 + 0] = _matrix[x][y] % 256;
        }
    }

    uchar bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    uchar bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };
    uchar bmppad[3] = { 0, 0, 0 };

    bmpfileheader[2] = (uchar)(filesize);
    bmpfileheader[3] = (uchar)(filesize >> 8);
    bmpfileheader[4] = (uchar)(filesize >> 16);
    bmpfileheader[5] = (uchar)(filesize >> 24);

    bmpinfoheader[4] = (uchar)(_width);
    bmpinfoheader[5] = (uchar)(_width >> 8);
    bmpinfoheader[6] = (uchar)(_width >> 16);
    bmpinfoheader[7] = (uchar)(_width >> 24);
    bmpinfoheader[8] = (uchar)(_height);
    bmpinfoheader[9] = (uchar)(_height >> 8);
    bmpinfoheader[10] = (uchar)(_height >> 16);
    bmpinfoheader[11] = (uchar)(_height >> 24);

    f = fopen(file_name, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (unsigned int i = 0; i < _height; i++)
    {
        fwrite(img + (_width * (_height - i - 1) * 3), 3, _width, f);
        fwrite(bmppad, 1, (4 - (_width * 3) % 4) % 4, f);
    }

    fclose(f);
}

void Image::clear_image()
{
    _matrix.clear();
    _height = _width = 0;
}

void Image::set_pixel(const unsigned int x, const unsigned int y, const uchar value)
{
    _matrix[x][y] = value;
}


void Image::resize_image(const unsigned int new_width, const unsigned int new_height)
{
    _width = new_width;
    if (_width != new_width)
    {
        _matrix.resize(new_width);
        _width = new_width;
    }

    if (_height != new_height)
    {
        _height = new_height;
        for (auto& v : _matrix)
        {
            v.resize(_height);
        }
    }
}


void Image::fill_image(const uchar value)
{
    for (size_t i = 0; i < _matrix.size(); i++)
    {
        for (size_t j = 0; j < _matrix[0].size(); j++)
        {
            _matrix[i][j] = value;
        }
    }
}

void Image::draw_line(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2, const uchar value)
{
    for (size_t i = 0; i < _matrix.size(); i++)
    {
        for (size_t j = 0; j < _matrix[0].size(); j++)
        {
            if (i == x1)
                if (j <= y1)
                    _matrix[i][j] = value;

            if (j == y2)
                if (i <= x2)
                    _matrix[i][j] = value;
        }
    }
}
