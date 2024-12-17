#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *dati;
    FILE *risultati;
    int x;

    dati = fopen("numeri.txt", "r");
    risultati = fopen("r.txt", "w");
    if ( dati == NULL || risultati == NULL ) {
        printf("Errore\n");
        exit(EXIT_FAILURE);
    }

    fscanf(dati, "%d", &x);
    fprintf(risultati, "%d\n", 2*x);
    fscanf(dati, "%d", &x);
    fprintf(risultati, "%d\n", 2*x);

    fclose(dati);
    fclose(risultati);

    exit(EXIT_SUCCESS);
}
