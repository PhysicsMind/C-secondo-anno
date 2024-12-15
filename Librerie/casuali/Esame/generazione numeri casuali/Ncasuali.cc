#include "Ncasuali.h"
#include <cstdlib>
#include <cmath>

//generazione di pdf uniforme

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 
//FUNZIONI per usare il metodo TAC

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



//NUMERI CASUALI CON METODO FUNZIONE INVERSA
//generazione numeri con andamento esponenziale 
 float rand_exp (double t_zero) //-1/t0*e^-t/t0
{
  return -1. * log (1 - rand_range (0., 1.)) * t_zero ;
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
// generazione numeri casuali esponenziali con il metodo dell'inversa della funzione cumulativa
double rand_IFC_Exp (double mu) //mu*e^-mu*x
{
  double y = rand_range (0., 1.) ;
  double x = -(1/mu) * log (1 - y) ;
  return x ;
} 
//generazione di pdf qualsiasi con il metodo try-and-catch
float rand_TAC (float f (float), float xMin, float xMax, float yMax)
  {
    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;
    return x ; 
  }//prende in ingresso la funzione densità di prob. che devono avere i numeri generati, l'intervallo di x in cui generarli e il massimo stimato della pdf (ymax).

  
//generazione di pdf con il metodo del teorema centrale del limite

float rand_TCL (float xMin, float xMax, int N = 10)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }//genera numeri casuali con pdf di Gauss.



//generazione numeri casuali con pdf gauss partendo da esponenziali data sigma e mu
double Exp_gauss_TCL (double mean, double sigma, int N)
{
  double number = 0. ;
  double lambda = 1. / (sqrt (N) * sigma) ;
  for (int i = 0 ; i < N ; ++i) number += inv_exp (lambda) ;
  number /= N ;
  return mean + number - 1. / lambda ;
}
//generazione numeri casuali con pdf gauss partendo da distribuzione uniforme data sigma e mu
double rand_TCL_gaus (double mean, double sigma, int N) 
  {
    double delta = sqrt (3 * N) * sigma ;
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += random_range (mean - delta, mean + delta) ;
    y /= N ;
    return y ;
  }

