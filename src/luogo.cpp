#include "luogo.h"
#include <iostream>
#include <stdlib.h>

Luogo::Luogo() {
	descrizione = "";
	direzioni = "";
}

Luogo::Luogo(string descr, string dir) {
	descrizione = descr;
	direzioni = dir;
}

Luogo::Luogo(const Luogo &l) {
	descrizione = l.descrizione;
	direzioni = l.direzioni;
}

string Luogo::get_descrizione() {
	return descrizione;
}

int Luogo::luogo_adiacente(int direzione) {
	return atoi(direzioni.substr(2*direzione-2, 2).c_str());
}

Luogo & Luogo::operator=(const Luogo &l) {
	descrizione = l.descrizione;
	direzioni = l.direzioni;
	return *this;
}

string Luogo::get_direzioni() {
	return direzioni;
}
