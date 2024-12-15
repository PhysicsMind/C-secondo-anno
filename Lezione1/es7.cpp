#include <iostream>
#include <math.h>

void riempivettore (int N , int v[]){
  
   for (int i=0; i<N; i++){
   	std::cout <<"Elemento" << i+1 << ": "<<std::endl;
   	std::cin  >> v[i] ;
   }
}

void cast (int N, int v[], double real[]){     //copia e trasforma i valori in double
	double re;
	for (int i=0; i<N; i++){
	     float re = static_cast<float>(v[i]);
	     real[i]=re;
	}
}

void stampavettoreint(int l, int v[]){
 
   std::cout << "Gli elementi del vettore sono: "<< std::endl;
   for(int i=0; i<l; i++){
       std::cout << v[i] << std::endl;
   }
}
void stampavettoredouble (int l, double v[]){
 
   std::cout << "Gli elementi del vettore sono: "<< std::endl;
   for(int i=0; i<l; i++){
       std::cout << v[i] << std::endl;
   }
}

int main(){
	int N;
	std::cout<<"Inserire la lunghezza del vettore: "<<std::endl;
        std::cin >> N ;
        int v[N];
        riempivettore(N,v);
   stampavettoreint(N,v);
   double copia[N];
   cast(N,v,copia);
   std::cout << "VETTORE COPIATO IN DOUBLE :" << std::endl;
   stampavettoredouble(N,copia);
   std::cout << "Questo è il puntatore all'array :"<< copia <<std::endl;
   

   return 0;
}
