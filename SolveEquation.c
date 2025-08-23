#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


bool Are_Same_Digits(double number_1, double number_2) {
    return fabs(number_1 - number_2) <= DBL_EPSILON;
}


void Solutions(double a, double b, double c, double *roots) {
    double discriminant = 0.0, sqrt_discriminant = 0.0;
    // NOTE: *(ptr + i) === ptr[i] -> roots[0] = 1.0
    // NOTE: *(i + prr) === i[ptr]
    // TODO: beware of the indentation DONE
    if (Are_Same_Digits(a, 0.0)) {
            if (!(Are_Same_Digits(b, 0.0))) {
                roots[0] = -1 * c / b;
            }
            else {
                if (Are_Same_Digits(c, 0.0)) {
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
            roots[0] = (-1 * b + sqrt_discriminant) / (2 * a); // TODO: extract sqrt(discriminant), also you could make a variable sqrt_discriminant DONE
            roots[1] = (-1 * b - sqrt_discriminant) / (2 * a);
        }
        else {
            if (Are_Same_Digits(discriminant, 0.0)) {
                roots[0] = (-1 * b) / (2 * a);
            }
        }
    }
}


void Solutions_Presentation(double *roots) {
    if (Are_Same_Digits(roots[0], INFINITY)) {
        printf("INFINITE NUMBER OF ROOTS\n");
    }
    else if (Are_Same_Digits(roots[0], NAN) && Are_Same_Digits(roots[1], NAN)) {
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
    scanf("%lf %lf %lf", &a, &b, &c); // TODO: scanf can fail, check
    Solutions(a, b, c, roots);
    Solutions_Presentation(roots);
    return 0;
}
