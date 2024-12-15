//Funzione somma con template

// c++ -o es52 somma.h complessi.cc es52.cpp

#include <iostream>
#include <math.h>
#include "somma.h"
#include "complesso.h"

int main(){
	
	complesso c1 (1.,1.);
	complesso c2 (3.,2.);
	
 	std::cout<< "La somma è : "  <<std::endl;
 	somma(c1, c2).stampami();
	

 return 0;
}
