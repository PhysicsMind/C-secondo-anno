/** Scrivere un programma che dichiara un vettore di N elementi di tipo int e lo riempie leggendo i valori dello 
 * standard input. In seguito il programma determina la posizione del valore minimo e lo scambia col valore in prima
 * posizione. Infine, stampa i valori nel vettore.*/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #define N 4
 
 int main ( )
 {
 int V[N];
 int i, j, min, t;

 for (i=0; i<4; i++) {
 printf("Inserisci il valore %d: ", i);
 scanf ("%d", &V[i]);
 }
 for (j=0; j<3; j++){
 min=j;
 for (i=j+1; i<4; i++){
 if (V[i]<V[min])
 min=i;
 }
 t=V[min];
 V[min]=V[0];
 V[0]=t;
 }
 for (i=0; i<4; i++){
 printf ("%d", V[i]);
 }
 exit(EXIT_SUCCESS);
 }
