#ifndef H_OGGETTI
#define H_OGGETTI

#define MAXOGGETTI 50

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "oggetto.h"

class Oggetti {
    public:
        Oggetti();
        void inserisci(Oggetto);
        int get_n_oggetti();
        Oggetto get_oggetto(int);
        Oggetti posizionati_in(int);
        int luogo_oggetto(int, int);
        void set_luogo(int, int); // serve perche' Oggetti.get_oggetto(o).set_luogo(l) non funziona
        void get_zaino(int);
        int get_zaino2(int);
        int get_valigia(int);
        void svuota();
    private:
        Oggetto oggetti[MAXOGGETTI];
        int fine_Oggetti; // fineOggetti: numero oggetti riconosciuti
};

#endif
