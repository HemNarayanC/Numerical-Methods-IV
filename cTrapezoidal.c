#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return sqrt(1+pow(x,2));
}

int main() {
    float x0, xn, k, h, term, v;

    printf("Enter the value of lower limit: ");
    scanf("%f", &x0);
    printf("Enter the value of upper limit: ");
    scanf("%f", &xn);
    printf("Enter the value of k (number of subintervals): ");
    scanf("%f", &k);

    h = (xn - x0) / k;

    term = f(x0) + f(xn);

    for (int i = 1; i < k; i++) {
            term += 2 * f(x0 + i * h);
    }

    v = (h / 2) * term;

    printf("The value of integration is = %f\n", v);

    return 0;
}