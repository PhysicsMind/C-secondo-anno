/**
Scrivete un programma che dichiara un vettore di N
elementi di tipo int e lo riempie leggendo i valori
dallo standard input. Successivamente il programma
determina la posizione del valore minimo nel vettore, e
lo scambia con il valore nella prima posizione. Infine,
il programma stampa i valori nel vettore.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 10

/**
 * trovaposmin: determina la posizione dell'elemento più
 * piccolo nel vettore v, tra le posizioni 'da' e 'a'.
 * Restituisce la posizione trovata.
 */
int trovaposmin (int v[], int da, int a) {
  int vmin, posmin;

  vmin = v[da]; posmin = da;
  for (int i=da+1; i <= a; i++) {
    if ( v[i] < vmin ) {
      vmin = v[i];
      posmin = i;
    }
  }
  return posmin;
}

/**
 * Pericolosa! x e y devono essere posizioni all'interno
 * del vettore v.
 */
void scambia (int v[], int x, int y) {
  int tmp = v[x];
  v[x] = v[y];
  v[y] = tmp;
  return;
}

void stampa (int v[], int da, int a) {
  for (int i=da; i <= a; i++) {
    printf("%4d ", v[i]);
  }
  printf("\n");
}

int main (int argc, char *argv[]) {
  int v[N] = { 13, 9, -4, 23, 3, 17, -7, 0, 9, 20 };
  int m;
  /* Lettura dei dati */
  stampa(v, 0, N-1);
  for (int i=0; i < N-1; i++) {
    m = trovaposmin(v, i, N-1);
    scambia(v, i, m);
    stampa(v, 0, N-1);
  }
  stampa(v, 0, N-1);

  exit(EXIT_SUCCESS);
}
