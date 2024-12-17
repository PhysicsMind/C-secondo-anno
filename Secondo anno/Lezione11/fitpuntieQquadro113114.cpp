/*
c++ -o fitpuntieQquadro113114 fitpuntieQquadro113114.cpp funzioni.cc `root-config --glibs --cflags`
./fitpuntieQquadro113114

Calcolo i parametri del fit date 10 coppie e confronto i risultati con ROOT + matrice di covarianza(esercizio7)
*/

#include <iostream>
#include <vector>
#include <cmath>

#include "TF1.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TFitResult.h"

#include "funzioni.h"


using namespace std ;

int main (int argc, char ** argv)
{

  int nPoints = 10 ;		//Numero punti
  double min = 0.5 ;
  double max = 10.5 ;
  double epsilon = 0.15 ;

  TF1 f_true ("f_true", retta, 0., 2. * nPoints, 2) ;  //nome, funzione, intervallo, 2 parametri liberi
  f_true.SetParameter (0, 0.4) ;		//decido i parametri di y=a+bx
  f_true.SetParameter (1, 1.5) ;

  vector<double> v_x ;		//coordinate x
  vector<double> v_y ;		//coordinate y

  double x = 0. ;
  for (int i = 0 ; i < nPoints ; ++i)
    {
      x+= rand_range (0., 1.) ;
      v_x.push_back (x) ;
      double y = f_true.Eval (x) + rand_TCL (0, epsilon) ;  //valore y reale + errore  y
      v_y.push_back (y) ;
    }
  
  // errore sulle coordinate x dei punti
  vector<double> v_ex (v_x.size (), 0.) ;
  // errore sulle coordinate y dei punti
  vector<double> v_ey (v_y.size (), epsilon);

  TGraphErrors g_retta (v_x.size (), &v_x[0], &v_y[0], &v_ex[0], &v_ey[0]) ;  //disegno il grafico con le barre d'errore nei punti
  g_retta.SetMarkerStyle (4) ;
  g_retta.SetMarkerColor (kRed) ;

  TF1 f_fit ("f_fit", retta, 0., 2. * nPoints, 2) ;	//per rappresentare la funzione modello
  TFitResultPtr fit_result = g_retta.Fit (&f_fit, "S") ;	//operazione di fit, S salva

  cout << endl ;
  cout.precision (3) ;
  cout << "risultato del fit: " << fit_result->IsValid () << endl ;	//true o 1 in caso di successo
  cout << "termine noto : " << f_fit.GetParameter (0) << "\t+- " << f_fit.GetParError (0) << endl ;
  cout << "pendenza     : " << f_fit.GetParameter (1) << "\t+- " << f_fit.GetParError (1) << endl ;

  cout << "numero di gradi di libertà: " << fit_result->Ndf () << endl ;
  cout << "valore di Q quadro: " << fit_result->Chi2 () << endl ;	//valore vero del chi quadro
  
  
  cout << "\nmatrice di covarianza del risultato\n\n:" ;	//MATRICE DI COVARIANZA 
  cout << "\t " << fit_result->CovMatrix (0,0) ;
  cout << "\t " << fit_result->CovMatrix (1,0) << "\n" ;
  cout << "\t " << fit_result->CovMatrix (0,1) ;
  cout << "\t " << fit_result->CovMatrix (1,1) << "\n\n\n" ; 

  double Q2 = 0 ;
  for (int i = 0 ; i < v_x.size () ; ++i)	//formula calcolo chi quadro
    {
      Q2 += (v_y.at (i) - f_fit.Eval (v_x.at (i))) * (v_y.at (i) - f_fit.Eval (v_x.at (i))) / 
            (v_ey.at (i) * v_ey.at (i)) ; 
    }

  cout << "valore di Q quadro ricalcolato: " << Q2 << endl ;


  TCanvas c1 ;
  g_retta.Draw ("AP") ;
  c1.Print ("retta.png", "png") ; 

  return 0 ;
}










