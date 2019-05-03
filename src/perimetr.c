#include "foo.h"
#include <math.h>

float PerimetrC(int r, float PI)
{
    float per = 0;
    per = 2 * PI * r;
    return per;
}

int PerimetrT(int a, int b, int c)
{
    int per = 0;
    per = a + b + c;
    return per;
}
