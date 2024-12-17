#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Nodo;

struct nodo {
  int valore;
  Nodo * prox;
};

void stampa (Nodo * t) {
    while ( t != NULL ) {
        printf("%d ", t->valore);
        t = t->prox;
    }
    printf ("\n");
    return;
}

Nodo * nuovonodo (int n) {
        Nodo * np;
        np = (Nodo *) malloc (sizeof(Nodo));
        if ( np == NULL ) exit(EXIT_FAILURE);
        np->valore = n;
        np->prox = NULL;
        return np;
    }

Nodo * inserisci(int n, Nodo * t) {
    Nodo * nuovo;

    nuovo = nuovonodo (n);

    if (t == NULL) { /* Catena vuota */
        return nuovo;
    }

    if (nuovo->valore <= t->valore) {
        nuovo->prox = t;
        return nuovo;
    }

    Nodo * cur;
    Nodo * bcur;
    int inserito = 0; /* Interpretiamo 0 come 'falso' */
    cur = t->prox;
    bcur = t;
    while ( cur != NULL && inserito == 0 ) {
        if ( nuovo->valore <= cur->valore ) {
            nuovo->prox = cur;
            bcur->prox = nuovo;
            inserito = 1;
        }
        else { /* Passiamo all'elemento successivo */
            cur = cur->prox;
            bcur = bcur->prox;
        }
    }

    if ( cur == NULL ) {
        printf("cur ha raggiunto il fondo\n");
        nuovo->prox = NULL;
        bcur->prox = nuovo;
    }

    return t;
}

int main (int argc, char * argv[]) {
    int n;
    Nodo * testa;

    testa = NULL;

    scanf ("%d", &n);
    while ( n != 0 ) {
        testa = inserisci(n, testa);
        stampa(testa);
        scanf ("%d", &n);
    }

    exit(EXIT_SUCCESS);
}
