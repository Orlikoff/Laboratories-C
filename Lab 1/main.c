#include <stdio.h>
#include "math.h"

int main()
{
    int num, a, b, c;

    num = 100;

    while (num < 1000)
    {
        if (power(num / 100, 3) + power(num / 10 % 10, 3) + power(num % 100 % 10, 3) == num)
        {
            printf("%d\n", num);
        }

        num++;
    }

    return 0;
}
