/**
 * L'argomento n deve essere non negativo
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double eleva (double x, int n) {
    assert(n >= 0);

    double val = 1.0; // Perché il valore iniziale è 1?
    for ( int i=0; i < n; i++ ) {
        val = val*x;
    }
    return val;
}

int main (int argc, char *argv[]) {
    double base;
    int    esp;

    scanf("%lf", &base);
    scanf("%d", &esp);

    printf("%10.6lf\n", eleva(base,esp));

    exit(EXIT_SUCCESS);
}
