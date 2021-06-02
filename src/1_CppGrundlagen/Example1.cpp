#include "Example1.h"
#include <iostream>

void Example1::ReadSquare()
{
    int side{};
    std::cout << "Enter side:";
    std::cin >> side;

    std::cout << "Square area:" << side * side;
}
