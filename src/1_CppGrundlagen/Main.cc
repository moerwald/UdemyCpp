#include <iostream>
#include "Square.h"
#include "DataTypes.h"
#include "Circle.h"
#include "SizeOf.h"
#include "Prime.h"

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
    SizeOf::Print();
    DataTypes::Print();
    Square::ReadSquare();
    Circle::PrintCircle();

    std::cout << "Enter prime: " << std::endl;
    int number{};
    std::cin >> number;
    std::cout << "Is prime: " << Prime::IsPrime(number);

	return 0;
}


