/**
 * Scrivo un programma che legge una serie di numeri dallo standard input e si arresta quando viene inserito
 * il numero 0, calcola la somma dei quadrati dei numeri inseriti e la media dei quadrati, stampando
 * i risultati */
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

 //strutturo il programma in modo che elabori un dato alla volta tramite un while loop
 //il programma non deve conservare contemporaneamente tutti i valori
 int main ( )
 {
 int contatore=0; 
 float media, somma=0, nuovovalore; 
 printf ("Ferma il ciclo premendo 0/n/n");
 
 do {
 contatore++; //aggiorno il contatore dei cicli eseguiti
 printf ("inserire il valore %d", contatore);
 scanf ("%f", &nuovovalore); //questo comando permette di inserire dallo standard input il valore successivo
 somma= somma+(nuovovalore);
 }
 while (nuovovalore!=0); //quando nuovovalore è 0 il ciclo si arresta
 
 media=somma/(contatore-1);
 printf ("/n");
 printf ("Il valore della somma è %f/n", somma);
 printf ("Il valore della media è %f/n/n", media);

 exit(EXIT_SUCCESS);
 } 
