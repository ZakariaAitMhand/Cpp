#include "personnage.h"

Personnage::Personnage ( int initialX, int initialY, int nbrFramesW, int nbrFramesH, char* file ) {
    
    loadSpriteSheet ( file );
    _nbrFramesW = nbrFramesW;
    _nbrFramesH = nbrFramesH;
    _x = initialX;
    _y = initialY;
    _w = _spriteSheet->w / _nbrFramesW;
    _h = _spriteSheet->h / _nbrFramesH;
    _direction = RIGHT;
    _actualFrame = 0;
}

Personnage::Personnage ( int initialX, int initialY) {
    _x = initialX;
    _y = initialY;
}


Personnage::~Personnage () {
       
    if ( _spriteSheet )
       delete _spriteSheet;
       
       _spriteSheet = NULL;
}
int Personnage::getx(){
    return _x;
}

int Personnage::gety(){
    return _y;
}

void Personnage::loadSpriteSheet ( char* file ) {
     
     _spriteSheet = IMG_Load  ( file );
}

void Personnage::setDirection ( DIRECTION direction ) {
     
     _direction = direction;
}
void Personnage::moveright(int step){
      if ( _x > _SCREEN_WIDTH - _w ){
        _x = _SCREEN_WIDTH - _w;
        
        }
        else{
      _x += step;
       _actualFrame++;
     if ( _actualFrame > _nbrFramesW - 1 )
        _actualFrame = 0;
        }
     }
void Personnage::moveleft(int step){
      if ( _x < 0 )
     _x = 0 ;
     else{
        _x -= step;
    _actualFrame++;
     if ( _actualFrame > _nbrFramesW - 1 )
        _actualFrame = 0;
        }
     }
void Personnage::moveup(int step){
      if ( _y < 0 )
          _y = 0;
          else{
           _y -= step;
           _actualFrame++;
     if ( _actualFrame > _nbrFramesW - 1 )
        _actualFrame = 0;
        }     
     } 
 void Personnage::movedown(int step){
      if ( _y > _SCREEN_HEIGHT - _h-68 ){
          _y = _SCREEN_HEIGHT - _h-68 ;
          
           }
          else{
            _y += step;  
             _actualFrame++;
     if ( _actualFrame > _nbrFramesW - 1 )
        _actualFrame = 0;
        }
     }
     


void Personnage::show ( SDL_Surface* s) {
     
     SDL_Rect frameRect;
     
     frameRect.w = _w;
     frameRect.h = _h;
     frameRect.x = _actualFrame * _w;
     frameRect.y = _direction * _h;
  
     SDL_Rect pos;
  
     pos.x = _x;
     pos.y = _y;
     SDL_BlitSurface ( _spriteSheet, &frameRect, s, &pos );
    
}

