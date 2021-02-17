#ifndef MATH
#define MATH

#include <stdio.h>

//Can be used to track errors with colors

// void green(int bold)
// {
//     if (bold)
//     {
//         printf("\033[1;32m");
//     }
//     else
//     {
//         printf("\033[0;32m");
//     }
// }

// void yellow(int bold)
// {
//     if (bold)
//     {
//         printf("\033[1;33m");
//     }
//     else
//     {
//         printf("\033[0;33m");
//     }
// }

// void reset()
// {
//     printf("\033[0m");
// }

int power(int a, int pow)
{
    int result = 1;
    for (int i = 0; i < pow; i++)
    {
        result *= a;
    }

    return result;
}

#endif
