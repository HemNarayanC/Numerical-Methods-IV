#include <stdio.h>

int main() {
    float x0 = 1, y0 = 1;
    float x = 2;
    float h = x - x0;
    float y, y1, y2, y3;


    y1 = 3 * x0 * x0; 
    y2 = 6 * x0;      
    y3 = 6;           

    y = y0 + y1 * h + (y2 / 2) * h * h + (y3 / 6) * h * h * h;

    printf("The approximate value of y at x = 2 is = %f\n", y);

    return 0;
}