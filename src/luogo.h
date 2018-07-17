#ifndef LUOGO_H
#define LUOGO_H

#include <string>

using namespace std;

class Luogo {
	public:
		// enum Direzioni {N, E, S, W, U, D};
       Luogo();
       Luogo(string, string);
       Luogo(const Luogo &);
       string get_descrizione();
       string get_direzioni();
       int luogo_adiacente(int);
       Luogo & operator=(const Luogo &);
	private:
		string descrizione;
		string direzioni;
        string nome;
		int periodo;
};

#endif
