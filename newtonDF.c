#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, j;
    float x[10], y[10], h, x0, u, result = 0, term = 1;

    printf("Enter the number of data points:\n");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f%f", &x[i], &y[i]);
    }

    printf("Enter the value of x for interpolation:\n");
    scanf("%f", &x0);

    h = x[1] - x[0]; // Calculate spacing
    u = (x0 - x[0]) / h; // Calculate u

    // Calculate forward differences
    float diff[n][n];
    for (i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    // Apply Newton Forward Difference Formula
    result = diff[0][0];
    for (j = 1; j < n; j++) {
        term *= (u - (j - 1)) / j; 
        result += term * diff[0][j];
    }

    printf("Interpolated value at x = %0.4f is y = %0.4f\n", x0, result);
    return 0;
}