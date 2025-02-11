#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int n, i;
    float a = 0, b = 0, x[10], y[10];
    float sx = 0, sxy = 0, sx2 = 0, sy = 0;

    printf("For regression line\n---------- y = ax + b ----------\n");
    printf("Enter the number of points:\n");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f%f", &x[i], &y[i]);
    }

    for (i = 0; i < n; i++) {
        sx = sx + x[i];
        sy = sy + y[i];
        sxy = sxy + (x[i] * y[i]);
        sx2 = sx2 + (x[i] * x[i]);
    }

    b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx));
    a = (sy / n) - (b * sx / n);

    printf("Fitted line is: y = %0.4f + %0.4fx\n", a, b);
    return 0;
}