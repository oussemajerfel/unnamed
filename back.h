
#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

// structure de backgroung
typedef struct back 
{
SDL_Surface *back ;
SDL_Rect backpos ; 
SDL_Rect campos ; 
}back,b ; 

void initback( back* b) ;
void afficher_Map(back b ,SDL_Surface *fenetre) ;
void freeBackground(back* b ) ; 
