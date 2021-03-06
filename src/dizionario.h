#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#include <iostream>
#include "listaP.h"
#include "entry.h"
#include <cstdlib>
#define MAXDIM 101

using namespace std;

typedef unsigned int HashValue;

template<typename K, class E> class Dizionario { // E=tipo elemento, K=tipo chiave
	typedef Entry<K, E> entry;

public:
	Dizionario();
	Dizionario(unsigned int);
	~Dizionario();
	bool dizionarioVuoto(); // restituisce true se il dizionario e' vuoto
	bool appartiene(const K&); // restituisce true se l'elemento appartiene al dizionario
	void inserisci(K, E); // inserisce un elemento nel dizionario
	E recupera(const K&); // restituisce l'elemento corrispondente alla chiave (se esiste)
	void aggiorna(const K&, E&); // aggiorna l'elemento
	void cancella(const K&); // elimina l'elemento
	unsigned int dimensione(); // restituisce il numero elementi del dizionario
private:
	unsigned int H(const K&); // calcola il valore hash della chiave
	unsigned int lunghezza; // lunghezza massima del dizionario
	unsigned int nelementi; // elementi presenti in un certo istante nel dizionario
	Lista<Entry<K, E> >* table; // liste di trabocco per le entry
	// HASH STATICO ED APERTO
	HashValue hash(string);
	HashValue hash(int);
};

template<typename K, typename E>
Dizionario<K, E>::Dizionario() {
	lunghezza = MAXDIM;
	nelementi = 0;
	table = new Lista<entry> [lunghezza]; // array di liste
}

template<typename K, typename E>
Dizionario<K, E>::Dizionario(unsigned int n) {
	lunghezza = n;
	nelementi = 0;
	table = new Lista<entry> [lunghezza];
}

template<typename K, typename E>
Dizionario<K, E>::~Dizionario() {
	delete[] table;
}

template<typename K, typename E>
bool Dizionario<K, E>::dizionarioVuoto() {
	return (nelementi == 0);
}

template<typename K, typename E>
void Dizionario<K, E>::inserisci(K chiave, E element) {
	entry e(chiave, element);
	unsigned int h = H(chiave);
	Cella<entry>* pos = table[h].primo();
	table[h].ins(pos, e);
	nelementi++;
}

template<typename K, typename E>
bool Dizionario<K, E>::appartiene(const K &key) {
	Cella<entry>* iter; //Lista<entry>::posizione
	bool trovato = false;
	unsigned int pos = H(key);
	iter = table[pos].primo();
	while (!table[pos].fine(iter) && !trovato) {
		if (key == table[pos].leggi(iter)->get_key())
			trovato = true;
		iter = table[pos].succ(iter);
	}
	return trovato;
}

template<typename K, typename E>
E Dizionario<K, E>::recupera(const K& key) {
	Cella<entry>* iter;
	bool trovato = false;
	E elem;
	unsigned int pos = H(key);
	iter = table[pos].primo();
	while (!table[pos].fine(iter) && !trovato) {
		if (key == table[pos].leggi(iter)->get_key()) {
			trovato = true;
			elem = table[pos].leggi(iter)->get_value();
		}
		iter = table[pos].succ(iter);
	}
	return elem;
}

template<typename K, typename E>
void Dizionario<K, E>::aggiorna(const K& key, E& elemento) {
	cancella(key);
	inserisci(key, elemento);
}

template<typename K, typename E>
void Dizionario<K, E>::cancella(const K& chiave) {
	Cella<entry>* iter;
	bool trovato = false;
	unsigned int pos = H(chiave);
	iter = table[pos].primo();
	while (!table[pos].fine(iter) && !trovato) {
		if (chiave == table[pos].leggi(iter)->get_key())
			trovato = true;
		else
			iter = table[pos].succ(iter);
	}
	if (trovato) {
		table[pos].canc(iter);
		nelementi--;
	}
}

template<typename K, typename E>
unsigned int Dizionario<K, E>::H(const K& chiave) {
	return (hash(chiave) % lunghezza);
}

template<typename K, typename E>
unsigned int Dizionario<K, E>::dimensione() {
	return nelementi;
}

//

template<typename K, typename E>
HashValue Dizionario<K, E>::hash(string str) {
	HashValue hash = 5381;
	int l = str.length();
	for (int i = 0; i < l; i++)
		hash = hash * 33 + str[i];
	return hash;
}

template<typename K, typename E>
HashValue Dizionario<K, E>::hash(int i) {
	return i;
}

#endif // DIZ_H
