#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, somma ;
    somma = 0 ;
    double media ;
    
    for (int i = 0; i < 10; i++) {
        printf("Inserisci il numero %d/10 della somma:\t", i+1) ;
        scanf("%d", &n) ;
        somma = somma + n ;
    }
    
    printf("La somma dei numeri è: %d\n", somma) ;
   
    media = somma/10. ;
    printf("La media dei numeri è: %f\n", media) ;
    
    return 0;
}

