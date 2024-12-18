#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, somma ;
    somma = 0 ;
    
    printf("Inserisci 3 numeri interi\n") ;
    scanf("%d %d %d", &a, &b, &c) ;
    
    somma = a + b + c ;
    printf("La somma dei numeri è: %d\n", somma) ;
    
    if ((somma % 2) == 0) {
        printf("La somma è pari\n") ;
    }
    else {
        printf("La somma è dispari\n") ;
    }
    
    exit (EXIT_SUCCESS);
}
