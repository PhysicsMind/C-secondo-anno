/*
 Escogitate un modo per servirvi di rand() allo scopo di:
 (1) simulare mille lanci di un dado da sei facce, e calcolare la distribuzione statistica dei risultati;
 (2) simulare mille lanci di due dadi, e calcolare la distribuzione statistica dei risultati. Confrontando tale caso con il precedente, cosa notate? E perche?´
 (3) simulare mille lanci di tre dadi, e calcolare la distribuzione statistica
 dei risultati.
 Simulare distribuzione uniforme 0, 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa_vettore (double v[], int K) {
    printf("STAMPA VETTORE\n");
    for (int i = 0; i < K; i++) {
        printf("l'elemento %d è %f\n", i, v[i]) ;
    }
}

void dado (int N_1[], int Nlanci, int S) {
    srand(S) ;
    for (int i = 0; i < Nlanci; i++) {
        N_1[i] = (rand()%6) + 1 ;
        }
}

// Funzione per generare un numero pseudocasuale reale tra 0 e M
double generateRandom(double M) {
    return ((double)rand() / RAND_MAX) * M;
}

void uniforme (double N_2[], int Nlanci) {
    srand(time(NULL)) ;                     // time(NULL) va a prendere la distanza temporale in secondi dal primo gennaio 1970. Mette il seme in base all'orario del computer      (Non funziona a velocità relativistiche)
    for (int i = 0; i < Nlanci; i++) {
        N_2[i] = generateRandom (2.) ;
        }
}

int main (int argc, char * argv[]) {
    
    int Nlanci = 1000 ;
    int S_1 = atoi (argv[1]) ;      // Semi da passare all'ingresso
    
    int N_1[Nlanci] ;               // dado
    double N_2[Nlanci] ;
    
    dado (N_1, Nlanci, S_1) ;
    uniforme(N_2, Nlanci) ;
    stampa_vettore(N_2, Nlanci) ;
    
    exit (EXIT_SUCCESS) ;
}
