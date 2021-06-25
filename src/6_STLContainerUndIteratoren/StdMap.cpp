#include "StdMap.h"
#include <map>
#include <string>
#include <iostream>


void print_map(const std::map<std::string, int>& map)
{
    for (auto kvp : map)
    {
        std::cout << "Key: " << kvp.first << " Value: " << kvp.second;
    }
}

int StdMap::main()
{
    std::map<std::string, int> my_map;
    const std::string test = "test";
    my_map[test] = 1;
    my_map["henlo"] = 2;

    print_map(my_map);

    


    return 0;
}
