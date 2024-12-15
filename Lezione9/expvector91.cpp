/*
numeri pseudo-casuali distribuiti secondo una distribuzione di densità esponenziale con tempo caratteristico t0 ed numero di eventi da generare passato a linea di comando e inseriti in un VECTOR

c++ -o expvector91 expvector91.cpp `root-config --glibs --cflags` casual.cc
./expvector91 (t0) (Neventi)
*/

#include <iostream>
#include <vector>

#include "casual.h"

using namespace std ;

int main (int argc, char ** argv)
{
  if (argc < 3)	 //verifica argomenti
    {
      cerr << "uso: " << argv[0] << " tau e numero_di_eventi" << endl ;
      exit (1) ;
    }

  double t_zero = atof (argv[1]) ; //tempo caratteristico da linea di comando
  vector<double> campione ;	    // dichiarazione vector campione
  
  //ciclo di riempimento del campione con Neventi
  for (int i = 0 ; i < atoi (argv[2]) ; ++i)	
    {
      campione.push_back (rand_exp (t_zero)) ;	
    }
	
  //stampo il numero di eventi generati
  cout << "generati: " << campione.size () << " numeri pseudo-casuali\n" ;
  return 0 ;
}
