#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

#include"perso.c"
//#include".c"
#include"back.c"


int main()
{


int continuer=1;

//initiation
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());


//creation ecran
SDL_Surface *ecran=NULL;
ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
SDL_Flip(ecran);

map m ;


initback(&m) ;
afficher_Map(m,ecran) ;


/*


//initialisation obstacle et affichage
obstacle ob;
obstacle ob1;
obstacle ob2;



initialiser_obstacle(&ob);
initialiser_obstacle1(&ob1);
initialiser_obstacle2(&ob2); */

player p;
 initialiser(&p);
afficher(ecran,p);


//boucle du jeu

while(continuer)
{
SDL_Event event;
SDL_WaitEvent(&event);

if(event.type==SDL_QUIT)
{
continuer=0;
break;
}




else if(event.type==SDL_KEYDOWN){
  if(event.key.keysym.sym==SDLK_RIGHT){
if((p.Sprite.x>=400)&&(m.camera.x<473))
{

m.camera.x+=50;/*
ob.obstacle_pos.x-=10;
ob1.obstacle_pos.x-=10;
ob2.obstacle_pos.x-=10;*/

}
else
{

             p.Sprite.x+=50;

}


 if ( p.scrn.x ==202)
            p.scrn.x =303;
          else
            p.scrn.x=202;

/*
if(collision(map,p.sprite,ob.obstacle_pos.x,0)==1)||(collision(map,p.sprite,ob.obstacle_pos.x,0)==1))||(collision(map,p.sprite,ob.obstacle_pos.x,0)==1))
{

timerMort--;
p.Sprite.x-=150;

}

if(timerMort==0)
{
continuer=0;
}




}
*/
 if(event.key.keysym.sym==SDLK_LEFT){
if(m.camera.x>0)
{

m.camera.x-=50;
/*ob.obstacle_pos.x+=10;
ob1.obstacle_pos.x+=10;
ob2.obstacle_pos.x+=10;*/
}

else
{
          p.Sprite.x -=50;
}



if (p.scrn.x==0)
            p.scrn.x=95.72;
          else
            p.scrn.x =0;
/*


if((collision(p.Sprite,ob.obstacle_pos)==1)||(collision(p.Sprite,ob1.obstacle_pos)==1)||(collision(p.Sprite,ob2.obstacle_pos)==1))
{

timerMort--;
p.Sprite.x+=150;

}

if(timerMort==0)
{
continuer=0;
}

*/

}
 if ( p.Sprite.x < 0 ) {
      p.Sprite.x = 0;
    }
    else if ( p.Sprite.x > 807-95.72) {
     p.Sprite.x =  807-95.72;
    }



}

else if(event.key.keysym.sym==SDLK_UP)
{


p.Sprite.y-=30;






}
else if(event.key.keysym.sym==SDLK_DOWN)
{


p.Sprite.y+=30;






}





afficher_Map(m,ecran);
afficher(ecran,p);
SDL_Flip(ecran); 





SDL_Delay(2000) ;
/*
afficher_obstacle(ecran,ob);
afficher_obstacle(ecran,ob1);
afficher_obstacle(ecran,ob2);

*/
}

afficher_Map(m,ecran);
afficher(ecran,p);
SDL_Flip(ecran); 

SDL_FreeSurface(ecran);
freeBackground(&m);

liberer_player(&p) ;
SDL_Delay(2000) ;
SDL_Quit();
return 0 ;
}
}

