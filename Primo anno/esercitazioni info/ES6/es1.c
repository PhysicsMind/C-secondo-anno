/* BALDO CRISTIAN			PER ESEGUIRE: ./es1 K n   (con K e n interi)
Un file di dati e composto di righe, ciascuna delle quali contiene 
(1) una lettera, (2) un numero intero, (3) un numero reale, separati fra loro da un singolo spazio. Le righe sono disposte in modo che i numeri interi siano ordinati in senso crescente. I valori nei tre campi possono essere ripetuti in righe diverse.

Dovete scrivere un programma che acquisisce due argomenti di tipo intero, K e n, dalla riga di comando; 
legge e memorizza le prime K righe del file di dati; 
stabilisce se il numero n è presente nella seconda posizione di una riga; 
stampa l’intero contenuto di quella riga in caso di risposta positiva, e un messaggio in caso di risposta negativa.*/

#include <stdio.h>
#include <stdlib.h>

struct riga {
	char  lettera;
	int intero;
	double reale;
	};
	
struct riga *riempimento(struct riga *rg, int K) {		//Funzione per RIEMPIRE I RECORD nella memoria predisposta dinamicamente
   printf("RIEMPIMENTO DEI RECORD:\n");
	for(int i=0;i<K;i++){				// ciclo riempimento dei campi del record

		printf("Inserisci valori della riga %i : carattere, intero, reale: ", i); 				
          	scanf(" %c %i %le", &rg[i].lettera, &rg[i].intero, &rg[i].reale ); 				
	  	
	}	
   return rg;
   }
   
void ordinamento (struct riga *rg, int K){ 		//FUNZIONE PER ORDINAERE i record nella memoria dinamica
	struct riga min, temp;

	for(int i=0; i<K; i++){   		
 	min=rg[i];				
	temp=rg[i];
		for(int cont=i;cont<K;cont++){
			if(rg[cont].intero < rg[i].intero){
			min=rg[cont];
			temp=rg[i];
			rg[i]=min;
			rg[cont]=temp;
			}
		}	
	}
}
   
void stampa (struct riga *rg, int K){			//FUNZIONE PER STAMPARE i record
        printf("CONTENUTO DEI RECORD:\n");
	for(int i=0;i<K;i++){	
		printf("La riga numero %i è: %c %i %f\n", i, rg[i].lettera, rg[i].intero, rg[i].reale);
	}
}

void ricerca (struct riga *rg, int K, int n){   	//FUNZIONE PER CERCARE un numero naturale e STAMPARE la sua riga
	printf("Cerco il numero %i nelle righe e stampo la riga corrispondente :\n", n);
	int j=0; 				//indice che tiene conto delle volte in cui è stato trovato il numero
	
	for(int i=0; i<K; i++){   	        //ciclo di ricerca
		if (rg[i].intero == n ) {
		printf("Riga numero %i contenente %i : %c %i %f\n", i,n,rg[i].lettera, rg[i].intero,rg[i].reale);	//stampa la riga
		j++;
		}
	}
	if(j==0){							
	printf("Il numero cercato (%i) NON è stato trovato nelle righe\n",n);
	}
}

int main(int argc, char *argv[]) {

 int K=atoi(argv[1]); //acquisisce due argomenti di tipo intero, K e n, dalla riga di comando; 
 int n=atoi(argv[2]);

	struct riga *rg; //dichiaro il puntatore del record
	rg =  malloc(K*sizeof(struct riga)); //Allocazione di memoria dinamica del puntatore
	
	riempimento(rg,K);//funzione riempimento della memoria dinamica con i record
	ordinamento(rg,K);//funzione ordinamento dei record all'interno della memoria
	stampa(rg,K); //funzione per STAMPARE
	ricerca(rg, K,n); //RICERCA il numero n nei record e STAMPA la riga in caso affermativo
  
exit(EXIT_SUCCESS);
}
