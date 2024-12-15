#ifndef complesso_h
#define complesso_h

class complesso
{
public: 
  complesso (double r, double i) ;  //costruttori
  complesso (double r);
  complesso ();
  complesso (const complesso & orig);  //  copy constructor, come argomento ha un altro complesso già esistente
  ~complesso () ;   //distruttore

  double modulo () ;      
  //double fase () ;    
  double parte_reale () const;
  double parte_immaginaria () const;
 
  void stampami();  
  
  complesso & operator= (const complesso & orig); //punto al complesso che è uguale tramite referenza
  complesso operator+ (const complesso & addendo);
  complesso operator- (const complesso & addendo);
  complesso operator* (const complesso & fattore);
  complesso& operator+= (const complesso & addendo); //fa la somma restituendo il primo complesso aggiornato
  complesso& operator-= (const complesso & addendo);
  complesso& operator*= (const complesso & addendo);
  complesso& operator/= (const complesso & addendo);
  

private:
  double m_real ;
  double m_imag ;
} ;

 complesso operator+ (const complesso & uno, const double & due); //somma tra complesso e un altro oggetto (reale)
 complesso operator* (const complesso & uno, const double & due); //prodotto tra complesso e un altro oggetto (reale)

#endif
