#include "complesso.h"
#include <math.h>
#include <iostream>

//COSTRUTTORI

complesso::complesso(double r, double i): //costruttore più veloce
	m_real (r),			//questa scrittura velocizzà l'utilizzo della memoria
	m_imag  (i)
{  
	//std::cout <<"costruzione di un numero complesso"<< std::endl;
} 

complesso::complesso (const complesso & orig): //copy contructor
  m_real (orig.m_real),			//ha come argomento un altro coplesso
  m_imag (orig.m_imag)				//copio il suo contenuto in un nuovo complesso
  {}			//esempio: complesso nome_complesso2 (nome_complesso1);

complesso::complesso (double r): //overloading del costruttore, argomento diverso
  m_real (r),
  m_imag (0.)
  {
    //std::cout << "costruzione di un numero complesso" << std::endl ;
  }

complesso::complesso (): //costruttore di default, numero complesso (0,0)
  m_real (0.),
  m_imag (0.)
  {
    //std::cout << "costruzione di un numero complesso" << std::endl ;
  }


complesso::~complesso ()   //distruttore
  {
    // qui va ripulita la memoria allocata dinamicamente
  }

//METODI INTERNI ALLA CLASSE
  
double complesso::modulo ()
  {
    return sqrt (m_real * m_real + m_imag * m_imag) ;
  }   
  
void complesso::stampami ()
  {
    std::cout << this-> m_real << " + " << this-> m_imag << "i" << std::endl ; 
    return;	////this è il puntatore all'oggetto corrente
  }
  
double 
complesso::parte_reale () const  //restituisce la parte reale
{
  return m_real ;
}

double 
complesso::parte_immaginaria () const
{
  return m_imag ;
}
  
/*
double complesso::fase (){
	if(m_real=0){
		if(m_imag>0)
			return 3.14/2;
		if(m_imag<0)
			return -3.14/2;
		if(m_imag=0)
			std::cout<<"Fase non definita"<<std::endl;
			return 0;
	}
	if(m_real>0){
		return atan(m_imag/m_real);
	}
	if(m_real<0){
		if(m_imag>=0)
			return atan(m_imag/m_real)+3.14;
		if(m_imag<0)
			return atan(m_imag/m_real)-3.14;
	}
}*/

//METODI TRA OGGETTI

complesso & complesso::operator= (const complesso & orig) //punto al complesso che è uguale tramite referenza
{
  m_real = orig.m_real ;
  m_imag = orig.m_imag ;
  return *this ;
}  

complesso complesso::operator+ (const complesso & addendo){ 	//operatore di somma
	return complesso (m_real + addendo.m_real , m_imag+ addendo.m_imag); 
} 

/* complesso complesso::operator+ (const complesso & addendo)  //operatore di somma alternativo
{
 complesso somma (m_real, m_imag) ;
 somma.m_real = somma.m_real + addendo.m_real ;
 somma.m_imag = somma.m_imag + addendo.m_imag ;
 return somma ; 
} */


complesso complesso::operator- (const complesso & addendo){
	return complesso (m_real- addendo.m_real , m_imag- addendo.m_imag);
}

complesso complesso::operator* (const complesso & fattore){
	return complesso (m_real*fattore.m_real-m_imag*fattore.m_imag , m_real*fattore.m_imag+m_imag*fattore.m_real);
	//(a+ib)(c+id)=ac+adi+bci-bd
}


complesso& complesso::operator+= (const complesso & addendo){	
						//deve fare c1 = c1+c2 restituendo c1 aggiornato
	m_real = m_real + addendo.m_real ;
 	m_imag = m_imag + addendo.m_imag ;
	return *this ; 
} 

complesso& complesso::operator-= (const complesso & addendo){	
						//deve fare c1 = c1-c2 restituendo c1 aggiornato
	m_real = m_real - addendo.m_real ;
 	m_imag = m_imag - addendo.m_imag ;
	return *this ; 
} 

complesso& complesso::operator*= (const complesso & fattore){	
						//deve fare c1 = c1*c2 restituendo c1 aggiornato
	m_real = m_real*fattore.m_real-m_imag*fattore.m_imag  ;
 	m_imag = m_real*fattore.m_imag+m_imag*fattore.m_real ;
	return *this ; 
} 

complesso& complesso::operator/= (const complesso & fattore){	
						//deve fare c1 = c1/c2 restituendo c1 aggiornato
	m_real = (m_real*fattore.m_real + m_imag*fattore.m_imag) / (fattore.m_real*fattore.m_real+fattore.m_imag*fattore.m_imag) ;
 	m_imag = (m_imag*fattore.m_real - m_real*fattore.m_imag) / (fattore.m_real*fattore.m_real+fattore.m_imag*fattore.m_imag) ;
	return *this ; 
} 

 
//METODI FUORI DALLA CLASSE 


complesso operator+ (const complesso & uno, const double & due) //somma tra complesso e parte reale
  {
    double real = uno.parte_reale () + due ; 
    double imag = uno.parte_immaginaria () ;
    complesso somma (real, imag) ;
    return somma ;
  } //esempio: complesso numero_complesso_5 = numero_complesso_4 + 5. ;
  
complesso operator* (const complesso & uno, const double & due) //prodotto tra complesso e parte reale
  {
    double real = uno.parte_reale () * due ; 
    double imag = uno.parte_immaginaria () * due ;
    complesso prodotto (real, imag) ;
    return prodotto ;
  } //esempio: complesso numero_complesso_5 = numero_complesso_4 * 5. ;
  
 
