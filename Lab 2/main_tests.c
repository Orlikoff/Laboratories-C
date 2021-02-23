#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "formulas.h"
#include "input.h"
#include "formulas.c"
#include "input.c"

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
int checkFunction4(char *, float (*)(float, float, float, float), float *, float);
int checkFunction3(char *, float (*)(float, float, float), float *, float);
int checkFunction2(char *, float (*)(float, float), float *, float);
int checkFunction1(char *, float (*)(float), float *, float);

//** Overloading function till the 200'th line TODO: not working :(

int main()
{
    int correct = 0, incorrect = 0, checked = 0;
    float params[4] = {0.0, 0.0, 0.0, 0.0}, expectedValue;

    //Writing welcome :3
    magenta(0);
    printf("\n\n\t\t*****Starting checking*****\n\n");
    reset();

    //? Checking function getAngularVelocity
    //** Expecting float:
    expectedValue = 1.00;
    //!! Adding necessary params:
    params[0] = 2 * PI;
    if (checkFunction1("getAngularVelocity", getAngularVelocity, params, expectedValue))
    {
        correct++;
        checked++;
    }
    else
    {
        incorrect++;
        checked++;
    }
    //? Finishing checking getAngularVelocity

    // SPACEER

    //? Checking function calculateDistance
    //** Expecting float:
    expectedValue = 3.00;
    //!! Adding necessary params:
    params[0] = 1.5;
    params[1] = 2.0;
    params[2] = 1.5 * PI;
    params[3] = 1.3 * PI;
    if (checkFunction4("calculateDistance", calculateDistance, params, expectedValue))
    {
        correct++;
        checked++;
    }
    else
    {
        incorrect++;
        checked++;
    }
    //? Finishing checking calculateDistance

    //SPACER

    //? Checking function calculateForce
    //** Expecting float:
    expectedValue = 37.00;
    //!! Adding necessary params:
    params[0] = 3.5;
    params[1] = 4.0;
    params[2] = 0.000005;
    if (checkFunction3("calculateForce", calculateForce, params, expectedValue))
    {
        correct++;
        checked++;
    }
    else
    {
        incorrect++;
        checked++;
    }
    //? Finishing checking calculateForce

    //? Checking function getPeriod
    //** Expecting float:
    expectedValue = 8.00;
    //!! Adding necessary params:
    params[0] = 2.5;
    params[1] = 1.75;
    if (checkFunction2("getPeriod", getPeriod, params, expectedValue))
    {
        correct++;
        checked++;
    }
    else
    {
        incorrect++;
        checked++;
    }
    //? Finishing checking getPeriod

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

int checkFunction4(char *name, float (*boo)(float, float, float, float), float *params, float expectedValue)
{
    //? Variable is showing the result of fucntion: 1 - correct, 0 - incorrect
    int correct;

    //? Printing some info about fucntion that is being tested
    yellow(0);
    printf("\n---Checking %s function---\n", name);
    reset();

    //? Checking value of function with expected value
    if (floorf((*boo)(params[0], params[1], params[2], params[3])) == expectedValue)
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

int checkFunction3(char *name, float (*boo)(float, float, float), float *params, float expectedValue)
{
    //? Variable is showing the result of fucntion: 1 - correct, 0 - incorrect
    int correct;

    //? Printing some info about fucntion that is being tested
    yellow(0);
    printf("\n---Checking %s function---\n", name);
    reset();

    //? Checking value of function with expected value
    if (floorf((*boo)(params[0], params[1], params[2])) == expectedValue)
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

int checkFunction2(char *name, float (*boo)(float, float), float *params, float expectedValue)
{
    //? Variable is showing the result of fucntion: 1 - correct, 0 - incorrect
    int correct;

    //? Printing some info about fucntion that is being tested
    yellow(0);
    printf("\n---Checking %s function---\n", name);
    reset();

    //? Checking value of function with expected value
    if (floorf((*boo)(params[0], params[1])) == expectedValue)
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

int checkFunction1(char *name, float (*boo)(float), float *params, float expectedValue)
{
    //? Variable is showing the result of fucntion: 1 - correct, 0 - incorrect
    int correct;

    //? Printing some info about fucntion that is being tested
    yellow(0);
    printf("\n---Checking %s function---\n", name);
    reset();

    //? Checking value of function with expected value
    if (floorf((*boo)(params[0])) == expectedValue)
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
