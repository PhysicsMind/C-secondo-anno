/*
c++ -o varianzastimatore104 funzioni.cc casual.cc varianzastimatore104.cpp
./varianzastimatore104 (Neventi) (t_zero)

Testo:

Si utilizzi il metodo della bisezione per trovare i due punti τ - στ e τ + στ nel caso 
dell'esercizio precedente.

Si confronti il valore di στ ottenuto in questo modo con quello calcolato a partire
dalla media aritmetica dei numeri salvati nel vector
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
    cout << "media = " << media_v << endl ; 

    double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data) ;//calcolo il massimo della likelihood

    cout << "massimo della likelihood = " << massimo << endl ; 

    double zero_sx = bisezione (h, 0.5 * media_v, massimo, data, massimo) ;	
    double zero_dx = bisezione (h, massimo, 1.5 * media_v, data, massimo) ;
    //in bisezione: funzione da bisezionare, minimo intervallo, massimo intervallo, set dati, valore massimo della likelihood

    cout << "zero_sx = " << zero_sx << endl ;
    cout << "zero_dx = " << zero_dx << endl ;

    cout << "sigma = " << 0.5 * (zero_dx - zero_sx) << endl ;
    cout << "sigma stimata = " << media_v / sqrt (data.size ()) << endl ;

    return 0 ;
}
