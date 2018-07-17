#include "oggetti.h"

Oggetti::Oggetti() {
     fine_Oggetti = 0;
}

void Oggetti::inserisci(Oggetto oggetto) {
     oggetti[++fine_Oggetti] = oggetto;
}

Oggetto Oggetti::get_oggetto(int oggetto) {
    return oggetti[oggetto];
}

int Oggetti::get_n_oggetti() {
    return fine_Oggetti;
}

//og=indice oggetto c2, 0 se non pres. o trasp.
int Oggetti::luogo_oggetto(int c2, int lu) {
	bool trovato = false;
    int i = 1;
	int og = 0;
	while (i <= fine_Oggetti && !trovato) {
		if (oggetti[i].get_codice() == c2) // linea 15 oggetto.cpp
			if (abs(oggetti[i].get_luogo()) == lu || oggetti[i].get_luogo() == 0 || oggetti[i].get_luogo() == 12) { // linea 19 oggetto.cpp
				og = i;
				trovato = true;
			}
		i++;
	}
	return og;
}

void Oggetti::set_luogo(int oggetto, int luogo) {
    oggetti[oggetto].set_luogo(luogo); // linea 23 oggetto.cpp
}

// Elenca oggetti in luogo L (0 = posseduti)
Oggetti Oggetti::posizionati_in(int l) {
	Oggetti inventario = Oggetti();

	for (int i = 1; i <= fine_Oggetti; i++) {
		if (abs(oggetti[i].get_luogo()) == l) // linea 19 oggetto.cpp
			inventario.inserisci(oggetti[i]); // linea 7
	}
	return inventario;
}

void Oggetti::svuota() {
     fine_Oggetti = 0;
}

void Oggetti::get_zaino(int c) {
	bool trovato = false;
	int i = 1;
	while (i <= fine_Oggetti && !trovato) { // scandisco tutti gli oggetti presenti nel vocabolario finché o finiscono gli oggetti o trovato viene impostato a true
		if (oggetti[i].get_codice() == c){ // controllo che il codice dell’oggetto con indice “i” sia uguale al codice “c”
			cout << "- " <<oggetti[i].get_nome() << endl;
			trovato = true;
		}
		i++;
	}
}

int Oggetti::get_zaino2(int c) {
	bool trovato = false;
	int i = 1;
	int i2 = 0;
	while (i <= fine_Oggetti && !trovato) { // scandisco tutti gli oggetti presenti nel vocabolario finché o finiscono gli oggetti o trovato viene impostato a true
		if (oggetti[i].get_codice() == c){ // controllo che il codice dell’oggetto con indice “i” sia uguale al codice “c”
			i2=i;
			trovato = true;
		}
		i++;
	}
	return(i2);
}

int Oggetti::get_valigia(int c) {
	bool trovato = false;
	int i = 1;
	int i2 = 0;
	while (i <= fine_Oggetti && !trovato) { // scandisco tutti gli oggetti presenti nel vocabolario finché o finiscono gli oggetti o trovato viene impostato a true
		if (i == c){//controllo che l’indice “i” sia uguale al codice c
			i2= oggetti[i].get_codice();
			trovato = true;
		}
		i++;
	}
	return(i2);
}
