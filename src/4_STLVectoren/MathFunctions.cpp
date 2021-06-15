#include "MathFunctions.h"
#include <iostream>

void MathFunctions::FillDoubleVector(std::vector<double>&& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        vec.push_back(i);
    }
}

void MathFunctions::PrintDoubleVector(std::vector<double>&& vec)
{
    std::cout << "PrintDoubleVector" << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

void MathFunctions::DoubleVectorExp(std::vector<double>&& vec)
{
}

void MathFunctions::DoubleVectorLog(std::vector<double>&& vec)
{
}

int MathFunctions::Main()
{
    return 0;
}
