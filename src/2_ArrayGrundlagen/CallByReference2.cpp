#include "CallByReference2.h"
#include <iostream>

using std::cout;
using std::endl;


// call by value
void f1(int number)
{
    number++;
}

// call by reference
void f2(int &number)
{
    number++;
}

int CallByReference2::main()
{
    int num{ 5 };
    cout << "num " << num << endl;
    f1(num);
    cout << "num " << num << endl;
    f2(num);
    cout << "num " << num << endl;
    return 0;
}
