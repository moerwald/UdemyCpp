#include <iostream>
#include "Square.h"
#include "DataTypes.h"
#include "Circle.h"
#include "SizeOf.h"
#include "Prime.h"

int AddVars()
{
    int zahl1{};
    int zahl2{};
    int ergebnis;

    ergebnis = zahl1 + zahl2;

    return ergebnis;
}

typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;


class A
{
public:
    A()
    {
        std::cout << "A Default CTOR" << std::endl;
    };

    A(int x)
    {
        std::cout << "A Parameter CTOR" << std::endl;
        _x = x;
    };

    int _x;
};

class B
{
    public:
    B()
    {
        std::cout << "B Default CTOR" << std::endl;
    }

    B(int x)
    {
        std::cout << "B Parameter CTOR" << std::endl;
        _a = 3;
    }

    B(const B& rhs)
    {
        std::cout << "B Copy CTOR" << std::endl;
        _a = rhs._a;
    }

    B operator=(const B& rhs)
    {
        std::cout << "B =-operator" << std::endl;
        _a = rhs._a;
        return *this;
    }

private:
    A _a;
};

int main(void)
{

    B b;
    b = B(3);

    B c = B(2);
    B d = c;

    unsigned char a[8];
    a[0] = 'a';
    a[7] = 'b';

    GUID g = GUID();
    g.Data1 = 1;
    g.Data2 = 2;
    g.Data3 = 3;

    auto g2 = g;


    SizeOf::Print();
    DataTypes::Print();
    Square::ReadSquare();
    Circle::PrintCircle();

    std::cout << "Enter prime: " << std::endl;
    int number{};
    std::cin >> number;
    std::cout << "Is prime: " << Prime::IsPrime(number);

	return 0;
}


