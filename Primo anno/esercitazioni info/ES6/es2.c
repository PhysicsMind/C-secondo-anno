/* BALDO CRISTIAN			
Scrivete un programma che legge dallo standard input una sequenza di caratteri terminata dal segnale EOF e la riproduce sullo standard output conservando solo i caratteri ’parentesi aperta’ e ’parentesi chiusa’, di qualsiasi tipo (tonde, graffe e quadre). Se, ad esempio, la sequenza in ingresso fosse
{
  while ( v[i] < h[i-1] ) {
    v[f(i)] = sqrt(h[i]);
    i++;
  }
}
il programma dovrebbe stampare la sequenza {([][]){[()]([])}}. 
Il programma deve anche determinare il massimo livello di profondità delle parentesi, misurato come segue: una parentesi al livello esterno ha profondità 0; una parentesi all’interno di una parentesi di profondita` n ha profondita` n+1.
La sequenza dell’esempio ha profondita 3.*/

#include <stdio.h>
#include <stdlib.h>

int riempimento (char *lett){ //FUNZIONE
 // int i=0;
  int k=0;    
  char *puntatore;
  char fine='*';
 
  printf(" indirizzo lett: %i\n", lett);	//stampo l'indirizzo di memoria dove è puntato il puntatore
  puntatore=lett;
/* *lett='a';
  printf(" contenuto dell'indirizzo di lett : %c \n", *lett);
  puntatore=lett+1;
  printf(" indirizzo puntatore: %i\n", puntatore);
   puntatore = malloc (sizeof(char));
   *puntatore ='b';
   printf(" contenuto dell'indirizzo di lett : %c \n", *puntatore);   */
 
   printf("Inserire la stringa di caratteri:\n");
    while (*puntatore != fine){      				//riempio la memoria dinamica
   
    
    
   
    puntatore=lett+k;		       //punto alla cella successiva
    scanf("  %c  \n", &*puntatore);      //metto nella posizione k il carattere nello spazio creato in precedenza
    if (*puntatore ==fine){
       break;
       }
    printf(" indirizzo puntatore: %i\n", puntatore);
     printf(" contenuto dell'indirizzo del puntatore %i : %c \n",k, *puntatore);   
    puntatore = malloc (sizeof(char));    //all'indizzo successivo creo memoria per un carattere
    k=k+1; //k conta quante celle  di memoria ho creato
   }
   
   printf("FINE\n");
   return k;
}

 void stampa ( int n, char *lett){
	char *puntatore;
	puntatore=lett;
	printf(" indirizzo lett: %i\n", lett);
	for (int i=0; i<n; i++){
		puntatore=lett+i;	
		printf(" %c \n", *puntatore);
			}

}	

int main(int argc, char *argv[]) {
	
	char *lett;
	int n=0;


 lett = malloc (sizeof(char));         //creo della memoria di dimensione char alla casella a cui punta  il puntatore lett
 n= riempimento(lett);
 printf(" n= %i ",n);
 
 stampa(n, lett);

exit(EXIT_SUCCESS);
}
