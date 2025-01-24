#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define the function f(x)
float f(float x) {
    return pow(x,3) + pow(x,2) - 1;
}

// Define the fixed-point function g(x)
float g(float x) {
    return 1 / sqrt(1 + x); // Suitable fixed-point function
}

int main() {
    float x0, x1;
    float e = 0.001; // Tolerance
    int itr = 1;

    // Input initial guess
    printf("Enter initial guess:\n");
    scanf("%f", &x0);

    // Print table header
    printf("\nIteration\t x0\t\t x1\t\t f(x1)\t\t Error\n");
    printf("----------------------------------------------------------------\n");

    // Fixed-Point Iteration Method
    while (fabs(f(x0)) > e) {
        x1 = g(x0); // Compute next approximation
        float error = fabs((x1 - x0)/x1); // Calculate error
        printf("%d\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\n", itr, x0, x1, f(x1), error);
        x0 = x1; // Update x0
        itr++;

        // Safeguard against infinite loops
        if (itr > 100) {
            printf("Method did not converge within 100 iterations.\n");
            exit(1);
        }
    }

    // Output the root
    printf("\n\nFinal root = %.4f\n", x0);
    return 0;
}