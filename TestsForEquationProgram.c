#include <stdio.h>
#include <math.h>
#include <float.h>
#include "SolvingAlgorithm.h"

struct Equation_Elements {
    double a, b, c;
    double expected_roots[2];
};

int Are_Numbers_Special_Values(double roots[2]) {
    if (isnan(roots[0]) && isnan(roots[1])) {
        return 1; // two nans expected
    }
    else if (isinf(roots[0]) && isinf(roots[1])) {
        return 2; // two infs expected
    }
    else if (isnan(roots[0]) ^ isnan(roots[1])) {
        return 3; // one nan other not nan expected
    }
    else {
        return 4; // no nans neither infs expected
    }
}

int Test_Running(Equation_Elements data) {
    double obtained_roots[2] = { NAN, NAN };
    Equation_Solving(data.a, data.b, data.c, obtained_roots);
    if (Are_Numbers_Special_Values(data.expected_roots) == 1) {
        if (!(Are_Numbers_Special_Values(obtained_roots) == 1)) {
            printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf\n\n", data.a, data.b, data.c, data.expected_roots[0], data.expected_roots[1], obtained_roots[0], obtained_roots[1]);
            return 0;
        }
    }
    else if (Are_Numbers_Special_Values(data.expected_roots) == 2) {
        if (!(Are_Numbers_Special_Values(obtained_roots) == 2)) {
            printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf\n\n", data.a, data.b, data.c, data.expected_roots[0], data.expected_roots[1], obtained_roots[0], obtained_roots[1]);
            return 0;
        }
    }
    else if (Are_Numbers_Special_Values(data.expected_roots) == 3) {
        if (!(Are_Numbers_Special_Values(obtained_roots) == 3)) {
            printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf\n\n", data.a, data.b, data.c, data.expected_roots[0], data.expected_roots[1], obtained_roots[0], obtained_roots[1]);
            return 0;
        }
    }
    else {
        if (Are_Numbers_Special_Values(obtained_roots) == 4 && (!((Are_Same_Numbers(obtained_roots[0], data.expected_roots[0]) || Are_Same_Numbers(obtained_roots[0], data.expected_roots[1])) && (Are_Same_Numbers(obtained_roots[1], data.expected_roots[0]) || Are_Same_Numbers(obtained_roots[1], data.expected_roots[1]))))) {
            printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf\n\n", data.a, data.b, data.c, data.expected_roots[0], data.expected_roots[1], obtained_roots[0], obtained_roots[1]);
            return 0;
        }
    }
    return 1;
}

void Tests_Calls() {
    int successful_runs_count = 0;
    struct Equation_Elements data[] = {
        {.a = 1.0, .b = -3.0, .c = 2.0, .expected_roots = {2.0, 1.0}},
        {.a = 1.0, .b = -2.0, .c = 1.0, .expected_roots = {1.0, NAN}},
        {.a = 1.0, .b = 0.0, .c = 1.0, .expected_roots = {NAN, NAN}},
        {.a = 2.0, .b = 5.0, .c = -3.0, .expected_roots = {0.5, -3.0}},
        {.a = 1.0, .b = 4.0, .c = 4.0, .expected_roots = {-2.0, NAN}},
        {.a = 0.0, .b = 0.0, .c = 0.0, .expected_roots = {INFINITY, INFINITY}}
    };
    const int size = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < size; i++) {
        successful_runs_count += Test_Running(data[i]);
    }
    printf("Overall results: %d/%d called runs completed successfully\n", successful_runs_count, size);
}

