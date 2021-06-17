#include "Vector1.h"
#include <vector>
#include<algorithm>
#include<numeric>
#include<iostream>

using intVector = std::vector<int>;

int Vector1::Main()
{
    // Create int vector
    std::vector<int> iv(4, 42);

    // Fill vector with 10s
    std::fill(iv.begin(), iv.end(), 10);

    std::iota(iv.begin(), iv.end(), 42);

    intVector iv2 = iv;

    std::vector<int>& iv3 = iv;
    std::vector<int>* iv4 = &iv;

    std::cout << "&iv " << &iv << std::endl;
    std::cout << "&iv3 " << &iv3 << std::endl;
    std::cout << "&iv4 " << &iv4 << std::endl;
    std::cout << "iv4 " << iv4 << std::endl;

    return 0;
}
