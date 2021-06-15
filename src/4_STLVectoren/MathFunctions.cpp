#include "MathFunctions.h"
#include <iostream>
#include <math.h>

void MathFunctions::FillDoubleVector(std::vector<double>& vec)
{
    auto size = vec.size();
    for (size_t i = 0; i < size; i++)
    {
        vec[i] = i;
    }
}

void MathFunctions::PrintDoubleVector(std::vector<double>& vec)
{
    std::cout << "PrintDoubleVector" << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "VEC[" << i << "]" << vec[i] << std::endl;
    }

    std::cout << std::endl;
}

void MathFunctions::DoubleVectorExp(std::vector<double>& vec)
{
    auto size = vec.size();
    for (size_t i = 0; i < size; i++)
    {
        vec[i] = (std::exp(vec[i]));
    }
}

void MathFunctions::DoubleVectorLog(std::vector<double>& vec)
{
    auto size = vec.size();
    for (size_t i = 0; i < size; i++)
    {
        vec[i] = (std::log(vec[i]));
    }
}

int MathFunctions::Main()
{
    std::vector<double> vec(4, 0);

    FillDoubleVector(vec);
    PrintDoubleVector(vec);

    DoubleVectorExp(vec);
    PrintDoubleVector(vec);
    
    DoubleVectorLog(vec);
    PrintDoubleVector(vec);

    return 0;
}
