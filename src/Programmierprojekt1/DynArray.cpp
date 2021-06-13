#include "DynArray.h"

DynamicArray Create (const double& value, const std::size_t& length)
{
    DynamicArray arr = {nullptr, 0};

    arr.m_length = length;
    arr.m_data = new double[length];
    for (size_t i = 0; i < length; i++)
    {
        arr.m_data[i] = value;
        /* code */
    }

    return arr;
}

void DynArray::PushBack(DynamicArray& dynamic_array, const int &value)
{
    double *temp = nullptr;
    temp = new double[dynamic_array.m_length + 1];

    for (size_t i = 0; i < dynamic_array.m_length; i++)
    {
        temp[i] = dynamic_array.m_data[i];
    }

    temp[dynamic_array.m_length] = value;

    delete[] dynamic_array.m_data;
    dynamic_array.m_data = temp;
    dynamic_array.m_length++;
}

void DynArray::PopBack(DynamicArray& dynamic_array)
{
    double *temp = nullptr;
    temp = new double[dynamic_array.m_length - 1];

    for (size_t i = 0; i < dynamic_array.m_length; i++)
    {
        /* code */
        temp[i] = dynamic_array.m_data[i];
    }

    delete[] dynamic_array.m_data;
    dynamic_array.m_data = temp;
    dynamic_array.m_length--;
}
