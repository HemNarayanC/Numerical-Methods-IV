#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define the function f(x)
float f(float x) {
    return x*x - 4*cos(x);
}

int main() {
    float x1, x2, x0;
    float e = 0.01; // Tolerance (correct up to 2 significant figures)

    // Input initial guesses
    printf("Enter the value of x1 and x2:\n");
    scanf("%f %f", &x1, &x2);
    printf("Initial guess: x1 = %.4f, x2 = %.4f\n", x1, x2);

    // Check if initial guesses are valid
    if (f(x1) * f(x2) > 0) {
        printf("Wrong initial guess!!!\n");
        exit(0);
    }

    // Bisection Method
    x0 = (x1 + x2) / 2;
    int iteration = 1;

    // Print table header
    printf("\nIteration\t x1\t\t x2\t\t x0\t\t f(x0)\n");
    printf("------------------------------------------------------------\n");

    while (fabs(f(x0)) > e) {
        printf("%d\t\t %.4f\t %.4f\t %.4f\t %.4f\n", iteration, x1, x2, x0, f(x0));

        if (f(x0) * f(x1) > 0) {
            x1 = x0;
        } else {
            x2 = x0;
        }
        x0 = (x1 + x2) / 2;
        iteration++;
    }

    // Final result
    printf("%d\t\t %.4f\t %.4f\t %.4f\t %.4f\n", iteration, x1, x2, x0, f(x0));
    printf("\nThe root = %.4f\n", x0);
    return 0;
}