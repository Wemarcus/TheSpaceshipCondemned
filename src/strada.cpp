#include "strada.h"

Strada::Strada() {}

Strada::Strada(string descr, string dir) {
	descrizione = descr;
	direzione = dir;
}

string Strada::get_descrizione() {
	return descrizione;
}

string Strada::get_direzione() {
	return direzione;
}
