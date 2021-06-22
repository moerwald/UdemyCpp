#include "RAndLValueSamples.h"
#include<string>
#include<iostream>

void print_const_l_value_reference(const std::string& str)
{
    std::cout << "print_const_l_value_reference: " << str << std::endl;
}

void print_r_value_reference(std::string&& str)
{
    std::cout << "print_r_value_reference: " << str << std::endl;
}

int RAndLValueSamples::main()
{
    std::string str = "test";
    std::string& str_l_value_ref = str;
    std::string* str_l_value_ptr = &str;
    const std::string str_const = "test";

    print_const_l_value_reference(str_const);
    print_const_l_value_reference(str);
    print_const_l_value_reference(str_l_value_ref);
    print_const_l_value_reference(*str_l_value_ptr);

    print_r_value_reference("test");

    std::string str1 = "str1";
    std::string str2 = "str2";
    std::string str12 = str1 + str2;
    print_r_value_reference(str1 + str2);
    // Won't compile print_r_value_reference(str12); 

    return 0;
}
