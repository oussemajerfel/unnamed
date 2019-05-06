#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h" 

typedef struct perso

{
SDL_Surface* image[2][2];
SDL_Surface* img_int;
SDL_Rect pospersonnage;

}perso;


void initialiser(perso *p)  ;
void afficher(SDL_Surface* fenetre,perso p) ; 
void liberer_player(perso* p) ;
