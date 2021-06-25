#include "StdMap.h"
#include <map>
#include <string>
#include <iostream>


void print_map(const std::map<std::string, int>& map)
{
    for (auto kvp : map)
    {
        std::cout << "Key: " << kvp.first << " Value: " << kvp.second << std::endl;
    }
}

int StdMap::main()
{
    std::map<std::string, int> my_map;
    const std::string test = "test";
    my_map[test] = 1;
    my_map["henlo"] = 2;

    print_map(my_map);

    auto it = my_map.find("not existing");
    bool exists = it != my_map.end();
    std::cout << "Exists: " << exists << std::endl;
    
    std::map<std::string, int> my_map2 = {
        {"st1", 1},
        {"st2", 2},
        {"henlo", 4} // Duplicate values are not merged.
    };

    my_map.merge(my_map2);
    print_map(my_map);

    std::cout << "Ereasing st1 from my_map" << std::endl;
    my_map.erase(my_map.find("st1"));
    print_map(my_map);

    return 0;
}
