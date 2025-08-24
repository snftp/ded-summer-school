#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


void Checking_For_EOF(int flag) {
    if (flag == EOF) {
        printf("You terminated program\n");
        exit(1);
    }
}


void Input_Checking(double *a, double *b, double *c) {
    double *coefficients[3] = {a, b, c};
    int count = 0; // NOTE: checking whether scanf is working properly or not
    for (int i = 0; i < 3; i++) {
        double intermediate_result = 0.0;
        int flag = scanf("%lf", &intermediate_result);
        Checking_For_EOF(flag);
        while (flag != 1) {
            while (getchar() != '\n');
            printf("Input error: double number not found. Try again: ");
            flag = scanf("%lf", &intermediate_result);
            Checking_For_EOF(flag);
            printf("flag: %d\n", flag);
        }
        while (getchar() != '\n');
        count++;
        printf("coeffs filled counter: %d\n", count);
        *coefficients[i] = intermediate_result;
    }
}


int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    Input_Checking(&a, &b, &c); // TODO: scanf can fail, check
    printf("%lf %lf %lf\n", a, b, c);
}
