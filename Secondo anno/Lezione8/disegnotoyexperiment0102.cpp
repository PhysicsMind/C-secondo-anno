/*
Esercizio 01: Si scriva un programma che, fissato NMAX numero di eventi di un campione, generi NToys toy experiment di quel campione e ne calcoli la media.
Esercizio 02: Si Aggiunge al programma precedente un oggetto di tipo TH1F che visualizzi la distribuzione delle medie al variare dei toy experiment.

c++ -o disegnotoyexperiment0102 disegnotoyexperiment0102.cpp  `root-config --glibs --cflags` 
./disegnotoyexperiment0102
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "TH1F.h"
#include "TCanvas.h"

#include "statistiche.h"  

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  }
  
//----------------- MAIN -----------------  
  
int main (int argc, char ** argv)
  {
    srand(time(NULL));
    
    // numero di eventi generati per un singolo toy experiment
    int NMAX = 500 ;
    // numero di toy experiment per construire la pdf della media per campionamento
    int NToys = 10000 ;
    
    //definisco due oggetti della classe statistiche
    statistiche s_singleToy;
    statistiche s_media;
    
    TH1F h_medie ("h_medie", "Distribuzione delle medie", 41, -0.5, 0.5) ;
    
    // loop su tutti i toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        //loop sul singolo esperimento
        while (i++ < NMAX) s_singleToy.addEvent (rand_range (-3., 3.)) ; //aggiungo i numeri distribuiti uniformemente
                       
        h_medie.Fill(s_singleToy.getMean()); //calcolo la media e la inserisco nell'istogramma delle medie
        s_media.addEvent (s_singleToy.getMean ()) ;  //metto la media nell'oggetto s_media      
        s_singleToy.reset () ;	//cancello le componenti del singleToy
      }
    
    /*        
    //definisco due oggetti della classe statistiche
    statistiche* s_singleToy = new statistiche(NMAX);
    statistiche* s_media = new statistiche(NToys);
    
    TH1F h_medie ("h_medie", "Distribuzione delle medie", 41, -0.5, 0.5) ;
    
    // loop su tutti i toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        //loop sul singolo esperimento
        while (i++ < NMAX) s_singleToy->aggiungiNumero (rand_range (-3., 3.)) ; //aggiungo i numeri distribuiti uniformemente
                       
        h_medie.Fill(s_singleToy->media()); //calcolo la media e la inserisco nell'istogramma delle medie
        s_media->aggiungiNumero (s_singleToy->media ()) ;  //metto la media nell'oggetto s_media      
        s_singleToy->reset () ;	//cancello le componenti del singleToy
      } */

     TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000);
     h_medie.GetXaxis()->SetTitle("media del campione");  
     h_medie.GetYaxis()->SetTitle("numero di eventi");
     h_medie.Draw();		//disegno il grafico relativo alla distribuzione delle medie dei singleToys
     
     c1.Print("distribuzione medie singleToy 82.png", "png");

    //delete s_singleToy;	//cancello gli oggetti
    //delete s_media;


    return 0 ;
  }
