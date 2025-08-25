#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "SolvingAlgorithm.h"

int Flag_Fixing(int *flag, double *intermediate_result) { // TODO: read_number? Or, i your style, number_reading?
    assert(flag != NULL);
    assert(intermediate_result != NULL);
    *flag = scanf("%lf", intermediate_result); // TODO: do not assign it here, you never read this value
    *flag = Detecting_Scanf_Failure();
    if (*flag == -1) {
            return 0; // TODO: indentation
    }
    else {
        return 1;
    }
}

int Detecting_Scanf_Failure() {
    int symbol_from_buffer = getchar();
    if (symbol_from_buffer == EOF) { // TODO: What if getchar outputs EOF?
        printf("You terminated program\n");
        return -1; // TODO: it's better to avoid exit
    }
    else if (symbol_from_buffer != '\n') {
        while (getchar() != '\n'); // TODO: you should check for EOF here
        return 0;
    }
    else {
        return 1;
    }
}

int Input_Checking(double *a, double *b, double *c) { // TODO: check 5 5 5 test
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    double *coefficients[3] = {a, b, c};
    int count = 0;
    for (int i = 0; i < 3; i++) {
        double intermediate_result = 0.0;
        int flag = 0;
        do {
            if (!(Flag_Fixing(&flag, &intermediate_result))) {
                return 0; // TODO: prefer true/false from stdbool.h over 1/0
            }
            if (flag != 1) {
                printf("Input error: double number not found. Try again: ");
            }
        } while (flag != 1);
        count++; // is count == i + 1
        *coefficients[i] = intermediate_result;
        printf("filled coefficients counter: %d\ncoefficient: %lf\n", count, *coefficients[i]);
    }
    return 1;
}

void Solutions_Printing(double *roots) { // TODO: prefer verbs over nouns when naming functions. Print_Solution? DONE
    // TODO: figure out what is this: assert(roots != NULL);
    assert(roots != NULL);
    if (isinf(roots[0]) && isinf(roots[1])) { // NOTE: it's a little bit weird that infinite number of roots is marked as an INFINITE root
        printf("INFINITE NUMBER OF ROOTS\n");
    }
    else if (isnan(roots[0]) && isnan(roots[1])) {
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

int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    double roots[2] = { NAN, NAN };
    // TODO: scanf can fail, check
    if (!(Input_Checking(&a, &b, &c))) {
        return 1;
    }
    assert((a != INFINITY) && (a != NAN)); // TODO: a != NAN doesn't work, use isnan, isinf and/or isfinite?
    assert((b != INFINITY) && (b != NAN));
    assert((c != INFINITY) && (c != NAN));
    printf("%lg %lg %lg\n", a, b, c);
    Equation_Solving(a, b, c, roots);
    Solutions_Printing(roots);
    return 0;
    // -c -o
}
