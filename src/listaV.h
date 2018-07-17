/*
 * lista.h
 *
 *  Created on: 13/mag/2013
 *      Author: Marco
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "cellaV.h"
#include <iostream>
using namespace std;

template <class T>
class ListaV{
public:
	typedef CellaV<T>* posizione;
	typedef T tipoelem;
	ListaV(); //costruttore
	~ListaV(); //distruttore
	//dichiarazione operatori
	void creaLista();
	bool listaVuota() const;
	tipoelem leggiLista(posizione) const;
	void insLista(posizione&,tipoelem);
	void scriviLista(posizione,tipoelem);
	void cancLista(posizione&);
	posizione primoLista() const;
	bool fineLista(posizione) const;
	posizione succLista(posizione) const;
	posizione predLista(posizione) const;
	//Funzioni di servizio
	void stampaLista();
private:
	posizione pos;
};

template <class T> ListaV<T>::ListaV(){creaLista();};
template <class T> ListaV<T>::~ListaV(){};

template <class T> void ListaV<T>::creaLista(){
	pos=new CellaV<T>;
	pos->scriviSucc(NULL); //successivo non esiste quando creo una cella, quindi NULL
	pos->scriviPrec(pos); //precedente invece lo imposto a se stesso
}

template <class T> bool ListaV<T>::listaVuota() const {
	return((pos->leggiSucc()==NULL && pos->leggiPrec()==pos));
}

template <class T> T ListaV<T>::leggiLista(posizione p) const {
	if (!listaVuota())
		return(p->leggiCella());
}

template <class T> void ListaV<T>::insLista(posizione& p,tipoelem a) {
	posizione temp = new CellaV<T>;
	if(p->leggiSucc()==NULL)
	{
		temp->scriviSucc(NULL);
		temp->scriviPrec(p);
		p->scriviSucc(temp);
	}
	else
	{
		temp->scriviPrec(p);
		temp->scriviSucc(p->leggiSucc());
		p->leggiSucc()->scriviPrec(temp);
	    p->scriviSucc(temp);
	}
	temp->scriviCella(a);
	p=temp;
}

template <class T> void ListaV<T>::scriviLista(posizione p,tipoelem a){
	if (!listaVuota())
		p->scriviCella(a);
}

template <class T> void ListaV<T>::cancLista(posizione& p){
	if(!listaVuota())
	{
		posizione temp = p->leggiPrec();
	    if(fineLista(p))
	    {
	    	temp->scriviSucc(NULL);
	        delete (p);
	        p=temp;
	    }
	    else
	    {
	        temp->scriviSucc(p->leggiSucc());
	        p->leggiSucc()->scriviPrec(temp);
	        delete (p);
	        p=temp->leggiSucc();
	    }
	}
}

template <class T> CellaV<T>* ListaV<T>::primoLista() const {
	return(pos);
}

template <class T> bool ListaV<T>::fineLista(posizione p) const {
	if (!listaVuota())
		return(succLista(p)==NULL);
	else
		return(false);
}

template <class T> CellaV<T>* ListaV<T>::succLista(posizione p) const{
	if(!listaVuota())
		return(p->leggiSucc());
}

template <class T> CellaV<T>* ListaV<T>::predLista(posizione p) const{
	if(!listaVuota())
		return(p->leggiPrec());
}

// FUNZIONI DI SERVIZIO

template <class T> void ListaV<T>::stampaLista(){
	//inserire if listaVuota();
	cout<<"[";
	CellaV<T>* indice=primoLista();
	do
	{
		indice = succLista(indice);
		cout << leggiLista(indice);
		if (!fineLista((indice)))
			cout << ",";
	}while (!fineLista(indice));
	cout<<"]\n";
}

#endif /* LISTA_H_ */
