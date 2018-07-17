#include "mappa.h"

Mappa::Mappa() {}

Luogo Mappa::get_luogo(int cod_luogo) {
      return mappa.legginodo(cod_luogo); // linea 127 grafo.h
}

void Mappa::ins_luogo(int i, Luogo l) {
     mappa.insnodo(i);
     mappa.scrivinodo(i,l);
}

void Mappa::ins_strada(int i, int j, Strada s) {
     mappa.insarco(i,j);
     mappa.scriviarco(i,j,s); // PERDE I DATI
}
