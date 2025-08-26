#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

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
    scanf("%lf", intermediate_result); // TODO: do not assign it here, you never read this value DONE
    *flag = Detecting_Scanf_Failure();
    if (*flag == -1) {
        return 0;
    }
    else {
        return 1;
    }
}

bool Input_Checking(double *a, double *b, double *c) { // TODO: check 5 5 5 test
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    double *coefficients[3] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        double intermediate_result = 0.0;
        int flag = 0;
        do {
            if (!(Number_Reading(&flag, &intermediate_result))) {
                return false; // TODO: prefer true/false from stdbool.h over 1/0 DONE
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

int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    // double roots[2] = { NAN, NAN };
    // TODO: scanf can fail, check
    if (!(Input_Checking(&a, &b, &c))) {
        return 1;
    }
    assert((!(isinf(a))) && (!(isnan(a)))); // TODO: a != NAN doesn't work, use isnan, isinf and/or isfinite? DONE
    assert((!(isinf(b))) && (!(isnan(b))));
    assert((!(isinf(c))) && (!(isnan(c))));
    printf("%lg %lg %lg\n", a, b, c);
    return 0;
}
