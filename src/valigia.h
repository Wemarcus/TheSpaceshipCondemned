/*
 * insieme.h
 *
 *  Created on: 13/mag/2013
 *      Author: Marco
 */

#ifndef VALIGIA_H_
#define VALIGIA_H_
#include <iostream>
using namespace std;
#include "listaV.h"

template <class T>
class Insieme{
public:
	typedef T tipoelem;
	Insieme();
	~Insieme();
	void creaInsieme();
	bool InsiemeVuoto();
	bool Appartiene(tipoelem);
	void Inserisci(tipoelem);
	void Cancella(tipoelem);
	//Insieme<T> Unione(Insieme<T>&);
	//Insieme<T> Intersezione(Insieme<T>&);
	//Insieme<T> Differenza(Insieme<T>&);
	Insieme<T> operator = (const Insieme<T>&);
	//FUNZIONI DI SERVIZIO:
	void stampaInsieme();
private:
	ListaV<T> lista;
};

template <class T> Insieme<T>::Insieme(){creaInsieme();};

template <class T> Insieme<T>::~Insieme(){};

template <class T> void Insieme<T>::creaInsieme(){
	lista.creaLista();
}

template <class T> bool Insieme<T>::InsiemeVuoto(){
	return(lista.listaVuota());
}

template <class T> bool Insieme<T>::Appartiene(tipoelem a){
	CellaV<T>* indice=lista.primoLista();
	bool trovato=false;
	if(!lista.listaVuota()){
		do
		{
			indice = lista.succLista(indice);
			if(a==lista.leggiLista(indice)){
				trovato=true;
			}
		}while (!lista.fineLista(indice) && !trovato);
		//return(trovato);
	}
	return(trovato);
}

template <class T> void Insieme<T>::Inserisci(tipoelem a){
	CellaV<T>* indice=lista.primoLista();  //è l'indice della lista ordinata
    if(lista.listaVuota())
    {
    	lista.insLista(indice, a);
    }
        else if(!Appartiene(a))
        {
            while(!lista.fineLista(indice) && a>lista.leggiLista(lista.succLista(indice)))
            {
                indice=lista.succLista(indice);
            }
            lista.insLista(indice, a);
        }
}

template <class T> void Insieme<T>::Cancella(tipoelem a){
	CellaV<T>* indice=lista.primoLista();
	if(Appartiene(a)){
		indice = lista.succLista(indice);
		while (!lista.fineLista(indice) && a!=lista.leggiLista(indice)){
			indice=lista.succLista(indice);
		}
		lista.cancLista(indice);
	}
}

/*template <class T> Insieme<T> Insieme<T>::Unione(Insieme<T>& i2){
	CellaV<T>* indice=lista.primoLista();
	Insieme<T> temp;
	temp=i2;
	do
	{
		indice = lista.succLista(indice);
		temp.Inserisci(lista.leggiLista(indice));
	}while (!lista.fineLista(indice));
	return temp;
}

template <class T> Insieme<T> Insieme<T>::Intersezione(Insieme<T>& i2){
	CellaV<T>* indice=lista.succLista(lista.primoLista());
	Insieme<T> temp;
	do
	{
		if(i2.Appartiene(lista.leggiLista(indice)))
			temp.Inserisci(lista.leggiLista(indice));
		indice=lista.succLista(indice);
	}while (!lista.fineLista(indice));
	if(i2.Appartiene(lista.leggiLista(indice)))
		temp.Inserisci(lista.leggiLista(indice));
	return temp;
}

template <class T> Insieme<T> Insieme<T>::Differenza(Insieme<T>& i2){
	CellaV<T>* indice=lista.primoLista();
	Insieme<T> temp;
	//temp=i2; //B-A
	temp=*this; //A-B
	do
	{
		indice = lista.succLista(indice);
		if(i2.Appartiene(lista.leggiLista(indice)))
			temp.Cancella(lista.leggiLista(indice));
	}while (!lista.fineLista(indice));
	return temp;
}*/

template <class T> Insieme<T> Insieme<T>::operator=(const Insieme<T> &i2){
	CellaV<T>* indice=i2.lista.primoLista();

	if(!i2.lista.listaVuota())
	{
		do{
			indice=i2.lista.succLista(indice);
			Inserisci(i2.lista.leggiLista(indice));
		}while(!i2.lista.fineLista(indice));
	}
	return *this;
}

//FUNZIONI DI SERVIZIO

template <class T> void Insieme<T>::stampaInsieme(){
	CellaV<T>* indice=lista.primoLista();
	if(!lista.listaVuota())
	{
		do
		{
			indice=lista.succLista(indice);
			//oggetti.get_zaino(lista.leggiLista(indice));
			cout << "- " << lista.leggiLista(indice) << endl;
		}while(!lista.fineLista(indice));
	}
	else
		cout << "Insieme Vuoto.." << endl;
}

#endif /* VALIGIA_H_ */
