#include "math.h"

int power(int a, int pow)
{
    int result = 1;
    for (int i = 0; i < pow; i++)
    {
        result *= a;
    }

    return result;
}