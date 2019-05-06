#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct back 
{
SDL_Surface *back ;


SDL_Rect backpos ; 
SDL_Rect campos ; 

}back ; 


typedef struct perso

{
SDL_Surface* image[2][2];
SDL_Surface* img_int;
SDL_Rect pospersonnage;
SDL_Surface *vie[4];
SDL_Surface *img;
float vx,vy;
int s;
}perso;


typedef struct obstacle 
{
SDL_Surface *ob ; 
SDL_Rect posob ; 
} obstacle  ; 


typedef struct obstacl 
{
SDL_Surface *obi ; 
SDL_Rect posob ; 
} obstacl ; 


typedef struct score
{
SDL_Surface *score[6] ; 
SDL_Surface *imgi ; 
SDL_Rect position;

}score;

typedef struct temps
{
SDL_Rect position;

}temps;

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
	SDL_Rect dimensions;
} Sprite;

typedef struct ennemie 
{
SDL_Surface* imag[2][2]; 
SDL_Rect posen ; 
SDL_Surface* img_in; 
int direction ; 
int frame; 
}ennemie ; 

typedef struct heal 
{
SDL_Surface *heal ; 
SDL_Rect posheal ; 
} heal  ; 

typedef struct inter
{
 SDL_Surface* radar;
 SDL_Rect posradar;
 SDL_Surface* rectangle;
 SDL_Rect position;
}inter;

void initback( back* b);
void initscore( score* s);
//void initscore( vie* v);
void initperso( perso* p);
void initialiser_obstacle(obstacle* ob);
void initialiser_obstacl1(obstacl* ob1);
void initialiser_obstacl2(obstacl* ob2);
void initialiser_obstacl3(obstacl*ob3);
void initialiser_obstacl4(obstacl*ob4);
void initialiser_obstacl5(obstacl*ob5);
void initialiser_obstacl6(obstacl*ob6);
void affichage_map( back back,SDL_Surface* fenetre);
void afficher_pers(SDL_Surface* fenetre,perso p) ;
//************************************

void Saute(perso* p,float impulsion);
void ControleSol(perso* p);
void Gravite(perso* p,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(perso* p,Uint8* keys);

//**********************************************************
//initialisation ennemie  
void init (ennemie *e);
void deplacement (ennemie *e, perso p);
void display_ennemi(ennemie *e, SDL_Surface* fenetre);



//******************************************************
void initialiser_coeur(heal* h);
void initialiser_coeur1(heal* h1);
void initialiser_coeur2(heal* h2);
//************************************
//interface : mini_map
void init_inter( inter* i);
void affichage_inter( inter i,SDL_Surface* screen);
void liberation_inter(inter* i,SDL_Surface* screen );






