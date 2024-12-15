#include <iostream>
#include <math.h>

void ordinavettore (int l , int v[]){
	int min, temp;
	
	for(int i=0; i<l; i++){
	    min=v[i];
	    temp=v[i];
	    for(int cont=0; cont<i; cont++){
	    	if(v[cont]<v[i]){
	    	min=v[cont];
	    	temp=v[i];
	    	v[i]=min;
	    	v[cont]=temp;
	    	}
	    }
	}
}

void stampavettore(int l, int v[]){
 
   std::cout << "Gli elementi del vettore sono: "<< std::endl;
   for(int i=0; i<l; i++){
       std::cout << v[i] << std::endl;
   }
}

int main(){
	int N;
  	int i;
   std::cout<<"Inserire la lunghezza del vettore: "<<std::endl;
   std::cin >> N ;
   int v[N];
   for (i=0; i<N; i++){
   	std::cout <<"Elemento" << i+1 << ": "<<std::endl;
   	std::cin  >> v[i] ;
   }
   stampavettore(N,v);
   ordinavettore(N,v);
   std::cout << "VETTORE ORDINATO" << std::endl;
   stampavettore(N,v);

   return 0;
}
