#include "TransformMain.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int increment(int i)
{
    return ++i;
}


int TransformMain::main()
{
    std::vector my_vec1(10, 7);
    std::vector my_vec2(10, 3);
    std::vector my_vec3(10, 0);

    std::transform(my_vec1.begin(), my_vec1.end(), my_vec3.begin(), increment);

    for (auto val : my_vec3)
    {
        std::cout << "Value: " << val << std::endl;
    }

    auto &&x = std::plus<int>();

    std::transform(my_vec1.begin(), my_vec1.end(),
        my_vec2.begin(), my_vec3.begin(),
        std::plus<int>());

    for (auto val : my_vec3)
    {
        std::cout << "Value: " << val << std::endl;
    }

    return 0;
}
