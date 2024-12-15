/*
numeri pseudo-casuali distribuiti secondo una distribuzione di densità esponenziale con tempo caratteristico t0 ed numero di eventi da generare passato a linea di comando e inseriti in un VECTOR (ESECIZIO 1)

Disegno un ISOGRAMMA con i toy experiment

c++ -o istotoyexp92 istotoyexp92.cpp `root-config --glibs --cflags` utils.cc casual.cc
./istotoyexp92 (tau) (neventi)
*/
#include <iostream>
#include <vector>
#include "TH1F.h"
#include "TCanvas.h"

//#include "utils.h"
#include "casual.h"
#include "statistiche.h"

using namespace std ;

int main (int argc, char ** argv)
{

  if (argc < 3)
    {
      cerr << "uso: " << argv[0] << " tau nnumero_di_eventi" << endl ;
      exit (1) ;
    }

  double t_zero = atof (argv[1]) ;
  vector<double> campione ;
  for (int i = 0 ; i < atoi (argv[2]) ; ++i)
    {
      campione.push_back (rand_exp (t_zero)) ;
    }

  //TH1F * histo = crea_histo ("h_exp", campione) ;
   TH1F * histo = new TH1F ("h_exp", "istogramma exp toyexperiment", 100, 0 , 10* t_zero) ;
   for(int i=0; i < atoi (argv[2]); ++i){
	histo->Fill(campione[i]);
    }

  TCanvas c1 ;
  histo->SetFillColor (kBlue) ;
  histo->Draw () ;
  c1.Print ("disognoexp_02.png", "png") ;

  delete histo ;
  return 0 ;
}
