#include "cellule.h"
#include<iostream>

      cellules::cellules(){
                visited=false;
                tab_mur = new murs[4];
                //Initialisation
                tab_mur[0].set_cote('N');
                tab_mur[0].set_num(1);
                
                tab_mur[1].set_cote('S');
                tab_mur[1].set_num(2);
                
                tab_mur[2].set_cote('O');
                tab_mur[2].set_num(4);
                
                tab_mur[3].set_cote('E');
                tab_mur[3].set_num(8);
      }
      void cellules::visite(){
           visited=true;
      }
      void cellules::sortir(){
           visited=false;
      }
      bool cellules::is_visited(){
           return visited;
      }
      void cellules::detruire_mur(int x){
               tab_mur[x].cacher();
      }
      
      int cellules::get_etat(){
          int somme=0;
          for(int i=0;i<4;i++){
                  if(tab_mur[i].presence())
                  somme+=tab_mur[i].get_num();
          }
          return somme;
      }

