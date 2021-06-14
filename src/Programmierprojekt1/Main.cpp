#include "DynArray.h"
#include "AlgoArray.h"
#include <iostream>
#include <cstddef>

constexpr std::size_t SIZE = 5;

int main()
{
    DynamicArray arr = CreateDynamicArray(42.0, SIZE);

    for (std::size_t i = 0; i < SIZE; i++)
    {
        arr.m_data[i] = i;
    }

    std::cout << "Mean: " << Mean(arr) << std::endl;
    std::cout << "Median: " << Median(arr) << std::endl;


    return 0;
}
