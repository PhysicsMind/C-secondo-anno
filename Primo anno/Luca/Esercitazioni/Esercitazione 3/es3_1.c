#include <stdio.h>
#include <stdlib.h>

#define N 5

void riempi_vettore (int v[N]) {
    for (int i = 0; i < N; i++) {
        printf("inserisci un numero intero\t") ;
        scanf("%d", &v[i]) ;
    }
}

void stampa_vettore (int v[N]) {
    for (int i = 0; i < N; i++) {
        printf("l'elemento %d è %d\n", i, v[i]) ;
    }
}

void scambia_min_vettore (int v[N]) {
    int pos_min = 0 ;                   //posizione del minimo
    for (int i = 1; i < N; i++) {
        if (v[i] < v[pos_min]) {
            pos_min = i ;
        }
    }
    if (pos_min != 0) {
        int j = v[pos_min] ;
        v[pos_min] = v[0] ;
        v[0] = j ;
    }
}

int main () {
    // Le righe commmentate non c'entrano col programma (domande di ragionamento pre esame)
    //int * v = malloc(dim*sizeof(int)) ;
    // v[0] = 5 ;
    // int N = atoi (argv[1]) ;
    int vettore[N] ;
    
    riempi_vettore (vettore) ;
    stampa_vettore (vettore) ;
    printf("il vettore scambiato è: \n") ;
    scambia_min_vettore(vettore) ;
    stampa_vettore(vettore) ;
    
    exit (EXIT_SUCCESS) ;
}
