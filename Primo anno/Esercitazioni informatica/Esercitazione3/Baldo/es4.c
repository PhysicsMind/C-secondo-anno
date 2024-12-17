/*
 *  Laboratorio 3, Esercizio 4
 *
 *  Inventate un algoritmo per stabilire se un numero intero positivo è primo.
 *  Traducete l'algoritmo in una funzione,  in C, con un parametro,  e
 *  inseritela nel programma primi.c.  Sperimentate il programma con diversi
 *  valori.  Aggiungete una nuova funzione che riceve come parametro un numero
 *  intero, k, e stampa tutti i numeri primi minori o uguali a k, servendosi
 *  della prima funzione. Completate il programma facendo in modo che nella
 *  funzione main il programma  chieda  di  inserire  un  numero  intero n e
 *  richiami  la  seconda funzione.
 */

#include <stdio.h>
#include <stdlib.h>

#define VERO 1
#define FALSO 0

/*
 * Funzione che riceve un numero intero x e
 * restituisce VERO se è primo, FALSO altrimenti
 */
double primo(int x) {
  /*
   * Nota: 1 non è primo, ma non possiamo far
   * partire il for da 1, in quanto ogni numero
   * è divisibile per 1.
   */
  if (x == 1) {
    return FALSO;
  }

  int i;
  /*
   * Nota: un numero non può essere divisibile per un numero
   * maggiore della sua metà. In realtà questo potrebbe essere
   * ancora esteso alla radice di x
   */
  for (i = 2; i <= x / 2; i++) {
    if (x % i == 0) {     //se il resto è 0
      return FALSO;
    }
  }

  return VERO;
}

int main(int argc, char *argv[]) {
  int n, i;

  printf("Inserire un numero intero: ");
  scanf("%d", &n);

  if (primo(n) == VERO) {
    printf("Il numero è primo.\n");
  } else {
    printf("Il numero non è primo.\n");
  }

  printf("Numeri primi < %d\n", n);
  for (i = 2; i < n; i++) {
    if (primo(i) == VERO) {
      printf("%d ", i);
    }
  }
  printf("\n");

  exit(EXIT_SUCCESS);
}
