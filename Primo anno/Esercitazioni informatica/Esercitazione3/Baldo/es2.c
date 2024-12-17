//BALDO CRISTIAN
//ESERCIZIO2 Scrivete un programma che dichiara un vettore di Nelementi di tipo int e lo riempie leggendo i valori dallo standard input.  Successivamente il programma determina la posizione del valore minimo nel vettore, e lo scambia con il valore nella prima posizione.  Infine, il programma stampa i valori nel vettore

#include <stdio.h>
#include <stdlib.h>

#define N 10 //dichiaro la lunghezza del vettore

/* trovaposmin: determina la posizione dell'elemento più  piccolo nel vettore v, tra le      posizioni 'da' e 'a'.
 * Restituisce la posizione trovata.*/

void riempivettore (int l, int vettore[l]){                 //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite standard imput
	printf("Inserire valore %i del vettore: ", i); 		
	scanf("%i", &vettore[i]);
	}
}

void stampavettore(int l, int vettore[l]){    //funzione per stampare i valori di un vettore 
	for(int i=0; i<l; i++){               //ciclo di stampa di ogni elemento
	printf("%i ", vettore[i]);
	}
	printf("\n");
}

int trovaposmin (int l, int v[]) {   //trova e stampa la posizione dell'elemento più  piccolo nel vettore v
  int vmin, posmin;

  vmin = v[0]; posmin = 0;        //azzeramento variabili
  for (int i=0; i <= l; i++) {
    if ( v[i] < vmin ) {  //se la posizione successiva è minore allora è il nuovo minimo
      vmin = v[i];
      posmin = i;
    }
  }
  return posmin;  
}

void scambia (int v[], int x, int y) {   //scambia nel vettore v[x] con v[y]
  int tmp = v[x];
  v[x] = v[y];
  v[y] = tmp;
  return;
}


int main (int argc, char *argv[]) {

  int V[N];
  int min; //variabile per posizione del valore minimo del vettore
  int pos=0; //posizione con cui scambiare il minimo
  
  riempivettore(N, V);   //riempimento del vettore  V[N]
  min=trovaposmin(N ,V);
  scambia(V, pos, min);
  
  stampavettore(N , V);
    
  exit(EXIT_SUCCESS);
}
