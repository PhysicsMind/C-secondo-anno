#ifndef casual_h
#define casual_h

//FUNZIONI per TAC

float fgaus (float x);		//Distribuzione Gaussiana con Sigma=1 e non normalizzata

double fgausTAC (double x, double mean, double sigma) ;

float fpois (float x);

//RANDOM CLASSICO

double random_range (double min, double max) ;

float rand_exp (double t_zero) ;

float rand_pois (double media) ;

//RANDOM TAC (Try and Catch)

float rand_TAC (float f (float), float xMin, float xMax, float yMax);

double rand_TAC_gaus (double mean, double sigma);

//RANDOM TEOREMA CENTRALE LIMITE
double rand_TCL_gaus (double mean, double sigma, int N) ;


#endif
