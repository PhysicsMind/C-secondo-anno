/** Scrivere un programma che legga una serie di numeri INTERI dallo standard input, arrestandosi quando viene inserito
 il numero 0 e determinare il massimo della serie di numeri inseriti
*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
 //strutturo il programma in modo che legga un valore alla volta mediante un ciclo while
 //il programma non deve conservare i valori contemporaneamente
 
 int main ( )
 {
  int contatore=0, nuovovalore; //dichiaro le variabili e azzero le condizioni iniziali
  float  massimo;
  
  printf ("Inserire il valore 0 per arrestare il ciclo./n");
  do {
  contatore++; //aggiorno il contatore dei cicli eseguiti
  printf ("Inserire il valore %d: ", contatore);
  scanf ("%d", &nuovovalore); //il comando permette di inserire il valore successivo
  if (nuovovalore>massimo) {
  massimo=nuovovalore; } //se il valore nuovo è maggiore del massimo, quest'ultimo diventa il massimo
  else { }	  
  }
  while (nuovovalore!=0); //se invece il valore è 0 il ciclo si deve arrestare
  
 
  printf ("Il massimo della serie è: %f/n/n", massimo);
 
 exit(EXIT_SUCCESS);
 }      	 

