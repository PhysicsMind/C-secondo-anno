/**
 *ESERCIZIO 1 ,esercitazione 2
 * Scrivete un programma che legge una serie di dieci numeri interi dallo standard input,
 * ne accumula la somma in una variabile, calcola la media aritmetica dei dieci numeri, 
 * e stampa somma e media. I dieci valori non devono essere conservati dal programma
 */

//strutturare il programma elaborando un dato alla volta (con un while loop)
//il programma non deve conservare tutti i valori contemporaneamente
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{ 
  int contatore=0,nuovovalore; //dichiarazione variabili e azzeramento condizioni iniziali
  float media,somma=0;
  
  printf("I valori richiesti sono 10\n\n");
  
  while (contatore < 10) {
   contatore = contatore + 1;
   printf("inserire il valore %i:   ", contatore);
   scanf("%d", &nuovovalore); //comando per inserire dallo standard imput la variabie successiva
   somma = somma + nuovovalore;
   }
  
  media = somma/contatore;
  printf("\n");
  printf("Il valore della somma è: %f\n", somma);
  printf("Il valore della media è: %f\n\n", media);
   
    exit(EXIT_SUCCESS);
}
