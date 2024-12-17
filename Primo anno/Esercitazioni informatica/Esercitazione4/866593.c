// 866593 866579 866777      BALDO CRISTIAN-SALA LUCA-DECLICH FRANCESCO
/* Dato un vettore A di lunghezza N e un vettore B di lunghezza M, scrivere un programma che legga i valori dello 
 * standard input, li inserisca in ordine crescente nei due vettori e li fonda in ordine crescente in un vettore C.
 *In seguito stampare il contenuto finale del vettore. */

#include <stdlib.h>
#include <stdio.h>

#define N 5
#define M 3

void riempivettore (int l, int vettore[l], char num){       //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite standard imput
	printf("Inserire valore %i del vettore %c: ", i, num); 		
	scanf("%i", &vettore[i]);
	}
}

void fondivettori (int vettoreA[], int vettoreB[],int l1, int l2, int vettoreC[l1+l2]){ //funzione di fusione di due vettori
   int k=0;

	for(int i=0; i<l1; i++){     // il primo ciclo for riempe il vettore C con i valori del vettore A
	vettoreC[i]=vettoreA[i];
	}

	for(int j=l1; j<l1+l2; j++){  //il secondo ciclo copia i valori del vettore B in C
	vettoreC[j]=vettoreB[k];
	k++;
	}
}

void ordinavettore(int l, int vettore[l]){   //funzione di ordinamento degli elementi di un vettore
    int min, temp;

	for(int i=0; i<l; i++){   		// array di ordinamento con due cicli for annidati, nel secondo for ogni volta che viene trovato un valore minore rispetto a quello fissato nel primo ciclo for vengono scambiati,
	min=vettore[i];				// tramite una variabile ausiliaria
	temp=vettore[i];
		for(int cont=i;cont<l;cont++){
			if(vettore[cont]<vettore[i]){
			min=vettore[cont];
			temp=vettore[i];
			vettore[i]=min;
			vettore[cont]=temp;
			}
		}	
	}
}

void stampavettore(int l, int vettore[l]){    //funzione per stampare i valori di un vettore 
	for(int i=0; i<l; i++){               //ciclo di stampa di ogni elemento
	printf("%i ", vettore[i]);
	}
}

int main(){         //funzione principale

int vettoreA[N];    //dichiarazione vettori
int vettoreB[M];
int vettoreC[N+M];
char num1='A';      // le tre variabili char vengono utilizzate per avere una stampa più ordinata e leggibile dall'utente
char num2='B';
char num3='C';

printf("Fusione vettori A+B e ordinamento in ordine crescente:\n"); //descrizione programma
riempivettore(N, vettoreA,num1);   //riempimento dei vettori A e B
riempivettore(M, vettoreB,num2);

fondivettori(vettoreA,vettoreB,N,M, vettoreC);   //fusione A+B nel vettore C

ordinavettore((N+M),vettoreC);    //ordino il vettore C

printf("Il vettore %c ordinato e':\n", num3);   //stampa elementi vettore C ordinati
stampavettore((N+M),vettoreC);
printf("\n");
exit(0);

}
