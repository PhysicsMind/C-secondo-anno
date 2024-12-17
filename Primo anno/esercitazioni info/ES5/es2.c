/*BALDO CRISTIAN
Scrivete un programma che 
(1) legge un numero intero N e due numeri reali, m e M; 
(2) alloca lo spazio per un vettore di N numeri reali; 
(3) legge una serie di N numeri reali e li colloca nel vettore; 
(4) percorre il vettore e calcola la somma degli elementi, scartando i valori minori di m e quelli maggiori di M; 
(5) percorre nuovamente il vettore eliminando gli elementi minori di m e quelli maggiori di M, spostando gli elementi in modo da riempire i buchi che si sono formati. Supponendo che siano stati scartati k elementi, al termine dell’operazione gli elementi superstiti devono occupare le prime N−k posizioni del vettore.*/

#include <stdio.h>
#include <stdlib.h>
#define NULL 0

void riempivettore (int l, double vettore[l]){                 //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite standard imput
	printf("Inserire valore %i del vettore: ", i); 		
	scanf(" %le", &vettore[i]);
	}
}

void sommatoria(double a, double b, int l ,double vettore[l]){
	double somma=0;
	for(int i=0; i<l; i++){
	    if (vettore[i]>a && vettore[i]<b){
	        somma=somma+vettore[i];}
	 
	}
	printf("La somma degli elementi del vettore compresi fra %f e %f è:  %f\n", a,b,somma);
}

void ricomponivettore(double a, double b, int l ,double vettore[l]){
      for(int i=0; i<l-1; i++){
	for(int i=0; i<l-1; i++){
		if(vettore[i]<a || vettore[i]>b ||vettore[i]==NULL){
	 	   vettore[i]=vettore[i+1];
	 	   vettore[i+1]=NULL;
	 	}
	}  
      }
      if (vettore[l-1]<a || vettore[l-1]>b){
           vettore[l-1]=NULL;
      }
}

void stampavettore(int l, double vettore[l]){    //funzione per stampare i valori di un vettore 
	printf("ELEMENTI DEL VETTORE:\n");
	for(int i=0; i<l; i++){               //ciclo di stampa di ogni elemento
	
	printf("%f\n ", vettore[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	double m;
	double M;
	int N;
	double v[N];

  printf("Inserire il valore del primo numero reale, m :  ");
  scanf(" %le", &m);
  printf("Inserire il valore del secondo numero reale, M :  ");
  scanf(" %le", &M);
  if (M<m){
     double z=m;
     m=M;
     M=z;
     }
  printf("Inserire il numero di N numeri reali da confrontare con m e M :  ");
  scanf(" %i", &N);
  riempivettore(N,v);
  
  sommatoria(m,M,N,v);
  ricomponivettore(m,M,N,v);
  stampavettore(N , v); //stampa il vettore  V[N]
  
  printf("\n");
  
exit(EXIT_SUCCESS);
}

