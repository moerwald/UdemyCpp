#include "MultiDimensionalVector.h"
#include <vector>
#include <iostream>

int MultiDimensionalVector::Main()
{
    // 4x2 array
    std::vector<std::vector<int>> vec(4, std::vector<int>(2, 0));

    // rows
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[i].size(); j++)
        {
            std::cout << "Vec[" << i << "," << j << "]=" << vec[i][j] << std::endl;
        }
    }

    return 0;
}
