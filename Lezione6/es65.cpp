//Metodo della sezione aurea il minimo della funzione g(x) = x^2 + 7.3x + 4 nell’intervallo (-10, 10)
// c++ -o es65 es65.cpp `root-config --glibs --cflags` 


#include <iostream>
#include <math.h>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TMarker.h"

double sez_aurea (
  double g (double),
  double xMin,		//estremi intervallo
  double xMax,
  double precision = 0.0001
)
{
  double xr = xMin + 0.618 * (xMax - xMin) ;
  double xrmeno1 = xMin + (1-0.618)*(xMax - xMin) ;		
  if ((xMax - xMin) < precision) return (xMax + xMin)/2 ;
  if (g (xr) - g (xrmeno1) < 0.) return sez_aurea (g, xrmeno1 , xMax, precision) ;
  else                          return sez_aurea (g, xMin, xr , precision) ;
}  

double g (double x){
	return  x*x + 7.3*x + 4 ;
}

int main(int argc, char ** argv){
	
	double minimo;
	minimo= sez_aurea(g,-10,10);
	std::cout << minimo << std::endl;
	
	TApplication theApp ("theApp", &argc, argv) ; 
	TF1 fa1 ("fa1", "x*x + 7.3*x + 4", -10, 10) ;
	TCanvas c1 ;
	fa1.Draw () ;
	TMarker punto (5., 0.5, 20) ;
	theApp.Run () ;
	
return 0;
}
