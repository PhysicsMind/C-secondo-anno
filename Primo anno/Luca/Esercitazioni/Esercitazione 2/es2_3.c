#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int main() {
    
    int n, somma_quadrati ;
    somma_quadrati = 0 ;
    double media_quadrati, i ;
    i = 1. ;
    
    printf("Inserisci il primo numero:\t") ;
    scanf("%d", &n) ;
    
    while (n != 0) {
        somma_quadrati = somma_quadrati + pow(n, 2) ;
        printf("Inserisci il numero %0.1f:\t", i+1) ;           // %0.1 mi stampa solo una cifra decimale
        scanf("%d", &n) ;
        i = i + 1. ;
    }
    
    if (i == 1) {
        printf("stai dividendo per zero\n") ;
    }
    else {
        media_quadrati = somma_quadrati/(i-1.) ;
        
        printf("la somma dei quadrati è: %d\n", somma_quadrati) ;
        printf("la media dei quadrati è: %f\n", media_quadrati) ;
    }
    return 0;
}
