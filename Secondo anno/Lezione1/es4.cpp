#include <iostream>
#include <math.h>

bool solve2nddegree (double par[3], double x[2])
  { 
    bool esistenza = false;
    double determinante;
    
    determinante = par[1]*par[1] - 4*par[0]*par[2];
    if (determinante >= 0){   //se esistono soluzioni bool vale 1
      esistenza = true;
     }
    return esistenza;
  }
 
void soluzioni (double par[3], double x[2]){
 
   x[0] = (-par[1]+sqrt(par[1]*par[1] - 4*par[0]*par[2]))/(2*par[0]);
   x[1] = (-par[1]-sqrt(par[1]*par[1] - 4*par[0]*par[2]))/(2*par[0]);

}

int main (int arcg, char ** argv)
  {
    bool esistenza;
    double par[3]= {2.0,9.0,5.0};  //coefficienti eq. ax^2+bx+c=0
    
    double x[2]= {0,0};
    esistenza = solve2nddegree(par,x);
    if (esistenza == false){
        std::cout << "Non esistono soluzioni reali" << std::endl ;
        }
    else{
        soluzioni (par,x);
    	std::cout << "Esistono soluzioni reali e sono: " << x[0]<<" "<<x[1]<<std::endl ;
    
        }
   
    return 0 ;
  }

