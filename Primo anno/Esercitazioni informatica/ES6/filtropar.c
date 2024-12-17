/**
 * Stampa solo i caratteri 'parentesi' nel testo che riceve
 * in input e il livello di profondità delle parentesi.
 * ATTENZIONE: non funziona correttamente se ci sono simboli
 * di parentesi usati come costanti.
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
    int c, prof, maxp; // maxp: massima profondità

    maxp = -1; prof = -1;
    while ( (c=getchar()) != EOF ) {
        if ( c == '(' || c == '[' || c == '{' ) {
            putchar(c);
            prof++;
            if ( maxp < prof ) maxp = prof;
        }
        else if ( c == ')' || c == ']' || c == '}' ) {
            putchar(c);
            prof--;
        }
    }
    printf("\n%d\n", maxp);

    exit(EXIT_SUCCESS);
}
