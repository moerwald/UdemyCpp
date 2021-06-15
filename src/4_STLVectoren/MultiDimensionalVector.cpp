#include "MultiDimensionalVector.h"
#include <vector>
#include <iostream>

int MultiDimensionalVector::Main()
{
    // 4x4 array
    std::vector<std::vector<int>> vec(4, // NUM OF vectors
                                      std::vector<int>(4, // NUM OF ints
                                                       0)); // Value to fill slots

    // rows
    for (size_t i = 0; i < vec.size(); i++)
    {
        // columns
        for (size_t j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
