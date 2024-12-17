#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 200

int main (int argc, char *argv[]) {
    char * riga;
    char id; int n; double z;
    int e;

/*
    if ( argc > 1 ) {
    }
*/

    riga = (char *) malloc (BUFSIZE);
    if ( riga == NULL ) exit (EXIT_FAILURE);

    for (int i=0; i < 4; i++) {
        fgets (riga, BUFSIZE, stdin);
        e = sscanf(riga, "%c %d %lf", &id, &n, &z);
        if ( e == 3 )
            printf ("id: %c, n: %4d, z: %4.4lf\n", id, n, z);
        else
            printf("%d\n", e);
    }

    exit(EXIT_SUCCESS);
}
