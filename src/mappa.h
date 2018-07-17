#ifndef H_MAPPA
#define H_MAPPA

using namespace std;

#include "grafo.h"
#include "luogo.h"
#include "strada.h"

class Mappa {
      public:
             Mappa();
             void ins_luogo(int,Luogo);
             void ins_strada(int,int,Strada);
             Luogo get_luogo(int);
      private:
              Grafo<int,Luogo,Strada> mappa;
};

#endif
