/*
c++ -o main_03 `root-config --glibs --cflags` main_03.cpp
*/

#include "TH1F.h"
#include "TCanvas.h"

int main (int argc, char ** argv)
  {
    TH1F istogramma ("istogramma", "titolo", 10, -5., 5.) ;

    istogramma.Fill (2.2) ;
    istogramma.Fill (2.1) ;
    istogramma.Fill (-1.4) ;

    TCanvas c1 ;
    istogramma.SetFillColor (kOrange + 1) ;
    istogramma.GetXaxis ()->SetTitle ("asse x") ;
    istogramma.GetYaxis ()->SetTitle ("conteggi per bin") ;
    istogramma.Draw () ;
    c1.Print ("esempio.png", "png") ;

    return 0 ;
  }
  
  //Riempimento di un istogramma con numeri casuali
  /*
c++ -o main_04 `root-config --cflags --glibs` main_04.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"

float fgaus (float x) 
  {
    return exp (-0.5 * x * x) ; 
  }

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 

float rand_TCL (float xMin, float xMax, int N = 10)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }

int main (int argc, char ** argv)
  {
    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;

    TH1F h ("h", "eventi pseudo-casuali Gaussiani", 200, -1.5, 1.5) ;

    for (int j = 0 ; j < 1000000 ; ++j)
      h.Fill (rand_TCL (-1., 1., 10)) ;

    h.GetXaxis ()->SetTitle ("numeri generati") ;
    h.SetFillColor (kOrange + 1) ;
    h.Draw () ;

    c1.Print ("Gaussian.png", "png") ;

    return 0 ;
  }
  
  //Visualizzazione in scala logaritmica
  
  
  c1.SetLogy () ;
  c1.Print ("Gaussian.png", "png") ;
