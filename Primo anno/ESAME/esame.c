/* BALDO CRISTIAN			
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 90

struct risultati { 			
	int estrazione;
	int frequenza;
};

void riempimatrice (int l, int k, int mat[l][k]){                 //funzione per assegnare i valori nella matrice
	for(int i=0; i<l; i++){ 	                              
	//    printf("Inserire 5 valori della riga %i: ", i+1); 	//DA TOGLIERE	
	    scanf("%i %i %i %i %i", &mat[i][0],&mat[i][1],&mat[i][2],&mat[i][3],&mat[i][4]);	     
	}
}

void stampamatrice(int l, int k, int mat[l][k]){		//funzione per STAMPARE la tabella
	printf("\nTabella \n");
	for (int i=0;i<l;i++){
	    for(int j=0;j<k;j++){
		  if(mat[i][j] != 0){
			printf(" %.2i ", mat[i][j]);			//stampa matrice
		//	printf("\n");
	        }
		  else{ 
		  printf(" -- ");
		  }
		}	
		printf("\n");
	}
}

void azzeramatrice(int r, int c, int tabella[r][c]){		//AZZERAMENTO MATRICE
   for (int i=0; i<r; i++){		
  	for (int j=0; j<c ;j++){
  	   tabella[i][j]=0;
  	}
   }
}

void azzeravettore(int l, int vettore[l]){
	for(int i=0; i<l; i++){
		vettore[i]=0;
	}
}

void ricolloca ( int mat[3][5],  int tabella[3][9]){		//colloco gli elementi della matrice nella tabella secondo le regole

   for (int i=0; i<3 ; i++){		//per ogni riga			
  	  for (int j=0; j<5 ; j++){	 //per ogni sua colonna effettuo il ricollocamento
  	  int m=0;		         //indice colonna iniziale pari a zero
  	     for (int a=0; a<9 ; a++ ){		//a ogni ciclo incremento 'a' di 10 	
  		if ( mat[i][j] >= a*10 && mat[i][j] < (a+1)*10){		//se è nell'intervallo allora assegna se no incrementa
  		 	tabella[i][m] = mat[i][j];			//allora lo stampi nella colonna pari al numero di iterazioni
  		 	break;
  		}			
  		else if ( mat[i][j] == dim){
  		 	tabella[i][8] = dim;
  		}
  		else{
  		m++;}
  	     }
	}
   }
}

void generatore (int estrazione[dim]){			//RIEMPIO IL VETTORE ESTRAZIONE CON 90 NUMERI CASUALI
	int N=dim; //N numeri casuali
  	int Massimo=dim;		//genera N numeri con valore massimo M
	int k=0,a ,j;
	
	azzeravettore(dim,estrazione);
	//estrazione[N-1] = 0; //azzero l'ultimo elemento del vettore per fare il controllo col ciclo while
//	srand(time(NULL));	//il seme è casuale

	do {
		a = (rand()%Massimo)+1;		//assegno il numero random alla variabile a
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

void azzerarecord(struct risultati *record){
	record[0].estrazione=1;
	record[0].frequenza=0;
	for(int i=1; i<dim; i++){
		record[i].estrazione=record[i-1].estrazione+1;
		record[i].frequenza=0;
	}
}

void confronto (int mat[3][5], int estrazione[dim], int N, struct risultati *record){
	int u;				//contatore per vero/falso
	int deposito[3][5];			//matrice dove segnare le estrazioni
	int primacinquina=0, primatombola=0;	//contatori di assegnamento
	int cont1=0, cont2=0;			//contatori di riempimento
	azzeramatrice(3,5,deposito);
	printf("Il valore estratto è presente nella tabella?\n");
	for (int k=0; k<dim; k++){			//confronto TUTTI le estrazioni con la tabella
		 u=0;			
		 for (int i=0; i<3 ; i++){			//percorro le righe della tabella
		        cont1=0; 
			for (int j=0; j<5 ; j++){		//percorro le colonne della tabella
			    if (deposito[i][j]!=0){
		           		   cont1++;}
			    if(mat[i][j] == estrazione[k]){
			   	 printf("%.2i vero\n",estrazione[k]);
			         u++;
			         deposito[i][j] = estrazione[k];  //riempio la matrice di deposito
			//         stampamatrice(3,5,deposito); //DA ELIMINARE 
			         cont2++;			   
			    }
			}
			if (cont1==5 && primacinquina==0){  //se ho riempito una riga
		 		record[k].frequenza=record[k].frequenza+1;
		 		printf("Cinquina alla %i estrazione nel gioco numero %i\n", k, N+1);
		 		primacinquina++; 	//fa in modo che rilevi solo la PRIMA cinquina
		 	   } 
			
		 }
		 if (u == 0){
		 	printf("%.2i falso\n", estrazione[k]);
		 }
	         
		 if (cont2==15 && primatombola==0){
		 	       printf("Tobola alla %i estrazione nel gioco numero %i\n", k, N+1); //RICHIESTO?
		 	       primatombola++; 
		 }
	 }
}
		

void stampavettore  ( int estrazione[dim]){  //NON RICHIESTO
	printf("VALORI ESTRATTI: \n");
	for (int i=0; i<dim; i++){
		printf(" %i", estrazione[i]);	
	}
	printf("\n");
} 

void stamparisultati (struct risultati *record){			//FUNZIONE PER STAMPARE i record
	FILE *result;
	result = fopen("estrazioni.dat", "w");
        if ( result == NULL ) {
      		  printf("Errore\n");
      		  exit(EXIT_FAILURE);
   	 }
   	 for(int i=0;i<dim ;i++){
   	    fprintf(result,"%i %i\n", record[i].estrazione, record[i].frequenza );
   	    }
   	 fclose(result);   
   	 
  /*     printf("CONTENUTO DEI RECORD:\n");		//DA ELIMINARE
       printf("Estrazione, frequenza\n");
	for(int i=0;i<dim ;i++){	
		printf(" %i %i \n", record[i].estrazione, record[i].frequenza);
	}   		*/
} 

int main(int argc, char *argv[]) {

  int mat[3][5];
  int tabella[3][9];
  int estrazione[dim];
  int N;			//numero di partite
  N = atoi(argv[1]);		//numero di giocate dalla linea di comando
  struct risultati *record;		//punta ai record

  riempimatrice(3,5, mat);
  
  azzeramatrice(3,9,tabella);		//AZZERAMENTO TABELLA
  ricolloca(mat,tabella);
  stampamatrice(3,9,tabella);
  
  record =  malloc(dim*sizeof(struct risultati));		//creo la memoria per 90 record
  azzerarecord(record);

  srand(time(NULL));	//il seme è casuale
  for(int i=0; i<N ;i++){		//PER N GIOCATE con la stessa tabella
	generatore(estrazione);
        stampavettore(estrazione);	//NON RICHIESTO
	confronto(mat,estrazione,i,record);	//confronto ogni estrazione con i valori della tabella e aggiorno i risultati
  }
  
  stamparisultati(record);
  
  exit(EXIT_SUCCESS);
}

