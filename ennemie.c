#include "ennemie.h"
void initialiser_ennemie(ennemie *e,SDL_Rect pos)
{
  //init numero image
    e->num_image=0;
  //init image
    e->tab[0][0]=IMG_Load("ennemie12.png");
    e->tab[0][1]=IMG_Load("ennemie13.png");
    e->tab[1][0]=IMG_Load("ennemie10.png");
    e->tab[1][1]=IMG_Load("ennemie11.png");
  //init position
    e->position=pos;
  //init direction
    e->direction=1;
}*/

void deplacer_ennemie(ennemie *e)
{
  	if(e->position.x>=440)
	{
		e->direction=0 ;
	}
	if(e->position.x<=390)
	{
		e->direction=1 ;
	}
	if(e->direction==0)
	{
		e->position.x-=2 ;
                e->position.y-=2;
	}

	else if(e->direction==1)
	{
		e->position.x+=2;

                e->position.y+=2 ;

	}
}
