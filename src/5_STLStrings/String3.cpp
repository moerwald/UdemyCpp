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
    str2.append(", yo");
    std::cout << "str2: " << str2 << std::endl;

    // Replace
    const std::string to_replace = "string";
    const std::string replace_with = "STRING";
    auto idx = str2.find(to_replace);
    str2.replace(idx, to_replace.size(), replace_with);
    std::cout << "str2 (replace 'string' with 'STRING'): " << str2 << std::endl;

    const std::string str3 = "hello";
    const std::string str4 = "hello";
    auto same = str3.compare(str4); // Compare character by character
    std::cout << "compare : " << same << std::endl;
    same = str3.compare("henllo"); // Compare character by character -1 -> n comes before l in alphabet
    std::cout << "compare : " << same << std::endl;

    return 0;
}
