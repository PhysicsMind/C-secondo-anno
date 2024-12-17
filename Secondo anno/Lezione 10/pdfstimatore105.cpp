/*
c++ -o pdfstimatore105 pdfstimatore105.cpp `root-config --glibs --cflags` funzioni.cc casual.cc 
./pdfstimatore105

Simulo N espirimenti e per ognuno (con Nestrazioni) calcolo lo stimatore, inserisco gli stimatori in un istogramma
Testo:
  Utilizzando il generatore di numeri pseudo-casuali secondo una pdf esponenziale sviluppato nella 
  Lezione 4, si disegni la distribuzione di probabilita' dello stimatore di τ in funzione del numero 
  di eventi a disposizione per la stima.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

#include "statistiche.h"
//#include "statistiche_vector.h"
#include "funzioni.h"
#include "casual.h"

using namespace std ;

int main (int argc, char ** argv)
  {

    if (argc < 2)
      {
        cerr << "uso: " << argv[0] << " mu_true numero_di_eventi [numero_di_toy = 10000]" << endl ;
        exit (1) ;
      }

    double mu_true = atof (argv[1]) ; 
    int numero_eventi = atoi (argv[2]) ;

    int N_toys = 10000 ;
    if (argc > 3) N_toys = atoi (argv[3]) ;

    TApplication theapp ("theapp", 0, 0) ;

    TH1F h_max (
        "h_max", "max likelihood distribution", 
        N_toys / 100, 
        mu_true - 3 * mu_true / sqrt (numero_eventi),
        mu_true + 3 * mu_true / sqrt (numero_eventi)
      ) ;

    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)		//per ogni simulazione 
      {
        if (i_toy % 1000 == 0) cout << "running toy " << i_toy << endl ;	//stampo il toy raggiunto in esecuzione
        vector<double> data_loc ;						//riempio un vector con le estrazioni 
        for (int i_sample = 0 ; i_sample < numero_eventi ; ++i_sample)
          {
            data_loc.push_back (rand_exp (mu_true)) ;
          } 

        double media_v = media (data_loc) ;  //media set estrazioni
       // double sigma_subsample = media_v / sqrt (data_loc.size ()) ;		//dev. standard della media
        double massimo = sezione_aurea_max (loglikelihood, 0.5 * media_v, 1.5 * media_v, data_loc) ; //massimo della likelihood
        h_max.Fill (massimo) ; 	//metto nell'istogramma lo stimatore relativo al singolo toyexperiment
      }

    h_max.SetLineColor (kGray) ;
    h_max.SetFillColor (kOrange + 1) ;
    h_max.GetXaxis ()->SetTitle ("stimatore di #tau") ;
    h_max.GetYaxis ()->SetTitle ("conteggi per bin") ;    
    TCanvas c1 ;
    c1.SetLeftMargin (0.10) ; 
    h_max.Draw () ;
    c1.Update();
    theapp.Run () ;

    return 0 ;
}
