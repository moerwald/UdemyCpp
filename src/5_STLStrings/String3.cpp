#include "String3.h"
#include <string>
#include <iostream>

int String3::main()
{
    std::string str = "This is a string";

    std::string str2 = str;
    std::cout << "str2: " << str2 << std::endl;

    // Empty the string
    str2.clear();
    std::cout << "str2.clear(): " << str2 << std::endl;

    // Append
    str2 = str;
    str2.append(" yo");
    std::cout << "str2: " << str2 << std::endl;

    return 0;
}
