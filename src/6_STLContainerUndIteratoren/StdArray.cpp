#include "StdArray.h"
#include <array>
#include <numeric>
#include <iostream>

int StdArray::main()
{

    std::array<int, 10> my_array; // Creates an array with 10 entries, size is FIXED!!!

    std::iota(my_array.begin(), my_array.end(), 1); // Fill up with increasing ints

    std::cout << "Iterate via foreach" << std::endl;
    for (auto it : my_array)
    {
        std::cout << it << std::endl;
    }

    

    return 0;
}
