#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "formulas.h"
#include "input.h"

// #define DEBUG

//! for debugging--------------------
#ifdef DEBUG
#include "tester.h"

int main()
{
    //** Starting debugging mode
    START;

    //? Testing functions
    TEST_FUNCTION(float, getAngularVelocity, 1.00, 2 * PI);
    TEST_FUNCTION(float, getPeriod, 1.00, 1.00, 2 * PI);
    TEST_FUNCTION(float, calculateForce, 333.0, 2.00, 2.50, 0.000001);
    TEST_FUNCTION(float, calculateDistance, 2.0, 1.0, 2.0, PI, 0.75 * PI);

    //* Showing results
    RESULTS;

    //? Waiting for the user
    getch();

    return 0;
}
//! for debugging--------------------
#else
//! Main cycle
int main()
{
    //TODO: Write some tests for this program and add variables checking

    //** Declaring the variables
    char flag;
    char input2[] = "";
    double temp2;
    float *data1, *data2, *data3,
        distance1, distance2, distance3,
        year1, year2, year3,
        force1, force2, force3,
        angularVelocity1, angularVelocity2, angularVelocity3,
        deltaTime;

    //? Getting user input
    data1 = inputData(1);
    data2 = inputData(2);
    data3 = inputData(3);

    //? Calculating years
    year1 = getPeriod(data1[1], data1[2]);
    year2 = getPeriod(data2[1], data2[2]);
    year3 = getPeriod(data3[1], data3[2]);

    //? Calculating angular velocity
    angularVelocity1 = getAngularVelocity(year1);
    angularVelocity2 = getAngularVelocity(year2);
    angularVelocity3 = getAngularVelocity(year3);

    //? Outputting the results (at least one time)
    do
    {
        //? Getting delta time
        printf("\n\n\nInput delta time (in seconds): ");
        scanf("%s", input2);
        while (!(atoi(input2) > 0))
        {
            printf("Enter the number please: ");
            scanf("%s", input2);
        }
        temp2 = atof(input2);
        deltaTime = (float)temp2;

        //? Calculating the distance between 1-2, 2-3, 1-3 planets
        distance1 = calculateDistance(data1[1], data2[1], fmodf(angularVelocity1 * deltaTime, 2 * PI), fmodf(angularVelocity2 * deltaTime, 2 * PI));
        distance2 = calculateDistance(data2[1], data3[1], fmodf(angularVelocity2 * deltaTime, 2 * PI), fmodf(angularVelocity3 * deltaTime, 2 * PI));
        distance3 = calculateDistance(data1[1], data3[1], fmodf(angularVelocity1 * deltaTime, 2 * PI), fmodf(angularVelocity3 * deltaTime, 2 * PI));

        //? Calculating the forces for each group of planets
        force1 = calculateForce(data1[0], data2[0], distance1);
        force2 = calculateForce(data2[0], data3[0], distance2);
        force3 = calculateForce(data1[0], data3[0], distance3);

        //? Outputting the results
        printf("\n\n\nYear on the first planet: %f\n", year1);
        printf("Year on the second planet: %f\n", year2);
        printf("Year on the third planet: %f\n\n", year3);
        printf("Distance between 1-2 planets: %f\n", distance1);
        printf("Distance between 2-3 planets: %f\n", distance2);
        printf("Distance between 1-3 planets: %f\n\n", distance3);
        printf("Force between 1-2 planets: %.20f\n", force1);
        printf("Force between 2-3 planets: %.20f\n", force2);
        printf("Force between 1-3 planets: %.20f\n", force3);
        printf("\n\n\nWould you like to change delta time? (Y/N) ");
        scanf("%s", &flag);

    } while (flag == 'Y');

    //!Clearing the memory
    free(data1);
    free(data2);
    free(data3);

    getch();

    return 0;
}
//! Main cycle
#endif
