#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute x1
float fx1(float x2, float x3) {
    return (-1 + 2 * x2 - 3 * x3) / 5;
}

// Function to compute x2
float fx2(float x1, float x3) {
    return (2 + 3 * x1 - 1 * x3) / 9;
}

// Function to compute x3
float fx3(float x1, float x2) {
    return ((2*x1) - x2 -3) / 7;
}

int main() {
    int itr = 0;
    float x = 0, y = 0, z = 0, x1, y1, z1, e1, e2, e3, tempx, tempy, tempz;
    float e = 0.001; // Tolerance for convergence

    // Input initial guess
    printf("Enter initial guess: \n");
    scanf("%f%f%f", &x1, &y1, &z1);

    // Print table header
    printf("itr\tx1   \tx2   \tx3   \te1   \te2   \te3\n");

    // Jacobi iteration
    do {
        tempx = x;
        tempy = y;
        tempz = z;

        // Update values of x, y, z
        x = fx1(y1, z1);
        y = fx2(x1, z1);
        z = fx3(x1, y1);

        itr++;

        // Update old values for next iteration
        x1 = x;
        y1 = y;
        z1 = z;

        // Compute relative errors
        e1 = fabs((x1 - tempx) / x1);
        e2 = fabs((y1 - tempy) / y1);
        e3 = fabs((z1 - tempz) / z1);

        // Print current iteration results
        printf("%d\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n", itr, x1, y1, z1, e1, e2, e3);

    } while (e1 > e && e2 > e && e3 > e); // Check for convergence

    // Output final results
    printf("\n _______________ Output ______________\n");
    printf("x1 = %f\t x2 = %f\t x3 = %f\n", x, y, z);
    printf("Iterations = %d\n", itr);

    return 0;
}