#include <iostream>

/*
> c++ -o es1 es1.cpp
> ./es1
*/

int main (int arcg, char ** argv)
  {
    int variabile1 = 0 ;
    int variabile2;
    std::cout << "valore1   : " << variabile1 << std::endl ;
    std::cout << "valore2   : " << variabile2 << std::endl ;
    int *puntatore = &variabile2;
    *puntatore = variabile1;
    std::cout << "valore1   : " << variabile1 << std::endl ;
    std::cout << "valore2   : " << variabile2 << std::endl ;

    
    return 0 ;
  }

