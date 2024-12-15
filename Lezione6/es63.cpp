//Fattoriale con funzione ricorsiva
// c++ -o es63 es63.cpp

#include <iostream>
#include <math.h>

int fattoriale_ricorsivo (
  int n //fattoriale
)
{
  if (n == 1) return 1 ;
  else {
  	int m =fattoriale_ricorsivo (n-1);
  	return m*n ;
  }
}  

int main(){
	
	int nfattoriale= 5; //numero di cui fare il fattoriale
	int risultato;		//risultato fattoriale
	risultato= fattoriale_ricorsivo (nfattoriale);
	std::cout << risultato << std::endl;
	
return 0;
}
