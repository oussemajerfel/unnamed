#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"



void initialiser(perso *p)
{
          p->image[0][0]= IMG_Load("persoright.png");
          p->image[0][1]= IMG_Load("persoright2.png");
         
          p->image[1][0]= IMG_Load("persoleft.png");
          p->image[1][1]= IMG_Load("persoleft1.png");
        
         p->pospersonnage.x=0;
         p->pospersonnage.y=300;
         
            p->img_int=p->image[0][0] ;
}

void afficher(SDL_Surface* fenetre,perso p)
{

SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
SDL_Flip(fenetre);

}


void liberer_player(perso* p)
{

SDL_FreeSurface(p->img_int);

}

