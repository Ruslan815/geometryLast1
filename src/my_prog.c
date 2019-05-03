#include "foo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
const float PI = 3.1415;

typedef struct figure {
    int x;
    int y;
    int r;
} circle;

int main()
{
    int r, i, j, flag = 0;
    float p, s, x, y, z;
    circle mass[3];
    printf("Enter 3 circles: \n");
    for (i = 0; i < 3; i++) {
        printf("\nEnter x,y,radius of circle: ");
        scanf("%f %f %d", &x, &y, &r);
        p = PerimetrC(r, PI);
        s = SquareC(r, PI);
        mass[i].x = x;
        mass[i].y = y;
        mass[i].r = r;
        printf("Perimetr: %f Square: %f\n", p, s);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j == i) {
                continue;
            }
            flag = 0;
            r = mass[j].r;
            x = mass[j].x - r;
            z = pow(mass[j].r, 2) - pow(x - mass[j].x, 2);
            z = sqrt(z);
            y = z + mass[j].y;
            while (x < (mass[j].x + r)) {
                if ((pow(x - mass[i].x, 2)) + (pow(y - mass[i].y, 2))
                    <= pow(mass[i].r, 2)) {
                    flag = 1;
                    break;
                }
                x += 0.1;
                z = pow(mass[j].r, 2) - pow(x - mass[j].x, 2);
                z = sqrt(z);
                y = z + mass[j].y;
            }

            x = mass[j].x - r;
            z = pow(mass[j].r, 2) - pow(x - mass[j].x, 2);
            z = sqrt(z);
            z *= -1;
            y = z + mass[j].y;
            while (x < (mass[j].x + r)) {
                if ((pow(x - mass[i].x, 2)) + (pow(y - mass[i].y, 2))
                    <= pow(mass[i].r, 2)) {
                    flag = 1;
                    break;
                }
                x += 0.1;
                z = pow(mass[j].r, 2) - pow(x - mass[j].x, 2);
                z = sqrt(z);
                z *= -1;
                y = z + mass[j].y;
            }
            if (flag) {
                printf("Circle %d crosses circle %d\n", j, i);
            }
        }
    }

    return 0;
}
