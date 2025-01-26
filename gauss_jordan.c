#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, j, k;
    float a[10][10], ratio;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (i = 0; i < n; i++) { 
        if (a[i][i] == 0.0) {
            printf("Mathematical Error! Pivot element is zero.\n");
            exit(0);
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Normalize the diagonal elements to 1
    for (i = 0; i < n; i++) {
        a[i][n] = a[i][n] / a[i][i];
        a[i][i] = 1.0;
    }

    // Display the solution
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, a[i][n]);
    }

    return 0;
} 