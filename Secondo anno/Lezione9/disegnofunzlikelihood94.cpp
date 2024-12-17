/*
Si scriva una funzione loglikelihood che calcoli il logaritmo della verosimiglianza al variare del parametro t0, per un campione di eventi pseudo-casuali
Si scriva la funzione in modo che possa essere utilizzata per costruire una TF1 di ROOT che ne disegni l’andamento in funzione di t0

c++ -o disegnofunzlikelihood94 disegnofunzlikelihood94.cpp `root-config --glibs --cflags` casual.cc funzioni.cc
./disegnofunzlikelihood94 (tau) (Neventi)
*/

#include <cmath>
#include <iostream>
#include <vector>

#include "TF1.h"
#include "TH1F.h"
#include "TCanvas.h"

#include "casual.h"
//#include "funzioni.h"
#include "statistiche.h"

using namespace std ;



double esponenziale (double x, double tau)
{
  if (tau == 0.) return 1. ;
  return exp (-1. * x / tau) / tau ;
}
double loglikelihood (double *x, double *param)	
//ho in igresso sia il vettore dei dati che il parametro di interesse
{
  double result = 0. ;	//azzero la somma iniziale
  //sommo il logaritmo della densità di probabilità in ogni punto
  for (int i = 0 ; i < param[0] ; ++i) result += log (esponenziale (param[i],x[0])) ;
  return result ;
}




int main (int argc, char ** argv)
{

  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " tau nnumero_di_eventi" << endl ;
      exit (1) ;
    }

  double t_zero = atof (argv[1]) ; 	//parametro t_zero da terminale
  vector<double> campione ;		//dichiarazione vettore campione dei dati
  //Riempio il campione con Neventi delle estrazioni pseudo-casuali 
  for (int i = 0 ; i < atoi (argv[2]) ; ++i)
    {
      campione.push_back (rand_exp (t_zero)) ;
    }


  double m = media (campione) ; //uso la classe statistiche per calcolare media e sigma
  double s = sigma (campione) ;



  /*
  TF1 f_ll ("f_ll", loglikelihood, max (0.1 * m, m - 3 * s), m + 3 * s, atoi (argv[2])) ;
  f_ll.SetParameter (0, campione.size()) ;
  for (int i=0; i<campione.size(); i++)
  { 
  f_ll.SetParameter (i+1, campione.at(i));
  }
  f_ll.SetLineColor (kRed) ;
  f_ll.SetLineWidth (2);*/



  vector<double> dati_forTF1 ;	//dichiarazione vettore dei dati per funzione TF1
  dati_forTF1.push_back (campione.size ()) ;
  dati_forTF1.insert (dati_forTF1.end (), campione.begin (), campione.end ()) ;

  TF1 f_ll ("f_ll", loglikelihood, max (0.1 * m, m - 3 * s), m + 3 * s, dati_forTF1.size ()) ;
  f_ll.SetParameters (&dati_forTF1[0]) ;
  f_ll.SetLineColor (kRed) ;
  f_ll.SetLineWidth (2) ;

  TCanvas c1 ;
  f_ll.Draw () ;
  c1.Print ("esercizio_04.png", "png") ;

  return 0 ;
}
