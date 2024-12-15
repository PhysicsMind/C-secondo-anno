//Funzione somma con template

//c++ -o  es1 es1.cpp

#include <iostream>
#include <math.h>

template <typename T>
	T somma (T a, T b)
  	{
   	 return a + b ;
 	}

int main(){
	
	int a=10;
	int b=11;
	//int sommainteri;
	double d=3.5;
	double e=5.5;
	//double sommarazionali;

	std::cout << "somma di interi    " << somma (a, b) << std::endl ;
	std::cout << "somma di interi    " << somma<int> (a, b) << std::endl ;
	std::cout << "somma di razionali " << somma (d, e) << std::endl ;
	

 return 0;
}
