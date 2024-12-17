//CRISTIAN BALDO 866593			

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define dim 90		//dichiarazione dimensione costante

struct risultati { 			//struttura di raccoglimento delle frequenze delle cinquine
	int estrazione;
	int frequenza;
};

void riempimatrice (int l, int k, int mat[l][k]){        //FUNZIONE per ASSEGNARE i valori della tabella dallo standard input
	for(int i=0; i<l; i++){ 	                              
	   scanf("%i %i %i %i %i", &mat[i][0],&mat[i][1],&mat[i][2],&mat[i][3],&mat[i][4]);	     
	}
}

void stampamatrice(int mat[3][9]){	//FUNZIONE per STAMPARE la tabella
	printf("\n");
	for (int i=0;i<3;i++){				//percorro la matrice 
	    for(int j=0;j<9;j++){
			if(mat[i][j] != 0){			//se non vale 0 allora stampa il numero presente
				printf(" %.2i", mat[i][j]);			
	        	}
			else{ 					//se vale 0 allora stampa i trattini
		  		printf(" --");
			}
	    }	
	printf("\n");	
	}
	printf("\n");
}

void azzeramatrice(int r, int c, int tabella[r][c]){	//FUNZIONE di AZZERAMENTO MATRICE
   for (int i=0; i<r; i++){		
  	for (int j=0; j<c ;j++){
  	   tabella[i][j]=0;				//assegno 0 a tutte le celle	
  	}
   }
}

void azzeravettore(int l, int vettore[l]){		//FUNZIONE di AZZERAMENTO VETTORE
	for(int i=0; i<l; i++){
		vettore[i]=0;	
	}			
}

void ricolloca ( int input[3][5],  int tabella[3][9]){
	//COLLOCO gli elementi della matrice di input nella TABELLA da stampare secondo le regole
   
   int colonnatab;			
   for (int i=0; i<3; i++){				
  	  for (int j=0; j<5; j++){	 
  	     colonnatab=0;		        			//indice colonna iniziale pari a zero
  	     for (int a=0; a<9; a++ ){				//incremento gli intervalli di 10 in 10 
  	     	//se il valore di input è nell'intervallo corretto allora assegna se no incrementa
  		if ( input[i][j] >= a*10 && input[i][j] < (a+1)*10){	
  		 	tabella[i][colonnatab] = input[i][j];			
  		 	break;						//evita operazioni di controllo inutili
  		}					
  		else if ( input[i][j] == dim){		//se il valore di input è 90 allora va nell'ultima posizione della tabella
  		 	tabella[i][8] = dim;
  		}
  		else{					//se non è stato assegnato allora dovrà assegnarlo alla colonna successiva
  		colonnatab++;}
  	     }
	}
   }
}

void generatore (int estrazione[dim]){	//FUNZIONE che RIEMPIE il vettore ESTRAZIONE con 90 NUMERI CASUALI che non si ripetono
  	
	azzeravettore(dim,estrazione);

	for (int i=0; i<dim; i++){
		estrazione[i] = rand()%dim+1;		//Assegno valori random per ogni cella
			for(int j=0; j<i; j++){ 		//Per ogni elemento precedente del vettore
				if(estrazione[i]==estrazione[j]){		//Se trova un valore uguale, decrementa il contatore
					i--;
					break;
				}	 
			}
	}
}

void azzerarecord(struct risultati *record){		//funzione che azzzera lo struct contenente le frequenze
	record[0].estrazione=1;
	record[0].frequenza=0;
	for(int i=1; i<dim; i++){
		record[i].estrazione=record[i-1].estrazione+1;
		record[i].frequenza=0;		//pongo le frequenze iniziali a 0
	}
}

void confronto (int mat[3][5], int estrazione[dim], struct risultati *record){
	int deposito[3][5];			//matrice dove segnare le estrazioni vere
	bool primacinquina=false, primatombola=false,aux;
	int cont1=0, cont2=0;			//contatori di riempimento del deposito per cinquina e tombola
	int caso=0;
	
	azzeramatrice(3,5,deposito);
	
	for (int k=0; k<dim; k++){			//confronto TUTTE le estrazioni con la tabella,percorro il  vettore estrazioni
		 aux=false;			
		 for (int i=0; i<3 ; i++){			//percorro le righe della tabella
		        cont1=0; 
			for (int j=0; j<5 ; j++){		//percorro le colonne della tabella
			    caso=0;
			    if(mat[i][j] == estrazione[k]){	//se l'estrazione è presente nella tabella allora stampa 'vero'
			         aux=true;
			         deposito[i][j] = estrazione[k];  //riempio la matrice di deposito
			         cont2++;	//se aggiungo un numero a deposito incrementa
		 	         caso=1;
			     } 
			     if (deposito[i][j] != 0){  //se il deposito nella posizione ij non è vuoto allora aggiorna cont1
			         cont1++;
		         	 if (cont1==5 && primacinquina==0){  //se ho riempito una riga del deposito allora ho cinquina
		 			record[k].frequenza=record[k].frequenza+1;
		 			primacinquina=1; 	//fa in modo che rilevi solo la PRIMA cinquina
		 			caso=2;
		 	        } 
		 	     if(caso==1){
		 	     	printf("%.2i vero\n", estrazione[k]);}
		 	     if(caso==2){printf("%.2i vero cinquina\n", estrazione[k]);}
		 	    }          
		 	}	
		 }
		 if (!aux){			//se aux rimane 'false'
		 	printf("%.2i falso\n", estrazione[k]);
		 }
		 if (cont2==15 && primatombola==0){		//se ho aggiunto 15 numeri al deposito e non ho mai fatto tombola
		 	       printf("Tombola\n"); 
		 	       primatombola=1; 
		 	       break;
		 }	 
	 }
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
} 

int main (int argc, char *argv[]) {

  int input[3][5];		//tabella che inserisce l'utente
  int tabella[3][9];		//tabella da stampare
  int estrazione[dim];		//vettore contenente le estrazioni
  int N = atoi(argv[1]);		//numero di giocate dalla linea di comando
  struct risultati *record;		//record con frequenze delle cinquine

  riempimatrice(3,5, input);		
  
  azzeramatrice(3,9,tabella);		//azzera tabella
  ricolloca(input,tabella);			//sistema i valori dalla tabella 3x5 a quella 3x9 da stampare
  stampamatrice(tabella);
  
  record =  malloc(dim*sizeof(struct risultati));		//creo la memoria per 90 struct
  azzerarecord(record);

  srand(time(NULL));	//inizializzazione del seme
  for(int i=0; i<N ;i++){		//per N giocate con la stessa tabella
	generatore(estrazione);
	confronto(input, estrazione,record);	//confronto ogni estrazione con i valori della tabella e aggiorno i risultati
  }
  
  stamparisultati(record);
  
  exit(EXIT_SUCCESS);
}
