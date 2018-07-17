#ifndef _LISTA_P_H
#define _LISTA_P_H

using namespace std;

#include <iostream>
#include "cellaP.h"

template<typename T> class Lista {
public:
	typedef Cella<T>* posizione;
	Lista();
	Lista(const Lista<T> &);
	~Lista();
	bool vuota();
	bool fine(posizione);
	posizione primo();
	posizione prec(posizione);
	posizione succ(posizione);
	void ins(posizione &pos, T);
	void canc(posizione &pos);
	T *leggi(posizione);
	void scrivi(posizione, T);
	Lista<T>& operator=(const Lista<T> &);
private:
	posizione lista;
};

template<typename T> Lista<T>::Lista() {
	lista = NULL;
}

template<typename T> Lista<T>::Lista(const Lista<T> & l) {
	lista = l.lista;
}

template<typename T> Lista<T>::~Lista() {
}

template<typename T> Lista<T>& Lista<T>::operator=(const Lista<T> & l) {
	lista = l.lista;
	return *this;
}

template<typename T> bool Lista<T>::vuota() {
	return (lista == NULL);
}

template<typename T> bool Lista<T>::fine(posizione pos) {
	return (pos == NULL);
}

template<typename T> Cella<T>* Lista<T>::primo() {
	return lista;
}

template<typename T> Cella<T>* Lista<T>::succ(posizione pos) {
	if (pos != NULL)
		return pos->get_succ();
	else
		return pos;
}

template<typename T> Cella<T>* Lista<T>::prec(posizione pos) {
	posizione posaux = lista;
	while (posaux->get_succ() != pos)
		posaux = posaux->get_succ();
	return posaux;
}

template<typename T> void Lista<T>::ins(posizione &pos, T elem) {
	Cella<T>* temp = new Cella<T> ;

	temp->scrivi(elem);
	temp->set_succ(pos);
	if (pos == lista) {
		lista = temp;
	} else {
		prec(pos)->set_succ(temp);
	}
	pos = temp;
}

template<typename T> void Lista<T>::canc(posizione &pos) {
	posizione temp = pos;
	posizione successivo = pos->get_succ();
	if (pos == lista)
		lista = successivo;
	else
		prec(pos)->set_succ(successivo);
	pos = successivo;
	delete (temp);
}

template<typename T> T *Lista<T>::leggi(posizione pos) {
	if (pos != NULL)
		return pos->leggi();
}

template<typename T> void Lista<T>::scrivi(posizione pos, T elem) {
	if (pos != NULL)
		pos->scrivicella(elem);
}

#endif           

