#include "AlgoArray.h"
#include <cstddef>

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
    auto isOdd = array.m_length % 2 != 0;
    if (isOdd)
    {
        std::size_t index = array.m_length / 2;
        return array.m_data[index];
    }

    std::size_t index1 = array.m_length / 2;
    std::size_t index2 = index1 - 1;
    return (array.m_data[index1] + array.m_data[index2]) / 2;
}
