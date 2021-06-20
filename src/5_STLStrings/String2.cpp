#include "String2.h"
#include <string>
#include <iostream>

int String2::main()
{
    std::string some_text = "one\ntwo\nthree\n";
    auto search_string = "thr";

    auto idx = some_text.find(search_string);
    if (idx != std::string::npos)
    {
        std::cout << "find idx: " << idx << std::endl;
    }

    search_string = "o";
    idx = some_text.rfind(search_string);
    if (idx != std::string::npos)
    {
        std::cout << "rfind idx: " << idx << std::endl;
    }

    search_string = "ow"; // search either o or w!!
    idx = some_text.find_first_of(search_string);
    if (idx != std::string::npos)
    {
        std::cout << "find_first_of idx: " << idx << std::endl;
    }

    idx = some_text.find_first_not_of(search_string); // search for other chars then o and w!
    if (idx != std::string::npos)
    {
        std::cout << "find_first_not_of idx: " << idx << std::endl;
    }

    idx = some_text.find_last_of(search_string);
    if (idx != std::string::npos)
    {
        std::cout << "find_last_of idx: " << idx << std::endl;
    }





    return 0;
}
