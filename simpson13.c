#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return sin(x);
}

int main() {
    float a, b, h, integral;
    printf("Enter the value of lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the value of upper limit (b): ");
    scanf("%f", &b);
    h = (b - a) / 2;

    integral = (h / 3) * (f(a) + 4 * f((a + b) / 2) + f(b));

    printf("The value of integration is = %f\n", integral);

    return 0;
}