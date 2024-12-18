#include <stdio.h>
#include <stdlib.h>

int * crea_array (int dim) {         // dim = dimensione vettore
    int * v = malloc(dim*sizeof(int)) ;
    int value ;
    for (int i = 0; i < dim; i++) {
        printf("inserisci valore %d del vettore:\t", i) ;
        scanf("%d", &value) ;
        v[i] = value ;
    }
    return v ;
}

void stampa (int * ptr, int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        printf("elemento %d del vettore: %d\n", i, ptr[i]) ;
    }
}

int main (int argc, char * argv[]) {
    
    int dimensione ;
    printf("inserisci la dimensione del vettore:\t") ;                  //inserire anche controllo dimensione
    scanf("%d", &dimensione) ;
    
    int * p = crea_array(dimensione) ;
    stampa(p, dimensione) ;
    
    exit (EXIT_SUCCESS) ;
}
