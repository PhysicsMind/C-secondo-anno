//Cro una DISTRIBUZIONE UNIFORME, GAUSSIANA, POISSONIANA con l'algoritmo TAC (Try and Catch)
/*
c++ -o tryandcatch  tryandcatch.cpp `root-config --glibs --cflags` 
./tryandcatch
*/
#include <iostream> 
#include <cmath>
#include <iomanip>
#include "TH1F.h"
#include "TCanvas.h"

//ALGORIRMO LCG 

static const int A =  214013;
static const int C =  2531011;
static const int M =  2147483647;
long int seed_;

void rnd(){  //aggiorno il seed con l'algoritmo LCG (generatore lineare congruenziale )
    seed_ = (A* seed_ + C)%M;
    return;
}

float rand_range(float min, float max){ //Aggiorno il seed e lo scalo nel range [min, max]
    rnd();
    return min + (max - min)*seed_ / static_cast<float> (M);
}

//DICHIARAZIONE FUNZIONI DENSITÀ DI PROBABILITÀ

float fgaus (float x){		//Distribuzione Gaussiana con Sigma=1 e non normalizzata
    return exp (-0.5 * x * x) ; 
}

float fpois (float x){
    /*	Distribuzione poissoniana con mu=3
    	
        The definition of a factorial cannot be defined for non-integers, 
        but a common generalization is the gamma function, defined for all 
        positive reals and all negative non-integers -> true gamma in stl (std::tgamma).
    */
    float fact = std::tgamma(x+1);	//fattoriale di x tramite la GAMMA FUNCTION
    return exp(-3)*pow(3, x)/fact; 	//espressione Poissoniana
}

float funif (float x){	//Distribuzione uniforme "in [-2,2]" costante a 1/4
    return float(1)/4;
}

//ALGORITMO TRY AND CATCH
float rand_TAC (float f (float), float xMin, float xMax, float yMax){
    /*
        Try and catch. input requires a function  (f) taking as
        inputs float values and output float values. The algorithm also 
        requires x_min and x_max to extract a uniform number in this range.
        It then requires the y_max of the pdf (as pdf are non-negative y_min=0).
    */
    float x = 0. ;
    float y = 0. ; 
    do {
      x = rand_range (xMin, xMax) ;	//genero direttamente i punti nel grafico nel range [min,max] con altezza y data dalla pdf
      y = rand_range (0, yMax) ;
    } while (y > f (x)) ;	//Ripetere la generazione fino a che la condizione y < f(x) non è soddisfatta
    return x ; 
}

/*										//VISUALIZZAZIONE DETTAGLI NELLA SHELL
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
    float vals[dim]; //Creo un array contenente le estrazioni pseudocausali dell'algoritmo TAC
    
    //GAUSSIANA

    float x_min = -3;		//Definisco l'intervallo di estrazione [Xmin,Xmax]
    float x_max = 3;

    TH1F hist_gauss ("hist_gauss", "GAUSS", 100 , x_min, x_max) ;

    for(int i=0; i < dim; ++i){
        vals[i] = rand_TAC(fgaus, x_min, x_max, 10);	//riempio il vettore
	hist_gauss.Fill (vals[i]);			//assegno man mano i punti nell'istogramma
    }

    TCanvas c1 ;
    hist_gauss.Draw () ;
    c1.Print ("hist_gauss.png", "png") ;
    
   /*
    //Rough visualization of gaussian
    std::cout << "\n\nGAUSSIAN\n\n" << std::endl;
    visualize(vals, dim, 10, x_min, x_max);
   */
   
   //POISSONIANA
    
    x_min = 0;		//definisco un nuovo intervallo
    x_max = 10;
   
    TH1F hist_poisson ("hist_poisson", "POISSON", 100 , x_min, x_max) ;
    
    for(int i=0; i < dim; ++i){
        vals[i] = rand_TAC(fpois, x_min, x_max, 10);
	hist_poisson.Fill (vals[i]);
    }
    
    TCanvas c2 ;
    hist_poisson.Draw () ;
    c2.Print ("hist_poisson.png", "png") ;
  
  /*  
    //Rough visualization of poisson
    std::cout << "\n\nPOISSONIAN\n\n" << std::endl;
    visualize(vals, dim, 10, x_min, x_max);
  */
  
    //DISTRIBUZIONE UNIFORME

    x_min = -2;
    x_max = 2;
 
    TH1F hist_uniform ("hist_uniform", "UNIFORM", 100 , x_min-1 , x_max+1) ;
 
    for(int i=0; i < dim; ++i){
        vals[i] = rand_TAC(funif, x_min, x_max, float(1)/4);
	hist_uniform.Fill (vals[i]);
    }
    
    TCanvas c3 ;
    hist_uniform.Draw () ;
    c3.Print ("hist_uniform.png", "png") ;

  /*  
    //Rough visualization of uniform
    std::cout << "\n\nUNIFORM\n\n" << std::endl;
    visualize(vals, dim, 10, x_min, x_max);
  */

    return 0;
}
