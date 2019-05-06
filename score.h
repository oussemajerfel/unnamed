#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
 
typedef struct score
{
SDL_Rect position;

}score;

#ifndef SCORE_H
#define SCORE_H

/*#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES//evité les inculsions infinies*/


//jeu
void scor(score s);

#endif
