
#include <iostream>
#include <math.h>
#include <cstdlib>

int main(){
	int M = 2147483647.;
	int A = 214013;
	int C = 2531011;
	
	int numeronumeri=10;
	
	int seed;
	int psd;
	std::cout << "Inserire un seme nell'algoritmo :" << std::endl;
	std::cin >> seed ;
	
	for(int i=0; i<numeronumeri; i++){
		psd= (A*seed+C) % M;
		std::cout << "Il numero pseudocasueale è :" << psd << std::endl;
		seed=psd;
	}




	return 0;
}
