#include "Matrix.h"
#include <type_traits>

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
    return 0;
}
