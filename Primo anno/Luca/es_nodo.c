/*Scrivete un programma che, leggendo una serie di numeri, costruisce una concatenata doppia, inserendo ogni volta in testa il nuovo elemento; il programma deve richiedere dinamicamente lo spazio di memoria per il nuovo elemento prima di inserirlo. Supponete che la fase di lettura termini quando il programma legge il valore 0. Conclusa la fase di lettura e costruzione della lista, il programma attraversa la lista per calcolare la somma dei valori e determinare il valore minimo. Aggiungete una funzione che percorre la lista ed elimina il primo elemento divisibile per 3.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Nodo ;
struct nodo {
    int valore ;
    Nodo * prox ;
    Nodo * pre ;
};

Nodo * creazione (int n, Nodo * testa) {
    Nodo * nuovo ;
    nuovo = (Nodo*) malloc (sizeof(Nodo)) ;            //(Nodo *) forza la memoria dinamica al tipo del puntatore. sto puntando l'indirizzo dello spazio che ho creato che avrà dimensioni di Nodo
    if (nuovo == NULL) {                               //se l'indirizzo è nullo, esci; errore
        exit(EXIT_FAILURE);
    }
    nuovo -> valore = n ;                              // sto assegnando al campo "valore" dello struct puntato da "nuovo"
    if (testa == NULL) {
        nuovo -> pre = NULL ;                         //assegno al puntatore prox il valore nullo  (testa diveterà il puntatore allo struct successivo)
    } else {
        nuovo -> pre = testa ;                        //assegno a nel campo "prox" di " nuovo" l'indirizzo del successivo, quindi testa
        testa -> prox = nuovo ;                       //assegno al campo "prev" di "testa" l'indirizzo del precendente, quindi di nuovo
    }
    
    return nuovo ;                                     //return l'indirizzo di nuovo, diventerà la nuova testa
}


void stampa (Nodo * current) {                         //STAMPARE LA CATENA, gli passo il puntatore corrente della catena, all'inizio si trova in testa
    printf("gli elementi della catena sono\n") ;
    while (current != NULL) {
        printf("%d\n", current -> valore) ;
        current = current -> pre ;                      // stampa a ritroso
    }
    return ;
}


void somma (Nodo * current) {
    int sum = 0;
    while (current != NULL) {
        sum = sum + (current -> valore) ;
        current = current -> pre ;                      // stampa a ritroso
    }
    printf ("somma:\t %d\n", sum) ;
    return ;
}


void minimo (Nodo * current) {
    int min = (current -> valore);
    while (current != NULL) {
        if ((current -> valore) < min) {
            min = (current -> valore) ;
        }
        current = current -> pre ;
    }
    printf("minimo catena: %d\n", min) ;
    return ;
}



void ghigliottina (Nodo * current) {                        //elimina il primo nodo divisibile per tre
    //int min = (current -> valore) ;
    Nodo * cella_incriminata ;
    while (current != NULL) {
        /*if ((current -> valore) < min) {
            min = (current -> valore) ;
        }*/
        if (((current -> valore)%3) == 0) {
            cella_incriminata = current ;
            printf("il numero %d\t è divisibile per 3\n", cella_incriminata -> valore) ;
        }
        current = current -> pre ;
    }
    if (cella_incriminata -> pre == NULL) {                 // se il nodo è il primo
        current = cella_incriminata -> prox ;
        current -> pre = NULL ;
    } else {
        current = cella_incriminata -> pre ;
        current -> prox = cella_incriminata -> prox ;
        current = current -> prox ;
        current -> pre = cella_incriminata -> pre ;
    }
    //printf("minimo catena: %d\n", min) ;
    return ;
}



int main (int argc, char * argv[]) {
    int n = 1 ;
    
    Nodo * testa ;              //puntatore di tipo nodo che punta alla testa della rete
    testa = NULL ;
    Nodo * current ;            //puntatore dinamico all'indirizzo corrente
    
    while (n != 0) {
        printf("inserisci il valore intero:\t") ;
        scanf("%d", &n) ;
        testa = creazione (n, testa) ;              // assegno a testa l'indirizzo della nuova testa
    }
    current = testa ;
    stampa(current) ;
    
    somma(current) ;
    minimo(current) ;
    
    ghigliottina(current) ;
    stampa(current) ;
    
    exit (EXIT_SUCCESS) ;
}
