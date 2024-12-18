/**
 * Legge N valori reali dallo standard input e li colloca in un
 * vettore. Percorre il vettore, eliminando gli elementi minori
 * di un valore di soglia fissato a priori, e sposta verso sinistra
 * i valori superstiti. Stampa i valori superstiti.
 *
 * Al termine dell'esecuzione, le ultime posizioni del vettore
 * possono contenere valori non significativi.
 */
#include <stdio.h>
#include <stdlib.h>

#define L 0.01  // Valore di soglia
#define N 8     // Lunghezza del vettore dei dati

void lettura (float v[], int nelem) {
    for (int i=0; i < N; i++)
        scanf("%f", &v[i]);

    return;
}

/**
 * Stampa gli elementi nel vettore v, dalla posizione sin, inclusa,
 * alla posizione des, esclusa.
 */
void stampa (float v[], int sin, int des) {
    for (int i=sin; i < des; i++)
        printf("%f ", v[i]);

    return;
}

/**
 *  Funzione scorri: determina quali elementi del vettore v hanno
 *  valore inferiore a soglia, li "cancella" dal vettore, e sposta
 *  verso sinistra gli elementi superstiti per non lasciare lacune.
 *  Argomenti: v, vettore di numeri reali; nelem, lunghezza del
 *  vettore; soglia, valore di riferimento.
 *
 *  La funzione percorre il vettore da sinistra a destra, esaminando
 *  gli elementi. Quando trova un valore inferiore alla soglia,
 *  incrementa il valore della variabile nelim (numero di elementi
 *  eliminati). Quando trova un valore superiore o uguale alla
 *  soglia, lo sposta verso sinistra di un numero di posizioni pari
 *  al numero di elementi da eliminare trovati fino a quel momento.
 */
int scorri (float v[], int nelem, float soglia) {
    int     i = 0;
    int nelim = 0;  // Conta gli elementi da eliminare
    while ( i < N ) {
        if ( v[i] < soglia )
            nelim++;
        else
            v[i-nelim] = v[i];
        i++;
    }
    return nelim;
}

int main (int argc, char *argv[]) {
    float v[N];
    int   nelim;  // Numero di elementi eliminati
    lettura (v, N);
    nelim = scorri (v, N, L);
    stampa (v, 0, N-nelim);

    exit (EXIT_SUCCESS);
}
