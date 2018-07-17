#ifndef _GRAFO_H
#define _GRAFO_H

#define MAXLUNG 100
#include "listaP.h"
#include "dizionario.h"
#include "cellaGrafo.h"
#include "arco.h"
//REALIZZAZIONE CON LISTE DI ADIACENZA

using namespace std;

#include <iostream>

template<typename Nodo, typename E, typename P>
class Grafo {
	public:
		Grafo();
		~Grafo();
		bool grafoVuoto();
		void insnodo(Nodo);
		void insarco(Nodo, Nodo);
		void cancnodo(Nodo);
		void cancarco(Nodo, Nodo);
		Lista<Arco<Nodo, P> > adiacenti(Nodo);
		E legginodo(Nodo);
		void scrivinodo(Nodo, E);
		P leggiarco(Nodo, Nodo);
		void scriviarco(Nodo, Nodo, P);
		bool esistenodo(Nodo);
		bool esistearco(Nodo, Nodo);
		//operatori di servizio
		void stampa();
	private:
		Dizionario<Nodo, CellaGrafo<Nodo, E, P> > nodi; //insieme di nodo
};

template<typename Nodo, typename E, typename P>
Grafo<Nodo, E, P>::Grafo() {}

template<typename Nodo, typename E, typename P>
Grafo<Nodo, E, P>::~Grafo() {}

template<typename Nodo, typename E, typename P>
bool Grafo<Nodo, E, P>::grafoVuoto() {
	return nodi.dizionarioVuoto(); // linea 56 dizionario.h
}

template<typename Nodo, typename E, typename P>
bool Grafo<Nodo, E, P>::esistenodo(Nodo n) {
	return nodi.appartiene(n);
}

template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::insnodo(Nodo n) {
	if (!nodi.appartiene(n)) {
		CellaGrafo<Nodo, E, P> cella = CellaGrafo<Nodo, E, P> ();
		nodi.inserisci(n, cella);
	}
}

template<typename Nodo, typename E, typename P>
bool Grafo<Nodo, E, P>::esistearco(Nodo n, Nodo m) {
	bool trovato = false;
	if (esistenodo(n) && esistenodo(m)) {
		Lista<Arco<Nodo, P> > adiacenti = nodi.recupera(n).get_adiacenti();
		Cella<Arco<Nodo, P> >* indice = adiacenti.primo();
		while (!adiacenti.fine(indice) && !trovato) {
			if (m == adiacenti.leggi(indice)->get_nodo())
				trovato = true;
			else
				indice = adiacenti.succ(indice);
		}
	}
	return trovato;
}

template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::insarco(Nodo n, Nodo m) {
	if (esistenodo(n) && esistenodo(m) && !esistearco(n, m)) {
		Arco<Nodo, P> arco = Arco<Nodo, P> (m);
		CellaGrafo<Nodo, E, P> cella = nodi.recupera(n);
		Lista<Arco<Nodo, P> > adiacenti = cella.get_adiacenti();
		typename Lista<Arco<Nodo, P> >::posizione indice = adiacenti.primo();
		adiacenti.ins(indice, arco);
		cella.set_adiacenti(adiacenti);
		nodi.aggiorna(n, cella);
	}
}

template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::cancnodo(Nodo n) {
	if (nodi.appartiene(n)) {
		CellaGrafo<Nodo, E, P> cella = nodi.recupera(n);
		if (cella.get_adiacenti().vuota())
			nodi.cancella(n);
		//altrimenti il nodo non e' isolato e non puo' essere cancellato
	}
	//altrimenti il nodo non esiste
}

template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::cancarco(Nodo n, Nodo m) {
	if (esistearco(n, m)) {
		Lista<Arco<Nodo, P> > adiacenti = nodi.recupera(n).get_adiacenti();
		Cella<Arco<Nodo, P> >* indice = adiacenti.primo();
		while (adiacenti.leggi(indice).get_nodo() != n)
			indice = adiacenti.succ(indice);
		adiacenti.canc(indice);
	}
}

template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::scrivinodo(Nodo n, E etic) {
	if (esistenodo(n)) {
		CellaGrafo<Nodo, E, P> c = nodi.recupera(n);
		c.set_etichetta(etic);
		nodi.aggiorna(n,c);
    }
}

template<typename Nodo, typename E, typename P>
E Grafo<Nodo, E, P>::legginodo(Nodo n) {
	if (esistenodo(n))
		return nodi.recupera(n).get_etichetta(); //linea 53 cellaGrafo.h
}

template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::scriviarco(Nodo n, Nodo m, P p) {
	if (esistenodo(n) && esistenodo(m)) {
		bool trovato = false;
		Arco<Nodo, P> *attuale;
		Lista< Arco<Nodo, P> > adiacenti = nodi.recupera(n).get_adiacenti();
		typename Lista< Arco<Nodo,P> >::posizione indice = adiacenti.primo();
		while (!adiacenti.fine(indice) && !trovato) {
			attuale = adiacenti.leggi(indice);
			if (m == attuale->get_nodo()) {
				trovato = true;
				attuale->set_peso(p);
			} else
				indice = adiacenti.succ(indice);
		}
	}
}

template<typename Nodo, typename E, typename P>
P Grafo<Nodo, E, P>::leggiarco(Nodo n, Nodo m) {
	if (esistenodo(n) && esistenodo(m)) {
		Arco<Nodo, P> *attuale;
		Lista< Arco<Nodo, P> > adiacenti = nodi.recupera(n).get_adiacenti();
		typename Lista< Arco<Nodo,P> >::posizione indice = adiacenti.primo();
		while (!adiacenti.fine(indice)) {
			attuale = adiacenti.leggi(indice);
			if (m == attuale->get_nodo()) {
				return attuale->get_peso();
			} else
				indice = adiacenti.succ(indice);
		}
	}
}

template<typename Nodo, typename E, typename P>
Lista<Arco<Nodo, P> > Grafo<Nodo, E, P>::adiacenti(Nodo n) {
	if (esistenodo(n))
		return nodi.recupera(n).get_adiacenti();
}


template<typename Nodo, typename E, typename P>
void Grafo<Nodo, E, P>::stampa() {
	Cella<Arco<Nodo, P> >* indice = nodi.primo();
	while (!nodi.fine(indice))
		cout << legginodo(nodi.leggi(indice)) << endl;
}

#endif
