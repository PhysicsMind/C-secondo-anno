/*
CRISTIAN BALDO 866593

c++ -o main main.cpp casual.cc `root-config --glibs --cflags` 
./main 

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

#include "statistiche_vector.h"
#include "casual.h"

using namespace std ;

int main (int argc, char ** argv)
  {
    //Dichiarazione variabili
    double Neventi =1000;
    float x_min = 0;		
    float x_max = 3;
    double y_max=2./3.;

    vector<double> campione; 
    
    //Riempio il vettore campione con gli eventi e li inserisco nell'istogramma
    TH1F h_triangolare ("h_triangolare", "PDF triangolare", 100 , x_min-1, x_max+1) ;

    for(int i=0; i < Neventi  ; ++i){
      campione.push_back (rand_TAC(ftriangolare, x_min, x_max, y_max));
      h_triangolare.Fill (campione.at (i) );		
    }

    //Stampo le statistiche
    cout << "media del campione:        "<< media(campione)<< "\n" ;
    cout << "varianza del campione:     "<< varianza(campione)<< "\n" ;

    //Impostazioni istogramma
    TCanvas c1 ;
    h_triangolare.Draw () ;
    h_triangolare.GetXaxis () -> SetTitle ("x") ;
    h_triangolare.GetYaxis () -> SetTitle ("eventi") ;
    h_triangolare.SetFillColor (kRed+2) ;
    c1.Print ("h_triangolare.png", "png") ;


    //TOY EXPERIMENT (Richiesta 5)

    //Dichiarazione variabili
    double Nmax=100; //eventi per ogni Toy
    double NToys= 10000;
    
    vector<double> campioneToy; 

    //Dichiarazione istogrammi
    TH1F h_Media("h_Media", "istogramma media", NToys/100 , 1.5, 2.5) ;
    TH1F h_DevStdMedia("h_DevStdMedia", "istogramma Deviazione Standard Media", NToys/100 , 0.04, 0.10) ;

          
    //Ciclo di riempimento degli istogrammi per ogni ToyExperiment 
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int n = 0 ;              
        //loop sul singolo Toy
        while (n++ < Nmax) campioneToy.push_back(rand_TAC(ftriangolare, x_min, x_max, y_max));
        
        h_Media.Fill (media(campioneToy));
        h_DevStdMedia.Fill (devstdmedia(campioneToy));
     
        campioneToy.clear  (); //azzero il vettore campione per il nuovo Toy
    }   
     
     
    //Impostazione Istogrammi
    TCanvas c2;
    h_Media.Draw () ;
    h_Media.GetXaxis () -> SetTitle ("x") ;
    h_Media.GetYaxis () -> SetTitle ("conteggi per bin") ;
    h_Media.SetFillColor (kGreen+2) ;
    c2.Print ("h_Media.png", "png") ;
  
    TCanvas c3;
    h_DevStdMedia.Draw () ;
    h_DevStdMedia.GetXaxis () -> SetTitle ("x") ;
    h_DevStdMedia.GetYaxis () -> SetTitle ("conteggi per bin") ;
    h_DevStdMedia.SetFillColor (kMagenta+2) ;
    c3.Print ("h_DevStdMedia.png", "png") ;

    return 0 ;
}

  
