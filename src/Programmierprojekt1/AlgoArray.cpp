#include "AlgoArray.h"
#include <cstddef>
#include <math.h>

double Sum(DynamicArray& array)
{
    auto sum = 0;
    for (size_t i = 0; i < array.m_length; i++)
    {
        sum += array.m_data[i];
    }

    return sum;
}

double Mean(DynamicArray& array)
{
    return Sum(array) / array.m_length;
}

double Median(DynamicArray& array)
{
    auto isEven = array.m_length % 2 == 0;
    if (isEven)
    {
        std::size_t index1 = array.m_length / 2;
        std::size_t index2 = index1 - 1;
        return (array.m_data[index1] + array.m_data[index2]) / 2;
    }

    std::size_t index = array.m_length / 2;
    return array.m_data[index];
}

double Variance(DynamicArray& array)
{
    auto mean = Mean(array);
    auto variance = 0.0;
    auto probability = 1.0 / array.m_length;

    for (size_t i = 0; i < array.m_length; i++)
    {
        variance += pow(array.m_data[i] - mean, 2.0) * probability;
    }

    return variance;
}

double StdDev(DynamicArray& array)
{
    return sqrt(Variance(array));
}
