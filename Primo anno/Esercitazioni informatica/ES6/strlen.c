#include <stdio.h>
#include <stdlib.h>

int strln (char * s) {
    int i = 0;
    while ( s[i] != '\0' ) {
        i = i + 1;
    }

    return i;
}

int main (int argc, char *argv[]) {
    char p[] = "Una frase";
    printf("%d\n", strln(p));
    printf("%d\n", strln(p+2));

    char q[] = "B\nlu";
    printf("%d\n", strln(q));

    char r[] = "B\\nlu";
    printf("%d\n", strln(r));

    char *s;
    s = (char *) malloc (12*sizeof(char));
    s[0] = 'F';
    s[1] = 'l';
    s[2] = 'o';
    s[3] = 'p';
    s[4] = '\0';
    printf("%d\n", strln(s));

    // Non si può scrivere p = "Un'altra frase";

    exit(EXIT_SUCCESS);
}
