//BALDO CRISTIAN
/*ESERCIZIO2 3 Scrivete un programma che dichiara una matrice di dimensione M × N e
 la riempie di valori di tipo double, leggendoli dallo standard input. Successivamente, il programma calcola la somma di tutti i valori nella matrice, la somma dei valori della seconda colonna, la somma dei valori della terza riga.
Definite M e N attraverso direttive define, in modo che M ≥ 3 e N ≥ 2.*/

#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 3

void riempimatrice (int l, int k, double mat[l][k]){                 //funzione per assegnare i valori nella matrice
	for(int i=0; i<l; i++){ 
	    for(int j=0; j<k; j++){                             //ciclo di assegnamento delle variabili tramite standard imput
	    printf("Inserire valore riga %i, colonna %i: ", i+1,j+1); 		
	    scanf("%le", &mat[i][j]);
	    } 
	}
}

void stampamatrice(int l, int k, double mat[l][k]){
	printf("\nMatrice \n");
	for (int i=0;i<l;i++)	
	{
		for(int j=0;j<k;j++)
		{
			printf("%4f ",mat[i][j]);			//stampa matrice
		}
		printf("\n");	
	}
}

double sommatuttivalori(int l, int k, double mat[l][k]){
   double somma=0;
    for (int i=0;i<l;i++){
		for(int j=0;j<k;j++)
		{
			somma=somma+mat[i][j];			
		}
    }
    return somma;
}

double sommasecondacolonna(int l, int k, double mat[l][k]){
   double somma2c=0;
   int j=1;
		for(int i=0;i<k;i++)
		{
			somma2c=somma2c+mat[i][j];			
		}
    return somma2c;	
}
  
double sommaterzariga(int l, int k, double mat[l][k]){
   double somma3r=0;
   int i=2;
		for(int j=0;j<k;j++)
		{
			somma3r=somma3r+mat[i][j];			
		}
    return somma3r;
}
   

int main(){

  double mat[M][N];
  double sommavalori;
  double somma2c;
  double somma3r;
  
  if (M>=3 || N>=2){
  riempimatrice(M,N, mat);
  stampamatrice(M,N, mat);
  sommavalori=sommatuttivalori(M,N, mat);
  somma2c=sommasecondacolonna(M,N, mat);
  somma3r=sommaterzariga(M,N, mat);
  
  printf("La somma di tutti i valori della matrice è: %f\n",sommavalori);
  printf("La somma dei valori della seconda colonna è: %f\n",somma2c);
  printf("La somma dei valori della terza riga è: %f\n",somma3r);
  }
  else {
  printf("Valori errati per N e M");
  }
  
  exit(EXIT_SUCCESS);
}
