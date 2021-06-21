#include "SmallStringOptimization.h"
#include <string>
#include <iostream>
#include <cstdlib>

void* operator new(std::size_t n)
{
    std::cout << "Allocating " << n << " bytes on the heap" << std::endl;
    return malloc(n);
}

int SmallStringOptimization::main()
{
    const std::size_t nr_of_strings = 64;
    // Build and run under RELEASE!!! -> string with size < 16 are allocated on the heap
    for (size_t i = 0; i < nr_of_strings; i++)
    {
        std::string str(i, 'a');
        std::cout << i << " " << str << std::endl;
    }
    return 0;
}
