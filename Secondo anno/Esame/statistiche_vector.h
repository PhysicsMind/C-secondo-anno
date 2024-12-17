//CRISTIAN BALDO 866593
#ifndef statistiche_vector_h
#define statistiche_vector_h

#include <cmath>
#include <vector>

//Calcolo media del vettore
template <class T>
double media (std::vector<T> const & inputV)
  {
    double sum = 0. ;
    for (int i = 0 ; i < inputV.size () ; ++i) sum += inputV.at (i) ;
    return sum / inputV.size () ;
  }

//Calcolo Varianza con correzione di Bessel
template <class T>
double varianza (std::vector<T> const & inputV)
  {
    double sum = 0. ;
    double sumSq = 0. ;
    for (int i = 0 ; i < inputV.size () ; ++i) 
      {
        sum += inputV.at (i) ;			//sommatoria dei valori
        sumSq += inputV.at (i) * inputV.at (i) ;	//sommatoria dei valori al quadrato
      }
    return sumSq / inputV.size () - (sum * sum) / (inputV.size () * inputV.size ()) ;
  }

//Funzione per la deviazione standard
template <class T>
double sigma (std::vector<T> const & inputV)
  {
    return sqrt (varianza (inputV)) ;
  }

//Funzione per la deviazione standard della media
template <class T>
double devstdmedia (std::vector<T> const & inputV)
  {
    return sigma(inputV) / sqrt (inputV.size ()) ;
  }

#endif
