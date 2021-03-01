#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int CORRECT = 0;
int INCORRECT = 0;
int CHECKED = 0;

#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

#define COLORFY(color) printf(color);

#define START                                 \
    COLORFY(MAGENTA);                         \
    printf("\n\n\t\t*** DEBUG MODE ***\n\n"); \
    COLORFY(RESET);

#define TEST_FUNCTION(type, func, expectedValue, params...)          \
    {                                                                \
        CHECKED++;                                                   \
        COLORFY(YELLOW);                                             \
        printf("---Testing %s Function---\n", #func);                \
        COLORFY(RESET);                                              \
        COLORFY(GREEN);                                              \
        type result = func(params);                                  \
        if (#type != "float")                                        \
        {                                                            \
            if (result != expectedValue)                             \
            {                                                        \
                INCORRECT++;                                         \
                COLORFY(RED);                                        \
                printf("---%s function is incorrect---\n\n", #func); \
                COLORFY(RESET);                                      \
            }                                                        \
            else                                                     \
            {                                                        \
                CORRECT++;                                           \
                COLORFY(GREEN);                                      \
                printf("---%s function is correct---\n\n", #func);   \
                COLORFY(RESET);                                      \
            }                                                        \
        }                                                            \
        else                                                         \
        {                                                            \
            if (floorf(result) != expectedValue)                     \
            {                                                        \
                INCORRECT++;                                         \
                COLORFY(RED);                                        \
                printf("---%s function is incorrect---\n\n", #func); \
                COLORFY(RESET);                                      \
            }                                                        \
            else                                                     \
            {                                                        \
                CORRECT++;                                           \
                COLORFY(GREEN);                                      \
                printf("---%s function is correct---\n\n", #func);   \
                COLORFY(RESET);                                      \
            }                                                        \
        }                                                            \
    }

#define RESULTS                                  \
    {                                            \
        COLORFY(MAGENTA);                        \
        printf("\n\t\t*** RESULTS ***\n\n");     \
        COLORFY(RESET);                          \
        COLORFY(GREEN);                          \
        printf("Correct: %d", CORRECT);          \
        COLORFY(RED);                            \
        printf("\tIncorrect: %d", INCORRECT);    \
        COLORFY(CYAN);                           \
        printf("\tFrom checked: %d\n", CHECKED); \
        COLORFY(RESET);                          \
    }
