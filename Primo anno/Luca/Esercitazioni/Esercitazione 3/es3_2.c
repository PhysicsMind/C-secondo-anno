#include <stdio.h>
#include <stdlib.h>

#define N 5
#define L 3
void riempi_vettore (float v[N]) {
    for (int i = 0; i < N; i++) {
        printf("inserisci un numero intero\t") ;
        scanf("%f", &v[i]) ;
    }
}

void stampa_vettore (float v[N]) {
    for (int i = 0; i < N; i++) {
        printf("l'elemento %d è %f\n", i, v[i]) ;
    }
}

void elim_elem_vett (float v[N]) {
    for (int i = 0; i < N; i++) {
        if (v[i] <= L) {
            v[i] = 0. ;
        }
    }
    //printf("stampa del vettore:\n") ;
    //stampa_vettore(v) ;
    int j ;
    for (int i = 0; i < N; i++) {
        j = i ;
        while (v[j] == 0. && j < N) {
            j = j + 1 ;
        }
        v[i] = v[j] ;
        if (j != i) {
            v[j] = 0. ;
        }
    }
}

int main () {
    
    float vettore[N] ;
    riempi_vettore(vettore) ;
    stampa_vettore(vettore) ;
    
    elim_elem_vett(vettore) ;
    printf("la stampa del vettore ordinato è: \n") ;
    stampa_vettore(vettore) ;
    
    exit (EXIT_SUCCESS) ;
}
