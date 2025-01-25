#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x, float y) {
    return 3*pow(x,2)+1;
}

int main() {
    float x, y, x0, y0, xp, h;
    int itr = 0;

    printf("Enter the initial value of x and y:\n");
    scanf("%f%f", &x0, &y0);
    printf("Enter the step size (h):\n");
    scanf("%f", &h);
    printf("Enter the point to find value (i.e xp):\n");
    scanf("%f", &xp);

    x = x0;
    y = y0;

    while (x < xp) {
        printf("Iteration= %d\nx%d = %0.4f\t y%d = %0.4f\n", (itr + 1), itr, x, itr, y);
        y = y + h * f(x, y);
        x += h;
        itr++;
    }

    printf("\n\n The value at y(%0.2f) = %0.4f\n", xp, y);

    return 0;
}

/*
Enter the initial value of x and y:
0
2
Enter the step size (h):
0.25
Enter the point to find value (i.e xp):
2
Iteration= 1
x0 = 0.0000      y0 = 2.0000
Iteration= 2
x1 = 0.2500      y1 = 2.2500
Iteration= 3
x2 = 0.5000      y2 = 2.5469
Iteration= 4
x3 = 0.7500      y3 = 2.9844
Iteration= 5
x4 = 1.0000      y4 = 3.6563
Iteration= 6
x5 = 1.2500      y5 = 4.6563
Iteration= 7
x6 = 1.5000      y6 = 6.0781
Iteration= 8
x7 = 1.7500      y7 = 8.0156


 The value at y(2.00) = 10.5625
*/