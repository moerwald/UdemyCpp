#include "StdList.h"
#include <list>
#include <iostream>

int StdList::main()
{
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
