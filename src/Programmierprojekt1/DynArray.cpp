#include "DynArray.h"

void DynArray::PushBack(int *&inputArray, const unsigned int &size, const int &value)
{
    int *temp = nullptr;
    temp = new int[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        temp[i] = inputArray[i];
    }

    temp[size] = value;

    delete[] inputArray;
    inputArray = temp;
}

void DynArray::PopBack(int *&inputArray, const unsigned int &size)
{
    int *temp = nullptr;
    temp = new int[size - 1];

    for (size_t i = 0; i < size; i++)
    {
        /* code */
        temp[i] = inputArray[i];
    }

    delete[] inputArray;
    inputArray = temp;
}
