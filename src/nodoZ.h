#ifndef NODOZ_H_
#define NODOZ_H_
#include <iostream>
using namespace std;

template <class T>
class Nodo{
public:
	typedef T tipoelem;
	Nodo();
	Nodo(tipoelem);
	~Nodo();
	void scriviNodo(tipoelem);
	tipoelem leggiNodo() const;
	bool operator ==(Nodo &);
	Nodo* leggiSucc();
	void scriviSucc(Nodo*);
private:
	tipoelem elemento;
	Nodo* succ;
};

// std::ostream & operator<<(std::ostream &, const Nodo & nodo);

template <class T> Nodo<T>::Nodo(){}

template <class T> Nodo<T>::~Nodo(){}

template <class T> Nodo<T>::Nodo(tipoelem label){
	elemento=label;
}

template <class T> void Nodo<T>::scriviNodo(tipoelem label){
	elemento=label;
}

template <class T> T Nodo<T>::leggiNodo() const{
	return (elemento);
}

template <class T> bool Nodo<T>::operator==(Nodo & n){
	return (leggiNodo() == n.leggiNodo());
}

template <class T> Nodo<T>* Nodo<T>::leggiSucc(){
	return(succ);
}

template <class T> void Nodo<T>:: scriviSucc(Nodo* s){
	succ=s;
}

/*std::ostream & operator<<(std::ostream & out, const Nodo & nodo){
	return out << nodo.getElemento();
}*/

#endif /* NODOZ_H_ */
