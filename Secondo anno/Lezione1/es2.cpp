/*Dichiarare un puntatore e poi cercare di assegnargli direttamente un valore numerico. Cosa succede? Perché?*/
#include <iostream>

/*
> c++ -o es2 es2.cpp
> ./es2
*/

int main (int arcg, char ** argv)
  {
    int *puntatore;
    puntatore = 10;
    std::cout << "il puntatore vale   : " << puntatore << std::endl ;
    
    return 0 ;
  }

