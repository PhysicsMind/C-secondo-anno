/*
c++ -o teoremacentralelimite teoremacentralelimite.cpp `root-config --glibs --cflags` 
./teoremacentralelimite
*/

#include <cstdlib>
#include <iostream> 
#include <cmath>
#include <iomanip>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

static const int seed = 1234567;

float rand_range (float min, float max){
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
} 

float normal(int N, float min, float max){
    /*
        Basic principle: 
        Uniform distribution in [a,b] has a mean of 0.5*(a+b) and a variance 1/12 * (b-a)^2.
        The mean of N uniformly distributed numbers is a variable that approximates a gaussian 
        distribution (exactly gaussian when N -> infinity).
    */

    float mean = 0;
    for(int i  = 0; i < N; ++i) mean += rand_range(min, max);
    return mean/N;

}

void visualize(float* vals, int dim, int bins, float x_min, float x_max){
    /*
        Simple visualization of the distribution in the shell output.
        This function requires a pointer to the first element of an array of floats, its
        dimension, the bin you want to represent and the edges x_min and x_max.

    */

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

int main(){

    srand(seed); //initializing seed for reproducibility of results
    int Ns[4] = {1, 2, 10, 50};
    
    int dim = 10000;
    int nBins = 50;
    float vals[dim];

    // Computing the distributions 

    for(auto N : Ns){
        float sum = 0;
        float sum_q = 0;

        for(int i = 0; i < dim; ++i){
            vals[i] = normal(N, -3, 3);
            sum += vals[i];
            sum_q += pow(vals[i],2);
        }
        float mean = sum/dim;
        float var = (sum_q + dim*pow(mean, 2) - 2*mean*sum)/(dim-1);

        std::cout << "\n\nGAUSSIAN N,mean,var: " << N << " " << mean << " " << var << "\n\n" << std::endl;
        //visualize(vals, dim, 10, -2, 2);

    }

    // Same thing but with standardization of the variables to obtain 
    // values distributed normally ~ N(0,1)
    
    TApplication myApp("myApp", NULL, NULL);

    TCanvas c0("c0","c0", 10, 10, 700, 500);
    c0.Divide(2,2);

    TH1F arrHisto[4];
    for (unsigned int i = 0; i < 4; i++)
    {
      TString myStr = "GAUSSIAN STANDARD ";
      myStr += Ns[i];
      //std::cout << "Histo name : " << myStr << std::endl;
      arrHisto[i] = TH1F(myStr, myStr, nBins, -3, 3);
    }

      
    for (unsigned int k = 0; k < 4; k++){
        
	float sum = 0;
        float sum_q = 0;
        int N = Ns[k];
	
        for(int i = 0; i < dim; ++i){
            vals[i] = normal(N, -3, 3);
            sum += vals[i];
            sum_q += pow(vals[i],2);
        }
        float mean = sum/dim;
        float var = (sum_q + dim*pow(mean, 2) - 2*mean*sum)/(dim-1);

        //standardizing
        // Z = (\hat{X} - \mu)/(\sigma) -> distributed normally ~ N(0,1) 
        
        sum = 0;
        sum_q = 0;
        for(int i = 0; i < dim; ++i){
            vals[i] = (vals[i] - mean)/sqrt(var);
	    arrHisto[k].Fill(vals[i]);
            sum += vals[i];
            sum_q += pow(vals[i],2);
        }

        mean = sum/dim;
        var = (sum_q + dim*pow(mean, 2) - 2*mean*sum)/(dim-1);
        
        std::cout << "\n\nGAUSSIAN STANDARD N,mean,var: " << N << " " << mean << " " << var << "\n\n" << std::endl;
        //visualize(vals, dim, 10, -3, 3);

    }

    for (unsigned int i = 0; i < 4; i++)
    {
      c0.cd(i+1);
      arrHisto[i].Draw();
    }

    c0.Modified();
    c0.Update();

    myApp.Run();

    

    return 0;
}
