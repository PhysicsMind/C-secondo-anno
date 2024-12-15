#include "funzioni.h"
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
  

double sezione_aurea_max (
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


double h (	//funzione traslata con zeri su -0.5 
  const vector<double> & data, 
  double param,
  double max			//massimo della likelihood
)
{
  //traslo verso il basso del massimo della funzione e la rialzo di 0.5
  return loglikelihood (data, param) + 0.5 - loglikelihood (data, max) ;   //traslo 
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
  

double bisezione (
  double h (const vector<double> & , double, double),	//funzione di cui calcolare gli zeri
  double xMin,						//intervallo in cui cercare gli zeri
  double xMax,
  const vector<double> & data,			//set di dati
  double massimo,					//valorer massimo della likelihood
  double precision
)
{
  double xAve = xMin ; //imposto la media sul minimo
  while ((xMax - xMin) > precision)	//itero fino alla precisione richiesta
    {
      xAve = 0.5 * (xMax + xMin) ;	//calcolo la nuova media
      if (h (data, xAve, massimo) * h (data, xMin, massimo) > 0.) xMin = xAve ;
      else                                                        xMax = xAve ;
    }
  return xAve ;
}

double retta (double * x, double * par)
  {
    return par[0] + par[1] * x[0] ;
  }


double rand_range (double min, double max)
  {
    return min + (max - min) * rand () / static_cast<double> (RAND_MAX) ;
  } 


float rand_TCL (double mean, double sigma, int N)
  {
    double y = 0. ; 
    double xMin = mean - sqrt (3 * N) * sigma ;
    double xMax = mean + sqrt (3 * N) * sigma ;
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }

