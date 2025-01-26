#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x) {
    return x*x*x - 2*x - 5;
}

int main() {
    float x1, x2, x0, prev_x0;
    int itr = 1;

    printf("Enter the value of x1 and x2:\n");
    scanf("%f%f", &x1, &x2);

    if (f(x1) * f(x2) > 0) {
        printf("Invalid initial guesses! f(x1) and f(x2) must have opposite signs.\n");
        exit(0);
    }

    printf("\nIteration\t x1\t\t x2\t\t x0\t\t f(x1)\t\t f(x2)\t\t f(x0)\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    do {
        prev_x0 = x0; // Store the previous value of x0
        x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        printf("%d\t\t %.4f\t\t %.4f\t\t %.4f\t\t %.4f\t %.4f\t %.4f\n", 
               itr, x1, x2, x0, f(x1), f(x2), f(x0));

        if (f(x1) * f(x0) > 0) {
            x1 = x0;
        } else {
            x2 = x0;
        }

        itr++;
    } while (fabs(x0 - prev_x0) > 0.0005);

    printf("\nThe root = %.4f\n", x0);
    return 0;
}