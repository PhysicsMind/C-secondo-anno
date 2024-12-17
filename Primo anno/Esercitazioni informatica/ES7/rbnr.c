/*
 * Ricerca binaria non ricorsiva.
 * I valori del vettore in cui cercare sono letti da standard input.
 * Si suppone che i valori inseriti siano in ordine crescente.
 * Il numero di elementi da leggere e il valore da cercare vengono
 * acquisiti come argomenti sulla riga di comando.
 */
#include <stdio.h>
#include <stdlib.h>

void acqdati (int *vd, int nelem) {
    int i = 0;
    while ( i < nelem ) {
      scanf("%d", &vd[i]);
      i++;
    }
    return;
}
  
int cerca (int n, int v[], int nelem) {
/* Presuppone che il vettore v sia ordinato e di lunghezza N */
/* Le variabili sx e dx indicano gli estremi della porzione
   di vettore che resta da esaminare. All'inizio gli estremi
   corrispondono al primo e all'ultimo elemento del vettore. */
  int sx = 0;
  int dx = nelem-1;
  int med;

/**
 * L'iterazione si arresta se si trova l'elemento nella posizione
 * a mezza strada fra sx e dx, oppure se sx diventa piu` grande
 * di dx; in questo caso, l'elemento cercato non si trova nel
 * vettore.  A ogni iterazione, si decide se proseguire la ricerca
 * nella meta` di sinistra o in quella di destra della porzione
 * residua del vettore, e si aggiorna l'estremo corrispondente.
 */
  while (sx <= dx) {
    med = (sx + dx)/2;
printf("%d %d %d\n", sx, med, dx);
    if (v[med] == n)
      return med;
    else if (v[med] < n)
      sx = med+1;
    else
      dx = med-1;
  }
  return -1;
}
    
int main (int argc, char * argv[]) {
    int *vdati, nelem;
    int p;
    int n; // Contiene il valore da cercare; acquisito da riga di cmd
  
    if (argc < 3) {
        printf("Dati insufficienti\nUso: rbnr K n\n");
        exit(EXIT_FAILURE);
    }
    nelem = atoi(argv[1]);
    n     = atoi(argv[2]);

    vdati = (int *) malloc (nelem*sizeof(int));
    if (vdati == NULL) exit(EXIT_FAILURE);

    acqdati(vdati, nelem);
    p = cerca (n, vdati, nelem);
    printf ("%d\n", p);
  
    exit (EXIT_SUCCESS);
}
