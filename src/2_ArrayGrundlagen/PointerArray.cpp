#include "PointerArray.h"
#include <iostream>

using std::cout;
using std::endl;

int getArrayMax(int* inputArray, unsigned int arrayLength)
{
    auto currentMax = inputArray[0];
    for (size_t i = 0; i < arrayLength; i++)
    {
        cout << inputArray[i] << endl;
        if (inputArray[i] > currentMax)
        {
            currentMax = inputArray[i];
        }
    }

    return currentMax;
}

int PointerArray::main()
{
    const unsigned int array_size = 10;

    // heap allocation
    int* p = new int[array_size];

    for (size_t i = 0; i < array_size; i++)
    {
        p[i] = i;
    }

    for (size_t i = 0; i < array_size; i++)
    {
        cout << p[i] << endl;
        cout << &p[i] << endl;
    }

    auto max = getArrayMax(p, array_size);
    cout << "max: " << max << endl;

    // headp deallocation
    delete[] p;

    int a[5] = { 1,2,3,4,5 };

    max = getArrayMax(a, sizeof(a)/sizeof(int));
    cout << "max: " << max << endl;

    return 0;
}
