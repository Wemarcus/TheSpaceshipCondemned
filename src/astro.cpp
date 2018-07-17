#include "astro.h"

Astro::Astro():Gioco(){} // linea 3 gioco.cpp

void Astro::init_specifiche() {
	// dizionario // linea 61 dizionario.h
	vocabolario.inserisci("a", 5);
	vocabolario.inserisci("aggiusta", 27);
	vocabolario.inserisci("aiuto", 58); // inserimento parola aiuto
	vocabolario.inserisci("alto", 5);
	vocabolario.inserisci("antenna", 69);
	vocabolario.inserisci("apri", 22);
	vocabolario.inserisci("armadietto", 67);
	vocabolario.inserisci("b", 6);
	vocabolario.inserisci("basso", 6);
	vocabolario.inserisci("bottone", 61);
	vocabolario.inserisci("camice", 52);
	vocabolario.inserisci("cartello", 60);
	vocabolario.inserisci("casco", 50);
	vocabolario.inserisci("chiave", 54);
	vocabolario.inserisci("cosa", 13);
	vocabolario.inserisci("e", 3);
	vocabolario.inserisci("est", 3);
	vocabolario.inserisci("etichetta", 70);
	vocabolario.inserisci("giallo", 63);
	vocabolario.inserisci("guarda", 10);
	vocabolario.inserisci("help", 58); // inserimento parola help
	vocabolario.inserisci("il", 7);
	vocabolario.inserisci("indicatore", 66);
	vocabolario.inserisci("indossa", 20);
	vocabolario.inserisci("inventario", 13);
	vocabolario.inserisci("l", 7);
	vocabolario.inserisci("la", 7);
	vocabolario.inserisci("lascia", 9);
	vocabolario.inserisci("leggi", 25);
	vocabolario.inserisci("letto", 68);
	vocabolario.inserisci("leva", 65);
	vocabolario.inserisci("lo", 7);
	vocabolario.inserisci("load", 12);
	vocabolario.inserisci("manuale", 55);
	vocabolario.inserisci("metti", 20);
	vocabolario.inserisci("n", 1);
	vocabolario.inserisci("nord", 1);
	vocabolario.inserisci("o", 4);
	vocabolario.inserisci("ovest", 4);
	vocabolario.inserisci("premi", 26);
	vocabolario.inserisci("prendi", 8);
	vocabolario.inserisci("pulsante", 61);
	vocabolario.inserisci("ripara", 27);
	vocabolario.inserisci("rosso", 64);
	vocabolario.inserisci("s", 2);
	vocabolario.inserisci("sali", 5);
	vocabolario.inserisci("save", 11);
	vocabolario.inserisci("scendi", 6);
	vocabolario.inserisci("schiaccia", 26);
	vocabolario.inserisci("secondo", 53);
	vocabolario.inserisci("spingi", 24);
	vocabolario.inserisci("sud", 2);
	vocabolario.inserisci("tira", 23);
	vocabolario.inserisci("togli", 21);
	vocabolario.inserisci("tuta", 51);
	vocabolario.inserisci("valigia", 56); // inserimento parola valigia
	vocabolario.inserisci("verde", 62);
	vocabolario.inserisci("w", 4);
	vocabolario.inserisci("zaino", 57); // inserimento parola zaino
	// mappa: (descrizione, direzioni) // linea 9 mappa.cpp
	mappa.ins_luogo(1,Luogo("nella cabina di pilotaggio", "000000000002")); // cifre 1-2 per N, 3-4 per S, 5-6 per E, 7-8 per O, 9-10 per UP, 11-12 per Down
	mappa.ins_luogo(2,Luogo("ad un'estremita' del corridoio", "000300050100"));
	mappa.ins_luogo(3,Luogo("nel corridoio", "020400060000"));
	mappa.ins_luogo(4,Luogo("ad un'estremita' del corridoio", "030000070008"));
	mappa.ins_luogo(5,Luogo("nella cabina del secondo pilota", "000002000000"));
	mappa.ins_luogo(6,Luogo("nella tua cabina", "000003000000"));
	mappa.ins_luogo(7,Luogo("nel compartimento stagno", "000000000000"));
	mappa.ins_luogo(8,Luogo("nella sala controllo del reattore", "000000000400"));
	mappa.ins_luogo(9,Luogo("all'esterno, a prua dell'astronave", "001000000000"));
	mappa.ins_luogo(10,Luogo("all'esterno dell'astronave", "091100000000"));
	mappa.ins_luogo(11,Luogo("all'esterno, a poppa dell'astronave", "100007000000"));
	// azioni // linea 61 dizionario.h
	azioni.inserisci(100, 1);
	azioni.inserisci(200, 1);
	azioni.inserisci(300, 1);
	azioni.inserisci(400, 1);
	azioni.inserisci(500, 1);
	azioni.inserisci(600, 1);
	azioni.inserisci(856, -2); // codice azione prendi valigia
	azioni.inserisci(857, -2); // codice azione prendi zaino
	azioni.inserisci(899, -2);
	azioni.inserisci(950, -10);
	azioni.inserisci(951, -10);
	azioni.inserisci(956, 3); // codice azione lascia valigia
	azioni.inserisci(957, 3); // codice azione lascia zaino
	azioni.inserisci(999, 3);
	azioni.inserisci(1051, -11);
	azioni.inserisci(1052, -14);
	azioni.inserisci(1053, -12);
	azioni.inserisci(1055, -13);
	azioni.inserisci(1056, -39); // codice azione guarda valigia
	azioni.inserisci(1057, -40); // codice azione guarda zaino
	azioni.inserisci(1060, -13);
	azioni.inserisci(1099, -4);
	azioni.inserisci(1100, 5);
	azioni.inserisci(1200, 6);
	azioni.inserisci(1300, 7);
	azioni.inserisci(2050, -41); // codice azione indossa/metti casco
	azioni.inserisci(2051, -41); // codice azione indossa/metti tuta
	azioni.inserisci(2052, -41); // codice azione indossa/metti camice
	azioni.inserisci(2150, -10);
	azioni.inserisci(2151, -10);
	azioni.inserisci(2152, -3);
	azioni.inserisci(2255, -15);
	azioni.inserisci(2555, -15);
	azioni.inserisci(2769, -29);
	azioni.inserisci(5600, 44); // codice azione inventario valigia
	azioni.inserisci(5700, 42); // codice azione inventario zaino
	azioni.inserisci(5800, 43); // codice azione aiuto/help
	azioni.inserisci(6550, -10);
	azioni.inserisci(6551, -10);
	azioni.inserisci(6552, -3);
	azioni.inserisci(11066, 16);
	azioni.inserisci(12570, 17);
	azioni.inserisci(12661, 18);
	azioni.inserisci(20300, 21);
	azioni.inserisci(20500, 20);
	azioni.inserisci(22560, 19);
	azioni.inserisci(30300, 21);
	azioni.inserisci(40300, 21);
	azioni.inserisci(42560, 22);
	azioni.inserisci(52267, 23);
	azioni.inserisci(62267, 24);
	azioni.inserisci(70300, 37);
	azioni.inserisci(70400, 38);
	azioni.inserisci(72661, 25);
	azioni.inserisci(72662, 27);
	azioni.inserisci(72664, 26);
	azioni.inserisci(81066, 16);
	azioni.inserisci(82365, 35);
	azioni.inserisci(82465, 34);
	azioni.inserisci(82560, 28);
	azioni.inserisci(82661, 30);
	azioni.inserisci(82662, 33);
	azioni.inserisci(82663, 32);
	azioni.inserisci(82664, 31);
	azioni.inserisci(91069, 36);
	// oggetti: (nome, codice, luogo) // linea 7 oggetti.cpp
	oggetti.svuota();
	oggetti.inserisci(Oggetto("un indicatore", 66, -1, 0)); // peso=0 per oggetti non "considerati"
	oggetti.inserisci(Oggetto("un pulsante", 61, -1, 0));
	oggetti.inserisci(Oggetto("un'etichetta", 70, -1, 0));
	oggetti.inserisci(Oggetto("una tuta", 51, 1, 2)); // peso= n per oggetti trasportabili in zaino o valigia
	oggetti.inserisci(Oggetto("un cartello bianco", 60, -2, 0));
	oggetti.inserisci(Oggetto("un cartello giallo", 60, -4, 0));
	oggetti.inserisci(Oggetto("un letto", 68, -5, 0));
	oggetti.inserisci(Oggetto("un armadietto", 67, -5, 0));
	oggetti.inserisci(Oggetto("un letto", 68, -6, 0));
	oggetti.inserisci(Oggetto("un armadietto", 67, -6, 0));
	oggetti.inserisci(Oggetto("un casco", 50, 6, 3));
	oggetti.inserisci(Oggetto("un pulsante rosso", 61, -7, 0));
	oggetti.inserisci(Oggetto("un pulsante verde", 61, -7, 0));
	oggetti.inserisci(Oggetto("un indicatore", 66, -8, 0));
	oggetti.inserisci(Oggetto("una leva", 65, -8, 0));
	oggetti.inserisci(Oggetto("un pulsante rosso", 61, -8, 0));
	oggetti.inserisci(Oggetto("un pulsante verde", 61, -8, 0));
	oggetti.inserisci(Oggetto("un cartello rosso", 60, -8, 0));
	oggetti.inserisci(Oggetto("un pulsante giallo", 61, -8, 0));
	oggetti.inserisci(Oggetto("il secondo pilota", 53, 9, 0));
	oggetti.inserisci(Oggetto("un'antenna parabolica", 69, -9, 0));
	oggetti.inserisci(Oggetto("un camice", 52, -99, 3));
	oggetti.inserisci(Oggetto("una chiave", 54, -99, 0));
	oggetti.inserisci(Oggetto("un manuale", 55, -99, 1));
	oggetti.inserisci(Oggetto("una valigia", 56, 5, 0)); // inserimento oggetto valigia
	oggetti.inserisci(Oggetto("uno zaino", 57, 6, 0)); // inserimento oggetto zaino
	// variabili
	tempo = 100;
	luogo_attuale = 6;
	passo_soluzione = 0;
	parete_stagna_aperta = 0;
	n_oggettiZ = 0; // numero oggetti nello zaino
	peso_MaxZ = 5; // peso massimo trasportabile nello zaino
	n_oggettiV = 0; // numero oggetti nella valigia
	peso_MaxV = 8; // peso massimo trasportabile nella valigia
	// variabili utilizzate per save e load
	el1 = 0;
	el2 = 0;
	el3 = 0;
	el4 = 0;
	el5 = 0;
	el6 = 0;
}

void Astro::introduzione() {
	interfaccia.scrivi("\n\n\n# L'astronave condannata:un'avventura #"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("# di Enrico Colombini e Chiara Tovena #\n");
	interfaccia.scrivi("(c) Dinosoft e Jackson Editrice 1985\n");
	interfaccia.scrivi("Sdraiato nella sabbia, ti godi il");
	interfaccia.scrivi("dolce calore del sole tropicale...\n");
	interfaccia.scrivi("Ora il sole picchia piu' forte,");
	interfaccia.scrivi("sei in pieno deserto e non c'e'");
	interfaccia.scrivi("traccia di oasi...\n");
	interfaccia.scrivi("Ti svegli di soprassalto nella tua");
	interfaccia.scrivi("cabina di comandante del 'Neutronia'.");
	interfaccia.scrivi("Fa molto caldo. Troppo caldo. Ci");
	interfaccia.scrivi("dev'essere qualcosa che non funziona.\n");
}

void Astro::tempo_specifiche() {
	if (tempo <= 10)
		interfaccia.scrivi("Sento un segnale di allarme."); // linea 12 interfaccia.cpp
	if (tempo <= 5)
		interfaccia.scrivi("La temperatura e' insopportabile.");
	if (tempo <= 2)
		interfaccia.scrivi("La nave e' scossa da vibrazioni.");
	if (tempo <= 0) {
		interfaccia.scrivi("*** Troppo tardi! ***");
		interfaccia.scrivi("Il reattore e' fuori controllo.");
		interfaccia.scrivi("L'astronave e' disintegrata in minuscoli frammenti");
		interfaccia.scrivi("E' incredibile il silenzio delle esplosioni nel vuoto.");
	}
}

void Astro::epitaffio() {
	interfaccia.scrivi("### IL GAZZETTINO DELLA GALASSIA ###"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("");
	interfaccia.scrivi("- Tragedia al largo di Vega -");
	interfaccia.scrivi("");
	interfaccia.scrivi("L'astronave 'Neutronia', in servizio");
	interfaccia.scrivi("passeggeri con 250 persone a bordo,");
	interfaccia.scrivi("e' stata distrutta da una violenta");
	interfaccia.scrivi("esplosione, causata probabilmente");
	interfaccia.scrivi("da imperizia del comandante (un");
	interfaccia.scrivi("novellino, stando a indiscrezioni");
	interfaccia.scrivi("raccolte dal nostro corrispondente)");
	interfaccia.scrivi("Il responsabile del peggior disastro");
	interfaccia.scrivi("della storia galattica sara' di certo");
	interfaccia.scrivi("degradato alla memoria.");
	interfaccia.scrivi("");
}

bool Astro::prendi_specifiche() {
	bool problemi = true;

	// controllo che l’oggetto sia o la tuta, o il casco, o il camice e che sia valigia che zaino non si trovino nell’inventario
	if ((og == 4 || og == 11 || og == 22 /*|| og == 24*/) && (oggetti.get_oggetto(25).get_luogo() != 0 && oggetti.get_oggetto(26).get_luogo() != 0)){
		interfaccia.scrivi("Trova prima uno zaino o una valigia.");
		interfaccia.scrivi("(Suggerimento: puoi comunque indossarlo.)");
	}
	else if(og == 25 && oggetti.get_oggetto(26).get_luogo() == 0){ // controllo che l’oggetto sia la valigia e che nell’inventario ci sia lo zaino
		interfaccia.scrivi("Lascia prima lo zaino.");  // linea 12 interfaccia.cpp
	}
	else if(og == 26 && oggetti.get_oggetto(25).get_luogo() == 0){ // controllo che l’oggetto sia lo zaino e che nell’inventario ci sia la valigia
		interfaccia.scrivi("Lascia prima la valigia.");  // linea 12 interfaccia.cpp
	}
	else // se non si verifica nessuna di queste ipotesi, imposto problemi a false
		problemi = false;
	return problemi;
}

bool Astro::preso_specifiche() {
	bool avvisato = true;
	// controllo che l’oggetto sia o la tuta, o il casco, o il camice, o il manuale e che la valigia stia nell’inventario
	if ((og == 4 || og == 11 || og == 22 || og == 24) && (oggetti.get_oggetto(25).get_luogo() == 0)){
		if(oggetti.get_oggetto(og).get_peso() > peso_MaxV && og != 24){// controllo che il peso dell’oggetto sia maggiore allo spazio disponibile nella valigia e che l’oggetto sia diverso dal manuale
			oggetti.set_luogo(og,luogo_attuale);
			interfaccia.scrivi("La valigia e' troppo piena...");
			interfaccia.scrivi("(Suggerimento: togli qualcosa dalla valigia.)");
		}
		else if(oggetti.get_oggetto(og).get_peso() > peso_MaxV && og == 24){// controllo che il peso dell’oggetto sia maggiore allo spazio disponibile nella valigia e che l’oggetto sia uguale al manuale
			oggetti.set_luogo(og,0);
			interfaccia.scrivi("La valigia e' troppo piena...");
			interfaccia.scrivi("Lo tengo in mano, e' troppo importante.");
			interfaccia.scrivi("(Suggerimento: controlla nell'inventario)");
		}
		else{ // se non si verifica nessuna di queste ipotesi l’oggetto viene inserito in valigia
			interfaccia.scrivi("Ora e' in valigia.");
			ins.Inserisci(oggetti.get_oggetto(og).get_codice());
			n_oggettiV++;
			peso_MaxV -= oggetti.get_oggetto(og).get_peso();
		}
	}
	else if ((og == 4 || og == 11 || og == 22 || og == 24) && (oggetti.get_oggetto(26).get_luogo() == 0)){ // controllo che l’oggetto sia o la tuta, o il casco, o il camice, o il manuale e che lo zaino stia nell’inventario
		if(oggetti.get_oggetto(og).get_peso() > peso_MaxZ && og != 24){// controllo che il peso dell’oggetto sia maggiore allo spazio disponibile nello zaino e che l’oggetto sia diverso dal manuale
			oggetti.set_luogo(og,luogo_attuale);
			interfaccia.scrivi("Lo zaino e' troppo pieno...");
			interfaccia.scrivi("(Suggerimento: togli qualcosa dallo zaino.)");
		}
		else if(oggetti.get_oggetto(og).get_peso() > peso_MaxZ && og == 24){// controllo che il peso dell’oggetto sia maggiore allo spazio disponibile nello zaino e che l’oggetto sia uguale al manuale
			oggetti.set_luogo(og,0);
			interfaccia.scrivi("Lo zaino e' troppo pieno...");
			interfaccia.scrivi("Lo tengo in mano, e' troppo importante.");
			interfaccia.scrivi("(Suggerimento: controlla nell'inventario)");
		}
		else{// se non si verifica nessuna di queste ipotesi l’oggetto viene inserito nello zaino
			interfaccia.scrivi("Ora e' nello zaino."); // linea 12 interfaccia.cpp
			p.inPila(oggetti.get_oggetto(og).get_codice());
			n_oggettiZ++;
			peso_MaxZ -= oggetti.get_oggetto(og).get_peso();
		}
	}
	else // se non si verifica nessuna di queste ipotesi, imposto avvisato a false
		avvisato = false;
	return avvisato;
}

bool Astro::lascia_specifiche() {
	bool lasciato = true;

	if (luogo_attuale >= 9 || (luogo_attuale == 7 && parete_stagna_aperta == 1)) { //controllo che il luogo sia pari o superiore a 9 (prua astronave, esterno astronave, poppa astronave) o che il luogo sia il compartimento stagno e che la combinazione dei pulsanti(rosso-verde) sia 1, quindi tasto rosso premuto
		oggetti.set_luogo(og, -99);  // linea 35 oggetti.cpp
		interfaccia.scrivi("Si e' perso nello spazio."); // linea 12 interfaccia.cpp
	} else
		lasciato = false;
	return lasciato;
}

void Astro::save_specifiche(ofstream &file) {
	file << parete_stagna_aperta << '\n';
}

void Astro::load_specifiche(ifstream &file) {
	file >> parete_stagna_aperta;
}

bool Astro::esegui_specifiche(int a) {
	bool eseguito = true;
	switch (a) {
	case 10:
		azione_10(); // linea 350
		break;
	case 11:
		azione_11(); // linea 361
		break;
	case 12:
		azione_12(); // linea 365
		break;
	case 13:
		azione_13(); // linea 374
		break;
	case 14:
		azione_14(); // linea 378
		break;
	case 15:
		azione_15(); // linea 383
		break;
	case 16:
		azione_16(); // linea 399
		break;
	case 17:
		azione_17(); // linea 407
		break;
	case 18:
		azione_18(); // linea 413
		break;
	case 19:
		azione_19(); // linea 418
		break;
	case 20:
		azione_20(); // linea 424
		break;
	case 21:
		azione_21(); // linea 433
		break;
	case 22:
		azione_22(); // linea 438
		break;
	case 23:
		azione_23(); // linea 444
		break;
	case 24:
		azione_24(); // linea 456
		break;
	case 25:
		azione_25(); // linea 460
		break;
	case 26:
		azione_26(); // linea 465
		break;
	case 27:
		azione_27(); // linea 489
		break;
	case 28:
		azione_28(); // linea 509
		break;
	case 29:
		azione_29(); // linea 515
		break;
	case 30:
		azione_30(); // linea 519
		break;
	case 31:
		azione_31(); // linea 524
		break;
	case 32:
		azione_32(); // linea 537
		break;
	case 33:
		azione_33(); // linea 548
		break;
	case 34:
		azione_34(); // linea 563
		break;
	case 35:
		azione_35(); // linea 575
		break;
	case 36:
		azione_36(); // linea 578
		break;
	case 37:
		azione_37(); // linea 583
		break;
	case 38:
		azione_38(); // linea 590
		break;
	case 39:
		azione_39();
		break;
	case 40:
		azione_40();
		break;
	case 41:
		azione_41();
		break;
	case 42:
		azione_42();
		break;
	case 43:
		azione_43();
		break;
	case 44:
		azione_44();
		break;
	default:
		eseguito = false;
	}
	return eseguito;
}

void Astro::azione_10() {
	if (oggetti.get_oggetto(og).get_luogo() != 0 && oggetti.get_oggetto(og).get_luogo() != 12) // controllo che l’oggetto non si trovi né nell’inventario, né nello zaino, né nella valigia
		interfaccia.scrivi("- Non ce l'hai."); // linea 12 interfaccia.cpp
	else if (!(luogo_attuale == 9) || (luogo_attuale == 7 && parete_stagna_aperta == 1)) //controllo che il luogo attuale non sia la prua dell’astronave o che il luogo attuale sia il compartimento stagno con la combinazione di pulsanti(rosso-verde) settata ad 1, quindi pulsante rosso premuto
		lascia(); // linea 207 gioco.cpp
	else {
		interfaccia.scrivi("L'aria! L'aria! Aaaagh!!!"); // linea 12 interfaccia.cpp
		morto(); // linea 45 gioco.cpp
	}
}

void Astro::azione_11() {
	interfaccia.scrivi("E' la tuta per la tua attivita' extraveicolare."); // linea 12 interfaccia.cpp
}

void Astro::azione_12() {
	interfaccia.scrivi("E' privo di conoscenza ed ha"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("un'ammaccatura nel casco.");
	interfaccia.scrivi("Probabilmente e' stato colpito");
	interfaccia.scrivi("da un piccolo meteorite");
	interfaccia.scrivi("mentre riparava l'antenna.");
	interfaccia.scrivi("Per fortuna, e' ancora vivo.");
}

void Astro::azione_13() {
	interfaccia.scrivi("Non e' meglio leggerlo?"); // linea 12 interfaccia.cpp
}

void Astro::azione_14() {
	interfaccia.scrivi("E' piuttosto pesante."); // linea 12 interfaccia.cpp
	interfaccia.scrivi("Probabilmente, e' trattato al piombo.");
}

void Astro::azione_15() {
	if (oggetti.get_oggetto(og).get_luogo() == luogo_attuale) // controllo che l’oggetto si trovi nel luogo attuale
		interfaccia.scrivi("Prendilo in mano, prima."); // linea 12 interfaccia.cpp
	else if(oggetti.get_oggetto(og).get_luogo() == 12){ // controllo che l’oggetto si trovi nello zaino o nella valigia
		if(ins.Appartiene(55)){ // controllo che l’oggetto manuale si trovi nella valigia
			interfaccia.scrivi("- MANUALE DI ISTRUZIONI DEL -"); // linea 12 interfaccia.cpp
			interfaccia.scrivi("-   REATTORE POSITRONICO    -");
			interfaccia.scrivi("-     Mod. YTREWQ 8421      -\n");
			interfaccia.scrivi("- Per attivare il reattore,");
			interfaccia.scrivi("tirare la leva e poi premere");
			interfaccia.scrivi("in sequenza i pulsanti verde,");
			interfaccia.scrivi("giallo e rosso.");
			interfaccia.scrivi("- Per disattivare il reattore...\n");
			interfaccia.scrivi("Dannazione! La pagina e' strappata.");
		}
		else if(p.leggiPila() == 55){ // controllo che l’oggetto manuale sia il primo visibile nello zaino
			interfaccia.scrivi("- MANUALE DI ISTRUZIONI DEL -"); // linea 12 interfaccia.cpp
			interfaccia.scrivi("-   REATTORE POSITRONICO    -");
			interfaccia.scrivi("-     Mod. YTREWQ 8421      -\n");
			interfaccia.scrivi("- Per attivare il reattore,");
			interfaccia.scrivi("tirare la leva e poi premere");
			interfaccia.scrivi("in sequenza i pulsanti verde,");
			interfaccia.scrivi("giallo e rosso.");
			interfaccia.scrivi("- Per disattivare il reattore...\n");
			interfaccia.scrivi("Dannazione! La pagina e' strappata.");
		}
		else{
			interfaccia.scrivi("Devi prima lasciare: ");
			oggetti.get_zaino(p.leggiPila());
		}
	}
	else{
		interfaccia.scrivi("- MANUALE DI ISTRUZIONI DEL -"); // linea 12 interfaccia.cpp
		interfaccia.scrivi("-   REATTORE POSITRONICO    -");
		interfaccia.scrivi("-     Mod. YTREWQ 8421      -\n");
		interfaccia.scrivi("- Per attivare il reattore,");
		interfaccia.scrivi("tirare la leva e poi premere");
		interfaccia.scrivi("in sequenza i pulsanti verde,");
		interfaccia.scrivi("giallo e rosso.");
	    interfaccia.scrivi("- Per disattivare il reattore...\n");
		interfaccia.scrivi("Dannazione! La pagina e' strappata.");
	}
}

void Astro::azione_16() {
	interfaccia.scrivi("- TEMPERATURA REATTORE -\n"); // linea 12 interfaccia.cpp
	interfaccia.scrivi_parziale("Segna "); // linea 63 interfaccia.cpp
	interfaccia.scrivi_parziale(840 - tempo * 4);
	interfaccia.scrivi(" gradi e sta salendo velocemente.");
	interfaccia.scrivi(" C'e' un segno rosso a 800 gradi.");
}

void Astro::azione_17() {
	interfaccia.scrivi("- S.O.S. GALATTICO -\n"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("Premere il pulsante solo in caso di emergenza.");
	interfaccia.scrivi("Ogni abuso verra' punito.");
}

void Astro::azione_18() {
	interfaccia.scrivi("Una scritta lampeggia brevemente:"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("- ANTENNA ESTERNA DIFETTOSA -");
}

void Astro::azione_19() {
	interfaccia.scrivi("E' alla base di una scaletta e dice:\n"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("INGRESSO RISERVATO AL");
	interfaccia.scrivi("PERSONALE DI BORDO.");
}

void Astro::azione_20() {
	luogo_attuale = 1;
	if (oggetti.get_oggetto(20).get_luogo() == 9) { // linea 11 oggetti.cpp e linea 19 oggetto.cpp
		interfaccia.scrivi("Se solo ci fosse qui il secondo"); // linea 12 interfaccia.cpp
		interfaccia.scrivi("pilota, il solo che se ne intende");
		interfaccia.scrivi("di problemi tecnici!");
	}
}

void Astro::azione_21() {
	interfaccia.scrivi("Meglio non svegliare i passeggeri,"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("potrebbero farsi prendere dal panico.");
}

void Astro::azione_22() {
	interfaccia.scrivi("E' posto ad ovest e dice:\n"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("- ATTENZIONE: -\n");
	interfaccia.scrivi("STANZA DEPRESSURIZZATA");
}

void Astro::azione_23() {
	if (oggetti.get_oggetto(24).get_luogo() != -99) // linea 11 oggetti.cpp e linea 19 oggetto.cpp
		interfaccia.scrivi("Gia' fatto."); // linea 12 interfaccia.cpp
	else if (oggetti.get_oggetto(23).get_luogo() != 0) // linea 11 oggetti.cpp e linea 19 oggetto.cpp
		interfaccia.scrivi("E' chiuso a chiave."); // linea 12 interfaccia.cpp
	else {
		interfaccia.scrivi("Fatto.");  // linea 12 interfaccia.cpp
		oggetti.set_luogo(24, luogo_attuale); // linea 35 oggetti.cpp
		oggetti.set_luogo(22, luogo_attuale); // linea 35 oggetti.cpp
	}
}

void Astro::azione_24() {
	interfaccia.scrivi("E' vuoto."); // linea 12 interfaccia.cpp
}

void Astro::azione_25() {
	interfaccia.scrivi("Dimmi: 'Premi il rosso'"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("o 'Premi il verde'.");
}

void Astro::azione_26() {
	int i;
	if (parete_stagna_aperta == 1)
		interfaccia.scrivi("Click."); // linea 12 interfaccia.cpp
	else {
		interfaccia.scrivi("La parete ad est si chiude."); // linea 12 interfaccia.cpp
		interfaccia.scrivi("La parete ad ovest si apre");
		interfaccia.scrivi("verso lo spazio esterno.");
		interfaccia.scrivi("L'aria esce sibilando.");
		if (oggetti.get_oggetto(4).get_luogo() != 0 || oggetti.get_oggetto(11).get_luogo() != 0) { // linea 11 oggetti.cpp e linea 19 oggetto.cpp
			interfaccia.scrivi("\nAaaagh!!!"); // linea 12 interfaccia.cpp
			morto(); // linea 45 gioco.cpp
		} else {
			for (i = 1; i <= oggetti.get_n_oggetti(); i++) { // linea 15 oggetti.cpp
				if (oggetti.get_oggetto(i).get_luogo() == luogo_attuale) { // linea 11 oggetti.cpp e linea 19 oggetto.cpp
					interfaccia.scrivi(oggetti.get_oggetto(i).get_nome() + " si perde nello spazio"); // linea 11 oggetti.cpp e linea 11 oggetto.cpp
					oggetti.set_luogo(i, -99); // linea 35 oggetti.cpp
				}
			}
			parete_stagna_aperta = 1;
		}
	}
}

void Astro::azione_27() {
	if (parete_stagna_aperta == 0)
		interfaccia.scrivi("Click."); // linea 12 interfaccia.cpp
	else {
		interfaccia.scrivi("La parete ad ovest si chiude."); // linea 12 interfaccia.cpp
		interfaccia.scrivi("La parete ad est si apre");
		interfaccia.scrivi("verso il corridoio.");
		interfaccia.scrivi("L'aria rientra sibilando.");
		parete_stagna_aperta = 0;
		if (!(oggetti.get_oggetto(20).get_luogo() != 0 || oggetti.get_oggetto(23).get_luogo() != -99)) {  // linea 11 oggetti.cpp e linea 19 oggetto.cpp
			interfaccia.scrivi("\nIl secondo pilota rinviene, si rende"); // linea 12 interfaccia.cpp
			interfaccia.scrivi("subito conto della situazione e dice:\n");
			interfaccia.scrivi("- Presto, ferma il reattore!");
			interfaccia.scrivi("Ecco la chiave del mio...");
			interfaccia.scrivi("Poi perde nuovamente i sensi");
			oggetti.set_luogo(23, luogo_attuale); // linea 35 oggetti.cpp
		}
	}
}

void Astro::azione_28() {
	interfaccia.scrivi("- L'EMERGENZA E' IN AGGUATO! -"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("-    Porta sempre con te     -");
	interfaccia.scrivi("-  il manuale del reattore.  -");
}

void Astro::azione_29() {
	interfaccia.scrivi("Il tecnico e' il secondo pilota.");  // linea 12 interfaccia.cpp
}

void Astro::azione_30() {
	interfaccia.scrivi("Dimmi: 'Premi il rosso', 'Premi"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("il verde' o 'Premi il giallo'.");
}

void Astro::azione_31() {
	interfaccia.scrivi("Click."); // linea 12 interfaccia.cpp
	if (passo_soluzione != 0)
		errore(); // linea 272 gioco.cpp
	else {
		interfaccia.scrivi("Una tubatura perde leggermente"); // linea 12 interfaccia.cpp
		interfaccia.scrivi("da un raccordo (probabilmente per");
		interfaccia.scrivi("sovrapressione). Le gocce cadono sul");
		interfaccia.scrivi("quadro di controllo, vicino a te.");
		passo_soluzione = 1;
	}
}

void Astro::azione_32() {
	interfaccia.scrivi("Click."); // linea 12 interfaccia.cpp
	if (passo_soluzione != 1)
		errore();  // linea 272 gioco.cpp
	else {
		passo_soluzione = 2;
		if (oggetti.get_oggetto(22).get_luogo() != 0) // linea 11 oggetti.cpp e linea19 oggetto.cpp
			interfaccia.scrivi("Non ti senti troppo bene."); // linea 12 interfaccia.cpp
	}
}

void Astro::azione_33() {
	interfaccia.scrivi("Click."); // linea 12 interfaccia.cpp
	if (passo_soluzione != 2)
		errore(); // linea 272 gioco.cpp
	else {
		passo_soluzione = 3;
		if (oggetti.get_oggetto(22).get_luogo() != 0) {  // linea 11 oggetti.cpp e linea19 oggetto.cpp
			interfaccia.scrivi("Temo che tu abbia assorbito troppe");  // linea 12 interfaccia.cpp
			interfaccia.scrivi("radiazioni. Ora stai decisamente");
			interfaccia.scrivi("male. Perdi conoscenza...");
			morto(); // linea 45 gioco.cpp
		}
	}
}

void Astro::azione_34() {
	interfaccia.scrivi("Clanck."); // linea 12 interfaccia.cpp
	if (passo_soluzione != 3)
		errore(); // linea 272 gioco.cpp
	else {
		interfaccia.pausa(); // linea 16 interfaccia.cpp
		encomio(); // linea 597
		fine_partita = true;
		riparti = false;
	}
}

void Astro::azione_35() {
	interfaccia.scrivi("Clunck."); // linea 12 interfaccia.cpp
}
void Astro::azione_36() {
	interfaccia.scrivi("Sembra danneggiata, forse");  // linea 12 interfaccia.cpp
	interfaccia.scrivi("da un grosso meteorite.");
}

void Astro::azione_37() {
	if (parete_stagna_aperta == 0)
		luogo_attuale = 4;
	else
		direzioni(); // linea 179 gioco.cpp
}

void Astro::azione_38() {
	if (parete_stagna_aperta == 1)
		luogo_attuale = 11;
	else
		direzioni();  // linea 179 gioco.cpp
}

void Astro::encomio() {
	interfaccia.scrivi("### IL GAZZETTINO DELLA GALASSIA ###\n"); // linea 12 interfaccia.cpp
	interfaccia.scrivi("- Comandante salva astronave -\n");
	interfaccia.scrivi("L'astronave 'Neutronia', in servizio");
	interfaccia.scrivi("passeggeri con 250 persone a bordo,");
	interfaccia.scrivi("e' stata salvata da sicura distruzione");
	interfaccia.scrivi("grazie al coraggio e al sangue freddo");
	interfaccia.scrivi("del comandante, che e' riuscito a");
	interfaccia.scrivi("disattivare il reattore impazzito.");
	interfaccia.scrivi("Il suo nome verra' ricordato per");
	interfaccia.scrivi("sempre tra gli eroi della nostra");
	interfaccia.scrivi("flotta galattica\n");
	interfaccia.scrivi("\n- Congratulazioni! -\n");
}

void Astro::azione_39() {
	interfaccia.scrivi("E' la valigia del secondo pilota."); // linea 12 interfaccia.cpp
	interfaccia.scrivi("Sembra molto capiente."); // linea 12 interfaccia.cpp
}

void Astro::azione_40() {
	interfaccia.scrivi("E' il tuo zaino, puo' essere utile per trasportare oggetti."); // linea 12 interfaccia.cpp
}

void Astro::azione_41() {
	if (oggetti.get_oggetto(og).get_luogo() == 0) // controllo che l’oggetto si trovi nell’inventario
		interfaccia.scrivi("- Gia' fatto."); // linea 12 interfaccia.cpp
	else if (oggetti.get_oggetto(og).get_luogo() < 0) // controllo che l’oggetto non sia indossabile
		interfaccia.scrivi("- Non e' possibile."); // linea 12 interfaccia.cpp
	else if (!indossa_specifiche()) { // faccio alcuni controlli in indossa_specifiche
		if(oggetti.get_oggetto(26).get_luogo() == 0){ // controllo che lo zaino sia presente nell’inventario
			if (oggetti.get_oggetto(4).get_luogo() == 12 || oggetti.get_oggetto(11).get_luogo() == 12 || oggetti.get_oggetto(22).get_luogo() == 12){ // controllo che almeno uno tra: tuta, casco e camice sia presente nello zaino
				if(og == 4 || og == 11 || og == 22){ // controllo che l’oggetto in questione sia proprio uno tra: tuta, casco e camice
					int c;
					c=p.leggiPila();
					if(og == oggetti.get_zaino2(c)){ // controllo che l’oggetto sia proprio il primo oggetto nello zaino
						oggetti.set_luogo(og,0);
						p.fuoriPila();
						n_oggettiZ--;
						peso_MaxZ += oggetti.get_oggetto(og).get_peso();
						//cout << peso_MaxZ;
					}
					else if(oggetti.get_oggetto(og).get_luogo() == luogo_attuale){ // controllo che l’oggetto si trovi nel luogo attuale
						oggetti.set_luogo(og,0);
					}
					else{
						interfaccia.scrivi("Devi prima lasciare: ");
						oggetti.get_zaino(c);
					}
				}
				else{
					oggetti.set_luogo(og,0);
					interfaccia.scrivi("Fatto.");
				}
			}
			else{
				oggetti.set_luogo(og,0); // linea 35 oggetti.cpp
			}
		}
		else if(oggetti.get_oggetto(25).get_luogo() == 0){ // controllo che la valigia si trovi nell’inventario
			if (oggetti.get_oggetto(4).get_luogo() == 12 || oggetti.get_oggetto(11).get_luogo() == 12 || oggetti.get_oggetto(22).get_luogo() == 12){// controllo che almeno uno tra: tuta, casco e camice si trovi nella valigia
				if(og == 4 || og == 11 || og == 22){ // controllo che l’oggetto sia proprio uno tra: tuta, casco e camice
					int c;
					c=og;
					if(ins.Appartiene(oggetti.get_valigia(c))){ // controllo che l’oggetto sia presente nella valigia
						oggetti.set_luogo(og,0);
						ins.Cancella(oggetti.get_valigia(c));
						n_oggettiV--;
						peso_MaxV += oggetti.get_oggetto(og).get_peso();
					}
					else if(!ins.Appartiene(oggetti.get_valigia(c))) //controllo che l’oggetto non sia presente nella valigia
						interfaccia.scrivi("- Non ce l'hai in valigia.");
					else if(oggetti.get_oggetto(og).get_luogo() == luogo_attuale){ //controllo che l’oggetto si trovi nel luogo attuale
						oggetti.set_luogo(og,0);
					}
				}
				else{
					oggetti.set_luogo(og,0);
					interfaccia.scrivi("Fatto.");
				}
			}
			else{
				oggetti.set_luogo(og,0); // linea 35 oggetti.cpp
				}
		}
		else{
			if(og != 0 && oggetti.get_oggetto(og).get_luogo() != 12){ // controllo che l’oggetto non si trovi in un altro luogo e che l’oggetto non si trovi nello zaino o nella valigia
				oggetti.set_luogo(og,0);
			}
			else
				interfaccia.scrivi("- Sta nello zaino o nella valigia, e non li hai.");
		}
		if (!indosso_specifiche()){ // faccio alcuni controlli in indosso_specifiche
			if(oggetti.get_oggetto(og).get_luogo() == 0) //controllo che l’oggetto si trovi nell’inventario
				interfaccia.scrivi("Fatto.");  // linea 12 interfaccia.cpp
		}
	}
}

bool Astro::indossa_specifiche() {
	bool problemi = true;

	if (og == 4 && oggetti.get_oggetto(22).get_luogo() == 0) // controllo che l’oggetto sia la tuta e che il camice si trovi nell’inventario
		interfaccia.scrivi("Togli prima il camice.");  // linea 12 interfaccia.cpp
	else if (og == 22 && oggetti.get_oggetto(4).get_luogo() == 0) // controllo che l’oggetto sia il camice e che la tuta si trovi nell’inventario
		interfaccia.scrivi("Togli prima la tuta.");  // linea 12 interfaccia.cpp
	else
		problemi = false;
	return problemi;
}

bool Astro::indosso_specifiche() {
	bool avvisato = true;

	if (og == 4 || og == 11 || og == 22) //controllo che l’oggetto sia uno tra: tuta, casco e camice
		if(oggetti.get_oggetto(og).get_luogo() == 0) //controllo che l’oggetto stia nell’inventario
			interfaccia.scrivi("Ora l'hai addosso."); // linea 12 interfaccia.cpp
	else
		avvisato = false;
	return avvisato;
}

void Astro::azione_42() {
	if(oggetti.get_oggetto(26).get_luogo() == 0){ // controllo che l’oggetto zaino si trovi nell’inventario
		if (!p.pilaVuota()) { // controllo che l’oggetto zaino non sia vuoto
			interfaccia.scrivi("Inventario Zaino");
			interfaccia.scrivi("\nVedo in cima: ");
			int c;
			c=p.leggiPila();
			oggetti.get_zaino(c);
			cout << "\nTotale Oggetti nello Zaino: " << n_oggettiZ << endl;
			cout << "Spazio disponibile: "<< peso_MaxZ << " su 5 kg."<< endl;
		}
		else
			interfaccia.scrivi("E' vuoto.");
	}
	else
		interfaccia.scrivi("Non lo hai.");
}

void Astro::azione_43() {
	interfaccia.scrivi("\nCOMANDI DI GIOCO:");
	interfaccia.scrivi("\nDirezioni: ");
	interfaccia.scrivi("- n/nord: per muoverti in avanti;");
	interfaccia.scrivi("- s/sud: per muoverti indietro;");
	interfaccia.scrivi("- e/est: per muoverti a destra;");
	interfaccia.scrivi("- w/o/ovest: per muoverti a sinistra;");
	interfaccia.scrivi("- a/alto/sali: per salire ad un piano superiore;");
	interfaccia.scrivi("- b/basso/scendi: per scendere ad un piano inferiore;");
	interfaccia.scrivi("\nAzioni: ");
	interfaccia.scrivi("- prendi: per trasportare un oggetto in mano o con se(zaino/valigia);");
	interfaccia.scrivi("- indossa/metti: per indossare un oggetto(es. casco);");
	interfaccia.scrivi("- guarda: per guardare ed ottenere informazioni su un oggetto (es.tuta);");
	interfaccia.scrivi("- lascia/togli/leva: per lasciare o togliersi gli oggetti trasportati;");
	interfaccia.scrivi("- apri: per aprire un oggetto fisso(es. armadietto);");
	interfaccia.scrivi("- leggi: per leggere una scritta(es.cartello);");
	interfaccia.scrivi("- spingi/tira: per spingere o tirare un oggetto fisso(es.leva);");
	interfaccia.scrivi("- premi/schiaccia: per premere un oggetto fisso(es.pulsante);");
	interfaccia.scrivi("- inventario/cosa: per accedere all'inventario degli oggetti trasportati;");
	interfaccia.scrivi("- zaino: per accedere agli oggetti trasportati nello zaino;");
	interfaccia.scrivi("- valigia: per accedere agli oggetti trasportati nella valigia;");
	interfaccia.scrivi("- save/load: per salvare o caricare la partita;");
}

void Astro::azione_44() {
	if(oggetti.get_oggetto(25).get_luogo() == 0){// controllo che l’oggetto valigia si trovi nell’inventario
		if (!ins.InsiemeVuoto()) {// controllo che l’oggetto valigia non sia vuoto
			interfaccia.scrivi("Inventario Valigia");
			interfaccia.scrivi("\nVedo: ");
			if(ins.Appartiene(50)) // controllo che il casco sia presente nella valigia
				oggetti.get_zaino(50);
				//interfaccia.scrivi("- un casco");
			if(ins.Appartiene(51)) // controllo che la tua sia presente nella valigia
				oggetti.get_zaino(51);
				//interfaccia.scrivi("- una tuta");
			if(ins.Appartiene(52)) // controllo che il camice sia presente nella valigia
				oggetti.get_zaino(52);
				//interfaccia.scrivi("- un camice");
			if(ins.Appartiene(55)) // controllo che il manuale sia presente nella valigia
				oggetti.get_zaino(55);
				//interfaccia.scrivi("- un manuale");
			cout << "\nTotale Oggetti nella Valigia: " << n_oggettiV << endl;
			cout << "Spazio disponibile: "<< peso_MaxV << " su 8 kg."<< endl;
		}
		else
			interfaccia.scrivi("E' vuota.");
	}
	else
		interfaccia.scrivi("Non ce l'hai.");
}
