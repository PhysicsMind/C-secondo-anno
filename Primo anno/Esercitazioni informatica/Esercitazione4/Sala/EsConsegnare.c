
// 866579 ... ... 

#include <stdlib.h>
#include <stdio.h>

#define N 5
#define M 3

void riempivettore (int l, int vettore[l], char num){
	for(int i=0; i<l; i++){
	printf("Inserire valore %i del vettore %c: ", i, num); 		//l'utente inserisce i valori nei due vettori
	scanf("%i", &vettore[i]);
	}
}

void fondivettori (int vettoreA[], int vettoreB[],int l1, int l2, int vettoreC[l1+l2]){

int k=0;

	for(int i=0; i<l1; i++){		// il primo ciclo for riempe il vettore C con i valori del vettore A, mentre nel secondo ciclo vengono copiati i valori del vettore B in C
	vettoreC[i]=vettoreA[i];
	}

	for(int j=l1; j<l1+l2; j++){
	vettoreC[j]=vettoreB[k];
	k++;
	}



}

void ordinavettore(int l, int vettore[l]){
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

void stampavettore(int l, int vettore[l]){
	for(int i=0; i<l; i++){
	printf("%i ", vettore[i]);
	}
}

int main(){

int vettoreA[N];
int vettoreB[M];
int vettoreC[N+M];
char num1='A'; 	// le tre variabili char vengono utilizzate per avere una stampa più ordinata e leggibile dall'utente
char num2='B';
char num3='C';

riempivettore(N, vettoreA,num1);

riempivettore(M, vettoreB,num2);

fondivettori(vettoreA,vettoreB,N,M, vettoreC);

printf("Il vettore %c ottenuto fondendo i vettori %c e %c e':\n", num3, num1, num2);
stampavettore((N+M),vettoreC);
printf("\n");

ordinavettore((N+M),vettoreC);

printf("Il vettore %c ordinato e':\n", num3);
stampavettore((N+M),vettoreC);
exit(0);

}
