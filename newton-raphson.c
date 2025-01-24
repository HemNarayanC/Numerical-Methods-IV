#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define the function f(x)
float f(float x) {
    return cos(x) - x * exp(x);
}

// Define the derivative of f(x)
float df(float x) {
    return -sin(x) - exp(x) - x * exp(x);
}

int main() {
    float x0, x1;
    float e = 0.0001; // Tolerance
    int itr = 1;

    printf("Enter the value of x0:\n");
    scanf("%f", &x0);

    printf("\nIteration\t x\t\t f(x)\t\t f'(x)\t\t x1 = x - (f(x)/f'(x))\n");
    printf("----------------------------------------------------------------------------\n");

    do {
        x1 = x0 - f(x0) / df(x0);
        printf("%d\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\n", itr, x0, f(x0), df(x0), x1);
        x0 = x1; // Update x0 for the next iteration
        itr++;
    } while (fabs(f(x1)) > e);

    printf("\nThe root = %.4f\n", x0);
    return 0;
}