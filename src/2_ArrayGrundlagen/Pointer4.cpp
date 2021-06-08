#include "Pointer4.h"
#include <iostream>

void print_int_pointer(int* p)
{
    std::cout << "Deref: " << *p << " Pointer Address: " << &p << std::endl;
}

void print_double_pointer(double* p)
{
    std::cout << "Deref: " << *p << " Pointer Address: " << &p << std::endl;
}

int Pointer4::main()
{
    int a = 1237;
    double b = -13.73;

    int* c = &a;
    print_int_pointer(c);

    *c -= 10;
    print_int_pointer(c);

    int* d = &a;
    print_int_pointer(d);
    *c -= 10;
    print_int_pointer(d);

    return 0;
}
