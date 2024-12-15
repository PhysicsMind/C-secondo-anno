//Genero numeri pseudo-casuali uniformemente distribuiti in un intervallo [min,max]
/*
c++ -o distribuniforme distribuniforme.cpp `root-config --glibs --cflags` 
./distribuniforme
*/
#include <iostream> 
#include "TH1F.h"
#include "TCanvas.h"

static const int A =  214013;		//Parametri algoritmo LCG
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

void rnd(){		//aggiorno il seed con l'algoritmo LCG (generatore lineare congruenziale )
   
    seed_ = (A* seed_ + C)%M;
    return;
}

float rand_range(float min, float max){	//Aggiorno il seed e lo scalo nel range [min, max]
    
    rnd();
    return min + (max - min)*seed_ / static_cast<float> (M);
}

int main(){

    seed_ = 0; 	//Imposto il seed globale
    float min = -3;	//Imposto il min e max dell'estrazione
    float max = 3;
    
    TH1F histo ("histo", "Distribuzione uniforme", 100 , min-2 , max+2 ) ;	
    
    for(int i =0; i < 10000; ++i){		//metto i numeri generati nell'istogramma
       float rand = rand_range(min, max);
       std::cout << "Il numero generato è: " << rand << std::endl;
       histo.Fill (rand);			
    }   
    
    TCanvas c1 ;
    histo.SetFillColor (kOrange + 1) ;
    histo.GetXaxis ()->SetTitle ("asse x") ;
    histo.GetYaxis ()->SetTitle ("conteggi per bin") ;
    histo.Draw () ;
    c1.Print ("histo.png", "png") ;


    return 0;
}
