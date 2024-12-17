#include "casual.h"
#include <cstdlib>
#include <cmath>

double random_range (double min, double max)  //Numero fra min e max
{
  return min + (max - min) * rand () / static_cast<double> (RAND_MAX);
}

//FUNZIONI per TAC

float fgaus (float x){		//Distribuzione Gaussiana con Sigma=1 e non normalizzata
    return exp (-0.5 * x * x) ; 
}

double fgausTAC (double x, double mean, double sigma) 
  {
    return exp (-0.5 * (x - mean) * (x - mean) / (sigma * sigma)) ; 
  }

float fpois (float x){
    /*	Distribuzione poissoniana con mu=3
    */
    float fact = std::tgamma(x+1);	//fattoriale di x tramite la GAMMA FUNCTION
    return exp(-3)*pow(3, x)/fact; 	//espressione Poissoniana
}



//CASUALI FUNZIONE INVERSA

float rand_exp (double t_zero)
{
  return -1. * log (1 - random_range (0., 1.)) * t_zero ;
}

float rand_pois (double media) 
{
  double t_tot = rand_exp (1.) ;
  int N_evt = 0 ;
  while (t_tot < media)
    {
      ++N_evt ;
      t_tot += rand_exp (1.) ;
    }
  return N_evt ;
}


//ALGORITMO TRY AND CATCH
float rand_TAC (float f (float), float xMin, float xMax, float yMax){

    float x = 0. ;
    float y = 0. ; 
    do {
      x = random_range (xMin, xMax) ; //genero direttamente i punti nel grafico nel range [min,max] con altezza y data dalla pdf
      y = random_range (0, yMax) ;
    } while (y > f (x)) ;   //Ripetere la generazione fino a che la condizione y < f(x) non è soddisfatta
    return x ; 
}

//RANDOM TAC GAUSS
double rand_TAC_gaus (double mean, double sigma)
  {
    double x = 0. ;
    double y = 0. ; 
    do {
      x = random_range (mean - 4 * sigma, mean + 4 * sigma) ;
      y = random_range (0, fgausTAC (mean, mean, sigma)) ;
    } while (y > fgausTAC (x, mean, sigma)) ;
    return x ; 
  }

//TEOREMA CENTRALE LIMITE
double rand_TCL_gaus (double mean, double sigma, int N) 
  {
    double delta = sqrt (3 * N) * sigma ;
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += random_range (mean - delta, mean + delta) ;
    y /= N ;
    return y ;
  }

