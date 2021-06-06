#include "Prime.h"

bool Prime::IsPrime(int number)
{
    for (size_t i = 2; i < number-1; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
