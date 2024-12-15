#include <iostream>
#include "complesso.h"

int main(){

	//DICHIARAZIONE 
	double reale=5.;
	complesso c1(3.,5.); 
	complesso c2(1.,8.);
	complesso somma;
	complesso differenza;
	complesso prodotto;
	complesso prodottoreale;
	complesso sommareale;
	
	//STAMPA
	std::cout <<"I due numeri complessi sono:"<< std::endl;
	c1.stampami();
	c2.stampami();
	
	//METODI INTERNI
	c1.modulo();
	c2.fase();
	//METODI TRA COMPLESSI
	std::cout <<"La somma è :"<< std::endl;
	somma = c1 + c2; //chiama la funzione di addizione
	somma.stampami();
	std::cout <<"La differenza è :"<< std::endl;
	differenza = c1 - c2;
	differenza.stampami();
	std::cout <<"Il prodotto è :"<< std::endl;
	prodotto = c1 * c2;
	prodotto.stampami();
	
	/*
	//OPERATORE +=
	c1 += c1 + c2;
	std::cout <<"Il nuovo valore di c1 dato da c1+c2 è :"<< std::endl;
	c1.stampami();
	*/
	
	//METODI TRA COMPLESSI E REALI
	//SOMMA TRA COMPLESSO E REALE
	std::cout <<"La somma tra il primo numero complesso e reale (5) è:"<< std::endl;
	sommareale = c1 + reale;
	sommareale.stampami();
	//PRODOTTO TRA COMPLESSO E REALE
	std::cout <<"Il prodotto tra il primo numero complesso e reale (5) è:"<< std::endl;
	prodottoreale = c1 * reale;
	prodottoreale.stampami();
	


   return 0;
}
