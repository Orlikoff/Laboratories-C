#include <math.h>
#include "formulas.h"

float getAngularVelocity(float period)
{
    return (2 * PI / period);
}

float getPeriod(float radius, float velocity)
{
    return (2 * PI * radius / velocity);
}

float calculateForce(float m1, float m2, float distance)
{
    return (G * m1 * m2) / powf(distance, 2.0);
}

float calculateDistance(float r1, float r2, float angle1, float angle2)
{
    return powf((powf(r1, 2.0) + powf(r2, 2.0) + 2 * r1 * r2 * cosf(fabs(angle1 - angle2))), 0.5);
}