#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int c;
    int max_depth = 0;
    int current_depth = 0;
    
    // Leggiamo i caratteri uno alla volta
    while ((c = getchar()) != EOF) {
        if (c == '(' || c == '[' || c == '{') {
            // Stampa la parentesi di apertura
            putchar(c);
            // Incrementa la profondità corrente
            current_depth = current_depth + 1;
            // Aggiorna la profondità massima se necessario
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        } else if (c == ')' || c == ']' || c == '}') {
            // Stampa la parentesi di chiusura
            putchar(c);
            // Decrementa la profondità corrente
            current_depth = current_depth - 1;
        }
    }

    // Stampa la profondità massima
    printf("\nMassima profondità delle parentesi: %d\n", max_depth);

    exit (EXIT_SUCCESS);
}

