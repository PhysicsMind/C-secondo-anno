/**
 *ESERCIZIO 3 ,esercitazione 2
 * Scrivete un programma che legge una serie di numeri interi dallostandard input, arrestandosi quando viene inserito il numero zero,       
 * e determina il massimo della serie.
 */

//strutturare il programma elaborando un dato alla volta (con un while loop)
//il programma non deve conservare tutti i valori contemporaneamente
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{ 
  int contatore=0,nuovovalore; //dichiarazione variabili e azzeramento condizioni iniziali
  float massimo;
  
  printf("Inserire 0 per arrestare il ciclo\n\n");
  do {
     contatore++;
     printf("inserire il valore %i:    ",contatore);
     scanf("%d", &nuovovalore); //comando per inserire dallo standard imput la variabie successiva
     if (nuovovalore>massimo){ //se il nuovo valore è maggiore del massimo precedente allora assegna il nuovo valore come nuovo massimo
     massimo=nuovovalore; }
     else {}
     }
  while (nuovovalore!=0); //se il valore è 0 il ciclo si arresta
  
   printf("\n");
   printf("Il valore massimo della serie è: %f\n\n", massimo);
   
   exit(EXIT_SUCCESS);
}
