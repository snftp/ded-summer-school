#include <stdio.h>
#include <float.h>
#include "SolvingAlgorithm.h"

struct Equation_Elements {
    double a, b, c;
    double expected_roots[2];
};

void Test_Running(Equation_Elements data) {}
    double obtained_roots[2] = { NAN, NAN };
    Equation_Solving(data.a, data.b, data.c, obtained_roots);
    if (!((Are_Same_Numbers(obtained_roots[0], data.expected_roots[0]) && Are_Same_Numbers(obtained_roots[1], data.expected_roots[1]))
            || (Are_Same_Numbers(obtained_roots[1], data.expected_roots[0]) && Are_Same_Numbers(obtained_roots[0], data.expected_roots[1])))) {
        printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf\n\n", &a, &b, &c, data.expected_roots[0], data.expected_roots[1], obtained_roots[0], obtained_roots[1]);
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
    const size = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < size; i++) {
        successful_runs_count += Testing_Result(data[i]);
    }
    printf("Overall results: %d/%d called runs completed successfully\n", successful_runs_count, size);
}

