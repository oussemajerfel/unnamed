#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

typedef struct ennemie
{
SDL_Surface *tab[2][2];
SDL_Surface *image[4];
SDL_Rect position;
int direction;
int num_image;
State state;
}ennemie;
