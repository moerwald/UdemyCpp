#include "StdIterators.h"
#include <vector>
#include <iostream>
#include <numeric>
#include <iterator>

void print(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "[" << i << "]: Value: " << vec[i] << " Address: " << &(vec[i]) << std::endl;
    }

    std::cout << std::endl;
}

void print(const std::vector<int>::const_iterator it)
{
    std::cout << "Value: " << *it << " Address: " << &*it << std::endl;
}

void print(const std::vector<int>::const_reverse_iterator it)
{
    std::cout << "Value: " << *it << " Address: " << &*it << std::endl;
}

void print(std::vector<int>::const_iterator first, const std::vector<int>::const_iterator& last)
{
    for (; first != last; ++first)
    {
        print(first);
    }
}

void print_reverse(const std::vector<int>& vec)
{
    auto rbegin = vec.crbegin();
    auto rend = vec.crend();
    for (; rbegin != rend; ++rbegin)
    {
        print(rbegin);
    }
}


int StdIterators::main()
{
    std::vector<int> my_vec(5, 0);
    print(my_vec);

    std::iota(my_vec.begin(), my_vec.end(), 1);
    print(my_vec);

    auto it = my_vec.begin();
    std::advance(it, 2);
    print(it, my_vec.end());

    auto distance = std::distance(it, my_vec.end());
    std::cout << "Distance: " << distance << std::endl;

    auto prev = std::prev(it);
    auto next = std::next(it);
    print(prev);
    print(next);

    print_reverse(my_vec);


    return 0;
}
