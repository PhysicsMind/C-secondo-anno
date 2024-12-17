/* BALDO CRISTIAN			
Modificate il programma dell’esercizio 2 in modo che legga la sequenza da un file di nome testo.c, e stampi la sequenza risultante in un file di nome p-testo.c.
Modificate ulteriormente il programma in modo che possa ricevere i nomi dei due file sulla riga di comando. 
Il programma deve leggere dallo standard input e stampare sullo standard output se, all’avvio dell’esecuzione, non sono presenti tutti e due gli argomenti.*/

#include <stdio.h>
#include <stdlib.h>

/* int riempimento (char *lett){ //FUNZIONE
 // int i=0;
  int k=0;    
  char *puntatore;
  char fine='*';
 
  printf(" indirizzo lett: %i\n", lett);	//stampo l'indirizzo di memoria dove è puntato il puntatore
  puntatore=lett;
 
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
}  */

/* void stampa ( int n, char *lett){
	char *puntatore;
	puntatore=lett;
	printf(" indirizzo lett: %i\n", lett);
	for (int i=0; i<n; i++){
		puntatore=lett+i;	
		printf(" %c \n", *puntatore);
			}
}	
*/
int main(int argc, char *argv[]) {
	
	
 
    FILE *testo;
    FILE *copia;
    FILE *parentesi;
    char x, y;

    testo = fopen("testo.c", "r");
    copia = fopen("copia.txt", "w");
    parentesi = fopen("parentesi.txt", "w");
    if ( testo == NULL || copia == NULL || parentesi == NULL ) {
        /* char *lett;
	int n=0;
	lett = malloc (sizeof(char));         //creo della memoria di dimensione char alla casella a cui punta  il puntatore lett
 	n= riempimento(lett);
 	printf(" n= %i ",n);
	stampa(n, lett);  */
        printf("Errore\n");                         //sostituisci con programma 2
        exit(EXIT_FAILURE);
    }

    while (( x =  getc(testo)) != EOF ){     //copia il file testo in "copia"
    	putc (x , copia);
    }
    
    while (( y = getc(testo)) != EOF ){     //copia solo le parentesi del testo in "parentesi"
       printf(" %c \n", y);
    	if (y=="("|| y==')'|| y=='[' || y==']' || y=='{'||y=='}'){
    	putc (y , copia);
    	}
    }
    
   /* fscanf(dati, "%d", &x);
    fprintf(risultati, "%d\n", 2*x);
    fscanf(dati, "%d", &x);
    fprintf(risultati, "%d\n", 2*x);  */

    fclose(testo);
    fclose(copia);
    fclose(parentesi);


    exit(EXIT_SUCCESS);
}

