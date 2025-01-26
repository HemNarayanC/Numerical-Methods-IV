#include <stdio.h>

float f(float x, float y) {
    return 1 + x * y;
}

float picard(float x0, float y0, float x, int n) {
    float y = y0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            y = y0 + (x - x0);
        } else if (i == 2) {
            y = y0 + (x - x0) + (x * x / 2) * y0;
        } else if (i == 3) {
            y = y0 + (x - x0) + (x * x / 2) * y0 + (x * x * x / 6) * (1 + x0 * y0);
        }
        printf("y%d(%.1f) = %.6f\n", i, x, y);
    }
    return y;
}

int main() {
    float x0 = 0, y0 = 1, x = 0.2;
    int n = 3;
    printf("Approximations using Picard's Method:\n");
    float result = picard(x0, y0, x, n);
    printf("The approximate value of y at x = 0.2 (up to third order) is = %.6f\n", result);
    return 0;
}
