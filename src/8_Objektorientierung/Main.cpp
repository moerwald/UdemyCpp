#include "Image.h"

int main()
{
    Image im1(400, 200);
    im1.save_image("Image.bmp");
    im1.set_pixel(10, 50, 0xFF);
    im1.save_image("Image.bmp");
    im1.fill_image(0xAA);
    im1.save_image("Image.bmp");
    Image im2;
    
    return 0;
}
