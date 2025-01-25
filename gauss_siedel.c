#include <stdio.h>
#include <math.h>

float f1(float b, float c) {
    return (-1+(2*b)-(3*c)) / 5;
}

float f2(float a, float c) {
    return (2+(3*a)-c) / 9;
}

float f3(float a, float b) {
    return ((2*a)-b-3) / 7;
}

int main() {
    int i = 0;
    float a = 0, b = 0, c = 0;
    float a_new, b_new, c_new;
    float ea, eb, ec;
    float tol = 0.001;

    printf("Initial guess:\n");
    printf("a = %0.4f, b = %0.4f, c = %0.4f\n\n", a, b, c);

    printf("Iteration\t  a\t\t  b\t\t  c\t\t  ea\t\t  eb\t\t  ec\n");
    printf("----------------------------------------------------------------------------------------\n");

    do {
        float a_old = a;
        float b_old = b;
        float c_old = c;

        a_new = f1(b, c);
        b_new = f2(a_new, c);
        c_new = f3(a_new, b_new);

        a = a_new;
        b = b_new;
        c = c_new;

        i++;

        ea = fabs((a - a_old) / a);
        eb = fabs((b - b_old) / b);
        ec = fabs((c - c_old) / c);

        printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\n", i, a, b, c, ea, eb, ec);

    } while (ea > tol || eb > tol || ec > tol);

    printf("\n______________Output_________________\n");
    printf("Final solution after %d iterations:\n", i);
    printf("a = %0.4f, b = %0.4f, c = %0.4f\n", a, b, c);

    return 0;
}