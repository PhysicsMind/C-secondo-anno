/*
Esercizio 04: Si utilizzino due TGraph per confrontare l'evoluzione della deviazione standard della media calcolata per ogni singolo toy con la deviazione standard del campione delle medie al variare del numero di eventi generati in un singolo toy experiment.

c++ -o evoluzionestatistichetoy84 evoluzionestatistichetoy84.cpp `root-config --glibs --cflags` 
./evoluzionestatistichetoy84
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

#include "statistiche.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  }
  
//----------------- MAIN -----------------  
  
int main (int argc, char ** argv)
  {
    srand(time(NULL)); 
  
    // numero massimo di eventi generati per un singolo toy experiment
    int NMAX = 40000 ;

    statistiche* s_singleToy = new statistiche();
    statistiche* s_media = new statistiche();
    statistiche* s_incertezzaMedia = new statistiche();
           
    TGraph g_sigma ;	//andamento deviazione standard (dovrebbe diventare sempre più precisa ma rimanere circa costante)
    TGraph g_sigmaMedia ;	//andamento deviazione standard della media (dovrebbe diminuire con i toys)
          
    //loop sul numero di eventi da generare per singolo esperimento  
    for (int n = 10 ; n < NMAX ; n = n*2)
      {
        int i = 0 ;
                       
        //loop sul singolo esperimento
        while (i++ < n) s_singleToy->addEvent(rand_range (-3., 3.)) ;	//distribuzione uniforme 

        s_media->addEvent (s_singleToy->getMean ()) ;                	//aggiungo la media del singolo Toy a s_media
        g_sigma.SetPoint (g_sigma.GetN(), n, s_media->getSigma ( )) ;        //aggiungo il punto nel grafico 
                
        s_incertezzaMedia->addEvent(s_singleToy->getSigmaMean ( ));        	//aggiungo la deviazione standard della media nell'oggetto
        g_sigmaMedia.SetPoint (g_sigmaMedia.GetN(), n, s_incertezzaMedia->getMean ()) ;     
        //aggiungo il punto nel grafico della media delle deviazioni standard della media  
                
        s_singleToy->reset () ;        
      }   
      
      

    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;
    c1.SetLogx () ; 

    g_sigma.SetMarkerStyle (20) ;
    g_sigma.SetMarkerColor (kBlue + 1) ;
    g_sigma.SetLineColor (kBlue - 9) ;
    g_sigma.SetMarkerSize (2) ;
    g_sigma.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi") ;
    g_sigma.GetHistogram ()->GetYaxis ()->SetTitle ("media della deviazione standard") ;
    g_sigma.Draw ("ALP") ;

    c1.Print ("esercizio4_sigma.png", "png") ;

    TCanvas c2 ("c2", "c2", 100, 100, 1000, 1000) ;
    c2.SetLogx () ;

    g_sigmaMedia.SetMarkerStyle (20) ;
    g_sigmaMedia.SetMarkerColor (kGreen + 1) ;
    g_sigmaMedia.SetLineColor (kGreen -5) ;
    g_sigmaMedia.SetMarkerSize (2) ;
    g_sigmaMedia.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi") ;
    g_sigmaMedia.GetHistogram ()->GetYaxis ()->SetTitle ("deviazione standard dalla media") ;
    g_sigmaMedia.Draw ("ALP") ;    

    c2.Print ("esercizio4_sigmaMedia.png", "png") ;

    delete s_singleToy;
    delete s_media;
    delete s_incertezzaMedia;


    return 0 ;
  }
