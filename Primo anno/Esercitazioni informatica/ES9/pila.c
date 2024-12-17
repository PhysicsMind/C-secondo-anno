#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

typedef struct cella * Pila;

struct cella {
    char        valore;
    Pila        resto;
};

Pila    p = NULL;

struct cella * nuovacella (char c)
{
    struct cella * temp;
    temp = (struct cella *) malloc (sizeof(struct cella));
    if (temp == NULL) exit(2);

    temp->valore = c;
    temp->resto  = NULL;

    return  temp;
}

int   pilavuota ()
{
    if ( p == NULL )
        return 1;
    else
        return 0;
}

void  push (char c)
{
    struct cella * nuova;
    nuova = nuovacella(c);

    nuova->resto = p;
    p = nuova;
}

char  pop ()
{
    char c;

    if ( pilavuota() ) exit (1);

    c = p->valore;
    p = p->resto;

    return c;
}

void stampapila ()
{
    while ( p != NULL )
    {
        printf ("%c", p->valore);
        p = p->resto;
    }
    printf ("\n");
}
