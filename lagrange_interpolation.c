#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, j;
    float x[10], y[10], x0, result = 0, term;

    printf("Enter the number of data points:\n");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f%f", &x[i], &y[i]);
    }

    printf("Enter the value of x for interpolation:\n");
    scanf("%f", &x0);

    // Lagrange's Interpolation Formula
    for (i = 0; i < n; i++) {
        term = y[i];
        for (j = 0; j < n; j++) {
            if (j != i) {
                term *= (x0 - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    printf("Interpolated value at x = %0.4f is y = %0.4f\n", x0, result);
    return 0;
}