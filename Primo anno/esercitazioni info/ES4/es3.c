/* BALDO CRISTIAN
Definite un tipo di dati adeguato a rappresentare un rettangolo nel piano cartesiano, con i lati paralleli agli assi (ragionate su quali informazioni siano sufficienti a determinare univocamente il rettangolo).
Scrivete una funzione che, dato un rettangolo, ne calcola l’area.
Scrivete una funzione che, dati due rettangoli, calcola l’area della regione in cui si sovrappongono (se i due rettangoli non si sovrappongono, o si sovrappongono solo in un punto o in un lato, la funzione deve restituire il valore 0).
Incorporate le due funzioni in un programma che collauda le due funzioni in varie circostanze.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct rettangolo{              //definisco la struttura del rettangolo
	char nome;
	double x;
	double y;
	double base;
	double altezza;
};

struct rettangolo riempirettangolo(struct rettangolo a){
	printf("ASSEGNAMENTO VALORI DEL RETTANGOLO: \n");
	printf("Inserire il nome del triangolo: ");
	scanf(" %c", &a.nome);
	printf("Inserire ascisse del punto in basso a sinistra: ");
	scanf(" %le", &a.x);
	printf("Inserire ordinate del punto in basso a sinistra: ");
	scanf(" %le", &a.y);
	printf("Inserire la lunghezza della base: ");
	scanf(" %le", &a.base);
	printf("Inserire la lunghezza dell'altezza: ");
	scanf(" %le", &a.altezza);
	printf("\n");
	return a;
}

void area (struct rettangolo b){
	double arear;
	arear= (b.base) * (b.altezza);
	printf("L'area del rettangolo '%c' è:  %f\n", b.nome, arear);
}

int main(int argc, char *argv[]) {
   struct rettangolo r1;
  

   r1=riempirettangolo(r1);
   area(r1);

exit(EXIT_SUCCESS);
}
