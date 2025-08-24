#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


// TODO: check 5 5 5 test
void Checking_For_EOF(int flag) {
    if (flag == EOF) {
        printf("You terminated program\n");
        exit(1);
    }
}


int Detecting_Scanf_Failure() {
    int symbol_from_buffer = getchar();
    if (symbol_from_buffer != '\n') {
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
        printf("filled coefficients counter: %d\ncoefficient: %lf\n", count, *coefficients[i]);
    }
}


bool Are_Same_Numbers(double number_1, double number_2) {
    return fabs(number_1 - number_2) <= DBL_EPSILON;
}


void Equation_Solving(double a, double b, double c, double *roots) {
    double discriminant = 0.0, sqrt_discriminant = 0.0;
    // NOTE: *(ptr + i) === ptr[i] -> roots[0] = 1.0
    // NOTE: *(i + prr) === i[ptr]
    if (Are_Same_Numbers(a, 0.0)) {
        if (!(Are_Same_Numbers(b, 0.0))) {
            roots[0] = -1 * c / b;
        }
        else {
            if (Are_Same_Numbers(c, 0.0)) {
                roots[0] = INFINITY;
                roots[1] = INFINITY;
                // TODO: make a const that will explicitly say what this means, e.g. const int INFINITE_ROOTS = -1;
            }
            // NOTE: не требуется прописывать ELSE для с != 0 и b == 0 потому что значения в ROOTS останутся NAN (нет корней)
        }
    }
    else {
        discriminant = b * b - 4 * a * c;
        // NOTE: случай discriminant < 0 не требуется прописывать потому что значения в ROOTS останутся NAN
        if (discriminant > 0) {
            sqrt_discriminant = sqrt(b * b - 4 * a * c);
            roots[0] = (-1 * b + sqrt_discriminant) / (2 * a);
            roots[1] = (-1 * b - sqrt_discriminant) / (2 * a);
        }
        else {
            if (Are_Same_Numbers(discriminant, 0.0)) {
                roots[0] = (-1 * b) / (2 * a);
            }
        }
    }
}


void Solutions_Printing(double *roots) { // TODO: prefer verbs over nouns when naming functions. Print_Solution? DONE
    if (isinf(roots[0]) && isinf(roots[1])) { // TODO: read about isnan, isinf? DONE
        printf("INFINITE NUMBER OF ROOTS\n");
    }
    else if (isnan(roots[0]) && isnan(roots[1])) { // TODO: this is unreachable DONE
        printf("NO ROOTS\n");
    }
    else {
        for (int i = 0; i < 2; i++) {
            if (!isnan(roots[i])) {
                printf("ROOT(S): %lf\n", roots[i]);
            }
        }
    }
}


// TODO: it's better to use full names when possible, prefer count over cntr
int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    double roots[2] = { NAN, NAN };
    Input_Checking(&a, &b, &c); // TODO: scanf can fail, check
    printf("%lf %lf %lf\n", a, b, c);
    Equation_Solving(a, b, c, roots);
    Solutions_Printing(roots);
    return 0;
}
