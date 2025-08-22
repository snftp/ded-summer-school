#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void task1_2(int *digit) {
    scanf("%d", digit);
}


int main() {
                // task 2_1
    // float a = 3.4 * pow(10.0, -1.0), b = 10.0;
    // printf("%lf", a + b);

                // task 3_1
    // double a = rand() / 0.0, b = -1 * rand() / 0.0, c = 0.0 / 0.0;
    // printf("%lf %lf %lf", a, b, c);

                // task 1_2
    // int a = 0;
    // task1_2(&a);
    // printf("%d", a);

                // task 2_2
    // int x = 10, y = 5;
    // int *pointer = &x;
    // printf("pointer:%d\n", *pointer);
    // *pointer = y;
    // printf("x:%d pointer:%d\n", x, *pointer);
    // pointer = &x;
    // printf("x:%d pointer:%d\n", x, *pointer);

                //task 5_2
    // int x = 9;
    // printf("%p\n", &x);
    // printf("%p\n", &x + 1);
    // float y = 9;
    // printf("%p\n", &y);
    // printf("%p\n", &y + 1);
    // double z = 9;
    // printf("%p\n", &z);
    // printf("%p\n", &z + 1);
    // return 0;

                //task 6_2
    int a = 5, b = 9;
    int *x = &a;
    int *y = &b;
    printf("%p\n", x + y);
    printf("%p\n", x * y);
    printf("%p\n", x / y);
    printf("%p\n", x - y);
}

