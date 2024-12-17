#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TGraph.h"

#include "prova1.h"
#include "statistiche.h"
using namespace std;
int main(int argc, char** argv) {
if (argc < 2) {
	cerr << "uso: " << argv[0] << "inserire valore di mu" << endl ;
	exit (1) ;
      }
double mu = atof(argv[1]);
vector<double> n_exp;

	for (int i = 0; i < 1000; i++){
		n_exp.push_back(rand_IFC_Exp (mu));
}
double mean = media(n_exp);
double sgm = sigma (n_exp);

TH1F istogramma ("istogramma", "esponenziale", 60, 0., mean+3*sgm) ;
	for(int i = 0; i < 1000; i++) {
		istogramma.Fill(n_exp.at(i));
	}
TCanvas c1 ;
    istogramma.SetFillColor (kOrange + 1) ;
    istogramma.GetXaxis ()->SetTitle ("asse x") ;
    istogramma.GetYaxis ()->SetTitle ("conteggi per bin") ;
    istogramma.Draw () ;
    c1.Print ("prova1.png", "png") ;
double mediaG = 0;
double sigmaG = 0;
cout << "inserire media della gaussiana desiderata: " << endl;
cin >> mediaG;
cout << "inserire sigma della gaussiana desiderata: " << endl;
cin >> sigmaG;
TH1F istogramma2 ("istogramma2", "Gaussiana", 60, 0., mediaG+3*sigmaG) ;
vector <double> n_gauss;
	for(int i = 0; i < 1000; i++) {
		n_gauss.push_back(gauss_TCL(mediaG, sigmaG, 10));
	}
	for(int i = 0; i < 1000; i++) {
		istogramma2.Fill(n_gauss.at(i));
	}
TCanvas c2 ;
    istogramma2.SetFillColor (kBlue + 1) ;
    istogramma2.GetXaxis ()->SetTitle ("asse x") ;
    istogramma2.GetYaxis ()->SetTitle ("conteggi per bin") ;
    istogramma2.Draw () ;
    c2.Print ("prova1_Gauss.png", "png") ;

double media_campione = media (n_gauss);
double varianzaND = varianza(n_gauss);
double sk = asimmetria(n_gauss);
cout << "media del campione: " << media_campione << endl;
cout << "varianza non distorta: " << varianzaND << endl;
cout << "asimmetria: " << sk <<endl;
return 0;
}
