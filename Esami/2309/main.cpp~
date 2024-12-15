

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "TH1F.h"
#include "TCanvas.h"
#include  "TGraph.h"
#include "TGraphErrors.h"

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 


double fsin (double x) 
  {
    return sin (x) ; 
  }

bool isBelow (double g (double), double xMin, double xMax,
              double yMin, double yMax)
  {
    double x = rand_range (xMin, xMax) ;
    double y = rand_range (yMin, yMax) ; 
    if (y < g (x)) return true ; 
    return false ;
  }

void calcolointegrale(double xMax,double xMin,double yMax,double yMin,int nHit,int N, double vector[2])
{
  
  double Area     = (xMax - xMin) * (yMax - yMin) ;
  double Integral = nHit * Area / static_cast<double> (N) ;
  double p        = nHit / static_cast<double> (N) ;
  double Var      = Area * Area / static_cast<double> (N) * p * (1. - p) ;
  double StdDev   = sqrt (Var) ;
  
  vector[0]=Integral;
  vector[1]=StdDev;
  
}

int main (int argc, char ** argv)
{
 
  srand (time (NULL)) ;
 
  int nHit = 0 ;
  double xMin = 0. ;
  double xMax = M_PI ; 
  double yMin = 0. ; 
  double yMax = 1. ;
  double vettore[2];
TGraphErrors g_int;

for(int N=10; N<=100000; N=N*10)
{
  for (int i = 0 ; i < N ; ++i) 
    {
      if (isBelow (fsin, xMin, xMax, yMin, yMax) == true) ++nHit ; 
    }
	
  calcolointegrale(xMax,xMin,yMax,yMin,nHit,N,vettore);

  std::cout<<"Integrale con N pari a "<<N<<" vale: "<<vettore[0]<<" incertezza: "<<vettore[1]<<std::endl;
  g_int.SetPoint(g_int.GetN(), N, vettore[0]);
  g_int.SetPointError(g_int.GetN()-1,0,vettore[1]);
  nHit=0;
 }
 
 TCanvas c1("c1","c1",100,100,1000,1000);
 
 g_int.SetMarkerStyle (20) ;
g_int.SetMarkerColor (kAzure - 1) ;
g_int.SetMarkerSize (1) ;
g_int.SetLineWidth(2);
//g_int.GetHistogram ()->GetXaxis ()->SetTitle ("numero di eventi nel campione") ;
//g_int.GetHistogram ()->GetYaxis ()->SetTitle ("integrale") ;
c1.SetLogx () ;

g_int.Draw ("APE") ;
c1.Print ("gintegrale_es6.png", "png") ;

 
 
  return 0 ;
}

