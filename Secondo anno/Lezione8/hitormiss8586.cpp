/*

Esercizio 05: Si implementi il metodo di integrazione hit-or-miss con la funzione di esempio f(x) = sin (x).
Si scriva l'algoritmo che calcola l'integrale come una funzione esterna al programma main, facendo in modo che prenda come parametri di ingresso, oltre agli estremi lungo l'asse x e l'asse y, anche il numero di punti pseudo-casuali da generare.
Si faccia in modo che l'algoritmo ritorni un contenitore contenente due elementi: il primo elemento sia il valore dell'integrale, il secondo sia la sua incertezza.


Esercizio 06: Si inserisca il calcolo dell'integrale dell'esercizio precedente in un ciclo che, al variare del numero N di punti generati, mostri il valore dell'integrale e della sua incertezza.
Si utilizzi un TGraph per disegnare gli andamenti del valore dell'integrale e della sua incertezza, al variare di N con ragione logaritmica.

c++ -o hitormiss8586 hitormiss8586.cpp myarray.cc `root-config --glibs --cflags`
./hitormiss8586
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

#include "myarray.h"

xz
float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fsin (double x) //funzione seno
  {
    return sin (x) ; 
  }
  
mioArray HitOrMiss (int Nrand, double g(double), double xMin, double xMax,
              double yMin, double yMax )
   {
     int nHit = 0;  //ho zero valori sotto la funzione
     double area  = (xMax - xMin) * (yMax - yMin) ;	//area di estrazione delle coppie
     
     for (int i = 0 ; i < Nrand ; ++i) 	//estraggo Nrand numeri con distribuzione uniforme
      {
        double x = rand_range (xMin, xMax) ;
        double y = rand_range (yMin, yMax) ; 
        if (y < g (x)) ++nHit ; 	//se sto sotto la funzione incremento nHit
      }   
      
     double p = nHit / static_cast<double> (Nrand) ;	//PROBABILITÀ
     double varianza = area * area / static_cast<double> (Nrand) * p * (1. - p) ;
     
     mioArray risultato (2) ;      
     risultato.fill (0, nHit * area / static_cast<double> (Nrand)) ;
     risultato.fill (1, sqrt (varianza)) ;
      
    return risultato ; 
                 
   }           

//----------------- MAIN ----------------- 
int main (int argc, char ** argv)
{
 
  srand (time (NULL)) ;
  int N = 10000 ;	//numero punti da generare
  double x_min = 0. ;	//estremi di integrazione
  double x_max = M_PI ; 
  double y_min = 0. ; 
  double y_max = 1. ;
  
  TGraph g_integrale ;	//grafico valore integrale
  TGraph g_incertezza;	//grafico incertezza valore integrale
  
  for (int iN = 10; iN < N; iN = iN*2)
  {
   mioArray risultato = HitOrMiss(iN,fsin,x_min,x_max,y_min,y_max);
  
  std::cout << "Integrale = " << risultato.get1 (0) << " +/- " << risultato.get1 (1) << std::endl ;
    
    g_integrale.SetPoint (g_integrale.GetN(), iN, risultato.get1 (0)) ;  //Punto i, ascissa, ordinata
    g_incertezza.SetPoint (g_incertezza.GetN(), iN, risultato.get1 (1)) ;    //Punto i, ascissa, ordinata                       
  }
    
    
   //DISEGNO GRAFICI integrale e incertezza dell'integrale
   TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
   c1.SetLogx () ; 

   g_integrale.SetMarkerStyle (20) ;
   g_integrale.SetMarkerColor (kRed + 1) ;
   g_integrale.SetLineColor (kRed - 9) ;
   g_integrale.SetMarkerSize (2) ;
   g_integrale.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi generati") ;
   g_integrale.GetHistogram ()->GetYaxis ()->SetTitle ("integrale") ;
   g_integrale.Draw ("ALP") ;

   c1.Print ("esercizio6_integrale.png", "png") ; 
   
   TCanvas c2 ("c2", "c2", 100, 100, 1000, 1000) ;
   c2.SetLogx () ; 

   g_incertezza.SetMarkerStyle (20) ;
   g_incertezza.SetMarkerColor (kBlue + 1) ;
   g_incertezza.SetLineColor (kBlue - 9) ;
   g_incertezza.SetMarkerSize (2) ;
   g_incertezza.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi generati") ;
   g_incertezza.GetHistogram ()->GetYaxis ()->SetTitle ("incertezza") ;
   g_incertezza.Draw ("ALP") ;

   c2.Print ("es6_incertezzaintegrale.png", "png") ;    
                                  
  return 0 ;
}
