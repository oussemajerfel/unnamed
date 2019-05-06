#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"back.h" 

void initback( back* b)
{
//creation background
b.back=IMG_Load("map.jpg") ; 
b.backpos->x=0;
b.backpos->y=0; 
b.campos->x=0;
b.campos->y=0;
b.campos->w=704 ;
b.campos->h=430;
}

void afficher_Map(back b ,SDL_Surface *fenetre)
{

   SDL_BlitSurface(b.back,NULL,fenetre,&b.backpos);

SDL_Flip(fenetre);

}

void freeBackground(back* b )
{
	SDL_FreeSurface(b->back);
}


