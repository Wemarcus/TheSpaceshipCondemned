#include "oggetto.h"

Oggetto::Oggetto() {}

Oggetto::Oggetto(string n, int c, int l, int p) {
	nome = n;
	codice = c;
	luogo = l;
	peso = p;
}

string Oggetto::get_nome() {
	return nome;
}

int Oggetto::get_codice() {
	return codice;
}

int Oggetto::get_luogo() {
	return luogo;
}

void Oggetto::set_luogo(int l) {
	luogo = l;
}

int Oggetto::get_peso() {
	return peso;
}
