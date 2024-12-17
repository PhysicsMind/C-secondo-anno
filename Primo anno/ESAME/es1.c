/* BALDO CRISTIAN			
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void stampavettore  (int N, int N1[N]){
	for (int i=0; i<N; i++){
		printf(" %i", N1[i]);	
	}
	printf("\n");
} 

int main(int argc, char *argv[]) {

	int N=90, Massimo=90;		//genera N numeri con valore massimo M
	int j=0;
	int estrazione[N];
	
	for(int i = 0; i < N; i++ ){		//azzero il vettore
		estrazione[i] = 0;}

	srand(time(NULL));
	while (estrazione[N-1] ==  0){
	 	printf("sei stupido?\n");
       	for ( int i = 0; i < N; i++ ){
    	           if((rand()%Massimo)+1 != estrazione[i]){  //se è diverso da TUTTI allora assegna
    	 	       estrazione[j]= (rand()%Massimo)+1;
    	 	      
    	// 	       break;
    	 	       }
    	 	j++;
    	 	}		
   	  }
    
    stampavettore(N,estrazione);
    
  
	
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

