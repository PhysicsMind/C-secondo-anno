#include <iostream>
#include <math.h>

void mediaevarianza (int N[10], double media, double varianza){
 
     int somma=0;
     double sommascartialquadrato=0; 
     int i;
     
     for (i=0; i<10; i++){
         somma= somma+N[i];
         std::cout<<"Somma parziale: " << somma << std::endl;
     }
     media=somma/10;
     for (i=0; i<10; i++){
        sommascartialquadrato=sommascartialquadrato+ (N[i]-media)*(N[i]-media);
     }
     varianza=sommascartialquadrato/10;
     std::cout << "La media vale: "<< media <<" e la varianza vale: "<< varianza<< std::endl;

}

int main() {
   int N[10]={1,3,4,5,6,7,8,9,10,11};
   double media;
   double varianza;
   mediaevarianza(N,media,varianza);





   return 0;
}
