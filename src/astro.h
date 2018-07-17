#ifndef ASTRO_H
#define ASTRO_H
#include "gioco.h"

class Astro: public Gioco {
public:
	Astro();
private:
	int parete_stagna_aperta; // parete_stagna_aperta BOOLEAN!
	//metodi
	void init_specifiche();
	void introduzione();
	void tempo_specifiche();
	bool esegui_specifiche(int);
	bool prendi_specifiche();
	bool indossa_specifiche();
	bool indosso_specifiche();
	bool preso_specifiche();
	bool lascia_specifiche();
	void save_specifiche(ofstream &);
	void load_specifiche(ifstream &);
	void epitaffio();
	void encomio();
	void azione_10();
	void azione_11();
	void azione_12();
	void azione_13();
	void azione_14();
	void azione_15();
	void azione_16();
	void azione_17();
	void azione_18();
	void azione_19();
	void azione_20();
	void azione_21();
	void azione_22();
	void azione_23();
	void azione_24();
	void azione_25();
	void azione_26();
	void azione_27();
	void azione_28();
	void azione_29();
	void azione_30();
	void azione_31();
	void azione_32();
	void azione_33();
	void azione_34();
	void azione_35();
	void azione_36();
	void azione_37();
	void azione_38();
	void azione_39(); // azione guarda valigia
	void azione_40(); // azione guarda zaino
	void azione_41(); // azione indossa/metti
	void azione_42(); // azione inventario zaino
	void azione_43(); // azione aiuto/help
	void azione_44(); // azione inventario valigia
};

#endif
