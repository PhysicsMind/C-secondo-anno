/** Modificare l'esercizio 2, fissando una soglia e scartando i valori inseriti sotto quella soglia. Il programma
 * deve stampare, oltre alla somma e alla media dei quadrati dei valori superstiti, anche il numero di valori
 * scartati*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
   //vado a strutturare il porgramma nello stesso modo dell'esercizio 2, ma andando a definire una soglia N 
   //che porrò uguale a 5
 #define N 5 
 int main ( )
 {
 int contatore=0, nscartati=0, nottenuti=0;
 float media, somma=0, nuovovalore;
 //dichiaro le variabili
 printf ("Ferma il ciclo inserendo 0 ./n");
 do {
 contatore++; //aggiorno il contatore dei cicli eseguiti
 printf ("Inserire il valore %d: ", contatore);
 scanf ("%f", &nuovovalore); // inserisco dallo standard input il valore successivo
 if (nuovovalore>N) {
 somma=somma+(nuovovalore*nuovovalore);
  nottenuti++;
 } //calcolo somma e media soltanto se il nuovovalore è maggiore di 5
 else { 
 nscartati++;	 
 }
 }
 while (nuovovalore!=0);  //quando il nuovovalore è 0 il ciclo si arresta

 nscartati=nscartati-1;
 media=somma/(nottenuti);
  printf ("Il valore della somma è %f/n", somma);
  printf ("Il valore della media è %f/n/n", media);
  printf ("Il numero di valori scartati è %d/n", nscartati);

  exit(EXIT_SUCCESS);
 }
