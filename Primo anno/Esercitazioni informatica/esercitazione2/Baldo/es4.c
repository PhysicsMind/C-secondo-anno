/**
 *ESERCIZIO 4 ,esercitazione 2
 *traccia es2:
 * Scrivete un programma che legge una serie di dieci numeri reali dallo standard input,
 * arrestandosi quando viene inseririto 0., calcola la somma dei quadrati e la media aritmetica dei quadrati, 
 * e stampa somma e media. non usare pow.
 *traccia es4:
 *Modificate il programma dell’esercizio 2 in questo modo. Attraverso una direttiva
 *define fissate un valore di soglia. Scartate dal calcolo tutti i valori inferiori alla soglia.
 *Oltre alla somma e alla media dei quadrati dei valori superstiti, il programma deve anche
 *stampare il numero di valori scartati.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SOGLIA 5 //definisco che il valore di soglia è 5 per tutto il programma

int main ()
{ 
  int nscarti=0,ntenuti=0; //dichiarazione variabili e azzeramento condizioni iniziali
  float media,somma=0,nuovovalore;

  printf("Premere 0 per fermare il ciclo\n\n");
  
  do {
     printf("inserire il nuovo valore: ");
     scanf("%e", &nuovovalore); //comando per inserire dallo standard imput la variabie successiva
       if (nuovovalore >= SOGLIA){
           somma = somma + (nuovovalore*nuovovalore);
           ntenuti++;
           }
       else { 
            nscarti++;
            }
     }
  while (nuovovalore!=0);
   
   nscarti=nscarti -1;
   media = somma/(ntenuti);
   printf("\n");
   printf("Il valore della somma è: %f\n", somma);
   printf("Il valore della media è: %f\n", media);
   printf("Il numero di valori scartati è: %i\n\n", nscarti);
   
   exit(EXIT_SUCCESS);
}
