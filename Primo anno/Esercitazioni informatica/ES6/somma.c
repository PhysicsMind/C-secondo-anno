#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    double x, y;

    if (argc < 3) {
        printf("Uso: somma x y\n");
        exit(EXIT_FAILURE);
    }

    x = atof (argv[1]);
    y = atof (argv[2]);

    printf ("%lf + %lf = %lf\n", x, y, x+y);

    exit(EXIT_SUCCESS);
}
