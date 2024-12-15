//Funzione bisezione con cos(x)
// c++ -o es61 es61.cpp
// c++ -o es61 es61.cpp `root-config --glibs --cflags` 

#include <iostream>
#include <math.h>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TMarker.h"

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

double g (double x){
	return cos(x);
}

int main(int argc, char ** argv){
	
	double zerofunzione;
	zerofunzione =bisezione(g,0,4);
	std::cout << zerofunzione << std::endl;
	
	TApplication theApp ("theApp", &argc, argv) ; 
	TF1 fa1 ("fa1", "cos(x)", 0, 10) ;
	TCanvas c1 ;
	fa1.Draw () ;
	TMarker punto (5., 0.5, 20) ;
	punto.Draw ();
	theApp.Run () ;
	
return 0;
}
