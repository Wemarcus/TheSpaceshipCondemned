#ifndef STRADA_H
#define STRADA_H

#include <string>
#include <cstdlib>

using namespace std;

class Strada {
public:
	// enum Direzioni {N, E, S, W, U, D};
	Strada();
	Strada(string, string);
	string get_descrizione();
	string get_direzione();
private:
	string descrizione;
	bool percorribile;
    string nome;
	string direzione;
	int periodo;
};

#endif
