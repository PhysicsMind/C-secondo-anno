/*
c++ -o usoTstring usoTstring.cpp `root-config --glibs --cflags` 
./usoTstring (Neventi)
*/

#include "TH1F.h"
#include "TString.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc, char ** argv)
  {
    int num = atoi (argv[1]) ;
    TString titolo = "ci sono " ;
    titolo += num ;
    titolo += " eventi" ;
    TH1F istogramma ("istogramma", titolo, 10, -5., 5.) ;
    for (int i = 0 ; i < num ; ++i) istogramma.Fill (2.2) ;

    TApplication theApp ("theApp", &argc, argv) ;
    TCanvas c1 ;
    istogramma.Draw () ;
    theApp.Run () ;

    return 0 ;
  }
