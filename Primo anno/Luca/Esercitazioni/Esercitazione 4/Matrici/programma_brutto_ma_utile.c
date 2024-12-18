#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

void riempi_mat (double mat[N][M]) {
    printf("     RIEMPIMENTO MATRICE\n");
    printf("\n") ;
    for (int i = 0 ; i < N ; i++) {
        printf("inserisci gli elementi della riga %d\n", i) ;
        for (int j = 0 ; j < M ; j++) {
            printf("colonna %d\t:", j);
            scanf("%lf", &mat[i][j]) ;
        }
        printf("\n") ;
    }
}

void stampa_matrice (double mat[N][M]) {
    printf("      MATRICE\n");
    printf("\n") ;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            printf("%f\t", mat[i][j]) ;
        }
        printf("\n") ;
    }
}

int main () {
    
    double matrice[N][M] ;
    
    riempi_mat(matrice) ;
    stampa_matrice(matrice) ;
    
    exit (EXIT_SUCCESS) ;
}
