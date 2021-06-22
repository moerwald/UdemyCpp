#include "RAndLValueSamples.h"
#include<string>
#include<iostream>

/* by making the l-value-reference const, the method can also take r-value. If we remove constness only l-values are supported!*/
void print(const std::string& str)
{
    std::cout << "print_const_l_value_reference: " << str << std::endl;
}

/* r value ref only takes temporary objects */
void print(std::string&& str)
{
    std::cout << "print_r_value_reference: " << str << std::endl;
}

void print(const int& i)
{
    std::cout << "int l-value-ref: " << i << std::endl;
}

void print(int&& i)
{
    std::cout << "int r-value-ref: " << i << std::endl;
}

int RAndLValueSamples::main()
{
    std::string str = "test";
    std::string& str_l_value_ref = str;
    std::string* str_l_value_ptr = &str;
    const std::string str_const = "test";

    print(str_const);
    print(str);
    print(str_l_value_ref);
    print(*str_l_value_ptr);

    print("test");

    std::string str1 = "str1";
    std::string str2 = "str2";
    std::string str12 = str1 + str2;
    print(str1 + str2);
    // Won't compile print_r_value_reference(str12); 

    print(10); // r-value-ref

    int a = 10;
    print(a);// l-value-ref

    int& b = a;
    print(b);// l-value-ref

    return 0;
}
