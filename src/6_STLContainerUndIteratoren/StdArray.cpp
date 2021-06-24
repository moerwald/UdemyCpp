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

    std::cout << "Value can be changed via []-operator" << std::endl;
    my_array[1] = 42;
    std::cout << "my_array[1]: " << my_array[1] << std::endl;

    std::cout << "Array size:" << my_array.size() << std::endl;

    

    return 0;
}
