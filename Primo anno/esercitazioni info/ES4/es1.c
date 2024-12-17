/* BALDO CRISTIAN
1 Scrivete un programma che, servendosi delle funzioni getchar e putchar,
legge una sequenza di caratteri dallo standard input, arrestandosi quando il
carattere e l’asterisco (*), e stampa la stessa sequenza sostituendo ogni ‘a’ con
una ‘e’. Il programma non deve trattenere in memoria la sequenza (modificate
il programma filtro.c).*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  printf("inserire la sequenza di caratteri e (*) per terminare:  ");

	int c=' ';
	char fine='*';
	char e='e', a='a';

	//c = getchar();
   printf("\n");
        do
	 {
	       if (c == a){
	        c=e;
		}
		putchar(c);
	        c = getchar();
	        printf("\n");
	}
	while ( c != fine );
	

exit(EXIT_SUCCESS);
}
