/*
c++ -o es1 `root-config --glibs --cflags` es1.cpp
*/

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc, char ** argv)
  {
    TH1F istogramma ("istogramma", "titolo", 5, -5., 5.) ;

    istogramma.Fill (2.5) ;  //se mettessi 5. viene contato ma non visualizzato
    istogramma.Fill (2.1) ;
    istogramma.Fill (-1.4) ;
    istogramma.Fill (-3.5);
    istogramma.Fill (4);
    
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
