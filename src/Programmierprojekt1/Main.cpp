#include "DynArray.h"
#include <iostream>
#include <cstddef>

int main()
{
    DynamicArray arr = CreateDynamicArray(42.0, 10);

    for (std::size_t i = 0; i < 10; i++)
    {
        std::cout << arr.m_data[i] << std::endl;
        /* code */
    }


    return 0;
}
