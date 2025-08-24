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


int Detecting_Scanf_Failure() {
    int symbol = getchar();
    if (symbol != '\n') {
        while (getchar() != '\n');
        return 0;
    }
    else {
        return 1;
    }
}


void Input_Checking(double *a, double *b, double *c) {
    double *coefficients[3] = {a, b, c};
    int count = 0;
    for (int i = 0; i < 3; i++) {
        double intermediate_result = 0.0;
        int flag = scanf("%lf", &intermediate_result);
        Checking_For_EOF(flag);
        flag = Detecting_Scanf_Failure();
        while (flag != 1) {
            printf("Input error: double number not found. Try again: ");
            flag = scanf("%lf", &intermediate_result);
            Checking_For_EOF(flag);
            flag = Detecting_Scanf_Failure();
        }
        count++;
        *coefficients[i] = intermediate_result;
        printf("coefficients filled counter: %d\nroot: ", count);
    }
}


int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    Input_Checking(&a, &b, &c); // TODO: scanf can fail, check
    printf("%lf %lf %lf\n", a, b, c);
}
