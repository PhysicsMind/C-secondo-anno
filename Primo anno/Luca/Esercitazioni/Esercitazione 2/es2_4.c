#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int main() {
    
    int n, i, max ;
    i = 1 ;
    printf("Inserisci il primo numero:\t") ;
    scanf("%d", &max) ;
    n = 1 ;
    
    while (n != 0) {
        printf("Inserisci il numero %d:\t", i+1) ;
        scanf("%d", &n) ;
        i = i + 1 ;
        if (n >= max) {
            max = n ;
        }
    }
    
    printf("Il massimo della serie è %d\n", max) ;
    
    exit (EXIT_SUCCESS);
}
