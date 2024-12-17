/* BALDO CRISTIAN
 Definite un tipo (record) adeguato a rappresentare i punti del piano cartesiano; la rappresentazione deve comprendere anche una lettera, che interpretiamo come nome simbolico di un punto.
Scrivete una funzione che riceve due punti come argomenti e calcola la loro distanza. 
Scrivete una funzione che riceve un punto come argomento e calcola la norma del vettore corrispondente.
Definite un tipo (record) per rappresentare circonferenze nel piano cartesiano. Quali informazioni sono sufficienti per determinare univocamente una circonferenza? Scrivete una funzione che riceve, come argomenti, un punto e una circonferenza, e stabilisce se il punto e interno alla circonferenza, esterno, oppure sulla circonferenza. 
Scrivete una funzione che riceve, come argomenti, due circonferenze, e stabilisce se la seconda e interna alla prima.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punto {     //definisco il record punto 
 char nome;
 double x;
 double y;
 };
 
struct circonferenza {   //definisco il record circonferenza
 char nomec;
 double xc;
 double yc;
 double raggio;
 };

struct punto riempipunto(struct punto r){                       //riempio i campi dei record
     printf("Inserire Carattere identificativo del punto:  ");
     scanf(" %c", &r.nome);
     printf("Inserire Ascisse del punto:  ");
     scanf("%le", &r.x);
     printf("Inserire Ordinate del punto:  ");
     scanf("%le", &r.y);
     printf("\n");
     return r;
}

struct circonferenza riempicirc(struct circonferenza c){                       //riempio i campi dei record
     printf("Inserire il nome della circonferenza:  ");
     scanf(" %c", &c.nomec);
     printf("Inserire Ascisse del centro:  ");
     scanf("%le", &c.xc);
     printf("Inserire Ordinate del centro:  ");
     scanf("%le", &c.yc);
     printf("Inserire Raggio della circonferenza:  ");
     scanf("%le", &c.raggio);
     printf("\n");
     return c;
}

void distanza(struct punto a,struct punto b){                       //calcolo la distanza
    double dist;
    dist= sqrt ((b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x));
    printf("La distanza tra il punto '%c' e il punto '%c' è: %le \n",a.nome, b.nome, dist);
}

void norma(struct punto a){
     double norma;
     norma=sqrt((a.y*a.y)+(a.x*a.x));
     printf("La norma del vettore corrispondente al punto'%c' è: %le \n", a.nome,norma);
}

void confrontopuntocirc(struct punto a, struct circonferenza d){
     double dist;
     dist= sqrt ((a.y-d.yc)*(a.y-d.yc)+(a.x-d.xc)*(a.x-d.xc));
     if (dist< d.raggio){
        printf("Il punto '%c' si trova INTERNO alla circonferenza \n", a.nome);}
     if (dist == d.raggio){
        printf("Il punto '%c' si trova SULLA circonferenza \n", a.nome);}
     if (dist > d.raggio){
        printf("Il punto '%c' si trova ESTERNO alla circonferenza \n", a.nome);}
}

void confrontofracirc(struct circonferenza n, struct circonferenza m){
     if( n.raggio >= (sqrt((m.yc-n.yc)*(m.yc-n.yc)+(m.xc-n.xc)*(m.xc-n.xc))+m.raggio)){
       printf("La circonferenza '%c' è INTERNA alla circonferenza '%c'\n",m.nomec, n.nomec);}
     else{
       printf("La circonferenza '%c' è ESTERNA alla circonferenza '%c'\n",m.nomec, n.nomec);}
}

int main(int argc, char *argv[]) {
  struct punto punto1;
  struct punto punto2;
  struct circonferenza c1;
  struct circonferenza c2;
  char scelta;
  
  punto1=riempipunto(punto1);    
  
 
  
  c1=riempicirc(c1);
  

  do
  {
  printf("\t\t-----------------------------------\n\n");
	printf("\t\tDigita 'a' per calcolare la norma del punto\n\t\tDigita 'b' per calcolare la distanza fra 2 punti\n\t\tDigita 'c' per confrontare la circonferenza con il punto\n\t\tDigita 'd' per confrontare due circonferenze\n\t\tDigita '*' per uscire\n\n");
	printf("\t\t-----------------------------------\n");
	scanf(" %c",&scelta);
	switch (scelta)
	{
		case 'a':
			norma(punto1);
			break;
		case 'b':
		        printf("Definire il secondo punto:\n");
			punto2=riempipunto(punto2);
			distanza(punto1,punto2); 
			break;
		case 'c':
			 confrontopuntocirc(punto1,c1);
			 break;
		case 'd':
			 c2=riempicirc(c2);
                        confrontofracirc(c1,c2);
                        break;
		default:
			printf("\nProgramma terminato\n\n");
			break;
	}
}
while(scelta!='*');

exit(EXIT_SUCCESS);
}
