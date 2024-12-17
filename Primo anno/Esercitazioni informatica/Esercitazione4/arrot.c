#include <stdio.h>
#include <stdlib.h>

int main () {
    double a, b;

    a = 1.0; b = 1.0;
    while ( a+b != a )
        b = b/2.0;

    printf("%e\n", b);

    exit(EXIT_SUCCESS);
}
