#include "DynamicArray.h"
#include <iostream>
#include <cstddef>

constexpr std::size_t SIZE = 5;

int main()
{
    DynamicArray<double> arr (42.0, SIZE);

    for (std::size_t i = 0; i < SIZE; i++)
    {
        arr[i] = i;
    }

    return 0;
}
