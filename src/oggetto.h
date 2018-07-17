#ifndef H_OGGETTO
#define H_OGGETTO

#include <string>

using namespace std;

class Oggetto {
public:
	Oggetto();
    Oggetto(string n, int c, int l, int p);
    string get_nome();
    int get_codice();
    int get_luogo();
    void set_luogo(int l);
    int get_peso();
private:
	string nome;
	int codice;
	int luogo; //Luogo posizione;
	int peso;
};

#endif
