#include "foo.h"
#include <math.h>

float SquareC(int r, float PI)
{
    float s = 0;
    s = PI * r * r;
    return s;
}

float SquareT(int a, int b, int c)
{
    float p, s, t;
    p = (a + b + c) / 2.;
    t = p * (p - a) * (p - b) * (p - c);
    s = sqrt(t);
    return s;
}
