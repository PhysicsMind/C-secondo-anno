#ifndef funzioni_h
#define funzioni_h

#include <vector>

double esponenziale (double x, double tau) ;

double loglikelihood (
  const std::vector<double> & data, 
  double param
) ;

double loglikelihoodprod (
  const std::vector<double> & data, 
  double param
) ;

double sezione_aurea_max (
  double logl (const std::vector<double> & , double),
  double xMin,
  double xMax,
  const std::vector<double> & data,
  double precision = 0.0001
) ;

double h (
  const std::vector<double> & data, 
  double param,
  double max
) ;
double bisezione (
  double g (double),
  double xMin,
  double xMax,
  double precision = 0.0001
);


/*double bisezione (
  double h (const std::vector<double> & , double, double),
  double xMin,
  double xMax,
  const std::vector<double> & data,
  double massimo,
  double precision = 0.0001
) ;*/

#endif
