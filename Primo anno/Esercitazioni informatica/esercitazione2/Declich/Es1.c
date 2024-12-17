/**
L'obiettivo è scrivere un programma che legga 10 valori casuali dallo standard imput, e che da essi ricavi somma e media aritmetica
*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

 // Uso un while loop per far sì che il programma elabori un dato alla volta */
 int main ( )
 {
 int contatore=0, nuovovalore; // in questo modo dichiaro le variabili e le azzero ogni volta */
 int somma=0;
 float media;

 printf(" I valori richiesti sono 10/n/n");
 
 while (contatore<10) {
 
 contatore=contatore+1;
 printf("%d", contatore);
 scanf("%d", &nuovovalore);
 //serve per inserire dallo standard imput il valore successivo*/
 somma=somma+nuovovalore;
 }
 
 media=somma/contatore;
 printf("/n");
 printf("%d/n", somma);
 printf("%f/n/n", media);

   exit (EXIT_SUCCESS);
 

   exit (EXIT_SUCCESS);
 }
