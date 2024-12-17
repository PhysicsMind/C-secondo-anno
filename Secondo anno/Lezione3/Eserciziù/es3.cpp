
#include <iostream>
#include <fstream>
//#include <vector>


int main (int argc, char ** argv){

   std::ifstream input_file ;
   input_file.open ("eventi_unif.txt", std::ios::in) ;  //apro il file eventi_unif.txt 
   
  // std::vector<double> data ;
   double input_val ;
   int numeroelementi=0;
   
   //CONTO GLI ELEMENTI DEL FILE
   while (true){   			 
   	input_file >> input_val ;
   	if (input_file.eof () == true) break ;  //è come se leggessi l'ultimo elemento due volte quindi incremento dopo che è uscito
    	numeroelementi++;		//aggiorno il contatore , ricorda che fa un ciclo a vuoto
   }
   
    std::cout << "Il numero di elementi del file sono:"<< numeroelementi<< std::endl;
    
    input_file.close () ; //chiudo il file 
    input_file.open ("eventi_unif.txt", std::ios::in) ;
    
    double * arraydinamico = new double [numeroelementi];
    
    int i=0; //indice del vettore
    
    //COPIO IL FILE NEL VETTORE DINAMICO
    while (true){   			
   	input_file >> input_val ;
   	if (input_file.eof () == true) break ;
   	
   	arraydinamico[i] = input_val;
   	i++;
   }
   
   //STAMPO I PRIMI 10 ELEMENTI
   std::cout << "I primi 10 elementi del file sono: "<< std::endl;
   for(int j=0; j<11; j++){
   	std::cout << "Elemento " << j << " :"<< arraydinamico[j] << std::endl;
   }
   
   /*
   //STAMPO I PRIMI 10 ELEMENTI PARI
   std::cout << "I primi 10 elementi PARI del file sono: "<< std::endl;
   for(int s=0; s<11; s++){
   	for(i=0; i<numeroelementi+1 ; i++){
   		if(arraydinamico[i]%2. == 0.){
   		std::cout <<"Elemento " << s << ":" << arraydinamico[i] << std::endl;
   		}
   	}
   }
   */
   
   //STAMPO MINIMO E MASSIMO
   int posmin=0; 
   int posmax=0;
   double min,max;
   min= arraydinamico[0];
   max= arraydinamico[0];
   for (int k=0; k<numeroelementi+1 ; k++){
   	if (arraydinamico[k] < min){
   		min=arraydinamico[k];
   		posmin=k;
   	}
   	if (arraydinamico[k] > max){
   		max=arraydinamico[k];
   		posmax=k;
   	}
   }
   std::cout << "Il numero massimo nel file è: " << arraydinamico[posmax] << std::endl;
   std::cout << "Il numero minimo nel file è: " << arraydinamico[posmin] << std::endl;
   
   
   
   delete [] arraydinamico;
   

 
  input_file.close () ; //chiudo il file 
  
  return 0;
}


