//c++ -o es5 es5.cpp  `root-config --glibs --cflags` 


#include <cstdlib>
#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include <fstream>


float fgaus (float x) 
  {
    return exp (-0.5 * x * x) ; 
  }

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 

float rand_TAC (float f (float), float xMin, float xMax, float yMax)
  {
    double x = 0. ;
    double y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;
    return x ; 
  }


int main (int argc, char ** argv)
  {
  
    //CREO IL GRAFICO 
    
   TH1F istogramma ("istogramma", "titolo", 100 , -4., 4.) ;
   int N=100000;
   for(int j=0; j<N ; j++){
    istogramma.Fill (rand_TAC (fgaus, -1., 1., 1.)) ;  //riempio l'istogramma con i primi N valori
    std::cout << "indice " << j << " --> " << (fgaus, -1., 1., 1.) << "\n" ;
    }
    
    
    TApplication theApp ("theApp", &argc, argv) ; //theApp è la stringa  dell'application
	
    TCanvas c1 ;
    istogramma.SetFillColor (kOrange + 1) ;
    istogramma.GetXaxis ()->SetTitle ("asse x") ;
    istogramma.GetYaxis ()->SetTitle ("conteggi per bin") ;
    
    //DISEGNO L'ISTOGRAMMA
    istogramma.Draw () ;
    c1.Print ("esempio.png", "png") ;  //salvo il file in esempio.png o posso usare anche esempio.pdf   e dopo specifico il tipo di file
    
    theApp.Run () ;



    return 0 ;
  }
