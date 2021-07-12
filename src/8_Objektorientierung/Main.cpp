#include "Image.h"

int main()
{
    Image im1(400, 200);
    im1.save_image("Image.bmp");
    im1.set_pixel(10, 50, 0xFF);
    im1.save_image("Image.bmp");
    im1.fill_image(0xAA);
    im1.save_image("Image.bmp");
    im1.draw_line(50, 150, 150, 100, 0XFF);
    im1.save_image("Image.bmp");
    
    return 0;
}
