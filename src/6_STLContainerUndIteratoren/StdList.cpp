#include "StdList.h"
#include <list>
#include <vector>
#include <iostream>

int StdList::main()
{
    std::cout << "Vector needs less memory size, since it directly works with an array" << std::endl;
    std::vector<int> my_vector = { 1,2,3 };
    for (size_t i = 0; i < my_vector.size(); i++)
    {
        std::cout << my_vector[i] << " " << &(my_vector[i]) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "List needs more memory size, since it works with object-nodes" << std::endl;
    std::list<int> my_list = { 1,2,3 };
    for (auto it = my_list.begin(); it != my_list.end(); ++it)
    {
        std::cout << *it << " " << &(*it) << std::endl;
    }

    std::cout << std::endl;

    my_list.push_front(0);
    my_list.push_back(4);
    for (auto it = my_list.begin(); it != my_list.end(); ++it)
    {
        std::cout << *it << " " << &(*it) << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
