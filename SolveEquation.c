#include <stdio.h>
#include <float.h>
#include <math.h>

// TODO: discriminant, cntr parameter is unnecessary
int Counting_Solutions(double a, double b, double c, int cntr, double discriminant,
                        double *p0, double *p1, double *p2) { // NOTE: is it a good idea to have separate p0 for 1 root case? // TODO: maybe a better name for p0, p1, etc? Possibly use an array, double roots[2]?
    // TODO: maybe this at the start, *p0 = *p1 = *p2 = NAN;
    if (fabs(a) <= DBL_EPSILON) { // TODO: beware of the indentation
            if (fabs(b) > DBL_EPSILON) {
                cntr = 1;
                *p0 = -1 * c / b;
                *p1 = 0.0 / 0.0; // TODO: it's better to write NAN explicitly in such cases (= NAN)
                *p2 = 0.0 / 0.0;
            }
            else {
                if (fabs(c) <= DBL_EPSILON) {
                    cntr = -1; // TODO: make a const that will explicitly say what this means, e.g. const int INFINITE_ROOTS = -1;
                }
                else {
                    cntr = 0;
                }

                // TODO: it's better to set roots here to NAN explicitly
            }
        }
    else {
        discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cntr = 0; // TODO:
        }
        else if (discriminant > 0) {
            cntr = 2;
            *p0 = 0.0 / 0.0;
            *p1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a); // TODO: extract sqrt(discriminant), also you could make a variable sqrt_discriminant
            *p2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        }
        else {
            cntr = 1;
            *p0 = (-1 * b) / (2 * a);
            *p1 = 0.0 / 0.0;
            *p2 = 0.0 / 0.0;
        }
    }
    return cntr;
}


void Solutions(int cntr, double x0, double x1, double x2) {
    if (cntr == 0) {
        printf("NO ROOTS"); // TODO: add a newline? puts?
    }
    else if (cntr == -1) {
        printf("INFINITE NUMBER OF ROOTS");
    }
    else {
        double arr[3] = {x0, x1, x2}; // NOTE: maybe you could store roots in an array to begin with?
        for (int i = 0; i < 3; i++) {
            if (!isnan(arr[i])) {
                printf("ROOT(S): %lf", arr[i]);
            }
        }
    }
}

// TODO: it's better to use full names when possible, prefer count over cntr
int main() {
    double a = 0.0, b = 0.0, c = 0.0, discriminant = 0.0, x0 = 0.0, x1 = 0.0, x2 = 0.0;
    // TODO: maybe use an array? double roots[3] = { NAN, NAN, NAN };
    int cntr_of_solutions = 0;
    scanf("%lf %lf %lf", &a, &b, &c); // TODO: scanf can fail, check
    cntr_of_solutions = Counting_Solutions(a, b, c, cntr_of_solutions, discriminant, &x0, &x1, &x2);
    Solutions(cntr_of_solutions, x0, x1, x2);
    return 0;
}
