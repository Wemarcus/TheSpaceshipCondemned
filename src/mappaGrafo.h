#ifndef H_MAPPA
#define H_MAPPA

using namespace std;

#include "luogo.h"

class Mappa: public Grafo {
public:
	Mappa();
	void inserisci(Luogo luogo);
	Luogo get_luogo(int luogo);
	void svuota();
private:
	Luogo luoghi[30];
	int n_luoghi; // fineMappa: numero luoghi nella mappa
};

Mappa::Mappa() {
	n_luoghi = 0;
}

void Mappa::inserisci(Luogo luogo) {
	luoghi[++n_luoghi].set(luogo.get_descrizione(), luogo.get_direzioni());
}

Luogo Mappa::get_luogo(int luogo) {
	return luoghi[luogo];
}

void Mappa::svuota() {
	n_luoghi = 0;
}

#endif

