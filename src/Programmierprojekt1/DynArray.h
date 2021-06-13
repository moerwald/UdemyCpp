#pragma once

#include <cstddef>

/**
 * @brief DynamicArray Structure
 *
 * @param double* m_data
 */
struct DynamicArray
{
    double *m_data;
    std::size_t m_length;
};

DynamicArray Create (const double& value, const std::size_t& length);

class DynArray
{
public:
    void PushBack(DynamicArray& dynamic_array, const int &value);

public:
    void PopBack(DynamicArray& dynamic_array);
};
