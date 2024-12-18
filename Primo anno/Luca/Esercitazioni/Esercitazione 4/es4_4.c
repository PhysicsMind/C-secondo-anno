#include <stdio.h>
#include <stdlib.h>

#include <math.h>

double potenza (double x, int n) {
    if (x == 1 || n == 0) {
        return 1. ;
    }
    double prodotto = x ;
    for (int i = 0 ; i < n ; i++) {
        prodotto = prodotto * x ;
    }
    return prodotto ;
}


int main () {
    double x, risultato;
    int n;
    
    printf("inserisci il valore da elevare ed il valore dell'esponente\n");
    scanf("%lf %d", &x, &n);
    
    risultato = potenza(x, n);
    printf("il risultato è: %lf\n", risultato);
    
    exit (EXIT_SUCCESS);
}
