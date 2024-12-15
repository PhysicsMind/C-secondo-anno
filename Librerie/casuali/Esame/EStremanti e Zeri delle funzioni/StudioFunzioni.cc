#include "StudioFunzioni.h"
#include <cmath>
#include <iostream>

using namespace std ;

double esponenziale (double x, double tau)
{
   if (tau == 0.) return 1. ;
   return exp (-1. * x / tau) / tau ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double loglikelihood (
  const vector<double> & data, 
  double param
)
{
  double result = 0. ; 
  for (int i = 0 ; i < data.size () ; ++i) result += log (esponenziale (data.at (i), param)) ;
  return result ;   
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double loglikelihoodprod (
  const vector<double> & data, 
  double param
)
{
  double result = 1. ; 
  for (int i = 0 ; i < data.size () ; ++i) result *= esponenziale (data.at (i), param) ;
  return log (result) ;   
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  
//ricerca estremanti:
//algoritmo sezione aurea
double sezione_aurea_max ( //cerco il max del log della likelihood in questo caso
  double logl (const vector<double> & , double),
  double xMin,
  double xMax,
  const vector<double> & data,
  double precision
)
{
  double x_2 = xMin ;
  double x_3 = xMax ;
  while ((xMax - xMin) > precision)
    {
      x_2 = xMin + (xMax - xMin) * 0.618 ;
      x_3 = xMin + (xMax - xMin) * 0.382 ;

      if (logl (data, x_3) < logl (data, x_2)) xMin = x_3 ;
      else                                     xMax = x_2 ;
//      cout << "estremi " << xMin << "\t" << xMax << "\t" << xMax - xMin << "\n" ;

    }
  return 0.5 * (xMax + xMin) ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double h (
  const vector<double> & data, 
  double param,
  double max
)
{
  return loglikelihood (data, param) + 0.5 - loglikelihood (data, max) ;   
}




//ricerca degli zeri:
//metodo bisezione implementazione normale
double bisezione (
  double g (double),
  double xMin,
  double xMax,
  double precision = 0.0001
)
{
  double xAve = xMin ;
  while ((xMax - xMin) > precision)
    {
      xAve = 0.5 * (xMax + xMin) ;
      if (g (xAve) * g (xMin) > 0.) xMin = xAve ;
      else                          xMax = xAve ;
    }
  return xAve ;
}  

//metodo bisezione implementazione ricorsiva

double bisezione_ricorsiva (
  double g (double),
  double xMin,
  double xMax,
  double precision = 0.0001
)
{
  double xAve = 0.5 * (xMax + xMin) ;
  if ((xMax - xMin) < precision) return xAve ;
  if (g (xAve) * g (xMin) > 0.) return bisezione_ricorsiva (g, xAve, xMax, precision) ;
  else                          return bisezione_ricorsiva (g, xMin, xAve, precision) ;
}  

//ricerca estremanti:
//algoritmo sezione aurea
