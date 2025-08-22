#include <stdio.h>
#include <float.h>
#include <math.h>

// TODO: discriminant, cntr parameter is unnecessary DONE
void Solutions(double a, double b, double c) { // NOTE: is it a good idea to have separate p0 for 1 root case? NO IF REPLACING ROOTS WITH ARRAY // TODO: maybe a better name for p0, p1, etc ROOTS? Possibly use an array, double roots[2] YES?
    // TODO: maybe this at the start, *p0 = *p1 = *p2 = NAN;
    double roots[2] = {NAN, NAN};
    double discriminant = 0.0, sqrt_discriminant = 0.0;
    if (fabs(a) <= DBL_EPSILON) { // TODO: beware of the indentation DONE
            if (fabs(b) > DBL_EPSILON) {
                roots[0] = -1 * c / b;
                // cntr = 1;
                // *p0 = -1 * c / b;
                // *p1 = 0.0 / 0.0; // TODO: it's better to write NAN explicitly in such cases (= NAN)
                // *p2 = 0.0 / 0.0;
            }
            else {
                if (fabs(c) <= DBL_EPSILON) {
                    roots[0] = -1.0; // INFINITY NUMBER OF ROOTS
                    roots[1] = -1.0;
                    // cntr = -1; // TODO: make a const that will explicitly say what this means, e.g. const int INFINITE_ROOTS = -1;
                }
                // else {
                //     значения в ROOTS останутся NAN поэтому не требуется прописывать ELSE
                //     cntr = 0;
                // }

                // TODO: it's better to set roots here to NAN explicitly
            }
    }
    else {
        discriminant = b * b - 4 * a * c;
        // if (discriminant < 0) { значения в ROOTS останутся NAN поэтому не требуется прописывать этот случай
        //     cntr = 0;
        // }
        if (discriminant > 0) {
            sqrt_discriminant = sqrt(b * b - 4 * a * c);
            roots[0] = (-1 * b + sqrt_discriminant) / (2 * a); // TODO: extract sqrt(discriminant), also you could make a variable sqrt_discriminant DONE
            roots[1] = (-1 * b - sqrt_discriminant) / (2 * a);
        }
        else {
            if (fabs(discriminant) <= DBL_EPSILON) {
                roots[0] = (-1 * b) / (2 * a);
            // cntr = 1;
            // *p0 = (-1 * b) / (2 * a);
            // *p1 = 0.0 / 0.0;
            // *p2 = 0.0 / 0.0;
            }
        }
    }
    // return roots;
    if ((fabs(roots[0]) - (-1)) <= DBL_EPSILON) {
        printf("INFINITE NUMBER OF ROOTS\n");
    }
    else if (((fabs(roots[0]) - NAN) <= DBL_EPSILON) && ((fabs(roots[1]) - NAN) <= DBL_EPSILON)) {
        printf("NO ROOTS\n"); // TODO: add a newline? puts? DONE
    }
    else {
        // double arr[3] = {x0, x1, x2}; // NOTE: maybe you could store roots in an array to begin with? DONE
        for (int i = 0; i < 2; i++) {
            if (!isnan(roots[i])) {
                printf("ROOT(S): %lf\n", roots[i]);
            }
        }
    }
}


// void Solutions_Presentation(double roots[2]) {
//     if (roots[0] == -1) {
//         printf("INFINITE NUMBER OF ROOTS\n");
//     }
//     else if (roots[0] == NAN) && (roots[1] == NAN) {
//         printf("NO ROOTS\n"); // TODO: add a newline? puts? DONE
//     }
//     else {
//         // double arr[3] = {x0, x1, x2}; // NOTE: maybe you could store roots in an array to begin with? DONE
//         for (int i = 0; i < 2; i++) {
//             if (!isnan(roots[i])) {
//                 printf("ROOT(S): %lf/n", roots[i]);
//             }
//         }
//     }
// }

// TODO: it's better to use full names when possible, prefer count over cntr
int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c); // TODO: scanf can fail, check
    // TODO: maybe use an array? double roots[3] = { NAN, NAN, NAN }; DONE WITH 2 ROOTS
    // double roots[2] = Solutions(a, b, c);
    // Solutions_Presentation(roots);
    Solutions(a, b, c);
    return 0;
}
