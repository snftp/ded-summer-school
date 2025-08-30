#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#ifndef RUNTEST
#include "SolvingAlgorithm.h"
struct Equation_Elements {
    double a, b, c;
    double roots[2];
};
#endif

#ifdef RUNTEST
#include "TestsForEquationProgram.h"
#endif

bool Checking_For_EOF(int symbol_from_buffer) {
    do {
        if (symbol_from_buffer == EOF) { // TODO: What if getchar outputs EOF?
            printf("You terminated program\n");
            return false; // TODO: it's better to avoid exit DONE
        }
    } while ((symbol_from_buffer = getchar()) != '\n');
    return true;
}

int Detecting_Scanf_Failure() {
    int symbol_from_buffer = getchar();
    if (symbol_from_buffer != '\n') {
        if (Checking_For_EOF(symbol_from_buffer)) {
            return 0;
        }
    }
    else {
        return 1;
    }
    return -1;
}

int Number_Reading(int *flag, double *intermediate_result) { // TODO: read_number? Or, i your style, number_reading? DONE
    assert(flag != NULL);
    assert(intermediate_result != NULL);
    scanf("%lf", intermediate_result);
    *flag = Detecting_Scanf_Failure();
    if (*flag == -1) {
        return 0;
    }
    else {
        return 1;
    }
}

bool Input_Checking(double *a, double *b, double *c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    double *coefficients[3] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        double intermediate_result = 0.0;
        int flag = 0;
        do {
            if (!(Number_Reading(&flag, &intermediate_result))) {
                return false; // TODO: prefer true/false from stdbool.h over 1/0
            }
            if (flag != 1) {
                printf("Input error: double number not found. Try again: ");
            }
        } while (flag != 1);
        *coefficients[i] = intermediate_result;
        printf("filled coefficients counter: %d\ncoefficient: %lf\n", i + 1, *coefficients[i]);
    }
    return true;
}

void Solutions_Printing(double *roots) { // TODO: prefer verbs over nouns when naming functions. Print_Solution? DONE
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

#ifndef RUNTEST // NOTE: g++ded -DRUNTEST SolveEquation.c -o SolveEquation.o; -D flag defines a macro at compile time.
    struct Equation_Elements equation_components = { .a = 0.0, .b = 0.0, .c = 0.0, .roots = { NAN, NAN } };
    if (!(Input_Checking(&equation_components.a, &equation_components.b, &equation_components.c))) { // TODO: scanf can fail, check
        return 1;
    }
    assert((!(isinf(equation_components.a))) && (!(isnan(equation_components.a))));
    assert((!(isinf(equation_components.b))) && (!(isnan(equation_components.b))));
    assert((!(isinf(equation_components.c))) && (!(isnan(equation_components.c))));
    printf("%lg %lg %lg\n", equation_components.a, equation_components.b, equation_components.c);
    Equation_Solving(equation_components.a, equation_components.b, equation_components.c, equation_components.roots);
    Solutions_Printing(equation_components.roots);
#endif

#ifdef RUNTEST
    Tests_Calling();
#endif

    return 0;
}
