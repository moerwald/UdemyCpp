#include "DynArray.h"

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
}
