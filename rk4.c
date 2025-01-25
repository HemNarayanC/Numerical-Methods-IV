#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x, float y) {
    return 2 * x + y;
}

int main() {
    float x, y, x0, y0, h, xp, m1, m2, m3, m4;
    int itr = 0;

    printf("Enter initial values of x0 and y0:\n");
    scanf("%f%f", &x0, &y0);
    printf("Enter the value at which functional value is required (i.e xp):\n");
    scanf("%f", &xp);
    printf("Enter the value of step size (h):\n");
    scanf("%f", &h);

    x = x0;
    y = y0;

    while (x < xp) {
        printf("Iteration=%d\n x%d=%0.2f\ty%d=%0.2f\t", (itr + 1), itr, x, itr, y);
        m1 = f(x, y);
        m2 = f(x + h / 2, y + (h / 2) * m1);
        m3 = f(x + h / 2, y + (h / 2) * m2);
        m4 = f(x + h, y + h * m3);
        y = y + (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4);
        x += h;
        itr++;
        printf("m1=%0.2f\tm2=%0.2f\tm3=%0.2f\tm4=%0.2f\n", m1, m2, m3, m4);
    }

    printf("\n\n The value at y(%f) = %0.2f\n", xp, y);

    return 0;
}