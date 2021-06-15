#include "MathFunctions.h"
#include <iostream>

void MathFunctions::FillDoubleVector(std::vector<double>& vec)
{
    auto size = vec.size();
    vec.clear();
    for (size_t i = 0; i < size; i++)
    {
        vec.push_back(i);
    }
}

void MathFunctions::PrintDoubleVector(std::vector<double>& vec)
{
    std::cout << "PrintDoubleVector" << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

void MathFunctions::DoubleVectorExp(std::vector<double>& vec)
{
}

void MathFunctions::DoubleVectorLog(std::vector<double>& vec)
{
}

int MathFunctions::Main()
{
    std::vector<double> vec = std::vector<double>();
    vec.push_back(1.0);
    vec.push_back(2.0);
    FillDoubleVector(vec);
    PrintDoubleVector(vec);

    return 0;
}
