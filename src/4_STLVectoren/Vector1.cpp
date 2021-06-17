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

    // Fill with increasing values.
    std::iota(iv.begin(), iv.end(), 42);

    intVector iv2 = iv;
    std::vector<int>& iv3 = iv;
    std::vector<int>* iv4 = &iv;

    std::cout << "&iv " << &iv << std::endl;
    std::cout << "intVector &iv2 " << &iv2 << std::endl;
    std::cout << "intVector& &iv3 " << &iv3 << std::endl;
    std::cout << "intVector* &iv4 " << &iv4 << std::endl;
    std::cout << "iv4 " << iv4 << std::endl;
    std::cout << "(*iv4)[0] " << (*iv4)[0] << std::endl;
    std::cout << "*(iv.begin()) " << *(iv.begin()) << std::endl;

    // Remove 43, the whole vector is shifted after the operation vector includes 42, 44, 45, 45
    auto deleteFrom = std::remove(iv.begin(), iv.end(), 43);
    for (auto i : iv)
    {
        std::cout << "iv " << i << std::endl;
    }

    iv.erase(deleteFrom, iv.end());
    for (auto i : iv)
    {
        std::cout << "iv " << i << std::endl;
    }

    return 0;
}
