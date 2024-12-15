//Utilizzare new e delete per creare e distruggere una variabile double ed un array di double.

#include <iostream>

/*
> c++ -o es2 es2.cpp
> ./es2
*/

int main (int arcg, char ** argv)
  {
    double array[10];
    double variabile = 10.7;
    double *arr = new double(10); arr=array;
    double *var = new double(1); *var =variabile;
    
     std::cout << "la variabile vale   : " << *var << std::endl ;
    delete [] arr;
    delete [] var;
    
    return 0 ;
  }

