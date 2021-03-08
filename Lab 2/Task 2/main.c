#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "formula.h"

// #define DEBUG

#ifdef DEBUG
//! For debugging
#include "tester.h"

int main()
{
    START;

    TEST_FUNCTION(float, mySin, 0, 2.98, 8);
    TEST_FUNCTION(float, fact, 6, 3);
    TEST_FUNCTION(float, fact, 3628800, 10);

    RESULTS;

    return 0;
}

#else
//! Main cycle
int main()
{
    //? Declaring variables
    float x, n, delta, rawResult, myResult;

    //? Getting user input
    printf("Input x[any float]: ");
    scanf("%f", &x);
    x = fmod(x, 6.283);
    printf("Input n[0, 17]: ");
    scanf("%f", &n);
    while (n > 17 || n < 0)
    {
        printf("Input n[0, 17]: ");
        scanf("%f", &n);
    }
    printf("Input delta[0, 5]: ");
    scanf("%f", &delta);
    while (delta > 5 || delta < 0)
    {
        printf("Input delta[0, 5]: ");
        scanf("%f", &delta);
    }

    //? Counting sin(x)
    rawResult = sinf(x);

    //? Counting mySin(x, n)
    myResult = mySin(x, n);

    //? Showing output
    printf("The result of raw function is: %f\n", rawResult);
    printf("The result of my function is: %f\n", myResult);

    //? Playing with delta
    n = 0;
    while (n < 18 && delta < fabsf(mySin(x, n) - sinf(x)))
    {
        n++;
    }

    //? Showing results of delta counting
    if (!(delta < (fabsf(mySin(x, n) - sinf(x)))))
    {
        printf("\nThe value of n with difference of delta is: %f\n", n);
    }
    else
    {
        printf("\nIt's impossible to calculate with such parameters...\n");
    }

    //? Waiting for user
    getch();

    return 0;
}
#endif
