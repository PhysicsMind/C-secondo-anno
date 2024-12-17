/* BALDO CRISTIAN			
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 90

void stampavettore  ( int estrazione[dim], int k){ 
	printf("VALORI ESTRATTI nel %i CICLO: \n", k+1);
	for (int i=0; i<dim; i++){
		printf(" %i", estrazione[i]);	
	}
	printf("\n");
}

void generatore (int estrazione[dim], int n){			//RIEMPIO IL VETTORE ESTRAZIONE CON 90 NUMERI CASUALI
	int N=dim; //N numeri casuali
  	int Massimo=dim;		//genera N numeri con valore massimo M
	int k=0,a ,j,b;
	//time_t t;

	estrazione[N-1] = 0; //azzero l'ultimo elemento del vettore per fare il controllo col ciclo while
	
	//	//il seme è casuale
	//srand(time(&t));
	srand((unsigned int)time(NULL));
	b=(rand()%time(NULL));
	srand(b);
	
	//srand(n);

	do {
	 	//srand((unsigned int)time(NULL));
		a = (rand()%Massimo+1);		//assegno il numero random alla variabile a
		j=0;					//azzero j
		for ( int i = 0; i < N; i++ ){	//PERCORRO IL VETTORE ESTRAZIONE e confronto se 'a' è già presente
			if(a == estrazione[i]){
			  j++;				//se 'a' è uguale ad un elemento del vettore allora icrementa
			}
		}
		if (j == 0){				//se j è rimasta pari a 0 allora non ha trovato elementi uguali, allora push
			estrazione[k] = a;
			k++;				//se a è stato assegnato allora si passa alla cella successiva del vettore
		}
	}
	while(estrazione[N-1] ==  0);			//finchè l'ultimo elemento vale ancora 0
}
    
int main(int argc, char *argv[]) {

	int estrazione[dim];
	int N;			//numero di partite
 	 N = atoi(argv[1]);		//numero di giocate dalla linea di comando
	
 	for(int i=0; i<N ;i++){		//PER N GIOCATE con la stessa tabella
	generatore(estrazione,i);
        stampavettore(estrazione,i);	
	}
    
    exit(EXIT_SUCCESS);
}

