#include "Matrix.h"
#include <type_traits>
#include <iostream>

int main()
{
    Matrix m1(1, 2, 3, 4);
    Matrix m2(1, 2, 3, 4);

    m1.print();
    m2.print();

    Matrix m3 = m1 + m2;
    m3.print();
    Matrix m4 = std::move(m1 - m2);
    m4.print();

    m1 -= m1;
    m1.print();

    m2 += m2;
    m2.print();

    Matrix m5(1, 2, 3, 4);
    Matrix m6(5, 6, 7, 8);

    std::cout << " auto m7 = m5 * m6; " << std::endl;
    auto m7 = m5 * m6;
    m7.print();
    std::cout << " m5 *= m5; " << std::endl;
    m5 *= m5;
    m5.print();

    std::cout << " auto m8 = m6 * 3; " << std::endl;
    auto m8 = m6 * 3;
    m8.print();

    std::cout << " m6 *= 3;" << std::endl;
    m6 *= 3;
    m6.print();

    return 0;
}
