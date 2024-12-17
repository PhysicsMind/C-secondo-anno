#include <stdio.h>
#include <stdlib.h>

void riempivettore (int l, int vettore[l], char *argv[]){                 //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite linea di comando
	vettore[i]=atoi(argv[i+1]);
	}
}

void stampavettore(int l, int vettore[l]){    //funzione per stampare i valori di un vettore 
	for(int i=0; i<l; i++){           
	printf("%i ", vettore[i]);
	}
}


int main (int argc, char *argv[]) {

  int V[argc-1]; 
  
  riempivettore(argc-1, V, argv);   //riempimento del vettore  V[argc-1]
  stampavettore(argc-1 , V);
    
  exit(EXIT_SUCCESS);
}
