/**
 * commento
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int n,k;
    float s,t;
    
    n=0; //contatore della sommatoria
    printf("inserisci il numero di termini della serie:");
    scanf("%d", &k);
    s=0; //sommatoria iniziale nulla
    
    while (n<=k)
    {
     s=s+((pow(-1,n))/(2*n+1));
     n=n+1;
    }
    
    
    t=4*s;
    printf("il risultato della serie moliplicata per 4 é: %f\n",t); 
    
    
    exit(EXIT_SUCCESS);
}
