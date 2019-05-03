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
    int r, i, j, flag = 0, r1, r2, x, y, x1, y1, x2,
                 y2; // x, y, z, x1=0, y1=0, r1=0, x2, y2, r2;
    float p, s;
    circle mass[3];
    printf("Enter 3 circles: \n");
    for (i = 0; i < 3; i++) {
        printf("\nEnter x,y,radius of circle: ");
        scanf("%d %d %d", &x, &y, &r);
        p = PerimetrC(r, PI);
        s = SquareC(r, PI);
        mass[i].x = x;
        mass[i].y = y;
        mass[i].r = r;
        x1 = mass[i].x;
        y1 = mass[i].y;
        r1 = mass[i].r;
        printf("Perimetr: %f Square: %f\n", p, s);
    }

    for (i = 0; i < 2; i++) {
        x1 = mass[i].x;
        y1 = mass[i].y;
        r1 = mass[i].r;
        for (j = 1; j < 3; j++) {
            x2 = mass[j].x;
            y2 = mass[j].y;
            r2 = mass[j].r;
            if (j == i) {
                continue;
            }
            flag = peres(x1, y1, r1, x2, y2, r2);
            if (flag)
                printf("\nCircle %d crosses circle %d\n", j + 1, i + 1);
        }
    }
    return 0;
}
