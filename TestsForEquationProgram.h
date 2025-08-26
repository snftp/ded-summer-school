#ifndef TEST_EQUATION
#define TEST_EQUATION

typedef struct {
    double a, b, c;
    double expected_roots[2];
} Equation_Elements;

void Test_Running(Equation_Elements data); // TODO: Equation_Elements should be defined here
void Tests_Calls();

// TODO: header guard

#endif
