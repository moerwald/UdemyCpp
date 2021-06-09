#include "CallByReference.h"
#include <iostream>

using std::cout;
using std::endl;

void g(int* &p_number)
{
    cout << "g: p_number " << p_number << endl;
    cout << "g: &p_number " << &p_number << endl;

    p_number = new int{ 8 };
}

int CallByReference::main()
{
    int* p_number = new int{ 4 };

    cout << "MAIN: p_number " << p_number << endl;
    cout << "MAIN: &p_number " << &p_number << endl;
    
    g(p_number);

    return 0;
}
