/*
 * cella.h
 *
 *  Created on: 13/mag/2013
 *      Author: Marco
 */

#ifndef CELLAV_H_
#define CELLAV_H_

template <class T>
class CellaV{
public:
	typedef T tipoelem;
	CellaV();
	~CellaV();
	void scriviCella(tipoelem);
	tipoelem leggiCella();
	CellaV* leggiSucc();
	CellaV* leggiPrec();
	void scriviSucc(CellaV*);
	void scriviPrec(CellaV*);
private:
	tipoelem elemento;
	CellaV* succ;
	CellaV* prec;
};

template <class T> CellaV<T>::CellaV(){}

template <class T> CellaV<T>::~CellaV(){}

template <class T> void CellaV<T>::scriviCella(tipoelem a){
	elemento=a;
}

template <class T> T CellaV<T>::leggiCella() {
	return(elemento);
}

template <class T> CellaV<T>* CellaV<T>::leggiSucc(){
	return(succ);
}

template <class T> CellaV<T>* CellaV<T>::leggiPrec(){
	return(prec);
}

template <class T> void CellaV<T>::scriviSucc(CellaV* s){
	succ=s;
}
template <class T> void CellaV<T>::scriviPrec(CellaV* p){
	prec=p;
}

#endif /* CELLAV_H_ */
