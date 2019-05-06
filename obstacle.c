#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

//structure d'obstacle
typedef struct obstacle 
{
SDL_Surface *ob ; 
SDL_Rect posob ; 
} obstacle  ; 


void initialiser_obstacle (obstacle *obstacle)
{   obstacle->image = IMG_Load("obstacle.png");
	obstacle->pos.x =200;
	obstacle->pos.y =250;


}
void initialiser_obstacle1 (obstacle *obstacle)
{   obstacle->image = IMG_Load("obstacle.png");
	obstacle->pos.x =500;
	obstacle->pos.y =250;


}

void initialiser_obstacle2 (obstacle *obstacle)
{   obstacle->image = IMG_Load("obstacle.png");
	obstacle->pos.x =750;
	obstacle->pos.y =250;


}







void afficher_obstacle(SDL_Surface ecran,obstacle obstacle)
{
	SDL_BlitSurface(obstacle.image,NULL,&ecran,&obstacle.pos);
    
}


