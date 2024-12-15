//Metodo della sezione aurea il minimo della funzione g(x) = x^2 + 7.3x + 4 nell’intervallo (-10, 10)
// c++ -o es64 es64.cpp
//DA RIFARE SENZA RICORSIONE

#include <iostream>
#include <math.h>

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

int main(){
	
	double minimo;
	minimo= sez_aurea(g,-10,10);
	std::cout << minimo << std::endl;
	
return 0;
}
