#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

void lettura (double m[][N], int nrighe) {
    for ( int i=0; i < nrighe; i++ ) {
        for ( int j=0; j < N; j++ ) {
            scanf("%lf", &m[i][j]);
        }
    }
    return;
}

double sommag (double m[][N], int nrighe) {
    double somma = 0.0;
    for ( int i=0; i < nrighe; i++ ) {
        for ( int j=0; j < N; j++ ) {
            somma = somma + m[i][j];
        }
    }
    return somma;
}

double sommacol (double m[][N], int nrighe, int col) {
    double somma = 0.0;
    for (int i=0; i < nrighe; i++)
        somma += m[i][col-1];

    return somma;
}

double sommariga (double m[][N], int nrighe, int riga) {
    double somma = 0.0;
    for (int i=0; i < N; i++)
        somma += m[riga-1][i];

    return somma;
}

int main (int argc, char *argv[]) {
    double mat[M][N];

    lettura(mat, M);
    printf ("Somma globale: %lf\n", sommag(mat, M));
    printf ("Somma col %i: %lf\n", 2, sommacol(mat, M, 2));
    printf ("Somma riga %i: %lf\n", 3, sommariga(mat, M, 3));

    exit(EXIT_SUCCESS);
}
