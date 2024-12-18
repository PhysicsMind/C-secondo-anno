#include <stdio.h>
#include <stdlib.h>

/* GENERATORE DI NUMERI PSEUDOCASUALI COMPRESI TRA ZERO ED M
N numero di valori da generare
M limite superiore della gamma di valori generati
S seme del generatore pseudocasuale
*/

int main (int argc, char * argv[]) {
    
    int N, M, S ;
    N = atoi (argv[1]) ;
    M = atoi (argv[2]) ;
    S = atoi (argv[3]) ;
    
    srand(S) ;              //assegno alla funzione random il seme S
    for (int i = 0; i < N; i++) {
        printf("%d\n", (rand()%M)) ;      //rand()%M genera numeri pseudocasuali tra zero ed M (non compreso)
    }
    
    exit (EXIT_SUCCESS) ;
}
