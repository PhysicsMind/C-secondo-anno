/**
 * Applicazione del modello 'pila' (stack):
 * correttezza sintattica di espressioni con
 * parentesi.
 *
 * La variabile p rappresenta la pila su cui opera il
 * programma; la sua dichiarazione è esterna alle funzioni
 * che compongono il programma; di conseguenza, secondo le
 * regole di visibilità delle variabili, p può essere usata
 * in tutta la parte di codice sorgente che segue la sua
 * dichiarazione.
 *
 * Le funzioni pilavuota, push e pop costituiscono il corredo
 * di operazioni con cui manipolare la pila. La funzione
 * nuovacella è una funzione ausiliaria, ed è legata alla
 * scelta di realizzare la pila per mezzo di una lista
 * concatenata. Un algoritmo che usa la pila come struttura
 * dei dati dovrebbe essere indipendente dalla particolare
 * realizzazione della struttura, e servirsi solo delle
 * operazioni prestabilite (in questo caso, push, pop, e
 * pilavuota).
 */
#include <stdio.h>
#include <stdlib.h>

#include "pila.h"


void chiusura (char c)
{
    char top;

    if ( pilavuota() )
        {printf("Scorretta\n"); exit(EXIT_SUCCESS);}
    else {
        top = pop();
        if ( c == ')' ) c = '(';
        else if (c == ']') c = '[';
        else c = '{';

        if ( c != top )
            {printf("Scorretta\n"); exit(EXIT_SUCCESS);}
    }
}

int main ()
{
    char c;

    c = getchar ();
    while ( c != '*' )
    {
        if ( c == '(' || c == '[' || c == '{' )
            push(c);
        else if ( c == ')' || c == ']' || c == '}' )
            chiusura (c);
        c = getchar();
    }

    if ( pilavuota() )
        printf("Corretta\n");
    else
        printf("Scorretta\n");

    exit (EXIT_SUCCESS);
}
