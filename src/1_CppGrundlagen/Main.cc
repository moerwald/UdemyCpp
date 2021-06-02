#include <iostream>
#include "Example1.h"

int AddVars()
{
    int zahl1{};
    int zahl2{};
    int ergebnis;

    ergebnis = zahl1 + zahl2;

    return ergebnis;
}

void DataTypes()
{
    auto printMessage = [](std::string type, unsigned long long size)
    { 
        std::cout << type << "\t" << size << std::endl;
    };

    // bools are represented as numeric value. True = 1, false = 0;
    bool boolIsFalse = false;
    auto boolIsTrue = !boolIsFalse;

    std::cout << boolIsFalse << std::endl;
    std::cout << boolIsTrue << std::endl;

    // 8-bit chars represent single letters, for UTF other types are needed
    auto letter = 'a';
    std::cout << letter << std::endl;
    
    bool b = false;
    printMessage("bool", sizeof(b));

    // 8-bit
    unsigned char uLetter = 97;
    printMessage("char", sizeof(uLetter));

    // 16 bit
    short sNumber{};
    printMessage("short", sizeof(sNumber));

    int iNumber{};
    printMessage("int", sizeof(iNumber));

    long long llNumber{};
    printMessage("long long", sizeof(llNumber));

}

int main(void)
{
	std::cout << "Hello World!" << std::endl;
    AddVars();
    DataTypes();

    Example1::ReadSquare();


	return 0;
}


