#pragma once

#include <cstddef>

struct DynamicArray
{
    double* m_data;
    std::size_t m_length;
};

DynamicArray CreateDynamicArray(const double& value, const std::size_t& length);

void PushBack(DynamicArray& dynamic_array, const int& value);

void PopBack(DynamicArray& dynamic_array);
