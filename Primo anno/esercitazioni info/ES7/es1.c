/* BALDO CRISTIAN			
 Escogitate un modo per servirvi di rand() allo scopo di: 
 (1) simulare mille lanci di due dadi, e calcolare la distribuzione statistica dei risultati; 
 (2) generare una sequenza di cento valori di tipo double, compresi fra 0 e 1.*/

#include <stdio.h>
#include <stdlib.h>

void somma (int N, int N1[N],int N2[N],int Ntot[N]){
	for (int i=0; i<N ; i++){
		Ntot[i]=N1[i]+N2[i];
	}
}

void stampavettore  (int N, int Ntot[N]){
	for (int i=0; i<N; i++){
		printf(" %i", Ntot[i]);	
	}
} 

int main(int argc, char *argv[]) {

	int N=1000, M=6, S1, S2;
	S1 = atoi(argv[1]);
	S2 = atoi(argv[2]);
	int N1[N], N2[N], Ntot[N];

	srand(S1);
    	for ( int i = 1; i <= N; i++ ){
    	 	N1[i-1]= (rand()%M)+1;
        //	printf("%d ", (rand()%M)+1);
   	// printf("\n");
   	  }
    
   	printf("\n");
    	srand(S2);
    	for ( int l = 1; l <= N; l++ ){
    		N2[l-1]= (rand()%M)+1;
        //	printf("%d ", (rand()%M)+1);
   	 // printf("\n");
        }
    
    somma(N,N1,N2,Ntot);
    stampavettore(N,Ntot);
    
  
	
    exit(EXIT_SUCCESS);
}



/* Generatore di numeri aleatori */
/* Genera N numeri, ciascuno compreso fra 1 e M */
/* Riceve tre argomenti dalla riga di comando:
     N numero di valori da generare
     M limite superiore della gamma di valori generati
     S seme del generatore pseudocasuale

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
} */

