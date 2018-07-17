#include "gioco.h"

Gioco::Gioco() {
    Salvataggio = "astro";
}

void Gioco::ciak() {
	string comando;
	do {
        init(); // linea 23
		introduzione(); // linea 31
		interfaccia.pausa(); // linea 16 interfaccia.cpp // <SP>
		do {
            interfaccia.disegna_scena(mappa.get_luogo(luogo_attuale)); // linea 23 interfaccia.cpp
            interfaccia.elenca_oggetti(oggetti.posizionati_in(luogo_attuale), "Vedo:"); // linea 27 interfaccia.cpp
			aggiorna_tempo(); // linea 33
			if(!fine_partita){ comando = interfaccia.leggi_comando(); // linea 53 interfaccia.cpp
				interpreta(comando);} // linea 63
		} while(!fine_partita);
	} while (riparti);
}

void Gioco::init() {
    fine_partita = false;
    salva = false;
    interfaccia.scrivi("\nUn attimo di pazienza...\n"); // linea 12 interfaccia.cpp
    init_specifiche(); // Carica dizionario, mappa, azioni, oggetti, variabili. // linea 29
}

void Gioco::init_specifiche() {} // linea 5 astro.cpp

void Gioco::introduzione() {} // linea 165 astro.cpp

void Gioco::aggiorna_tempo() {
	tempo--;
	tempo_specifiche(); // linea 43
	if (tempo <= 0) {
		morto(); // linea 45
		interfaccia.a_capo(); // linea 49 interfaccia.cpp
	}
	interfaccia.a_capo(); // linea 49 interfaccia.cpp
}

void Gioco::tempo_specifiche() {} // linea 180 di astro.cpp

void Gioco::morto() {
	string risposta; // scelta nuova partita
	interfaccia.pausa(); // linea 16 interfaccia.cpp // <SP>
	epitaffio(); // linea 61
	fine_partita = true;
	if(!(ins.InsiemeVuoto())){ // controllo che la valigia non sia vuota
		for(int i=50; i<=52; i++){ // ciclo sugli oggetti casco, tuta e camice
			if(ins.Appartiene(i))
				ins.Cancella(i);
		}
		if(ins.Appartiene(55)) // controllo che il manuale si trovi nella valigia
			ins.Cancella(55);
	}
	while(!(p.pilaVuota())){
		p.fuoriPila();
	}

	do {
		risposta = interfaccia.leggi_stringa("Vuoi giocare ancora ? "); // linea 42 interfaccia.cpp
	} while (risposta[0] != 's' && risposta[0] != 'n' && risposta[0] != 'S' && risposta[0] != 'N');
	if (risposta[0] == 's' || risposta[0] == 'S')
		riparti = true;
	else {
		riparti = false;
		interfaccia.scrivi("\n\nArrivederci!\n"); // linea 12 interfaccia.cpp
	}
}

void Gioco::epitaffio() {} // linea 195 astro.cpp

void Gioco::interpreta(string comando) {
	int lungh_comando; // lunghezza comando
	int in; // posizione iniziale di scansione del comando alla ricerca di una parola
	string primaParolaSTR; // prima parola comando
	string secondaParolaSTR; // seconda parola comando
	int codSecondaParola; // codice seconda parola comando
	int n1, n2; // variabili temporanee per costruire il codice comando
	bool eseguito; // indica se azione eseguita

	lungh_comando = comando.length();
	in = 0;
	codPrimaParola = estrai(comando, lungh_comando, &in, &primaParolaSTR); // linea 106
	if (primaParolaSTR[0] == '\0') {
		interfaccia.scrivi("- Beh?"); // linea 12 interfaccia.cpp
		}
	else if (lungh_comando > 2 && primaParolaSTR.substr(in-2, 2) == "re") {
		interfaccia.scrivi("- Dammi del tu, per favore."); // linea 12 interfaccia.cpp
		}
	else if (codPrimaParola == 0 && primaParolaSTR[0] != '\0') {
		interfaccia.scrivi("- Non conosco il verbo '" + primaParolaSTR + "'."); // linea 12 interfaccia.cpp
	}
	else {
		codSecondaParola = estrai(comando, lungh_comando, &in, &secondaParolaSTR); // linea 106
		if (codSecondaParola == 0 && secondaParolaSTR[0] != '\0') {
			interfaccia.scrivi("- Non conosco la parola '" + secondaParolaSTR + "'."); // linea 12 interfaccia.cpp
		} else {
			if (codSecondaParola != 0)
				og = oggetti.luogo_oggetto(codSecondaParola, luogo_attuale); // linea 19 oggetti.cpp //og = indice
			n1 = luogo_attuale * 10000;
			n2 = codPrimaParola * 100;
			eseguito = esegui_azione(n1 + n2 + codSecondaParola, codSecondaParola);//linea 126 // verbo + nome in lu
			if (!eseguito && codSecondaParola != 0)
				eseguito = esegui_azione(n1 + n2 + 99, codSecondaParola);//linea 126 // verbo + x in lu
			if (!eseguito)
				eseguito = esegui_azione(n2 + codSecondaParola, codSecondaParola);//linea 126 // verbo + nome generico
			if (!eseguito && codSecondaParola != 0)
				eseguito = esegui_azione(n2 + 99, codSecondaParola);//linea 126 // verbo + x generico
			if (!eseguito)
				interfaccia.scrivi("- Non capisco.");
		}
	}
}

int Gioco::estrai(string inStringa, int lunghezza_Input, int *pos_attuale, string *parola) {
	int cod_parola; // posizione della parola nel dizionario
	int inizio_parola; // indice di inizio parola
	do {
		cod_parola = 0;
		while (inStringa[*pos_attuale] == ' ' || inStringa[*pos_attuale] == '\'')
			(*pos_attuale)++;
		if (*pos_attuale >= lunghezza_Input)
			*parola = "";
		else {
			inizio_parola = *pos_attuale; // inizio
			while (inStringa[*pos_attuale] != ' ' && inStringa[*pos_attuale] != '\'' && (*pos_attuale) < lunghezza_Input)
				(*pos_attuale)++;
			*parola = inStringa.substr(inizio_parola, *pos_attuale-inizio_parola);
			cod_parola = vocabolario.recupera(*parola); // linea 84 dizionario.h  // cerca
		}
	} while (cod_parola == 7); // 7 codice degli articoli
	return cod_parola;
}

//Esegue azione a, a=0 se non trovata
bool Gioco::esegui_azione(int azione, int c2) {
	int cod_azione;
	if (azioni.appartiene(azione)) { // linea 70 dizionario.h
    	cod_azione = azioni.recupera(azione); // linea 84 dizionario.h
    	if (cod_azione != 0) {
    		if (c2 == 0 || cod_azione > 0) { // solo verbo o no test
    			esegui(cod_azione); //linea 147
    		} else {
    			if (og == 0) // && og != 12 && og != 13
    				interfaccia.scrivi("- Qui non c'e'.");
    			else
    				esegui(-cod_azione); //linea 147
    		}
    		cod_azione = 1;
    	}
    	return true;
	} else
	    return false;
}

void Gioco::esegui(int a) {
	switch (a) {
		case 1:
			direzioni(); // linea 179
		break;
		case 2:
			prendi(); // linea 187
		break;
		case 3:
			lascia(); // linea 207
		break;
		case 4:
			guarda(); // linea 224
		break;
		case 5:
			save(); // linea 228
		break;
		case 6:
			load(); // linea 244
		break;
		case 7:
			cosa(); // linea 262
		break;
		case 8: case 9:
			vuota(); // linea 266
		break;
		default:
			if (!esegui_specifiche(a)) // linea 268
               interfaccia.scrivi("AZIONE " + a); // linea 12 interfaccia.cpp
	}
}

void Gioco::direzioni() {
	int a = mappa.get_luogo(luogo_attuale).luogo_adiacente(codPrimaParola); //linea 5 mappa.cpp e linea 24 luogo.cpp // luogo corrispondente a direzione
    if (a == 0)
		interfaccia.scrivi("- Di li' non puoi andare"); // linea 12 interfaccia.cpp
	else
		luogo_attuale = a;
}

void Gioco::prendi() {
	if (oggetti.get_oggetto(og).get_luogo() == 0) // controllo che l’oggetto che desidero prendere non si trovi già nell’inventario
		interfaccia.scrivi("- Gia' fatto."); // linea 12 interfaccia.cpp
	else if(oggetti.get_oggetto(og).get_luogo() == 12) // controllo che l’oggetto che desidero non si trovi già nello zaino o nella valigia
		interfaccia.scrivi("- Sta gia' nello zaino o nella valigia.");
	else if (oggetti.get_oggetto(og).get_luogo() < 0) // controllo che l’oggetto che desidero sia prendibile
		interfaccia.scrivi("- Non e' possibile."); // linea 12 interfaccia.cpp
	else if (!prendi_specifiche()) { // faccio alcuni controlli in prendi_specifiche
		if(oggetti.get_oggetto(25).get_luogo() == 0){ // controllo se la valigia si trova nell’inventario
			if (og == 20 || og == 23) // controllo che l’oggetto sia il secondo pilota o la chiave
				oggetti.set_luogo(og,0);
			else
				oggetti.set_luogo(og,12); // linea 35 oggetti.cpp
		}
		else if(oggetti.get_oggetto(26).get_luogo() == 0){ // controllo se lo zaino si trova nell’inventario
			if (og == 20 || og == 23) // controllo che l’oggetto sia il secondo pilota o la chiave
				oggetti.set_luogo(og,0);
			else
				oggetti.set_luogo(og,12); // linea 35 oggetti.cpp
		}
		else // se non ho né valigia, né zaino nell’inventario, e l’oggetto può essere preso(vedi. prendi_specifiche), lo metto nell’inventario
			oggetti.set_luogo(og,0);
		if (!preso_specifiche()) // faccio alcuni controlli in preso_specifiche
		   interfaccia.scrivi("Fatto.");  // linea 12 interfaccia.cpp
	}
}

bool Gioco::prendi_specifiche() {
	return false; // linea 222 astro.cpp
}

bool Gioco::preso_specifiche() {
	return false; // linea 225 astro.cpp
}

void Gioco::lascia() {
	if (og == 0 && oggetti.get_oggetto(og).get_luogo() != 0 && oggetti.get_oggetto(og).get_luogo() != 12) // controllo che l’oggetto si trovi in un altro luogo e che l’oggetto non si trovi né nell’inventario, né nella valigia, né nello zaino
		interfaccia.scrivi("- Non ce l'hai e qui non c'e'."); // linea 12 interfaccia.cpp
	else if(og != 0 && oggetti.get_oggetto(og).get_luogo() != 0 && oggetti.get_oggetto(og).get_luogo() != 12) // controllo che l’oggetto non si trovi in un altro luogo e che l’oggetto non si trovi né nell’inventario, né nella valigia, né nello zaino
		interfaccia.scrivi("- Non ce l'hai.");
	else if (og == 0 && oggetti.get_oggetto(og).get_luogo() != 0) // controllo che l’oggetto si trovi in un altro luogo e che l’oggetto non si trovi nell’inventario
		interfaccia.scrivi("- Non ce l'hai.");
	else if (!lascia_specifiche()) { // faccio alcuni controlli in lascia_specifiche
		if(oggetti.get_oggetto(26).get_luogo() == 0){ // controllo che lo zaino si trovi nell’inventario
			if (oggetti.get_oggetto(4).get_luogo() == 12 || oggetti.get_oggetto(11).get_luogo() == 12 || oggetti.get_oggetto(22).get_luogo() == 12 || oggetti.get_oggetto(24).get_luogo() == 12){// controllo che uno tra:tuta, casco, camice e manuale si trovi nello zaino
				if(og == 4 || og == 11 || og == 22 || og == 24){// controllo che l’oggetto sia proprio uno tra: tuta, casco, camice e manuale
					if(oggetti.get_oggetto(og).get_luogo()== 0){// controllo che l’oggetto si trovi nell’inventario
						oggetti.set_luogo(og,luogo_attuale);
						interfaccia.scrivi("Fatto.");
					}
					else{// controllo che l’oggetto si trovi nello zaino
						int c,d;
						c=p.leggiPila();
						d=og;
						if(og == oggetti.get_zaino2(c)){// controllo che l’oggetto sia il primo visibile nello zaino
							oggetti.set_luogo(og,luogo_attuale);
							p.fuoriPila();
							n_oggettiZ--;
							peso_MaxZ += oggetti.get_oggetto(og).get_peso();
							interfaccia.scrivi("Fatto.");
						}
						else if(ins.Appartiene(oggetti.get_valigia(d))){ // controllo che l’oggetto si trovi nella valigia
							interfaccia.scrivi("- Non ce l'hai addosso e non sta nello zaino..");
							interfaccia.scrivi(" (Suggerimento: controlla nella valigia)");
						}
						else if (!p.pilaVuota()){// controllo che lo zaino non sia vuoto
							interfaccia.scrivi("Devi prima lasciare: ");
							oggetti.get_zaino(c);
						}
					}
				}
				else{
					oggetti.set_luogo(og,luogo_attuale);
					interfaccia.scrivi("Fatto.");
				}
			}
			else{
				if(oggetti.get_oggetto(og).get_luogo() != 0){// controllo che l’oggetto non si trovi nell’inventario
					interfaccia.scrivi("- Non ce l'hai.");
				}
				else{// controllo che l’oggetto si trovi nell’inventario
					oggetti.set_luogo(og,luogo_attuale); // linea 35 oggetti.cpp
					interfaccia.scrivi("Fatto.");
				}
			}
		}
		else if(oggetti.get_oggetto(25).get_luogo() == 0){// controllo che la valigia si trovi nell’inventario
			if (oggetti.get_oggetto(4).get_luogo() == 12 || oggetti.get_oggetto(11).get_luogo() == 12 || oggetti.get_oggetto(22).get_luogo() == 12 || oggetti.get_oggetto(24).get_luogo() == 12){// controllo che uno tra: tuta, casco, camice e manuale si trovi nella valigia
				if(og == 4 || og == 11 || og == 22 || og == 24){ // controllo che l’oggetto sia proprio uno tra: tuta, casco, camice e manuale
					int c;
					c=og;
					if(oggetti.get_oggetto(og).get_luogo()== 0){ //controllo che l’oggetto si trovi nell’inventario
						oggetti.set_luogo(og,luogo_attuale);
						interfaccia.scrivi("Fatto.");
					}
					else if(!ins.Appartiene(oggetti.get_valigia(c))){ // controllo che l’oggetto non si trovi nella valigia
						if((oggetti.get_valigia(c))==(p.leggiPila())){ // controllo che l’oggetto sia il primo visibile dello zaino
							interfaccia.scrivi("- Non ce l'hai in valigia.");
							interfaccia.scrivi(" (Suggerimento: controlla nello zaino)");
						}
						else if((oggetti.get_valigia(c))!=(p.leggiPila())) // controllo che l’oggetto non sia il primo visibile nello zaino
							interfaccia.scrivi("- Non ce l'hai in valigia.");
					}
					else if(ins.Appartiene(oggetti.get_valigia(c))){ // controllo che l’oggetto si trovi nella valigia
						oggetti.set_luogo(og,luogo_attuale);
						ins.Cancella(oggetti.get_valigia(c));
						n_oggettiV--;
						peso_MaxV += oggetti.get_oggetto(og).get_peso();
						interfaccia.scrivi("Fatto.");
					}
					else
						interfaccia.scrivi("- Non ce l'hai in valigia.");
				}
				else{ // dovrebbe riferirsi a chiave e secondo se stanno nell'inventario.
					oggetti.set_luogo(og,luogo_attuale);
					interfaccia.scrivi("Fatto.");
				}
			}
			else{
				if(oggetti.get_oggetto(og).get_luogo() != 0){ // controllo che l’oggetto non si trovi nell’inventario
					interfaccia.scrivi("- Non ce l'hai.");
				}
				else{
					oggetti.set_luogo(og,luogo_attuale); // linea 35 oggetti.cpp
					interfaccia.scrivi("Fatto.");
				}
			}
		}
		else{
			if(oggetti.get_oggetto(og).get_luogo() == 0){ // controllo che l’oggetto si trovi nell’inventario
				oggetti.set_luogo(og,luogo_attuale);
				interfaccia.scrivi("Fatto.");
			}
			else
				interfaccia.scrivi("- Non ce l'hai.");
		}
	}
	else if ((luogo_attuale == 7 || luogo_attuale >= 9) && (oggetti.get_oggetto(4).get_luogo() != 0 || oggetti.get_oggetto(11).get_luogo() != 0)) { // controllo che il luogo attuale sia o 7 o qualsiasi luogo pari o superiore a 9 e che la tuta o il casco non si trovino nell’inventario
		interfaccia.scrivi("\nAaaagh!!!"); // linea 12 interfaccia.cpp
		morto(); // linea 45
	}
}

bool Gioco::lascia_specifiche() {
	return false; // linea 235 astro.cpp
}

void Gioco::guarda() {
	interfaccia.scrivi("- Non noto nulla di particolare."); // linea 12 interfaccia.cpp
}

void Gioco::save() {
	int i;
	salva=true;
	interfaccia.scrivi("Salvataggio partita...");  // linea 12 interfaccia.cpp
	ofstream file(Salvataggio, ios::out);
	file << salva << '\n';
	for (i = 1; i <= oggetti.get_n_oggetti(); i++) { // linea 15 oggetti.cpp
		file << oggetti.get_oggetto(i).get_luogo() << '\n'; // linea 11 oggetti.cpp e linea 19 oggetto.cpp
	}
	file << luogo_attuale << '\n';
	file << tempo << '\n';
	file << passo_soluzione << '\n';
	file << n_oggettiZ << '\n';
	file << peso_MaxZ << '\n';
	if(!(p.pilaVuota())){ // controllo che lo zaino non sia vuoto
		el1 = p.leggiPila();
		p.fuoriPila();
		if(!(p.pilaVuota())){ // controllo che lo zaino non sia vuoto
			el2 = p.leggiPila();
			p.fuoriPila();
			p.inPila(el2);
		}
		p.inPila(el1);
	}
	file << el1 << '\n';
	file << el2 << '\n';
	file << n_oggettiV << '\n';
	file << peso_MaxV << '\n';
	if(!(ins.InsiemeVuoto())){ //controllo che la valigia non sia vuota
		if(ins.Appartiene(50)){ // controllo che il casco sia presente nella valigia
			el3 = 50;
		}
		file << el3 << '\n';
		if(ins.Appartiene(51)){ // controllo che la tuta sia presente nella valigia
			el4 = 51;
		}
		file << el4 << '\n';
		if(ins.Appartiene(52)){ // controllo che il camice sia presente nella valigia
			el5 = 52;
		}
		file << el5 << '\n';
		if(ins.Appartiene(55)){ // controllo che il manuale sia presente nella valigia
			el6 = 55;
		}
		file << el6 << '\n';
	}
	save_specifiche(file); // linea 238
	file.close();
}

void Gioco::save_specifiche(ofstream &f) {} // linea 246 astro.cpp

void Gioco::load() {
	int i;
	int valore;

	ifstream file(Salvataggio, ios::in);
	file >> salva;
	if(salva){ // controllo che la variabile salva sia impostata a true(viene impostata quando si entra in save())
		interfaccia.scrivi("Caricamento partita...");  // linea 12 interfaccia.cpp
		for (i = 1; i <= oggetti.get_n_oggetti(); i++) {// linea 15 oggetti.cpp
			file >> valore;
			oggetti.set_luogo(i,valore); // linea 23 oggetto.cpp
		}
		file >> luogo_attuale;
		file >> tempo;
		file >> passo_soluzione;
		while(!(p.pilaVuota())) //controllo che lo zaino non sia vuoto
			p.fuoriPila();
		file >> n_oggettiZ;
		file >> peso_MaxZ;
		file >> el1;
		file >> el2;
		if(el2 !=0)
			p.inPila(el2);
		if(el1 !=0)
			p.inPila(el1);

		file >> n_oggettiV;
		file >> peso_MaxV;
		file >> el3;
		file >> el4;
		file >> el5;
		file >> el6;
		if((!(ins.Appartiene(el3))) && el3 != 0)
			ins.Inserisci(el3);
		if((!(ins.Appartiene(el4))) && el4 != 0)
			ins.Inserisci(el4);
		if((!(ins.Appartiene(el5))) && el5 != 0)
			ins.Inserisci(el5);
		if((!(ins.Appartiene(el6))) && el6 != 0)
			ins.Inserisci(el6);

		load_specifiche(file); // linea 256
		file.close();
	}
	else
		interfaccia.scrivi("Non e' presente nessun salvataggio...");
}

void Gioco::load_specifiche(ifstream &f) {} // linea 250 astro.cpp

void Gioco::cosa() {
	interfaccia.elenca_oggetti(oggetti.posizionati_in(0),"Possiedi:"); // linea 27 interfaccia.cpp e linea 39 oggetti.cpp
}

void Gioco::vuota() {}

bool Gioco::esegui_specifiche(int) {
     return true;
}

void Gioco::errore() {
	passo_soluzione = 0;
	tempo = tempo/2;
}
