#include <vector>
#include "generation.h"
#include "labyrinthe.h"
#include <cstdlib>
#include <iostream>
#include<string.h>
#include <SDL/SDL.h>
#include <FMOD/fmod.h>
#include "personnage.h"
#include <ctime>

using namespace std;
    generation::generation(){
           lignes=10;
           cols=20;
    }
    
    int generation::get_lignes(){
           return lignes;
    }
    int generation::get_cols(){
           return cols;
    }
    void generation::generer(){
    
        labyrinthe labyrinthe;
        vector<int> targeti;
        vector<int> targetj;
        vector<int> possibility;
        int d,g,h,b,x,num_mur_contre,num_mur;
        int etat[20][10];
        
        
        int debuti=rand()%lignes;
        int debutj=rand()%cols;
        int xi=debuti;
        int xj=debutj;
        targeti.push_back(xi);
        targetj.push_back(xj);
        
        //cout<<"depart : i = "<<xi<<" j = "<<xj<<endl; 
        /*for(int i=0;i<lignes;i++){
                for (int j=0;j<cols;j++)
                    cout<<c[i][j].get_etat()<<" ";
                cout<<endl;
        }*/
        cout<<endl<<endl;
        int i = 0;
        do{  
                possibility.clear();
                c[xi][xj].visite();
                d=xj+1;
                g=xj-1;
                h=xi-1;
                b=xi+1;
                if(!c[xi][d].is_visited() && d>=0 && d<cols){ possibility.push_back(xi);possibility.push_back(d);}//cout<<"cellule["<<xi<<"]["<<d<<"]"<<" non visitée !!!"<<endl;}
                if(!c[xi][g].is_visited() && g>=0 && g<cols){ possibility.push_back(xi);possibility.push_back(g);}//cout<<"cellule["<<xi<<"]["<<g<<"]"<<" non visitée !!!"<<endl;}
                if(!c[h][xj].is_visited() && h>=0 && h<lignes){ possibility.push_back(h);possibility.push_back(xj);}//cout<<"cellule["<<h<<"]["<<xj<<"]"<<" non visitée !!!"<<endl;}
                if(!c[b][xj].is_visited() && b>=0 && b<lignes){ possibility.push_back(b);possibility.push_back(xj);}//cout<<"cellule["<<b<<"]["<<xj<<"]"<<" non visitée !!!"<<endl;}
                cout<<endl<<endl<<endl;
                
                if(possibility.size()==0){
                       i--;
                       xi=targeti[i];
                       xj=targetj[i];
                       continue;
                }
                i++;
                x=rand()%(possibility.size());
                if (x & 1) {x--;cout<<"x est impaire !!!!!!!!!!!!!!"<<endl;}
                if(possibility[x]==xi){
                     if(possibility[x+1]==d) {num_mur=3;num_mur_contre=2;}
                     else       {num_mur=2;num_mur_contre=3;}
                               
                }
                if (possibility[x+1]==xj){
                     if (possibility[x]==h) {num_mur=0;num_mur_contre=1;}
                     else      {num_mur=1;num_mur_contre=0;}
                }     
                c[xi][xj].detruire_mur(num_mur);
                xi=possibility[x];
                xj=possibility[x+1];
                c[xi][xj].detruire_mur(num_mur_contre);
                //cout<<"cellule suivante  c["<<xi<<"]["<<xj<<"]"<<endl;
                for(int i=0;i<lignes;i++){
                        for(int j=0;j<cols;j++)
                                etat[j][i]=c[i][j].get_etat();
                }
          
                targeti.push_back(xi);
                targetj.push_back(xj);
        }while (i!=0);
        
        
/* Chargement du du video et du son et vérification du chargement */

    if ( SDL_Init ( SDL_INIT_VIDEO ) == -1 )
         exit ( EXIT_FAILURE );
         
    atexit ( SDL_Quit );
     
    SDL_Surface* screen = SDL_SetVideoMode ( 800, 480, 32, SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF );
    
  
   SDL_Surface* cases[15];
    char nomBmp[15] = {0};
    SDL_Rect positionCase;

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
    /*for(int i=0;i<=19;i++){
                          for(int j=0;j<=9;j++)
                          etat[i][j]=rand()%14;
                          }*/
    
    for(int i=0;i<4;i++){
                       tabetat[i]=0;
                       }
    SDL_EnableKeyRepeat ( 10, 10 );
    
    
    
    while ( running ) {
           
           SDL_FillRect ( screen, NULL, SDL_MapRGB ( screen->format, 255, 255, 255 ) );
          SDL_FillRect(lab, NULL, SDL_MapRGB(lab->format, 255, 255, 255));
                  
        
        int x;
        
        for(int i=0;i<cols;i++){
                for (int j=0;j<lignes;j++){
                    x=etat[i][j];
                
         //                x=etat[i][j];
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
          
          //etat[i][j]=x;
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
                                      labyrinthe.menu();
                                      running = 0;
                                      break;
                                      
                      }
                      if((personnage.getx()>=19*40) && (personnage.gety()>=9*40)){
                                      SDL_FreeSurface(lab);
                                      labyrinthe.fin();
                                      running = 0;
                                         
                                       
                      }
                      break;
         
          }
          
          
        
 
          }
          
     
    SDL_FreeSurface(lab);
    
   
        
}

