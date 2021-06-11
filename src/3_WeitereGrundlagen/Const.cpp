#include "Const.h"
#include <iostream>

void printValue(const unsigned int value)
{
    std::cout << value << std::endl;
    // Compiler creates error since const value can't be changed!
    // value = 10;
}

int Const::Main()
{
    const int Len = 10;

    int arr[Len]{ 1,2,3,4 };

    // Compiler calculates value during compile stage!!!
    constexpr int Len2 = 5 * 2;
    int arr2[Len2] = { 1,2,3,4 };
    
    return 0;
}
