int menu();
int menu(){      
    SDL_Surface* floor = IMG_Load  ( "mur-de-brique.jpg" );
    SDL_EnableKeyRepeat ( 10, 10 );
    SDL_FillRect ( screen, NULL, SDL_MapRGB ( screen->format, 255, 255, 255 ) );
           SDL_BlitSurface ( floor, NULL, screen, NULL );
    running=1;
    while ( running ) {
          
          SDL_WaitEvent ( &event );
          
          switch ( event.type ) {
                 
                 case SDL_QUIT:
                      running = 0;
                      break;
                      
                 case SDL_KEYDOWN:
                      switch ( event.key.keysym.sym ) {
                             
                             case SDLK_LEFT:
                                 running=0;
                                  break;
                                   default:
                                     break;
                      }
                      
                      break;
                     
                 default:
                      break;
          }
          
           }
           SDL_Flip ( screen );
          
          SDL_Delay (80);
          
    }

    SDL_FreeSurface(floor);
   
    return EXIT_SUCCESS;
}
