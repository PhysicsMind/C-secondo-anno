#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int primo (int n) {
    if (n == 1) {
        //printf("è primo\n") ;
        return 1 ;
    }
    int i = 2 ;
    while (i <= sqrt(n)) {
        if (n%i == 0) {
            //printf("il numero non è primo\n") ;
            return 0 ;
        }
        i = i + 1 ;
    }
    //printf("il numero è primo\n");
    return 1 ;
}

void primo_ric (int n) {
    for (int i = 1; i <= n; i++) {
        if (primo(i) == 1) {
            printf("%d\n", i) ;
        }
    }
}

int main ()
{
    int m ;
    
    printf("inserisci un numero intero") ;
    scanf("%d", &m) ;

    primo_ric(m) ;
    
    exit (EXIT_SUCCESS);
}
