#ifndef GIOCO_H
#define GIOCO_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

#include "dizionario.h"
#include "mappa.h"
#include "oggetti.h"
#include "interfaccia.h"
#include "zaino.h"
#include "valigia.h"

#define MAXSTRINGA 50

class Gioco {
public:
	Gioco();
	void ciak();
protected:
	// variabili globali (usate dalle azioni)
	Interfaccia interfaccia;
	int tempo;
	int luogo_attuale;
	int og; // oggetto
	int passo_soluzione; // contatore soluzione
	int codPrimaParola; // codice prima parola comando
	// variabili necessarie per la strutturazione
	bool fine_partita;
	bool riparti; // per rigiocare alla fine della partita
	char *Salvataggio; // salvataggio della situazione del  gioco
	Dizionario<string, int> vocabolario;
	Mappa mappa;
	Dizionario<int, int> azioni;
	Oggetti oggetti;
	Pila<int> p;
	int n_oggettiZ; // numero oggetti nello zaino
	int peso_MaxZ; // peso massimo trasportabile nello zaino
	Insieme<int> ins;
	int n_oggettiV; // numero oggetti nella valigia
	int peso_MaxV; // peso massimo trasportabile nella valigia
	// Utilizzate per SAVE e LOAD
	// el1=primo elemento zaino, el2=secondo elemento zaino; el3,el4,el5,el6 elementi valigia
	int el1;
	int el2;
	bool salva; // booleano usato nella save e nella load, dice se sono entrato nella save o meno
	int el3;
	int el4;
	int el5;
	int el6;
	// metodi
	void init();
	void interpreta(string);
	bool esegui_azione(int, int);
	void esegui(int);
	int estrai(string, int, int *, string *);
	void morto();
	void aggiorna_tempo();
	void errore();
	void direzioni();
	void prendi();
	void lascia();
	void guarda();
	void save();
	void load();
	void cosa();
	void vuota();
	// VIRTUAL
	virtual void init_specifiche();
	virtual void introduzione();
	virtual void tempo_specifiche();
	virtual bool esegui_specifiche(int);
	virtual bool prendi_specifiche();
	virtual bool preso_specifiche();
	virtual bool lascia_specifiche();
	virtual void save_specifiche(ofstream &);
	virtual void load_specifiche(ifstream &);
	virtual void epitaffio();
	//void encomio();
};

#endif
