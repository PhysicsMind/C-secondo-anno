/*
c++ -o incertezzay116 incertezzay116.cpp funzioni.cc `root-config --glibs --cflags`
./incertezzay116

Modifico volutamente l'incertezza sperimentale associata ai punti yi e risalgo all'incertezza utilizzata nella generazione dei punti tramite il valore di aspettazione della variabile Q2
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

  int nPoints = 10 ;
  int nToys = 10000 ;
  double min = 0.5 ;
  double max = 10.5 ;
  double epsilon = 0.15 ;
  double modificatore = 0.33 ;

  TF1 f_true ("f_true", retta, 0., 2. * nPoints, 2) ;
  f_true.SetParameter (0, 0.4) ;
  f_true.SetParameter (1, 1.5) ;

  vector<double> v_x ;
  vector<double> v_y ;
  // errore sulle coordinate x dei punti
  vector<double> v_ex (nPoints, 0.) ;
  // errore sulle coordinate y dei punti
  vector<double> v_ey (nPoints, epsilon);

  TH1F h_Q2 ("h_Q2", "histogram of Q2", 20 * nPoints, 0., 4 * nPoints) ;
  int ndf = 0 ; //numero gradi di libertà

  // loop di toy experiment
  for (int iToy = 0 ; iToy < nToys ; ++iToy)
    {
      v_x.clear () ;
      v_y.clear () ;
      double x = 0. ;
      for (int i = 0 ; i < nPoints ; ++i)	//rimpio i vettori con le coppie
        {
          x+= rand_range (0., 1.) ;
          v_x.push_back (x) ;
          double y = f_true.Eval (x) + rand_TCL (0, modificatore * epsilon) ; //dilato l'errore mediante un prodotto
          v_y.push_back (y) ;
        }
      
      TGraphErrors g_retta (v_x.size (), &v_x[0], &v_y[0], &v_ex[0], &v_ey[0]) ;	//grafico errori
      TF1 f_fit ("f_fit", retta, 0., 2. * nPoints, 2) ;				//grafico fit
      TFitResultPtr fit_result = g_retta.Fit (&f_fit, "SQ") ;
      h_Q2.Fill (fit_result->Chi2 ()) ;	//calcolo il Q2
      ndf = fit_result->Ndf () ;
    
    } // loop di toy experiment

  TCanvas c1 ;
  h_Q2.SetFillColor (kOrange) ;
  h_Q2.Draw ("hist") ;
  c1.Print ("Q2.png", "png") ; 

  double scale = h_Q2.GetMean () / ndf ;

  cout << "sigma realistica: " << sqrt (scale) * epsilon << endl ;

  return 0 ;
}
