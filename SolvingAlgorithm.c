#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

bool Are_Same_Numbers(double number_1, double number_2) {
    return fabs(number_1 - number_2) <= DBL_EPSILON;
}

void Equation_Solving(double a, double b, double c, double *roots) {
    // TODO: assert(a is not NAN)?
    assert((roots != NULL) && (roots[0] == NAN) && (roots[1] == NAN)); // TODO: split assert into multiple asserts
    double discriminant = 0.0, sqrt_discriminant = 0.0;
    // NOTE: *(ptr + i) === ptr[i] -> roots[0] = 1.0
    // NOTE: *(i + prr) === i[ptr]
    if (Are_Same_Numbers(a, 0.0)) {
        if (!(Are_Same_Numbers(b, 0.0))) {
            roots[0] = -1 * c / b;
        }
        else {
            if (Are_Same_Numbers(c, 0.0)) {
                roots[0] = INFINITY; // TODO: INFINITY is more fitting for case where there are no roots but you could say that there is an INFINITE root, e.g. 0*x^2 + 0*x - 5 = 0
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
