/*
c++ -o main_02 main_02.cpp
*/

#include <cstdlib>
#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include <fstream>

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


int main (int argc, char ** argv)
  {
  
    //CREO IL GRAFICO 
    
   TH1F istogramma ("istogramma", "titolo", 100 , -7., 7.) ;
   int N=100000;
   for(int j=0; j<N ; j++){
    istogramma.Fill (rand_range (-4., 4.)) ;  //riempio l'istogramma con i primi N valori
    std::cout << "indice " << j << " --> " << rand_range (-4., 4.) << "\n" ;
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
