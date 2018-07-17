#ifndef INTERFACCIA_H
#define INTERFACCIA_H

#include <string>
#include "luogo.h"
#include "oggetti.h"

class Interfaccia {
	public:
		Interfaccia();
		void scrivi(string);
		void scrivi_parziale(string);
		void scrivi_parziale(int);
		void a_capo();
		string leggi_stringa(string);
		string leggi_comando();
		void disegna_scena(Luogo);
		void elenca_oggetti(Oggetti, string);
		void pausa();
};

#endif
