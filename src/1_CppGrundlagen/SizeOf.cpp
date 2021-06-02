#include "SizeOf.h"
#include <iostream>

void SizeOf::Print()
{
    auto printMessage = [](std::string type, unsigned long long size)
    { 
        std::cout << type << "\t" << size << std::endl;
    };

    char a{};
    short s{};
    int i{};
    long long int lli{};
    float f{};
    double d{};

    printMessage("Char", sizeof(a));
    printMessage("Short", sizeof(i));
    printMessage("Long long int", sizeof(lli));
    printMessage("Float", sizeof(f));
    printMessage("Double", sizeof(d));
}
