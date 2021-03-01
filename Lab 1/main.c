#include <stdio.h>
#include <conio.h>
#include "math.h"

// #define DEBUG

//! for debugging--------------------
#ifdef DEBUG
#include "tester.h"

int main()
{
    //** Starting debugging mode
    COLORFY(MAGENTA);
    printf("\n\n\t\t*** DEBUG MODE ***\n\n");
    COLORFY(RESET);

    //? Testing functions
    TEST_FUNCTION(int, power, 16, 4, 2);
    TEST_FUNCTION(int, power, 256, 4, 4);
    TEST_FUNCTION(int, power, 25, 5, 2);

    //? Waiting for the user
    getch();

    return 0;
}
//! for debugging--------------------
#else
//! Main cycle
int main()
{
    // Program to print all 3-digit numbers, such that a^3 + b^3 + c^3 = (abc)
    int fool;
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

    getch();

    return 0;
}
#endif
