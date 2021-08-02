#include "DynamicArray.h"

int main()
{
    DynamicArray<int> a1(1, 2);
    DynamicArray<int> a2(3, 3);
    DynamicArray<int> a3(1, 2);

    // Calls COPY CTOR
    auto a4(a1);
    auto a5 = a1;
    auto a6 = { a1 };
    auto a7{ a1 };

    // Calls assigment operator, below statements are equivalent
    a3 = a2;
    a3.operator=(a2);

    // MOVE CTOR
    auto a8 = std::move(DynamicArray<int>(2, 4));

    // MOVE assignment operator
    DynamicArray<int> a9(1, 2);
    a9 = std::move(a1);

    return 0;
}
