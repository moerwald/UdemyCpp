#include "DynArray.h"
#include <iostream>
#include <cstddef>

int main()
{
    int* myData = nullptr;

    const std::size_t size = 3;

    int a[size];
    myData = &(a[0]);

    myData[0] = 0;
    myData[1] = 1;
    myData[2] = 2;

    std::cout << "Start-values of the array " << std::endl;
    for (std::size_t i = 0; i < size; i++)
    {
        std::cout << myData[i] << std::endl;
    }

    return 0;
}
