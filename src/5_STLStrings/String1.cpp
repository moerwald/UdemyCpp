#include "String1.h"
#include <string>;
#include <iostream>

int String1::main()
{
    std::string str = "Hallo dies ist ein String";

    auto idx = str.find("dies");
    if (idx != std::string::npos)
        std::cout << "Index= " << idx << std::endl;
    else
        std::cout << "Substring not found!" << std::endl;


    return 0;
}
