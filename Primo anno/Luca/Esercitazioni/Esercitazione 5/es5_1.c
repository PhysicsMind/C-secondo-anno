#include <stdio.h>
#include <stdlib.h>

int main () {
    
    char lettera ;
    
    do {
        printf("\n") ;
        printf("inserisci una lettera o * per stoppare il programma\t") ;
        lettera = getchar() ;
        if (lettera == 'a') {
            lettera = 'e' ;
        }
        putchar(lettera) ;
        printf("\n") ;
        printf("%d\n", lettera) ;
    } while (lettera != '*') ;
    
    exit (EXIT_SUCCESS) ;
}
