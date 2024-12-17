/*
Stampo il valore di log(L) di una distribuzione esponenziale

t0=1
Dati fissati

c++ -o loglikelihood loglikelihood.cpp 
./loglikelihood 
*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

double esponenziale (double x, double tau)
{
  if (tau == 0.) return 1. ;
  return exp (-1. * x / tau) / tau ;
}

double loglikelihood (const std::vector<double> & data, double param)	
//ho in igresso sia il vettore dei dati che il parametro di interesse
{
  double result = 0. ;	//azzero la somma iniziale
  //sommo il logaritmo della densità di probabilità in ogni punto
  for (int i = 0 ; i < data.size () ; ++i) result += log (esponenziale (data.at (i), param)) ;
  return result ;
}

int main (int argc, char ** argv)
{
  // Riempio un vettore con un set di dati
  double dataArr[13] = {0.4,0.2,0.1,1.,1.2,0.8,0.9,0.9,1.5,0.1,0.2,0.1,0.2};
  std::vector<double> data(&dataArr[0],&dataArr[0]+13);			//Riempio il vettore data con i valori di dara Arr
  // Stampo il valore di log(L)
  std::cout << "t=1: log(L)=" << loglikelihood(data,1) << std::endl;
  return 0 ;
}
