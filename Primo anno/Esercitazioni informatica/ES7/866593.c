//866579 866593 866777  Luca Sala, Cristian Baldo, Francesco Declich//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct riga{         //definizione della struttura del record
   char carattere;
   int intero;
   double reale;
};


struct riga * riempimento(struct riga * record, int K, double a, double b){		//Funzione per riempire i record

	for(int i=0;i<K;i++){				// ciclo riempimento dei campi del record, con controllo sul numero reale inserito
		do{	
		printf("Inserisci valori della riga %i : carattere, intero, reale: ", i); 				
          	scanf(" %c %i %le", &record[i].carattere, &record[i].intero, &record[i].reale ); 				
	  	}while(record[i].reale<a || record[i].reale>b);
 	  printf("\n");
	}	

return record;
}

void contatore( struct riga * record, int K, double a, double b, double amp, int cont[K]){ //Funzione per contare i valori in ogni sottointervallo e per 												   scriverli nel file classi.txt											
 double c=a;
 double d= a+amp;
 FILE *risultati; 
 risultati= fopen("classi.txt", "w");	//Generazione e apertura file			

  	for(int i=0; i<K; i++){ //Ciclo per impostare tutte le celle del vettore contatore a 0
	cont[i]=0;
	}			

	for(int i=0; i<K; i++){ //Ciclo per incrementare la cella del vettore contatore
	c=a;
	d= a+amp; 
		for(int j=0; j<K; j++){  //Ciclo per incrementare il sottointervallo e controllare se il numero reale appartiene ad esso
			if(record[i].reale>=c && record[i].reale<d){
			cont[j]++;
			break;	
			}else if(record[i].reale==b){ 		//Se il numero reale coincide con l'estremo b dell'intervallo viene incrementato il contatore corrispondente all'ultimo sottointervallo
			cont[K-1]++;
			break;
			}	
		c=c+amp;
		d=d+amp;
		}
  } 

	c=a;
    	d= a+amp;	

	for(int i=0; i<K; i++){ 		//Ciclo per scrivere i risultati sul file classi.txt
	fprintf(risultati, "Intervallo (%f - %f): %i \n", c,d, cont[i]);
	c=c+amp;
	d=d+amp;	
	}							

 fclose(risultati);

}


int main(int argc,char * argv[]){

 double a=atof(argv[1]);
 double b=atof(argv[2]);
 
 	if(b<a){		//Se l'utente ha inserito un intervallo in cui b>a, scambio i due valori in modo da avere l'estremo a sinistra minore di quello a destra
 	double temp=a;
 	a=b;
 	b=temp;
 	}

 int K=atoi(argv[3]);
 double amp=(b-a)/K;
 int cont[K];
 struct riga * record;

 record=  malloc(K*sizeof(struct riga)); //Allocazione di memoria dinamica del puntatore


 riempimento(record,K,a,b);
 
 contatore(record, K, a, b, amp, cont);
 
 free(record);			//Liberazione memoria dinamica prima allocata
 
exit(0);
}








