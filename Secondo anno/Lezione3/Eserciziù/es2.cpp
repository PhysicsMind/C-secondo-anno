//USA UNA MEMORIA DINAMICA PER L'OGGETTO (ricorda delete)

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc, char ** argv)
  {
    TH1* h1 = new TH1F ("istogramma", "titolo", 10, -5., 5.);

    h1->Fill (2.5) ;
    h1->Fill (2.1) ;
    h1->Fill (-1.4) ;
    h1->Fill (-3.5);
    h1->Fill (4);
    
    TApplication theApp ("theApp", &argc, argv) ;
	
    TCanvas c1 ;
    h1->Draw () ;
    c1.Print ("esempio.png", "png") ;
    
    theApp.Run () ;
    
    delete h1;

    return 0 ;
  }
