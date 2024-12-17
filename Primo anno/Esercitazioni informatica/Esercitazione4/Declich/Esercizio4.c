/* Dato un vettore A di lunghezza N e un vettore B di lunghezza M, scrivere un programma che legga i valori dello 
 * standard input, li inserisca in ordine crescente nei due vettori e li fonda in ordine crescente in un vettore C.
 *In seguito stampare il contenuto finale del vettore. */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #define N 3
 #define M 4
 
 void fus (int A[], int B[]) {
 int C[N+M];
 int i=0, j=0, min, temp;

 //In questo modo unisco i vettori e poi li ordino 
 while (i<N+M) { //mediante questo ciclo mi assicuro che il processo si arresti quando si raggiunge la dimensione prevista
 if (i<N) {
 C[i]=A[i];
 }
 else { 
 C[i]=B[j];
 j++;
 }
 i++;
 } //A questo punto ho riempito il vettore C e procedo a ordinare i suoi elementi
   //Per farlo, uso l'algoritmo selection sort
 for (int k=0;  k<N+M-1; k++) {
 min=k;
 for (int x=k+1; x<N+M; x++) {
 if (C[x]<C[min]) {
 min=x;
 }
 }
 temp=C[min];
 C[min]=C[k];
 C[k]=temp;
 } 

 printf ("Unione e ordinamento crescente dei due vettori ./n");
 for (int y=0; y<N+M; y++){
	 printf ("%d ", C[y]);
 }
 }
 
 int main () {
 int A[N];
 int B[M];

 printf ("Unione e ordinamento crescente di due vettori.----------");

 printf ("Inserire %d valori per il primo vettore:", N);
 for (int x=0; x<N; x++) {
 scanf ("%d", &A[x]);
 }
 printf ("Inserire %d valori per il secondo vettore:", M);
 for (int y=0; y<M; y++) {
 scanf ("%d", &B[y]);
 }
 fus (A, B); //Con questa funzione dispongo gli elementi sulla stessa riga

 printf ("              ");
 exit(EXIT_SUCCESS);
 }
 
