#include "prova1.h"
#include <cstdlib>
#include <cmath>

//generazione di pdf uniforme

double rand_range (double min, double max)
  {
    return min + (max - min) * rand () / static_cast<double> (RAND_MAX) ;
  } 

// generazione numeri casuali con il metodo dell'inversa della funzione cumulativa
double rand_IFC_Exp (double mu)
{
  double y = rand_range (0., 1.) ;
  double x = -(1/mu) * log (1 - y) ;
  return x ;
}
//genera numeri casuali con pdf di Gauss sommando k esponenziali.
double gauss_TCL (double mean, double sigma, int N)
{
  double number = 0. ;
  double lambda = 1. / (sqrt (N) * sigma) ;
  for (int i = 0 ; i < N ; ++i) number += rand_IFC_Exp(lambda) ;
  number /= N ;
  return mean + number - 1. / lambda ;
}

