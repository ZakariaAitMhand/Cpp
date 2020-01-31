#include <cstdlib>
#include <iostream>
#include<string.h>
#include <SDL/SDL.h>
#include <FMOD/fmod.h>
#include "personnage.h"
#include "labyrinthe.h"
#include <ctime>
//methode jeu oû en affiche le personnage ainsi que la generation du labyrinthe 
void labyrinthe::jeu(){      
       /* Chargement du du video et du son et vérification du chargement */

    if ( SDL_Init ( SDL_INIT_VIDEO ) == -1 )
         exit ( EXIT_FAILURE );
         
    atexit ( SDL_Quit );
     
    SDL_Surface* screen = SDL_SetVideoMode ( 800, 480, 32, SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF );
    
  
   SDL_Surface* cases[15];
    char nomBmp[15] = {0};
    SDL_Rect positionCase;
    int etat[20][10];
    /*for(int i=0;i<20;i++){
                      for(int j=0;j<10;j++){
                                        etat[i][j]=0;
                                        }
                                        }
                                        */
    if ( !screen )
       exit ( EXIT_FAILURE );
     SDL_WM_SetCaption("Labyrinthe WZ", NULL);
       for (int i=0; i<=15; i++)
    {
        sprintf(nomBmp, "cel%d.bmp", i);
        cases[i] = SDL_LoadBMP(nomBmp);
    }
       
    SDL_Surface* floor = IMG_Load  ( "mur-de-brique.jpg" );
    SDL_Surface* flag = IMG_Load ("flag.png");
    SDL_Surface* lab = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 440, 32, 0, 0, 0, 0);



    SDL_Rect pos;
    SDL_Rect posflag;
             int posx;
             int posy;
             float testposx,testposxmin,testposxmax;
             float testposy,testposymin,testposymax;
             bool testposition;
             int pas=10;
             int tabetat[4];
    posflag.x=780;
    posflag.y=375;
    pos.x = (screen->w - lab->w) / 2;
    pos.y = (screen->h - lab->h) / 2;
    
    Personnage personnage (0, 0, 4, 4, "personnage.png" ); 
      
    SDL_Event event;
    bool running = 1;
    for(int i=0;i<=19;i++){
                          for(int j=0;j<=9;j++)
                          etat[i][j]=rand()%14;
                          }
    
    for(int i=0;i<4;i++){
                       tabetat[i]=0;
                       }
    SDL_EnableKeyRepeat ( 10, 10 );
    
    
    
    while ( running ) {
           
           SDL_FillRect ( screen, NULL, SDL_MapRGB ( screen->format, 255, 255, 255 ) );
          SDL_FillRect(lab, NULL, SDL_MapRGB(lab->format, 255, 255, 255));
                  
        
        int x;
        
        for(int i=0;i<=19;i++){
                  for(int j=0;j<=9;j++){
                         x=etat[i][j];
                          /*x=0;
                          if((i==1)&&(j==1)){
                                            x=3;
                                            }
                          if((i==2)&&(j==1)){
                                            x=11;
                                            }
                          if((i==3)&&(j==1)){
                                            x=7;
                                            }
                           if((i==5)&&(j==1)){
                                            x=7;
                                            }
                            if((i==5)&&(j==0)){
                                            x=7;
                                            }
                          
              */
                    
          positionCase.x=(40*i);
          // stockage dans la variable x de la cellule
          //On va prendre just un exemple pour la cellule 5i 4j---> testposx testposxmin et max
          positionCase.y=(40*j)+20;
          // stockage dans la variable x de la cellule
          //On va prendre just un exemple pour la cellule 5i 4j---> testposy testposymin et max
          
          etat[i][j]=x;
           SDL_BlitSurface ( cases[x],NULL, lab, &positionCase );
          
          }
          }
               
              
        SDL_BlitSurface ( flag ,NULL, lab, &posflag );
          personnage.show ( lab );
          SDL_BlitSurface ( lab, NULL, screen, &pos );
          
          SDL_Flip ( screen );
        
          SDL_Delay (80);
           
          testposition==false; 
           posx=personnage.getx();
          posx/=40;
          //posx++;
          posy=personnage.gety();
          posy/=40;
          
          testposx=(posx*40);// position x de la cellule divisé par 40
          testposxmin=testposx+10;
          testposxmax=testposx+35;
          testposy=(posy*40);//  position y de la cellule divisé par 40
           testposymin=testposy+10;
          testposymax=testposy+35;
          if((personnage.getx()+15>=testposxmin && personnage.getx()+15<=testposxmax ) || (personnage.gety()+20>=testposymin && personnage.gety()+20<=testposxmax)){
               testposition=true;
              
          }
         
          //posy++;
          switch (etat[posx][posy]){
                       case 1 :
                            tabetat[0]=1;
                            break;
                       case 2 :
                            tabetat[1]=1;
                            break;
                        case 3 :
                            tabetat[0]=1;
                            tabetat[1]=1;
                            break;
                        case 4 :
                            tabetat[2]=1;
                            break;
                        case 5 :
                            tabetat[0]=1;
                            tabetat[2]=1;
                            break;
                         case 6 :
                            tabetat[1]=1;
                            tabetat[2]=1;
                            break;
                         case 7 :
                            tabetat[0]=1;
                            tabetat[1]=1;
                            tabetat[2]=1;
                            break;
                         case 8 :
                            tabetat[3]=1;
                            break;
                          case 9 :
                            tabetat[0]=1;
                            tabetat[3]=1;
                            break;
                          case 10 :
                            tabetat[1]=1;
                            tabetat[3]=1;
                            break;
                          case 11 :
                            tabetat[0]=1;
                            tabetat[1]=1;
                            tabetat[3]=1;
                            break;
                          case 12 :
                            tabetat[2]=1;
                            tabetat[3]=1;
                            break;
                          case 13 :
                            tabetat[0]=1;
                            tabetat[2]=1;
                            tabetat[3]=1;
                            break;
                          case 14 :
                            tabetat[1]=1;
                            tabetat[2]=1;
                            tabetat[3]=1;
                            break;  
                          case 15 :
                            tabetat[0]=1;
                            tabetat[1]=1;
                            tabetat[2]=1;
                            tabetat[3]=1;
                            break;  
                         case 0:
                            tabetat[0]=0;
                            tabetat[1]=0;
                            tabetat[2]=0;
                            tabetat[3]=0;
                            break;  
                            default:
                            tabetat[0]=0;
                            tabetat[1]=0;
                            tabetat[2]=0;
                            tabetat[3]=0;
                                    break;
                                    }
          
           
 
                                    
          SDL_WaitEvent ( &event );
         
              switch ( event.type ) {
                     
                     
                     case SDL_QUIT:
                          running = 0;
                          break;
                          
                     case SDL_KEYDOWN:
                          
                          switch ( event.key.keysym.sym ) {
                                 
                                 
                                 case SDLK_LEFT:
                                     personnage.setDirection ( LEFT );
                                     if(tabetat[2]==1 && testposition && personnage.getx()+20>=testposxmin && personnage.getx()+20<=testposxmax){
                                                      //  && personnage.gety()>=testposymin && personnage.gety()<=testposymax
                                     tabetat[2]=0;                 
                                     break;
                                     }
                                     personnage.moveleft ( pas );
                                    // FSOUND_PlaySound(FSOUND_FREE, marche);
                                      break;
                                     
                                      
                                 case SDLK_RIGHT:
                                      personnage.setDirection ( RIGHT );
                                      if( tabetat[3]==1 && testposition && personnage.getx()>=testposxmin && personnage.getx()<=testposxmax){
                                          // && personnage.gety()>=testposymin && personnage.gety()<=testposymax
                                      tabetat[3]=0;
                                      break;
                                      }
                                      personnage.moveright ( pas );
                                      //FSOUND_PlaySound(FSOUND_FREE, marche);
                                      break;
                                      
                                 case SDLK_UP:
                                      personnage.setDirection ( UP );
                                      if(tabetat[0]==1 && testposition  && personnage.gety()+20>=testposymin && personnage.gety()+20<=testposymax)
                                      {
                                                       //&& personnage.getx()>=testposxmin && personnage.getx()<=testposxmax
                                      tabetat[0]=0;
                                      break;
                                      }
                                      personnage.moveup ( pas );
                                     // FSOUND_PlaySound(FSOUND_FREE, marche);
                                      break;
                                 case SDLK_DOWN:
                                      personnage.setDirection ( DOWN );
                                      if(tabetat[1]==1 && testposition  && personnage.gety()>=testposymin && personnage.gety()<=testposymax)
                                      {
                                                       // && personnage.getx()>=testposxmin && personnage.getx()<=testposxmax
                                      tabetat[1]=0;
                                      break;
                                      }
                                      personnage.movedown ( pas );
                                      //FSOUND_PlaySound(FSOUND_FREE, marche);
                                      break;
                                 case SDLK_ESCAPE:
                                      SDL_FreeSurface(lab);
                                      menu();
                                      running = 0;
                                      break;
                                      
                      }
                      if((personnage.getx()>=19*40) && (personnage.gety()>=9*40)){
                                      SDL_FreeSurface(lab);
                                      fin();
                                      running = 0;
                                         
                                       
                      }
                      break;
         
          }
          
          
        
 
          }
          
     
    SDL_FreeSurface(lab);
    
   

}
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
                                    jeu();
                                  break;
                              case SDLK_2:
                                running = 0;
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
menu();
SDL_FreeSurface(floor1);
}

