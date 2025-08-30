#ifndef TEST_EQUATION
#define TEST_EQUATION

struct Equation_Elements {
    double a, b, c;
    double roots[2];
};

bool Answers_Checking(double number_1, double number_2);
void Swap(double *obtained_roots);
int Test_Running(Equation_Elements data); // TODO: Equation_Elements should be defined here
void Tests_Calling();

// TODO: header guard

#endif
