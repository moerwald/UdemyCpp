#include <iostream>
#include "Circle.h"
constexpr auto PI = 3.14159;

void Circle::PrintCircle()
{
    double radius {};
    std::cout << "Circle enter radius: ";
    std::cin >> radius;

    std::cout << "Circle area: " << radius * radius * PI << std::endl;
    std::cout << "Circle perimeter: " << 2 * radius * PI << std::endl;
}
