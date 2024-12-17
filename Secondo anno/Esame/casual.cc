//CRISTIAN BALDO 866593
#include "casual.h"
#include <cstdlib>
#include <cmath>

//Generatore numero compreso fra min e max
double random_range (double min, double max)  
{
  return min + (max - min) * rand () / static_cast<double> (RAND_MAX);
}

//Funzione Pdf Triangolare
float ftriangolare (float x){   
  return (2./9.)*x ; 
}

//ALGORITMO TRY AND CATCH
float rand_TAC (float f (float), float xMin, float xMax, float yMax){

    float x = 0. ;
    float y = 0. ; 
    do {
      x = random_range (xMin, xMax) ; 
      y = random_range (0, yMax) ;
    } while (y > f (x)) ;   //Ripetere la generazione fino a che la condizione y < f(x) non è soddisfatta
    return x ; 
}


