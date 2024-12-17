/*	Generazione numeri pseudocasuali tramite funzione inversa di una distribuzione ESPONENZIALE

c++ -o funzioneinversa funzioneinversa.cpp `root-config --glibs --cflags` 
./funzioneinversa
*/
#include <iostream> 
#include <cmath>
#include <iomanip>
#include "TH1F.h"
#include "TCanvas.h"

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

void rnd(){ //aggiorno il seed con l'algoritmo LCG (generatore lineare congruenziale )
    seed_ = (A* seed_ + C)%M;
    return;
}

float rand_range(float min, float max){ //Aggiorno il seed e lo scalo nel range [min, max] :[Ymin,Ymax]=[0,1]
    rnd();
    return min + (max - min)*seed_ / static_cast<float> (M);
}


//FUNZIONE INVERSA ESPONENZIALE
float inv_exp(float y){
    /*
        For completeness we define the \lambda parameter of the 
        exponential distribution (actually a waste of memory but cool to play).
        pdf(x) = \lambda * exp(-\lambda x) x >= 0, 0 otherwise.
        F(x) = int_{0}^{x} pdf(x)dx = 1 - exp(-\lambda * x) for x >= 0, 0 otherwise.
        F^{-1}(y) = - (ln(1-y)) / \lambda
    */

    float lambda = 1;
    return - (log(1-y)/lambda);	
}


/*
void visualize(float* vals, int dim, int bins, float x_min, float x_max){
   
       // Simple visualization of the distribution in the shell output.
       // This function requires a pointer to the first element of an array of floats, its
       // dimension, the bin you want to represent and the edges x_min and x_max.

    float step = (x_max - x_min)/bins;
    std::cout << std::left << std::setw(4) << "Bin Range" << std::right << std::setw(10) << " " << "Entries" << std::endl ;
    for(int j  = 0; j < bins; ++j){
        float lower_edge = x_min + j*step;
        float upper_edge = x_min + (j+1)*step;
        
        std::cout << std::left << std::setw(4) << lower_edge << "," << std::right << std::setw(4) << upper_edge << ": " ;
        for(int i = 0; i < dim;  ++i){
            if (lower_edge <= vals[i] &&  vals[i] < upper_edge) std::cout << "=";
        }
        std::cout << "\n";
    }

    return;
}
*/

int main(){

    seed_ = 0; //setting global seed of the sequence
    int dim = 2000; //estraggo 2000 valori
    float vals[dim]; //Creo un array contenente le estrazioni pseudocausali dell'algoritmo 

    float y_min = 0;	//La F(x) varia tra 0 e 1
    float y_max = 1;
    
    TH1F histo ("histo", "EXPONENTIAL", 100, 0, 5) ;

    for(int i=0; i < dim; ++i){
        vals[i] = inv_exp(rand_range(y_min, y_max));
	histo.Fill(vals[i]);
    }
/*
    //Rough visualization of gaussian
    std::cout << "\n\nEXPONENTIAL\n\n" << std::endl;
    visualize(vals, dim, 10, 0, 5);
*/
    
    TCanvas c1 ;
    histo.Draw () ;
    c1.Print ("EXPONENTIAL.png", "png") ;



}
