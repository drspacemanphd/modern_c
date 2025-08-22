#include <stdio.h>
#include <stdlib.h>

int main() {
    int j = 3;
    double A[5] = {9, 2.5, 0, 0.0007, 3.E+25};
    for (short i = 0; i < 5; i++) {
        int j = -1;
        printf("j is %d\n", j);
        printf("element %d is %g. its square is %g\n", i, A[i], A[i] * A[i]);
    }
    printf("j is %d\n", j);
    return EXIT_SUCCESS;
}
