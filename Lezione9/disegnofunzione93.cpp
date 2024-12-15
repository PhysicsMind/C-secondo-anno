/*
Disegno una funzione (esponenziale) in un oggetto TF1

c++ -o disegnofunzione93 disegnofunzione93.cpp `root-config --glibs --cflags` 
./disegnofunzione93 (t_zero)    //esempio :t_zero=2
*/

#include <iostream>
#include <vector>

#include "TCanvas.h"
#include "TF1.h"

//#include "funzioni.h"

using namespace std ;

Double_t exp_R (Double_t * x, Double_t * par) //funzione esponenziale da disegnare con TF1
 {
      Float_t xx =x[0];	//variabile
      Double_t f = TMath::Exp(-par[0]*xx)/par[0];	//scrivo la funzione esponenziale in base ai parametri e le variabili
      return f;
   }

int main (int argc, char ** argv)
{

  if (argc < 2)
    {
      cerr << "uso: " << argv[0] << " tau" << endl ;
      exit (1) ;
    }

  double t_zero = atof (argv[1]) ; //tempo t_zero da linea di comando

  TF1 f_exp ("funzione_exp", exp_R, 0, 5 * t_zero, 1) ; //nome, fuzione, minimo del dominio, max dominio, numero di parametri
  f_exp.SetParameter (0, t_zero) ;	//primo argomento: indice parametro //secondo arg: valore del parametro 
  f_exp.SetParName (0, "t_0") ;	//imposto il nome del parametro
  f_exp.SetLineColor (kBlue) ;
  f_exp.SetLineWidth (2) ;

  TCanvas c1 ;
  f_exp.Draw () ;
  c1.Print ("disegnofunzione.png", "png") ;

  return 0 ;
}
