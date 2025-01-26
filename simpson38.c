#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 + cos(2 * sqrt(x));
}

int main() {
    double a, b, h, integral;

    printf("Enter the value of lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the value of upper limit (b): ");
    scanf("%lf", &b);

    h = (b - a) / 3;

    integral = (3 * h / 8) * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));

    printf("The value of integration is = %lf\n", integral);

    return 0;
}