#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return x * x * x + 2;
}

int main() {
    int x1 = 2, x2 = 8;
    float h, v;

    h = x2 - x1;

    v = (h / 2) * (f(x1) + f(x2));

    printf("The value of integration is = %f\n", v);

    return 0;
}