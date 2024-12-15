//Funzione bisezione ricorsiva con cos(x)
// c++ -o es62 es62.cpp


#include <iostream>
#include <math.h>

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

double g (double x){
	return cos(x);
}

int main(){
	
	double zerofunzione;
	zerofunzione=bisezione_ricorsiva(g,0,4);
	std::cout << minimo << std::endl;
	
return 0;
}
