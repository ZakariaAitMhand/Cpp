#include "murs.h"
#include <iostream>

using namespace std;
      murs::murs(){
                    present=true;
                    cote=' ';
                    n=0;
      }
      void murs::set_cote(char c){
           cote=c;
           }
      void murs::set_num(int x){
           n=x;
           }
      int murs::get_num(){
           return n;
           }//ce num nous permet de deduire l'etat de la cellule
      bool murs::presence(){
           return present;
           }
      void murs::cacher(){
           present=false;
           }
