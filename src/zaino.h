#ifndef ZAINO_H_
#define ZAINO_H_
#include <iostream>
using namespace std;
#include "nodoZ.h"

template <class T>
class Pila{
public:
	typedef Nodo<T>* posizione;
	typedef T tipoelem;
	Pila(); // costruttori
	~Pila(); // distruttore
	void creaPila(); //operatori
	bool pilaVuota();
	tipoelem leggiPila();
	void fuoriPila();
	void inPila(tipoelem);
	//Funzioni di servizio
	//void stampapila();
	//void stampapila2();

private:
	posizione pos;
};

template <class T> Pila<T>::Pila(){
	creaPila();
}

template <class T> Pila<T>::~Pila(){}

template <class T> void Pila<T>::creaPila(){
	pos= new Nodo<T>;
	pos->scriviSucc(NULL); //successivo non esiste quando creo un nodo, quindi NULL
}

template <class T> bool Pila<T>::pilaVuota(){
	return(pos->leggiSucc()==NULL);
}

template <class T> T Pila<T>::leggiPila(){
	if (!pilaVuota())
		return(pos->leggiSucc()->leggiNodo()); // Valore che ritorna se la pila non è vuota
	else{
		//cout << "\nLa pila e' vuota...\n" << endl;
		return(0); // Valore che ritorna se la pila è vuota
	}
}

template <class T> void Pila<T>::fuoriPila(){
	if (!pilaVuota()){
		posizione temp = new Nodo<T>;
		temp->scriviSucc(pos->leggiSucc()->leggiSucc());
		delete(pos->leggiSucc());
		pos->scriviSucc(temp->leggiSucc());
		delete(temp);
	}
	/*else {
		cout<<"\nNessun elemento nella pila..\n"<<endl;
	}*/
	//oppure
	/*
	 *  posizione temp=top->getSucc();
	 *  top->setSucc(temp->getSucc());
	 *  delete temp;
	 */
}

template <class T> void Pila<T>::inPila(tipoelem el){
	posizione temp = new Nodo<T>;
	temp->scriviSucc(pos->leggiSucc());
	pos->scriviSucc(temp);
	temp->scriviNodo(el);
}

//STAMPA PILA
/*template <class T> void Pila<T>::stampapila(){
	tipoelem Elemento;
	if (pilaVuota())
		return;
	else {
		Elemento = leggiPila();
		fuoriPila();
		cout << Elemento << endl;
		stampapila();
		inPila(Elemento);
	}
}

template <class T> void Pila<T>::stampapila2(){
	tipoelem Elemento;
	if (pilaVuota())
		return;
	else {
		Elemento = leggiPila();
		fuoriPila();
		stampapila2();
		cout << Elemento << endl;
		inPila(Elemento);
	}
}*/

#endif /* ZAINO_H_ */
