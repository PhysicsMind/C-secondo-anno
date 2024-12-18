#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int mcd (int a, int b) {
    assert (a >= b) ;
    int r ;
    while ( b != 0 ) {
        r = a % b;
        a = b;
        b = r;
    }
    return a ;
}


int main () {
    int k, a, b, c;
    printf("inserisci un numero qualsiasi, diverso da zero, per inizializzare il programma") ;
    scanf("%d", &k) ;

    while (k != 0) {
        printf("inserisci una coppia di numeri\t") ;
        scanf("%d %d", &a, &b) ;
        
        if (a < b) {
            c = a ;
            a = b ;
            b = c ;
        }
        printf("MCD (%d, %d) = %d\n", a, b, mcd(a, b)) ;
        
        printf("inserisci zero per interrompere o uno per continuare il programma\n") ;
        scanf("%d", &k) ;
    }
    
    exit (EXIT_SUCCESS) ;
}
