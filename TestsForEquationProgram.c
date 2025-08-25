#include <stdio.h>
#include "SolvingAlgorithm.h"

struct Equation_Elements {
    double a, b, c;
    double expected_roots[2];
}

void Test_Running(Equation_Elements data) {}
    double obtained_roots[2] = { NAN, NAN };
    Equation_Solving(data.a, data.b, data.c, obtained_roots);
    if (!((Are_Same_Numbers(obtained_roots[0], data.expected_roots[0]) && Are_Same_Numbers(obtained_roots[1], data.expected_roots[1]))
            || (Are_Same_Numbers(obtained_roots[1], data.expected_roots[0]) && Are_Same_Numbers(obtained_roots[0], data.expected_roots[1])))) {
        printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf", &a, &b, &c, data.expected_roots[0], data.expected_roots[1], obtained_roots[0], obtained_roots[1]);
    }

void Tests_Calls() {
    Equation_Elements data[] = {{}, {}, {}}; // { .a =, .b =, .c =, ?? .expected_roots = {x_1, x_2} };
    const size = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < size; i++) {
    /* count_successful += */Testing_Result(data[i]);
    }
}

// int Testing_Result(result) { // counts the amount of successful/failed test runs (if only Test_Running gave 1/0)
//     int successful_runs = 0; // int failed_runs = 0;
//     successful_runs += result; // failed_runs += (!(Test_Running(........)));
//     return successful_runs;
// }

