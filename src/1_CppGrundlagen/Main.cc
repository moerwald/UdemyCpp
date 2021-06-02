#include <iostream>
#include "Square.h"
#include "DataTypes.h"
#include "Circle.h"

int AddVars()
{
    int zahl1{};
    int zahl2{};
    int ergebnis;

    ergebnis = zahl1 + zahl2;

    return ergebnis;
}


int main(void)
{
	std::cout << "Hello World!" << std::endl;
    AddVars();
    DataTypes::Print();
    Square::ReadSquare();
    Circle::PrintCircle();

	return 0;
}


