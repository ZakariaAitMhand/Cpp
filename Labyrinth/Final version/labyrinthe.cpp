#include <cstdlib>
#include <iostream>
#include<string.h>
#include <SDL/SDL.h>
#include <FMOD/fmod.h>
#include "personnage.h"
#include "labyrinthe.h"
#include "generation.h"
#include <ctime>
//methode jeu oû en affiche le personnage ainsi que la generation du labyrinthe 
/*void labyrinthe::jeu(){      
       

}
*/
//methode menu qui permet d'afficger le menu du jeu
void labyrinthe::menu(){      
   
    SDL_Event event;
    FSOUND_SAMPLE *music = NULL;
    FSOUND_Init(44100, 32, 0);

    /* Chargement du du video et du son et vérification du chargement */
    
    music = FSOUND_Sample_Load(FSOUND_FREE, "One_Last_Breath.mp3", 0, 0, 0);
    if (music == NULL)
    {
        fprintf(stderr, "Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }
    if ( SDL_Init ( SDL_INIT_VIDEO ) == -1 )
         exit ( EXIT_FAILURE );
         
    atexit ( SDL_Quit );
    
    SDL_Surface* screen = SDL_SetVideoMode ( 800, 480, 32, SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF );
    if ( !screen )
       exit ( EXIT_FAILURE );
    SDL_WM_SetCaption("Labyrinthe WZ", NULL);  
    SDL_Surface* floor = IMG_Load  ( "menu.jpg" );
     SDL_Rect posfloor;
    generation g;
  
    FSOUND_PlaySound(FSOUND_FREE, music);
    int running=1;
    while ( running) {
          
          
          SDL_PollEvent(&event);
          switch ( event.type ) {
                 
                 case SDL_QUIT:
                      running = 0;
                      break;
                      
                 case SDL_KEYDOWN:
                      switch ( event.key.keysym.sym ) {
                             
                             case SDLK_1:
                                  
                                  running = 0;
                                  FSOUND_StopSound(1);
                                   FSOUND_Close();
                                   SDL_FreeSurface(floor);
                                    g.generer();
                                  break;
                              case SDLK_2:
                                running = 0;
                                FSOUND_Close();
                                SDL_FreeSurface(floor);
                                  break;
                              
                                   default:
                                     break;
                      }
                      
                      break;
                     
                 default:
                      break;
          }
          posfloor.x = (screen->w)-(screen->w);
    posfloor.y = (screen->h)-(screen->h-28);
    SDL_FillRect ( screen, NULL, SDL_MapRGB ( screen->format, 255, 255, 255 ) );
          
          SDL_BlitSurface ( floor, NULL, screen, &posfloor ); //afficher l'image menu.jpg
          
          SDL_Flip ( screen );// rafraichir l'ecran
           
           SDL_Delay (80);
           }
          FSOUND_Close();// fermer le sons
          SDL_FreeSurface(floor);//fermer la surface floor
          }
    

//methode fin qui permet d'afficher une fenetre de fin du jeu lorsque le personnage atteint la sortie du labyrinthe
void labyrinthe::fin(){
       FSOUND_SAMPLE *music = NULL;
    FSOUND_Init(44100, 32, 0);

    /* Chargement du du video et du son et vérification du chargement */
    
    music = FSOUND_Sample_Load(FSOUND_FREE, "appl.wav", 0, 0, 0);
    if (music == NULL)
    {
        fprintf(stderr, "Impossible de lire le fichier\n");
        exit(EXIT_FAILURE);
    }
      SDL_Event event;
     if ( SDL_Init ( SDL_INIT_VIDEO ) == -1 )
         exit ( EXIT_FAILURE );
         
    atexit ( SDL_Quit );
    
    SDL_Surface* screen = SDL_SetVideoMode ( 800, 480, 32, SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF );
    if ( !screen )
       exit ( EXIT_FAILURE );
    SDL_WM_SetCaption("Labyrinthe WZ", NULL);  
    SDL_Surface* floor1;
    
   
    SDL_Rect posfloor1;
    SDL_Rect posfloor2;
    FSOUND_PlaySound(FSOUND_FREE, music);
     int continuer=1;
     int j = 0;
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
posfloor1.x = (screen->w)-(screen->w);
    posfloor1.y = (screen->h)-(screen->h-28);
    SDL_FillRect ( screen, NULL, SDL_MapRGB ( screen->format, 255, 255, 255 ) );
      int tempsPrecedent = 0,  tempsActuel = 0;
      j=j+1;
for(int i=0;i<10;i++){
if (i<=5)
{
          floor1 = IMG_Load  ( "fin1.jpg" );
}
if (i>5)
{
    floor1 = IMG_Load  ( "fin2.jpg" );
}   
    
    SDL_BlitSurface ( floor1, NULL, screen, &posfloor1 ); 
     SDL_Flip ( screen );   
     if(j==5){
                  continuer=0;
                  
                 break;
                 } 
      
 }   

      
   
        
        //   SDL_Delay (80);

}
FSOUND_StopSound(1);
FSOUND_Close();

SDL_FreeSurface(floor1);
menu();
}

