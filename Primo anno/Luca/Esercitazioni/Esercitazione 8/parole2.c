/**
 * Esempi di funzioni della libreria standard per la
 * conversione di sequenze di caratteri in valori
 * numerici e per il trattamento di sequenze di
 * caratteri (stringhe)
 * -------------------------------------------------
 * L'esecuzione deve comprendere almeno un argomento
 * sulla riga di comando, da interpretare come numero
 * decimale; gli eventuali argomenti successivi sono
 * interpretati come parole.
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
    int         i, ln, v;
    double      nd;
    char      * p;
    char      * mots[2];

    if ( argc < 2 )
    {
        printf ("Manca l'argomento numerico\n");
        exit (EXIT_FAILURE);
    }
    printf ("\n");

    for ( i=0; i < argc; i++ )
    {
        printf ("%3d: %12s", i, argv[i]);
        printf ("  %2zu\n", strlen(argv[i]));
    }
    printf ("\n=======================\n");

    nd = atof (argv[1]);
    v  = atoi (argv[1]);
    printf ("  argv[1]: %4.2f\n", nd);
    printf ("  argv[1]: %e\n", nd);
    printf ("  argv[1]: %d\n", v);
    printf ("=======================\n\n");

    if ( argc > 3 )
    {
        ln = strlen(argv[2]) + strlen(argv[3]) + 1;
        p  = (char *) malloc (ln * sizeof(char));
        if ( p == NULL ) exit(EXIT_FAILURE);

        strcpy (p, argv[2]);
        printf ("p: %s\n", p);
        strcat (p, argv[3]);
        printf ("p: %s\n", p);

        mots[0] = argv[2];
        mots[1] = argv[3];
        printf ("mots[0]: %s\n", mots[0]);
        printf ("mots[1]: %s\n", mots[1]);

        if ( strcmp(mots[1], mots[0]) < 0 )
            scambia (&mots[0], &mots[1]);

        printf ("%s <= %s\n", mots[0], mots[1]);
    }

    printf ("\n");

    exit (EXIT_SUCCESS);
}
