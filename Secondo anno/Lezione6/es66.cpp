//Metodo della sezione aurea il MASSIMO della funzione g(x) = - (x^2 + 7.3x + 4) nell’intervallo (-10, 10)
// c++ -o es66 es66.cpp


#include <iostream>
#include <math.h>

double sez_aureamax (
  double g (double),
  double xMin,		//estremi intervallo
  double xMax,
  double precision = 0.0001
)
{
  double xr = xMin + 0.618 * (xMax - xMin) ;
  double xrmeno1 = xMin + (1-0.618)*(xMax - xMin) ;		
  if ((xMax - xMin) < precision) return (xMax + xMin)/2 ;
  if (g (xr) - g (xrmeno1) > 0.) return sez_aureamax (g, xrmeno1 , xMax, precision) ;
  else                          return sez_aureamax (g, xMin, xr , precision) ;
}  

double g (double x){
	return  -x*x - 7.3*x - 4 ;
}

int main(){
	
	double massimo;
	massimo= sez_aureamax(g,-10,10);
	std::cout << massimo << std::endl;
	
return 0;
}
