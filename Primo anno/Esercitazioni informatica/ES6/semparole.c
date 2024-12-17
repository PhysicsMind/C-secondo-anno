/**
 * Esempi di funzioni della libreria standard per la
 * conversione di sequenze di caratteri in valori
 * numerici e per il trattamento di sequenze di
 * caratteri (stringhe)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scambia (char ** a, char ** b)
{
    char * temp;

    temp = *a;
    *a   = *b;
    *b   = temp;
}

int main (int argc, char * argv[])
{
    int         ln;
    double      dn;
    char      * p = "corona";
    char      * q = "virus";
    char      * comp;
    char      * e = "1936.27";
    char      * verba[2];

    ln = strlen(p) + strlen(q) + 1;
    comp  = (char *) malloc (ln * sizeof(char));
    if ( comp == NULL ) exit(EXIT_FAILURE);

    strcpy (comp, p);
    printf ("comp: %s\n", comp);
    strcat (comp, q);
    printf ("comp: %s\n", comp);

    verba[0] = q;
    verba[1] = p;
    printf ("verba[0]: %s\n", verba[0]);
    printf ("verba[1]: %s\n", verba[1]);

    if ( strcmp(verba[1], verba[0]) < 0 )
        scambia (&verba[0], &verba[1]);

    printf ("%s <= %s\n", verba[0], verba[1]);

    dn = atof(e);
    printf ("dn: %lf\n", dn);
    printf ("\n");

    exit (EXIT_SUCCESS);
}
