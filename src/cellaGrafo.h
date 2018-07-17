#ifndef _CELLA_G_H
#define _CELLA_G_H

#include "listaP.h"
#include "arco.h"

using namespace std;

template<typename Nodo, class T, class P>
class CellaGrafo {
	public:
		CellaGrafo();
		CellaGrafo(const CellaGrafo<Nodo, T, P> &);
		~CellaGrafo();
		void set_etichetta(const T &);
		T get_etichetta();
		Lista< Arco<Nodo, P> > get_adiacenti();
		void set_adiacenti(Lista< Arco<Nodo, P> >);
		void stampa();
		CellaGrafo<Nodo, T, P>& operator=(const CellaGrafo<Nodo, T, P> &);
	private:
		T etichetta;
		Lista< Arco<Nodo, P> > adiacenti; // nodi adiacenti
};

template<typename Nodo, class T, class P>
CellaGrafo<Nodo, T, P>::CellaGrafo() {
}

template<typename Nodo, class T, class P>
CellaGrafo<Nodo, T, P>::CellaGrafo(const CellaGrafo<Nodo, T, P> &cella) {
	etichetta = cella.etichetta;
	adiacenti = cella.adiacenti;
}

template<typename Nodo, class T, class P>
CellaGrafo<Nodo, T, P>& CellaGrafo<Nodo, T, P>::operator=(
		const CellaGrafo<Nodo, T, P> &cella) {
	etichetta = cella.etichetta;
	adiacenti = cella.adiacenti;
	return *this;
}

template<typename Nodo, class T, class P>
CellaGrafo<Nodo, T, P>::~CellaGrafo() {
}

template<typename Nodo, class T, class P>
void CellaGrafo<Nodo, T, P>::set_etichetta(const T &etic) {
	etichetta = etic;
}

template<typename Nodo, class T, class P>
T CellaGrafo<Nodo, T, P>::get_etichetta() {
	return etichetta;
}

template<typename Nodo, class T, class P>
Lista< Arco<Nodo, P> > CellaGrafo<Nodo, T, P>::get_adiacenti() {
	return adiacenti;
}

template<typename Nodo, class T, class P>
void CellaGrafo<Nodo, T, P>::set_adiacenti(Lista< Arco<Nodo, P> > a) {
	adiacenti = a;
}

#endif
