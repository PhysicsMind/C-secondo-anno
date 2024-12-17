#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define N 12

int main (void)
{
    double v[N];

    struct artif {
        char    c;
        double  d;
    };

    struct trio {
        char    c[3];
    };

    printf("             char: %zd\n", sizeof(char));
    printf("              int: %zd\n", sizeof(int));
    printf("         long int: %zd\n", sizeof(long int));
    printf("     unsigned int: %zd\n", sizeof(unsigned int));
    printf("long unsigned int: %zd\n", sizeof(long unsigned int));
    printf("            float: %zd\n", sizeof(float));
    printf("           double: %zd\n", sizeof(double));
    printf("      long double: %zd\n", sizeof(long double));
    printf("     struct artif: %zd\n", sizeof(struct artif));
    printf("      struct trio: %zd\n", sizeof(struct trio));
    printf("     double v[%d]: %zd\n", N, sizeof(v));
    printf("          INT_MAX: %d\n", INT_MAX);
    printf("          FLT_MAX: %e\n", FLT_MAX);
    printf("          DBL_MAX: %e\n", DBL_MAX);

    printf("INT_MAX + 1 = %d\n", INT_MAX + 1);

    exit(EXIT_SUCCESS);
}
