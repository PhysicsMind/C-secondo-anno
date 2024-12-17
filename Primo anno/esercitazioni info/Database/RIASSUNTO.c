//RIASSUNTO
#include <stdio.h>
#include <stdlib.h>

#define N 10 //definisco la variabile N con valore 10 non modificabile

int main (int argc, char *argv[]) {       //funzione main
{
    exit(EXIT_SUCCESS);
}

//CICLO FOR
for(i=0; i<N ; i++){
     }
     
     
     
//FUNZIONE SWITCH
do
{
printf("\t\t-----------------------------------\n\n");
	printf("\t\tDigita 'a' per stampare il vettore\n\t\tDigita 'b' per fare uno shift left\n\t\tDigita 'c' per fare uno shift right\n\t\tDigita qualsiasi altro carattere per uscire\n\n");
	printf("\t\t-----------------------------------\n");
	scanf(" %c",&scelta);
	switch (scelta)
	{
		case 'b':
			shl(vet,N);
		case 'a':
			print(vet,N);
			break;
		case 'c':
			shr(vet,N);
		default:
			printf("\nProgramma terminato\n\n");
			break;
	}
}
while(scelta!='*');
