/*
Esercizio 03: Si utilizzi la classe statistiche per confrontare la deviazione standard della media calcolata per ogni singolo toy con la deviazione standard del campione delle medie.

c++ -o statistichetoy83 statistichetoy83.cpp 
./statistichetoy83
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
            
    statistiche s_singleToy;	
    statistiche s_media;	//campione medie dei toy
    statistiche s_incertezzaMedia;	//campione singole sigmamedia
           
    // loop su tutti i toy experiment
    for (int iToy = 0 ; iToy < NToys ; ++iToy)
      {
        int i = 0 ;
        //loop sul singolo esperimento
        while (i++ < NMAX) s_singleToy.addEvent(rand_range (-3., 3.)) ;

        s_media.addEvent (s_singleToy.getMean ()) ;   	//aggiungo la media del singolo Toy                   
        s_incertezzaMedia.addEvent(s_singleToy.getSigmaMean ());	//aggiungo la sigma della media relativa al singolo toy
                       
        s_singleToy.reset () ;
      } 


    //valori finali (dovrebbero coincidere)
    std::cout << "media delle deviazioni standard della media per i singoli toy experiment: " 
              << s_incertezzaMedia.getMean () << " \n" ;	//faccio la media delle singole deviazioni standard della media
    std::cout << "deviazione standard della distribuzione delle medie dei singoli toy experiment: " 
              << s_media.getSigma () << " \n" ;	//prendo la sigma del campione delle medie


    return 0 ;
  }
