#include "PointerArray.h"
#include <iostream>

using std::cout;
using std::endl;

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
    // headp deallocation
    delete[] p;

    return 0;
}
