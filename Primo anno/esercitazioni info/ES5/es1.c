/* BALDO CRISTIAN
Scrivete una funzione che riceve come argomenti due numeri reali e stabilisce se il valore assoluto del primo numero è inferiore al secondo numero. 
Scrivete un programma che 
(1) legge un numero intero N e due numeri reali, x e y ;
(2) alloca lo spazio per un vettore di N numeri reali; 
(3) legge una serie di N numeri reali e li colloca nel vettore; 
(4) percorre il vettore e, per ogni numero contenuto nel vettore, stabilisce se la differenza da x è minore di y */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void riempivettore (int l, double vettore[l]){                 //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite standard imput
	printf("Inserire valore %i del vettore: ", i); 		
	scanf(" %le", &vettore[i]);
	}
}

void confrontoabs(double a, double b){                     //funzione che riceve come argomenti due numeri reali e stabilisce se il valore assoluto del primo numero è inferiore al secondo numero. 
     if (fabs(a)<fabs(b)){
     	printf("Il valore assoluto di x è inferiore al valore assoluto di y\n");}
     else {
        printf("Il valore assoluto di x NON è inferiore al valore assoluto di y\n");
     }
}

void differenza(double a, double b, int l ,double vettore[l]){
	for(int i=0; i<l; i++){
		if (fabs(fabs(a)-fabs(vettore[i]))<fabs(fabs(b)-fabs(vettore[i]))){
		   printf("La differenza del numero %f da x è minore di y\n",vettore[i]);
		}
		else {
		printf("La differenza del numero %f da x NON è minore di y\n",vettore[i]);
		}
        }
}

int main(int argc, char *argv[]) {
	double x;
	double y;
	int N;
	double v[N];

  printf("Inserire il valore del primo numero reale, x :  ");
  scanf(" %le", &x);
  printf("Inserire il valore del secondo numero reale, y :  ");
  scanf(" %le", &y);
  printf("Inserire il numero di N numeri reali da confrontare con x e y :  ");
  scanf(" %i", &N);
  confrontoabs(x,y);
  riempivettore(N,v);
  differenza(x,y,N,v);
  printf("\n");
  
exit(EXIT_SUCCESS);
}

