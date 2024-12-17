#ifndef SimpleArray_h
#define SimpleArray_h
#include <iostream>



template <typename T>
class SimpleArray {
public:
  // Costruttore
  SimpleArray (const int & elementsNum) { 
  	elementsNum_p = elementsNum;
  	T * elements_p = new T(elementsNum); 
  }
  
  // Distruttore
  ~SimpleArray () {
   delete [] elements_p;
   }
   
  
  T & element (const int& i)  { 	//visualizzare elementi
  	if( i> -1 && i< elementsNum_p+1 ){
  	 return elements_p[i];
  	}
  	else{
  	std::cout<< "Elemento non esistente in questa posizione" << std::endl;
  	}
  
  }
  
  // Overloading di operator[]			//per aggiungere elementi 
  //T & operator[] (const int& i) { /* inserire  */ }

private:

  int elementsNum_p;
  T * elements_p;
} ;

#endif
