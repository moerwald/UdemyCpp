#include "String1.h"
#include <string>;
#include <iostream>

int String1::main()
{
    std::string str = "Hallo dies ist ein String";

    auto idx = str.find("dies");
    std::cout << "Index= " << idx << std::endl;


    return 0;
}
