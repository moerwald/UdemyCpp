#pragma once

#include <math.h>
#include "DynamicArray.h"

template <typename T>
T Sum(DynamicArray<T>& array)
{
    T sum = 0;
    for (size_t i = 0; i < array.length(); i++)
    {
        sum += array[i];
    }

    return sum;
}

template <typename T>
double Mean(DynamicArray<T>& array)
{
    return Sum(array) / array.length();
}

template <typename T>
double Median(DynamicArray<T>& array)
{
    auto isEven = array.length() % 2 == 0;
    if (isEven)
    {
        std::size_t index1 = array.length() / 2;
        std::size_t index2 = index1 - 1;
        return (array[index1] + array[index2]) / 2;
    }

    std::size_t index = array.length() / 2;
    return array[index];
}

template <typename T>
double Variance(DynamicArray<T>& array)
{
    auto mean = Mean(array);
    auto variance = 0.0;
    auto probability = 1.0 / array.length();

    for (size_t i = 0; i < array.length(); i++)
    {
        variance += pow(array[i] - mean, 2.0) * probability;
    }

    return variance;

}

template <typename T>
double StdDev(DynamicArray<T>& array)
{
    return sqrt(Variance(array));
}
