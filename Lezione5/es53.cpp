//Funzione somma con template

// c++ -o es53 somma.h SimpleArray.h complesso.cc es53.cpp

#include <iostream>
#include <math.h>
#include "somma.h"
#include "complesso.h"
#include "SimpleArray.h"

int main(){
	
	complesso c1 (1.,1.);
	complesso c2 (3.,2.);
	SimpleArray<complesso> contenitore (10) ;
	
 	std::cout<< "La somma è : "  <<std::endl;
 	somma(c1, c2).stampami();
 	contenitore[1]=c1;

 return 0;
}
