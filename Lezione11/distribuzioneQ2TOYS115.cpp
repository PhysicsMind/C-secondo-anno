/*
c++ -o distribuzioneQ2TOYS115 distribuzioneQ2TOYS115.cpp funzioni.cc `root-config --glibs --cflags`
./distribuzioneQ2TOYS115
*/

#include <iostream>
#include <vector>
#include <cmath>

#include "TF1.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TH1F.h"

#include "funzioni.h"


using namespace std ;

int main (int argc, char ** argv)
{

  int nPoints = 10 ; 		//numero punti
  int nToys = 10000 ;		//numero esperimenti
  double min = 0.5 ;
  double max = 10.5 ;
  double epsilon = 0.15 ;

  TF1 f_true ("f_true", retta, 0., 2. * nPoints, 2) ; //nome, funzione, intervallo, 2 parametri liberi
  f_true.SetParameter (0, 0.4) ;		//decido i parametri di y=a+bx
  f_true.SetParameter (1, 1.5) ;

  vector<double> v_x ;		//coordinate
  vector<double> v_y ;
  // errore sulle coordinate x dei punti
  vector<double> v_ex (nPoints, 0.) ;
  // errore sulle coordinate y dei punti
  vector<double> v_ey (nPoints, epsilon);

  TH1F h_Q2 ("h_Q2", "histogram of Q2", 20 * nPoints, 0., 4 * nPoints) ;//istogramma Q2

  // loop di toy experiment
  for (int iToy = 0 ; iToy < nToys ; ++iToy)
    {
      v_x.clear () ;	//pulisco i vettori
      v_y.clear () ;
      double x = 0. ;
      for (int i = 0 ; i < nPoints ; ++i)	//genero le coppie
        {
          x+= rand_range (0., 1.) ;
          v_x.push_back (x) ;
          double y = f_true.Eval (x) + rand_TCL (0, epsilon) ;
          v_y.push_back (y) ;
        }
      
      TGraphErrors g_retta (v_x.size (), &v_x[0], &v_y[0], &v_ex[0], &v_ey[0]) ; //grafico errori
      TF1 f_fit ("f_fit", retta, 0., 2. * nPoints, 2) ;			//grafico fit retta
      TFitResultPtr fit_result = g_retta.Fit (&f_fit, "SQ") ;
      h_Q2.Fill (fit_result->Chi2 ()) ;	//aggiungo il Q2 all'istogramma
    
    } // loop di toy experiment

  TCanvas c1 ;
  h_Q2.SetFillColor (kOrange) ;
  h_Q2.Draw ("hist") ;
  c1.Print ("Q2.png", "png") ; 

  return 0 ;
}
