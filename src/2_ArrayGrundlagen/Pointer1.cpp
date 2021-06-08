#include "Pointer1.h"
#include <iostream>

using std::cout;
using std::endl;

int Pointer1::main()
{
    int* p_zahl = new int{ 4 };

    cout << p_zahl << endl;
    cout << *p_zahl << endl;
    cout << &p_zahl << endl;

    delete p_zahl;


    return 0;
}
