#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "math.h"
#include "math.c"

// #define RED "\e[0;31m"
// #define GRN "\e[0;32m"
// #define YEL "\e[0;33m"

void magenta(int bold)
{
    if (bold)
    {
        printf("\033[1;35m");
    }
    else
    {
        printf("\033[0;35m");
    }
}

void cyan(int bold)
{
    if (bold)
    {
        printf("\033[1;36m");
    }
    else
    {
        printf("\033[0;36m");
    }
}

void green(int bold)
{
    if (bold)
    {
        printf("\033[1;32m");
    }
    else
    {
        printf("\033[0;32m");
    }
}

void red(int bold)
{
    if (bold)
    {
        printf("\033[1;31m");
    }
    else
    {
        printf("\033[0;31m");
    }
}

void yellow(int bold)
{
    if (bold)
    {
        printf("\033[1;33m");
    }
    else
    {
        printf("\033[0;33m");
    }
}

void reset()
{
    printf("\033[0m");
}

//! Prototypes of checkFunction
int checkFunction(char *, int (*)(int, int), int *, int);

//** Overloading function till the 200'th line

int main()
{
    int correct = 0, incorrect = 0, checked = 0, expectedValue;
    int params[4] = {0, 0, 0, 0};

    //Writing welcome :3
    magenta(0);
    printf("\n\n\t\t*****Starting checking*****\n\n");
    reset();

    //? Checking function power
    //** Expecting int:
    expectedValue = 16;
    //!! Adding necessary params:
    params[0] = 4;
    params[1] = 2;
    if (checkFunction("power", power, params, expectedValue))
    {
        correct++;
        checked++;
    }
    else
    {
        incorrect++;
        checked++;
    }

    //** Expecting int:
    expectedValue = 27;
    //!! Adding necessary params:
    params[0] = 3;
    params[1] = 3;
    if (checkFunction("power", power, params, expectedValue))
    {
        correct++;
        checked++;
    }
    else
    {
        incorrect++;
        checked++;
    }
    //? Finishing checking power

    // SPACEER

    printf("\n\n\n");
    cyan(0);
    printf("Final results: \n");
    green(0);
    printf("Correct: %d\n", correct);
    red(0);
    printf("Incorrect: %d\n", incorrect);
    yellow(0);
    printf("From %d checked functions", checked);
    reset();

    //Making some space
    printf("\n\n\n");

    getch();

    return 0;
}

int checkFunction(char *name, int (*boo)(int, int), int *params, int expectedValue)
{
    //? Variable is showing the result of fucntion: 1 - correct, 0 - incorrect
    int correct;

    //? Printing some info about fucntion that is being tested
    yellow(0);
    printf("\n---Checking %s function---\n", name);
    reset();

    //? Checking value of function with expected value
    if ((*boo)(params[0], params[1]) == expectedValue)
    {
        correct = 1;
    }
    else
    {
        correct = 0;
    }

    //? Outputting the results
    if (correct)
    {
        green(0);
        printf("---%s is correct---\n", name);
        reset();
        return 1;
    }
    else
    {
        red(0);
        printf("---%s is incorrect---\n", name);
        reset();
        return 0;
    }
}
