#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "interfaccia.h"

using namespace std;

Interfaccia::Interfaccia() {
	cout << "Interfaccia avviata" << endl;
}

void Interfaccia::scrivi(string testo) {
	cout << testo << endl;
}

void Interfaccia::pausa() {
	string invio;
	cout << "\n- Premi <invio> per continuare -\n";
	getline(cin, invio);
	cout << endl;
}

void Interfaccia::disegna_scena(Luogo luogo) {
	cout << "\nSei " << luogo.get_descrizione() << "." << endl; // linea 20 luogo.cpp
}

void Interfaccia::elenca_oggetti(Oggetti oggetti, string premessa) {
	int numero_Oggetti = oggetti.get_n_oggetti(); // linea 15 oggetti.cpp
	if (numero_Oggetti > 0) {
		cout << premessa;
		for (int i = 1; i <= numero_Oggetti; i++) {
			cout << "\n- " << oggetti.get_oggetto(i).get_nome(); // linea 11 oggetti.cpp + linea 11 oggetto.cpp
			if (i == numero_Oggetti)
				cout << ".";
			else
				cout << ";";
		}
		cout << endl;
	}
}

string Interfaccia::leggi_stringa(string domanda) {
	string risposta;
	cout << domanda << endl;
	cin >> risposta;
	return risposta;
}

void Interfaccia::a_capo() {
	cout << endl;
}

string Interfaccia::leggi_comando() {
	string risposta;
	do {
		cout << "Cosa devo fare?" << endl;
		getline(cin, risposta);
	} while (risposta[0] == '\0');
	cout << endl;
	return risposta;
}

void Interfaccia::scrivi_parziale(string testo) {
	cout << testo;
}

void Interfaccia::scrivi_parziale(int n) {
	cout << n;
}
