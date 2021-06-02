#include "Square.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Square::ReadSquare()
{
    double side{};
    cout << "Enter side:";
    cin >> side;

    auto result = side * side;
    cout << "Square area:" << result << endl;
    cout << "Square perimeter:" << 4 * side << endl;
}
