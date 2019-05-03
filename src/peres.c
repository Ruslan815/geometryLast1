#include "foo.h"
#include <math.h>

int peres(int x1, int y1, int r1, int x2, int y2, int r2)
{
    int r, y, z, flag;
    float x;
    flag = 0;
    r = r2;
    x = x2 - r;
    z = pow(r2, 2) - pow(x - x2, 2);
    z = sqrt(z);
    y = z + y2;
    while (x < (x2 + r)) {
        if ((pow(x - x1, 2)) + (pow(y - y1, 2)) <= pow(r1, 2)) {
            flag = 1;
            break;
        }
        x += 0.1;
        z = pow(r2, 2) - pow(x - x2, 2);
        z = sqrt(z);
        y = z + y2;
    }

    x = x2 - r;
    z = pow(r2, 2) - pow(x - x2, 2);
    z = sqrt(z);
    z *= -1;
    y = z + y2;
    while (x < (x2 + r)) {
        if ((pow(x - x1, 2)) + (pow(y - y1, 2)) <= pow(r1, 2)) {
            flag = 1;
            break;
        }
        x += 0.1;
        z = pow(r2, 2) - pow(x - x2, 2);
        z = sqrt(z);
        z *= -1;
        y = z + y2;
    }
    return flag;
}
