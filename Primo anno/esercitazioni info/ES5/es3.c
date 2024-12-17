/* BALDO CRISTIAN
Questo esercizio ha lo scopo principale di fare conoscenza con alcune funzioni definite nella libreria standard del C. Si tratta, in particolare, di funzioni corrispondenti a comuni funzioni matematiche: esponenziale, logaritmo, seno, coseno, e così via. Per poterle adoperare, si deve includere il file math.h; non basta: il comando di compilazione deve contenere, come ultimo elemento, l’opzione -lm (trattino elle emme). Le seguenti funzioni richiedono tutte un argomento di tipo double e restituiscono un valore dello stesso tipo:
sin(x) seno di x
cos(x) coseno di x
tan(x) tangente di x
exp(x) esponenziale e^x
log(x) logaritmo naturale di x (solo per x > 0)
log10(x) logaritmo in base 10 di x (solo per x > 0)
sqrt(x) radice quadrata di x (solo per x ≥ 0)
ceil(x) il minimo intero non minore di x (ma di tipo double!)
floor(x) il massimo intero non maggiore di x (ma di tipo double!)
fabs(x) il valore assoluto di x
La funzione seguente richiede due argomenti di tipo double e restituisce un valore dello stesso tipo:
pow(x,y) restituisce x^y; genera un errore se x ≤ 0 e y non ha un valore intero, oppure se x = 0 e y ≤ 0
Scrivete un programma che faccia uso di qualcuna delle funzioni qui menzionate.

La libreria definisce altre funzioni; per ulteriori informazioni, potete consultare un manuale di programmazione in C.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  
exit(EXIT_SUCCESS);
}
