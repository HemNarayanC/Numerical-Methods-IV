#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return exp(-pow(x, 2)); // f(x) = e^(x^2) using pow function
}

int main() {
    float x1, x2;
    float h, v;

    printf("Enter the value of lower limit: ");
    scanf("%f", &x1);
    printf("Enter the value of upper limit: ");
    scanf("%f", &x2);

    h = x2 - x1;

    v = (h / 2) * (f(x1) + f(x2));

    printf("The value of integration is = %f\n", v);

    return 0;
}