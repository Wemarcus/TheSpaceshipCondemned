#ifndef _ARCO_H
#define _ARCO_H

using namespace std;

#include <cstdlib>

template<class N, class P> class Arco {
public:
	Arco();
	Arco(N);
	Arco(const Arco<N, P> &);
	void set_nodo(N);
	N get_nodo() const;
	void set_peso(P);
	P get_peso() const;
	Arco<N, P>& operator=(const Arco<N, P> &);
private:
	N nodo;
	P peso;
};

template<class N, class P>
Arco<N, P>::Arco() {
}

template<class N, class P>
Arco<N, P>::Arco(N elem) {
	nodo = elem;
}

template<class N, class P>
Arco<N, P>::Arco(const Arco<N, P> &cella) {
	nodo = cella.nodo;
	peso = cella.peso;
}

template<class N, class P>
Arco<N, P>& Arco<N, P>::operator=(const Arco<N, P> &cella) {
	nodo = cella.nodo;
	peso = cella.peso;
	return *this;
}

template<class N, class P>
void Arco<N, P>::set_nodo(N elem) {
	nodo = elem;
}

template<class N, class P>
N Arco<N, P>::get_nodo() const {
	return nodo;
}

template<class N, class P>
void Arco<N, P>::set_peso(P elem) {
	peso = elem;
}

template<class N, class P>
P Arco<N, P>::get_peso() const {
	return peso;
}

#endif
