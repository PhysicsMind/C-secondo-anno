/*
c++ -o disegnocoppiecasuali111112 disegnocoppiecasuali111112.cpp funzioni.cc `root-config --glibs --cflags`
./disegnocoppiecasuali111112

Disegno su un grafico le coppie di punti generate casualmente lungo una funzione con le barre d'errore
*/

#include <iostream>
#include <vector>
#include <cmath>

#include "TF1.h"
#include "TGraphErrors.h"
#include "TCanvas.h"

#include "funzioni.h"


using namespace std ;

int main (int argc, char ** argv)
{

  int nPoints = 5 ;	//numero di punti
  double min = 0.5 ;	//intervallo
  double max = 10.5 ;
  double epsilon = 0.15 ;	//errore massimo y

  TF1 f_true ("f_true", retta, 0., 2. * nPoints, 2) ; //nome, funzione, intervallo, 2 parametri liberi
  f_true.SetParameter (0, 0.4) ;	//decido i parametri di y=a+bx
  f_true.SetParameter (1, 1.5) ;

  vector<double> v_x ;		//coordinate x
  vector<double> v_y ;		//coordinate y

  double x = 0. ;
  for (int i = 0 ; i < nPoints ; ++i)
    {
      x+= rand_range (0., 1.) ;	//
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

  TCanvas c1 ;
  g_retta.Draw ("AP") ;
  c1.Print ("coppieretta.png", "png") ; 

  return 0 ;
}


