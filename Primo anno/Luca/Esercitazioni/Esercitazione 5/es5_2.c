#include <stdio.h>
#include <stdlib.h>

#include <math.h>

struct coordinate {
    double x, y ;
    char nome ;
};

typedef struct coordinate coo;

void stampa_struct (coo pt) {
    printf("     COORDINATE PUNTO %c\n", pt.nome) ;
    printf("x = \t %f\n", pt.x);
    printf("y = \t %f\n", pt.y);
}

/*void riempi_struct (coo pt) {
    printf("nome del punto\t");
    scanf("%c", &pt.nome) ;
    printf("inserisci ascissa\t") ;
    scanf("%lf", &pt.x) ;
    printf("inserisci ordinata\t") ;
    scanf("%lf", &pt.y) ;
}*/

double distanza (coo pt1, coo pt2) {
    return sqrt(pow((pt1.x - pt2.x), 2) + pow((pt1.y - pt2.y), 2)) ;
}

struct circonferenza {
    coo centro ;
    double raggio ;
};
typedef struct circonferenza circ;

void dentro (circ c, coo pt) {
    if (distanza(c.centro, pt) > c.raggio) {
        printf("il punto è fuori dalla circonferenza\n");
    } else {
        printf("il punto è dentro alla circonferenza\n");
    }
}

int main () {
    
    /*      prova con puntatori
    coo * punti = malloc (2*sizeof(coo)) ;
    punti[0].nome = 'c' ;
    punti[0].x = 0. ;
    punti[0].y = 0. ;
    printf("primo punto dinamico: %c %lf %lf\n", punti[0].nome, punti[0].x, punti[0].y) ;
    */
    
    coo pt1 ;
    coo pt2 ;
    
    circ c1 ;
    c1.raggio = 1. ;
    
    printf("nome del primo punto\t");
    scanf("%c", &pt1.nome) ;
    printf("inserisci ascissa\t") ;
    scanf("%lf", &pt1.x) ;
    printf("inserisci ordinata\t") ;
    scanf("%lf", &pt1.y) ;
    printf("\n");

    printf("nome del secondo punto ");
    scanf("%c", &pt2.nome) ;
    printf("\n");
    printf("inserisci ascissa\t") ;
    scanf("%lf", &pt2.x) ;
    printf("inserisci ordinata\t") ;
    scanf("%lf", &pt2.y) ;
    printf("\n");
    
    //riempi_struct(pt1);
    stampa_struct(pt1) ;
    stampa_struct(pt2);
    printf("la distanza tra i punti è: %lf\n", distanza(pt1, pt2)) ;
    
    c1.centro = pt1 ;
    // si può anche fare una spcie di "impilamento" c1.centro.x = 0 ;
    dentro(c1, pt2) ;
    
    exit (EXIT_SUCCESS) ;
}
