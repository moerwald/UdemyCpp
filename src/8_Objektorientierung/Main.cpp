#include "Image.h"

int main()
{
    Image im1(400, 200);
    im1.save_image("Image.bmp");
    im1.clear_image();
    im1.save_image("Image.bmp");
    Image im2;
    
    return 0;
}
