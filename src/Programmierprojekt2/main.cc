#include "DynamicArray.h"
#include "AlgoArray.h"
#include <iostream>
#include <cstddef>

constexpr std::size_t SIZE = 5;

int main()
{
    DynamicArray<double> arr (42.0, SIZE);

    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    for (std::size_t i = 0; i < arr.length(); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    arr.pop_back();
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();

    for (std::size_t i = 0; i < arr.length(); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    std::cout << "Mean: " << Mean(arr) << std::endl;
    std::cout << "Median: " << Median(arr) << std::endl;

    std::cout << "Variance: " << Variance(arr) << std::endl;
    std::cout << "StdDev: " << StdDev(arr) << std::endl;

    return 0;
}
