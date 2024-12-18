#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 3

void ordinamento (int v[], int K) {
    int min, t ;
    for (int i = 0; i < K; i++) {
        min = i ;
        for (int j = i+1; j < K; j++) {
            if (v[j] < v[min]) {
                min = j ;
            }
        }
        t = v[i] ;
        v[i] = v[min] ;
        v[min] = t ;
    }
}

void fusione (int v[N], int w[M], int u[N+M]) {
    for (int i = 0 ; i < N+M ; i++) {
        if (i < N) {
            u[i] = v[i] ;
        } else {
            u[i] = w[i-N] ;
        }
    }
        ordinamento (u, N+M) ;
}

void stampa_vettore (int v[], int K) {
    printf("STAMPA VETTORE\n");
    for (int i = 0; i < K; i++) {
        printf("l'elemento %d è %d\n", i, v[i]) ;
    }
}

void riempi_vettore (int v[], int K) {
    printf("RIEMPIMENTO VETTORE\n") ;
    for (int i = 0; i < K; i++) {
        printf("inserire elemento intero %d\t", i) ;
        scanf("%d", &v[i]) ;
    }
}
    
int main () {
    
    int v[N], w[M], u[N+M] ;
    
    riempi_vettore(v, N) ;
    riempi_vettore(w, M) ;
    fusione (v, w, u) ;
    stampa_vettore(u, N+M);
    
    exit (EXIT_SUCCESS) ;
}
