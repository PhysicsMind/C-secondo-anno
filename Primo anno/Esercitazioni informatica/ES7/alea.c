/* Generatore di numeri aleatori */
/* Genera N numeri, ciascuno compreso fra 1 e M */
/* Riceve tre argomenti dalla riga di comando:
     N numero di valori da generare
     M limite superiore della gamma di valori generati
     S seme del generatore pseudocasuale
*/
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char * argv[])
{
    int i;
    int N, M, S;

    N = atoi(argv[1]);
    M = atoi(argv[2]);
    S = atoi(argv[3]);

    srand(S);
    for ( i = 1; i <= N; i++ )
        printf("%d ", (rand()%M)+1);
    printf("\n");

    exit(EXIT_SUCCESS);
}
