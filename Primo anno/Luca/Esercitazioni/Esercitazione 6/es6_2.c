#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    

    FILE * lettere ;
    
    char lettera = 'a' ;
    
    lettere = fopen("lettere.txt", "w") ;
    
    while (lettera != '*') {
        lettera = getchar() ;
        fprintf(lettere, "%c", lettera) ;
    }
    fclose(lettere) ;
    FILE * lettura ;
    lettura = fopen("lettere.txt", "r") ;

    fscanf(lettere, "%c", &lettera) ;
    while (lettera != EOF) {
        putchar(lettera) ;
        fscanf(lettere, "%c", &lettera) ;
    }
    
    fclose(lettura) ;
    
    exit (EXIT_SUCCESS) ;
}
