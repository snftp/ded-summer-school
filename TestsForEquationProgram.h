#ifndef TEST_EQUATION
#define TEST_EQUATION

typedef struct {
    double a, b, c;
    double expected_roots[2];
} Equation_Elements;

bool are_numbers_equal(double roots[2]);
void Test_Running(Equation_Elements data); // TODO: Equation_Elements should be defined here
void Tests_Calls();

// TODO: header guard

#endif
