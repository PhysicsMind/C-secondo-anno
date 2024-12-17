/* 			
Scrivete un programma che, leggendo una serie di numeri, costruisce una lista concatenata doppia, inserendo ogni volta in testa il nuovo elemento; 
il programma deve richiedere dinamicamente lo spazio di memoria per il nuovo elemento prima di inserirlo. 
Supponete che la fase di lettura termini quando il programma legge il valore 0. 
Conclusa la fase di lettura e costruzione della lista, il programma attraversa la lista per calcolare la somma dei valori e determinare il valore minimo.
Aggiungete una funzione che percorre la lista ed elimina il primo elemento divisibile per 3.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo Nodo; //evito tutte le volte di scrivere 'struct nodo' , basta scrivere Nodo

struct nodo{		//creo lo struct nodo con 3 campi: valore intero e due puntatori
	int valore;
	Nodo *prox; //devo conservare la posizione del nodo successivo
	Nodo *prev; // Nodo *.... indica un puntatore a una struct nodo, al nodo precedente
};

void stampa (Nodo *current){	//STAMPARE LA CATENA,  gli passo il puntatore corrente della catena, all'inizio si trova  in testa
  printf("Gli elementi 'numeri interi' della catena sono:\n");
  while(current != NULL){			//finchè il puntatore non punta ad uno struct vuoto allora stampa 			
  	printf(" %d\n", current->valore);	//stampa il campo "valore" dello struct a cui punta il puntatore corrente 
  	current = current->prox;		//assegna al puntatore corrente l'indirizzo del puntatore prox, quindi del prossimo struct
  }
  return;
}

Nodo *creazione (int n, Nodo *testa){		//inizializzo la nuova testa,   CREAZIONE DELLA CATENA, passo la "vecchia testa"
	Nodo *nuovo;				//dichiaro un puntatore a un record chiamato nuovo
	nuovo  = (Nodo *) malloc(sizeof(Nodo)); 	//al puntatore faccio puntare l'indirizzo dello spazio di un nuovo record
	if (nuovo == NULL){ 			//se l'indirizzo è nullo, esci; errore
	   exit(EXIT_FAILURE);
	}
	
	nuovo->valore = n;			//assegna al campo "valore" :'n' nello struct puntato da nuovo
	
	if(testa==NULL){			//se il valore di testa è nullo allora 	
	   nuovo->prox = NULL; }        //assegno al puntatore prox il valore nullo  (testa diveterà il puntatore allo struct successivo)
	else {					//se il valore di testa NON è nullo allora
	   nuovo->prox = testa;	//assegno a nel campo "prox" di " nuovo" l'indirizzo del successivo, quindi testa
	   testa->prev = nuovo;	//assegno al campo "prev" di "testa" l'indirizzo del precendente, quindi di nuovo
	}
	return nuovo;			//return l'indirizzo di nuovo, diventerà la nuova testa
}

int somma(Nodo *current){		//FUNZIONE SOMMA DEGLI ELEMENTI valore DELLA CATENA partendo dall'inizio (current vale testa)
	int somma=0; 			//azzero la sommatoria
	while(current != NULL){	//finchè il puntatore non diventa nullo aggiorno la somma
	  somma = somma + current->valore;
	  current = current->prox;	//mi sposto nella catena allo struct successivo
	}
	return somma;
}

int minimo (Nodo *current){			//FUNZIONE TROVA MINIMO NELLA CATENA, passo la testa della catena
	int minimo;
	minimo=current->valore;\		//assegno al minimo il valore del primo struct
	while (current != NULL){
		current = current->prox;       //avanzo col puntatore allo struct successivo
		if (current == NULL){		//se il current successivo è nullo allora si arresta il ciclo while
			break;}
	    	if(current->valore < minimo){	//se il valore è minore del minimo, allora è il nuovo minimo
	       	 minimo=current->valore;
	     	}
	     	current= current->prox;	//avanzo negli struct tramite il puntatore prox
	}	
	return minimo;
}

Nodo *ghigliottina(Nodo *testa){		//ELIMINO IL PRIMO DIVISORE DI 3;
   Nodo *current = testa;			//assegno al puntatore current il puntatore testa, per azzerare l'indice
   
   while (current != NULL){
      
      if(current->valore %3 == 0){		//se lo struct a cui punta current ha l'intero divisibile per 3...
           if (current->prev == NULL){
             current->prox->prev = NULL;
             testa = current->prox; //la testa cambia solo se essa è divisibile per 3
             free(current);
             current = NULL;
           }
           else{
     	     Nodo *prossimo = current->prox;
             Nodo *precedente = current->prev;
        
   	     current->prox->prev = precedente;
      	     current->prev->prox = prossimo;
             free(current);
             current = NULL;
          }
       }
      else{
         current = current->prox;
      }
   }
   return testa;
}
   
            
int main(int argc, char *argv[]) {

  int n;
  Nodo *testa;		//puntatore testa ad uno struct (inizio della catena)
  testa = NULL;	//puntatore inizialmente nullo 
  Nodo *current;	//puntatore dinamico, all'indirizzo corrente
//  Nodo *new_testa;	//puntatore alla nuova testa
  
  scanf("%d", &n);
  while( n != 0 ){			//creo la catena finchè non inserisco '0'
  	testa = creazione(n,testa);    //assegno alla testa l'indirizzo della nuova testa: "nuovo"	
  	//stampa(testa)
  	scanf(" %d", &n);     		//prendo dalla tastiera il numero n, mi serve nella funzione inserisci
  }
  
  current=testa;			//assegno al puntatore corrente il valore di testa (inizio della catena)
  stampa(current);		//STAMPA gli elementi della catena, conoscendo il puntatore di inizio della catena (current=testa)
  
 
  int s, min;			//trovo somma e minimo della catena e li stampo
  s= somma(current);
  min= minimo(testa);
  printf("La somma è: %.2i e il minimo è: %.2i\n", s, min);
  
 /* new_testa= ghigliottina(testa);
  
  current= new_testa;
  stampa(current);
  */
    exit(EXIT_SUCCESS);
}
