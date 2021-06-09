#include "CallByValue.h"
#include <iostream>

using std::cout;
using std::endl;

void f(int* p_number)
{
    cout << "f: p_number " << *p_number << endl;
    cout << "f: &p_number " << &p_number << endl;
}

int CallByValue::main()
{
    int* p_number = new int{ 4 };

    cout << "MAIN: p_number " << p_number << endl;
    cout << "MAIN: &p_number " << &p_number << endl;
    
    f(p_number);

    return 0;
}
