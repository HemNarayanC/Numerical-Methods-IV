#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define the function f(x)
float f(float x) {
    return x*x*x - x - 1;
}

int main() {
    float x0, x1, x2;
    float e = -0.001, Err = 1; // Tolerance and error
    int itr = 1;

    // Input initial guesses
    printf("Enter the value of x0 and x1:\n");
    scanf("%f%f", &x0, &x1);

    // Print table header
    printf("\nIteration\t x0\t\t x1\t\t x2\t\t f(x0)\t\t f(x1)\t\t f(x2)\t\t Error\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    // Secant Method
    while (fabs(Err) > e) {
        x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0)); // Secant formula
        Err = (x2 - x1) / x2; // Relative error
        printf("%d\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\n", 
               itr, x0, x1, x2, f(x0), f(x1), f(x2), Err);
        x0 = x1; // Update x0
        x1 = x2; // Update x1
        itr++;
    }

    // Output the root
    printf("\nThe root = %.4f\n", x2);
    return 0;
} 