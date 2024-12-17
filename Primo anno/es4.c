/**
 * ESERCIZIO 4*
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int   x1,x2,x3;
    long long int f1,f2,f3;
    long double g1,g2,g3,h1,h2,h3,tf1,tf2,tf3,tg1,tg2,tg3,th1,th2,th3;

    x1=10;    /* assegnazione valori  */
    x2=100;  
    x3=1000000;   

    f1=((x1*x1)-x1)/10;
    f2=((x2*x2)-x2)/10;
    f3=((x3*x3)-x3)/10;
    g1=10*x1*log10(x1);
    g2=10*x2*log10(x2); 
    g3=10*x3*log10(x3);
    h1=2^(x1/50);
    h2=2^(x2/50);
    h3=2^(x3/50);
    tf1=f1/1000000;
    tf2=f2/1000000;
    tf3=f3/1000000;
    tg1=g1/1000000;
    tg2=g2/1000000;
    tg3=g3/1000000;
    th1=h1/1000000;
    th2=h2/1000000;
    th3=h3/1000000;
    printf("%lli\n",f3);
    printf("il tempo per la prima funzione è: %Lf,%Lf,%Lf [s]\n",tf1,tf2,tf3);
    printf("il tempo per la seconda funzione è: %Lf,%Lf,%Lf [s]\n",tg1,tg2,tg3);
    printf("il tempo per la terza funzione è: %Lf,%Lf,%Lf [s]\n",th1,th2,th3);

    exit(EXIT_SUCCESS);
}
