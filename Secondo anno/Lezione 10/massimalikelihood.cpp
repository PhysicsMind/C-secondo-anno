/*
c++ -o massimalikelihood funzioni.cc casual.cc massimalikelihood.cpp
./massimalikelihood (Neventi) (t_zero)

Testo:
  Si scriva una libreria di funzioni per determinare il parametro τ della distribuzione 
  esponenziale utilizzata per generare gli eventi presenti nel file dati_esponenziali.txt, 
  a partire dal vector di numeri creato negli esercizi precedenti.

  Si implementino i prototipi delle funzioni presentate a lezione.
  Si confronti il risultato ottenuto con la media dei numeri salvati nel vector.
  Come dipende il risultato dall'intervallo inziale passato alla funzione sezione_aurea_max?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "statistiche.h"
//#include "statistiche_vector.h"
#include "funzioni.h"
#include "casual.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " numero_di_eventi [t_zero]" << endl ;
        exit (1) ;
      }

    double t_zero = 5. ;	//impongo t_zero=5 oppure lo passo da terminale
    if (argc == 3) 
      {
        t_zero = atof (argv[2]) ;
      }

    vector<double> data ;	//dichiaro vettore dei  dati
    for (int i = 0 ; i < atoi (argv[1]) ; ++i)
      {
        data.push_back (rand_exp (t_zero)) ; //riempio data con numeri pseudo-casuali
      }

    cout << "generati " << data.size () << " eventi" << endl ;

    double media_v = media (data) ;
    cout << "media = " << media_v << endl ; 	//media del vector

    double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data) ; //ricerco il massimo 

    cout << "massimo della likelihood = " << massimo << endl ; 

    return 0 ;
}
