#include <stdio.h>
#include <math.h>
#include "formula.h"

float mySin(float x, float n)
{
    float result = 0;

    while (n > 0)
    {
        result += powf(-1.0, n - 1) * powf(x, 2 * n - 1) / fact(2 * n - 1);
        n--;
    }

    return result;
}

float fact(float n)
{
    float result = 1;
    n = floorf(n);
    while (n > 1)
    {
        result *= n;
        n--;
    }

    return result;
}
