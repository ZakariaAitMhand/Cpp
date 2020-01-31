#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H
#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

enum DIRECTION { DOWN, LEFT, RIGHT , UP  };

class Personnage {
      
      int _w;
      int _h;
      int _x;
      int _y;
      int _nbrFramesW;
      int _nbrFramesH;
      int _actualFrame;
      
      DIRECTION _direction;
      
      SDL_Surface* _spriteSheet;
      
      public:
             Personnage ( int, int, int, int, char* ); //position initiale du personnage
             Personnage ( int, int);
             ~Personnage ();
             int getx();
             int gety();
             void loadSpriteSheet ( char* );
             void setDirection ( DIRECTION );
             void moveright ( int );
             void moveleft ( int );
             void moveup ( int );
             void movedown ( int ); //avancer
           
             void show ( SDL_Surface*);
                  };
      
#endif
