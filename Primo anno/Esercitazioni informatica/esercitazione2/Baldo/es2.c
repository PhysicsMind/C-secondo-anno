/**
 *ESERCIZIO 2 ,esercitazione 2
 * Scrivete un programma che legge una serie di dieci numeri reali dallo standard input,
 * arrestandosi quando viene inseririto 0., calcola la somma dei quadrati e la media aritmetica dei quadrati, 
 * e stampa somma e media. non usare pow.
 */

//strutturare il programma elaborando un dato alla volta (con un while loop)
//il programma non deve conservare tutti i valori contemporaneamente
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{ 
  int contatore=0; //dichiarazione variabili e azzeramento condizioni iniziali
  float media,somma=0,nuovovalore;
  
  printf("Fermare il ciclo premendo 0\n\n");
  
  do {
     contatore++;                                      //aggiorno il contatore dei cicli eseguiti
     printf("inserire il valore %i:   ",contatore);
     scanf("%e", &nuovovalore);                        //comando per inserire dallo standard imput la variabie successiva
     somma = somma + (nuovovalore*nuovovalore);
     }
  while (nuovovalore!=0);                              //quando il valore inserito è 0 il ciclo si arresta
  
   media = somma/(contatore-1);
   printf("\n");
   printf("Il valore della somma è: %f\n", somma);
   printf("Il valore della media è: %f\n\n", media);
   
   exit(EXIT_SUCCESS);
}
