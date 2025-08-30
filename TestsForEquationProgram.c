#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "SolvingAlgorithm.h"

#ifndef NDEBUG
#define ASSERT_FERROR(condition)     \
    do {                      \
        if (!(condition)) {   \
            fprintf(stderr, "An error occurred while reading file. Location: %s:%d %s\n", __FILE__, __LINE__, __FUNCTION__); \
            abort(); \
        }            \
    } while (0)
#define ASSERT_FCLOSE(condition) \
    do {                      \
        if (!(condition)) {   \
            fprintf(stderr, "Failed to close the file. Location: %s:%d %s\n", __FILE__, __LINE__, __FUNCTION__);             \
            abort(); \
        }            \
    } while (0)
#else
#define ASSERT_FERROR(condition) ((void)0)
#define ASSERT_FCLOSE(condition) ((void)0)
#endif

struct Equation_Elements {
    double a, b, c;
    double roots[2];
};

bool Answers_Checking(double number_1, double number_2) {
    if ((isnan(number_1) ^ isnan(number_2)) || (isinf(number_1) ^ isinf(number_2))) {
        return false;
    }
    if ((isnan(number_1) && isnan(number_2)) || (isinf(number_1) && isinf(number_2))) {
        return true;
    }
    return Are_Same_Numbers(number_1, number_2); // fabs(number_1 - number_2) < EPS;
}

void Swap(double *obtained_roots) {
    assert(obtained_roots != NULL);
    double temporary = obtained_roots[0];
    obtained_roots[0] = obtained_roots[1];
    obtained_roots[1] = temporary;
}

int Test_Running(Equation_Elements data) {
    double obtained_roots[2] = { NAN, NAN };
    Equation_Solving(data.a, data.b, data.c, obtained_roots);
    if ((!(isnan(obtained_roots[0]))) && (!(isinf(obtained_roots[0]))) && obtained_roots[1] < obtained_roots[0]){
        Swap(obtained_roots);
    }
    if (!(Answers_Checking(obtained_roots[0], data.roots[0]) && Answers_Checking(obtained_roots[1], data.roots[1]))) {
        printf("FAILURE\n coefficients: %lf, %lf, %lf\n expected results: %lf, %lf\n obtained results: %lf, %lf\n\n", data.a, data.b, data.c, data.roots[0], data.roots[1], obtained_roots[0], obtained_roots[1]);
        return 0;
    }
    return 1;
}

void Tests_Calling() {
    int runs_count = 0, successful_runs_count = 0;
    FILE *file = fopen("DataForTests.txt", "r");
    assert(file != NULL);
    while (1) {
        struct Equation_Elements data = {};
        ASSERT_FERROR(!(ferror(file)));
        int flag = fscanf(file, "%lf %lf %lf %lf %lf", &data.a, &data.b, &data.c, &data.roots[0], &data.roots[1]);
        if (flag != 5) {
            break;
        }
        successful_runs_count += Test_Running(data);
        runs_count++;
    }
    printf("Overall results: %d/%d called runs completed successfully\n", successful_runs_count, runs_count);
    ASSERT_FCLOSE(fclose(file) == 0);
}
