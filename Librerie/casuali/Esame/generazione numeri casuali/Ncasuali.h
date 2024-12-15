#ifndef Ncasuali_h
#define Ncasuali_h

double rand_range (double min, double max) ;

float fgaus (float x);

double fgausTAC (double x, double mean, double sigma);

float fpois (float x);

float rand_exp (double t_zero) ;

float rand_pois (double media) ;

double rand_IFC_Exp (double mu) ;

float rand_TAC (float f (float), float xMin, float xMax, float yMax);

float rand_TCL (float xMin, float xMax, int N = 10);

double Exp_gauss_TCL (double mean, double sigma, int N);

double rand_TCL_gaus (double mean, double sigma, int N);
#endif


