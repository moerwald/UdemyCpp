#include "Pointer1.h"
#include <iostream>

using std::cout;
using std::endl;

int Pointer1::main()
{
    int* p_zahl = new int{ 4 };

    // Heap memory address which is stored in p_zahl
    cout << p_zahl << endl;

    // Value of the heap memory the pointer points to
    cout << *p_zahl << endl;

    // Address of the pointer variable (on the stack)
    cout << &p_zahl << endl;

    delete p_zahl;
    p_zahl = nullptr;

    if (p_zahl == nullptr)
    {
        // Heap memory address which is stored in p_zahl
        cout << "Pointer address after setting it to nullptr " << p_zahl << endl;
    }

    return 0;
}
