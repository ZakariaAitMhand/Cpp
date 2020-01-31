#include "cellule.h"
#include <vector>


class generation{
      
        int lignes;
        int cols;
        cellules c[10][20];
        
        
      public: generation();
              void generer();
              int get_lignes();
              int get_cols();
      
      };
