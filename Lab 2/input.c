#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

float *inputData(int param)
{
    // var for checking the input
    double temp;
    char input[] = "";

    //int mass, radius, speed, i;
    float *data = (float *)malloc(sizeof(float) * 3);

    printf("Input Mass of the E2G_%d: ", param);
    scanf("%s", input);
    while (!(atof(input) > 0))
    {
        printf("Enter the number please: ");
        scanf("%s", input);
    }
    temp = atof(input);
    data[0] = (float)temp;

    printf("Input Orbitting Distance of the E2G_%d: ", param);
    scanf("%s", input);
    while (!(atof(input) > 0))
    {
        printf("Enter the number please: ");
        scanf("%s", input);
    }
    temp = atof(input);
    data[1] = (float)temp;

    printf("Input Velocity of the E2G_%d: ", param);
    scanf("%s", input);
    while (!(atof(input) > 0))
    {
        printf("Enter the number please: ");
        scanf("%s", input);
    }
    temp = atof(input);
    data[2] = (float)temp;

    return data;
}