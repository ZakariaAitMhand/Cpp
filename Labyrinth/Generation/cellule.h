#include "murs.h"  
#include<cstdlib>
#include <vector>

class cellules{
      private:
          bool visited;
          murs *tab_mur;
          public:
          cellules();
          void visite();
          bool is_visited();
          void detruire_mur(int);
          int get_etat();
          void sortir();
      };
