#include "SmallStringOptimization.h"
#include <string>
#include <iostream>


int SmallStringOptimization::main()
{

    for (size_t i = 0; i < 32; i++)
    {
        std::string str(i, 'a');
        std::cout << str << std::endl;
    }
    return 0;
}
