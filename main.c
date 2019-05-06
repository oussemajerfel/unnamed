#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

#include"jouer.h"

int main ()
{
ennemie e;
Sprite S;
int numkeys;
    Uint8 * keys;
    Uint32 timer,elapsed;
   inter ii;
perso p; 
//initialisation
int x=0;
SDL_Surface *fenetre=NULL ;
SDL_Surface *screen=NULL ;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 


 if (SDL_Init(SDL_INIT_VIDEO))
  fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

fenetre=SDL_SetVideoMode(704,430,32,SDL_HWSURFACE);
SDL_Flip(fenetre);


back b;
score s ; 
int si=0,u;
heal h,h1,h2;
//init coeur
initialiser_coeur(&h);
initialiser_coeur1(&h1);
initialiser_coeur2(&h2);

//initialisation score
initscore(&s);
initback(&b) ;


init_inter(&ii);


//SDL_BlitSurface(p.img,NULL,fenetre,&b.backpos);       
affichage_map(b,fenetre) ; 


initperso(&p) ; 
afficher_pers(fenetre,p) ;

  
SDL_Flip(fenetre);
int continuer=1 ;
int i=0;
obstacle ob ; 
obstacl ob1,ob2,ob3,ob4,ob5,ob6 ; 

initialiser_obstacle(&ob);
initialiser_obstacl1(&ob1);
initialiser_obstacl2(&ob2);
initialiser_obstacl3(&ob3);
initialiser_obstacl4(&ob4);
initialiser_obstacl5(&ob5);
initialiser_obstacl6(&ob6);


int m=0 ,n=0 ;
 
SDL_Surface *lv[2] ; 
SDL_Rect poslv ; 

lv[0]=IMG_Load("01.png") ;  
poslv.x=0 ;
poslv.y=0 ;
lv[1]=IMG_Load("02.png") ;  
poslv.x=0 ;
poslv.y=0 ;

int y=0;

float impulsion = 6.0f;

init (&e) ;

while(continuer)
	{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type)
	{
    		case SDL_QUIT:
        	continuer = 0;
        	break;

 		case SDL_KEYDOWN:
        	switch(event.key.keysym.sym)
        	{	/*case SDLK_ESCAPE:
             	   	continuer=0;
             	    	break;*/


 		    	case SDLK_RIGHT:
       
       			if((p.pospersonnage.x>=300)&&(b.campos.x<7000))
         		{

            		b.campos.x+=10;
             		ob.posob.x-=10;
              		ob1.posob.x-=10;
           		ob2.posob.x-=10; 
			ob3.posob.x-=10; 
           		ob4.posob.x-=10; 
           		ob5.posob.x-=10;
           		ob6.posob.x-=10;
           		h.posheal.x-=10 ; 
           		h1.posheal.x-=10 ; 
           		h2.posheal.x-=10 ; 

          		}
			else{p.pospersonnage.x+=100;}
			printf("n :%d",n) ; 
if ( b.campos.x>1830)
{
n=1 ; 


}
if ( b.campos.x>=2540)

{
n=0 ; 

}
if(b.campos.x>4360)
{
n=2 ; 
}
if ( b.campos.x>=5070)

{
n=0 ; 

}
if (ob.posob.x==p.pospersonnage.x)
 {

m=1 ; 
s.imgi=s.score[1];

  if (p.pospersonnage.y>=280)
 {
m=2;
i++;
s.imgi=s.score[0];
} 
}

if((h.posheal.x==p.pospersonnage.x)&&(p.pospersonnage.y>=280)&&(i!=0))
{
 i--; 
 y=1 ; 
}
if((h1.posheal.x==p.pospersonnage.x)&&(p.pospersonnage.y>=280)&&(i!=0))
{
 i--; 
 y=2 ; 
}
if((h2.posheal.x==p.pospersonnage.x)&&(p.pospersonnage.y>=280)&&(i!=0))
{
 i--; 
 y=3 ; 
}

printf("%d \n",p.pospersonnage.x) ;
printf("%d pos q\n",b.campos.x) ;

// collison avec le 1 er obstacle
if (ob1.posob.x==p.pospersonnage.x)
 {

m=3; 

s.imgi=s.score[2];
  if (p.pospersonnage.y>=280)
 {
m=4;
i++;
s.imgi=s.score[1];
} 
}
// collison avec le 2 eme obstacle 
if (ob2.posob.x==p.pospersonnage.x)
 {

s.imgi=s.score[3];
m=5; 
  if (p.pospersonnage.y>=280)
 {
m=6;
i++;
s.imgi=s.score[2];

} 
}
// collison avec le 3 eme obstacle 
if (ob3.posob.x==p.pospersonnage.x)
 {

m=7; 

s.imgi=s.score[4];
  if (p.pospersonnage.y>=280)
 {
m=8;
i++;
s.imgi=s.score[3];
} 
}
// collison avec le 4 eme obstacle 
if (ob4.posob.x==p.pospersonnage.x)
 {

m=9; 

s.imgi=s.score[5];
  if (p.pospersonnage.y>=280)
 {
m=10;
i++;
s.imgi=s.score[4];
} 
}
// collison avec le 5 eme obstacle 
if (ob5.posob.x==p.pospersonnage.x)
 {

m=11; 

s.imgi=s.score[5];
  if (p.pospersonnage.y>=280)
 {
m=12;
i++;
s.imgi=s.score[6];
} 
}
// collison avec le 6 eme obstacle 
if (ob6.posob.x==p.pospersonnage.x)
 {

m=13; 

s.imgi=s.score[5];
  if (p.pospersonnage.y>=280)
 {
m=14;
i++;
s.imgi=s.score[6];
} 
}
  if(x==0)
 {
x=1 ; 

}
else 
{
x=0 ;
}
p.img_int=p.image[0][x] ;
    
		break;

 		case SDLK_LEFT:
		if(b.campos.x>0)
		{
             		b.campos.x-=10;
             		ob.posob.x+=10;
             		ob1.posob.x+=10;
              		ob2.posob.x+=10;
			ob3.posob.x+=10; 
              		ob4.posob.x+=10; 
              		ob5.posob.x+=10; 
              		ob6.posob.x+=10; 
             		h.posheal.x+=10 ;
			h1.posheal.x+=10 ; 
			h2.posheal.x+=10 ; 
		}

		else	{ p.pospersonnage.x--;}
		if(x==0){x=1 ; }
		else {x=0 ;}
		p.img_int=p.image[1][x] ;

		break ;

		case SDLK_UP:
 		b.campos.y-=1;
		p.pospersonnage.y-=10;
		p.img_int=p.image[0][0] ;
		break ; 

		case SDLK_DOWN:
		b.campos.y+=1;  
		p.pospersonnage.y+=10;

		p.img_int=p.image[0][0] ;
		break ; 
		case SDLK_SPACE:
    		timer = SDL_GetTicks();
        	SDL_FillRect(fenetre,NULL,0);
        	SDL_PumpEvents();
        	keys = SDL_GetKeyState(&numkeys);
        	Evolue(&p,keys);
		afficher_pers(fenetre,p) ;
        	//SDL_Flip(fenetre);
        	elapsed = SDL_GetTicks() - timer;
        	if (elapsed<20)
            	  	SDL_Delay(20-elapsed);
		/*p.pospersonnage.y-=20;
		p.pospersonnage.x+=10;
		p.pospersonnage.x-=10;		
		p.pospersonnage.y+=20;*/
		
		//p.pospersonnage.y+=10;
		break ;
		}
if ( p.pospersonnage.x < 0 ) {
      p.pospersonnage.x= 0;
    }
    else if ( p.pospersonnage.x > 704-95.72) {
     p.pospersonnage.x = 704-95.72;
    } 


SDL_BlitSurface(b.back,&b.campos,fenetre,NULL) ;
SDL_Delay(50);
if (m==0)
{
 SDL_BlitSurface(ob.ob,NULL,fenetre,&ob.posob);

}
if( (m==1)||(m==2))
{
 SDL_BlitSurface(ob1.obi,NULL,fenetre,&ob1.posob);

}
if( (m==1)||(m==2)||(m==3)||(m==4))
{
 SDL_BlitSurface(ob2.obi,NULL,fenetre,&ob2.posob);

}
if((m==5)||(m==6))
{
 SDL_BlitSurface(ob3.obi,NULL,fenetre,&ob3.posob);
 

}
if((m==7)||(m==8))
{
 SDL_BlitSurface(ob4.obi,NULL,fenetre,&ob4.posob);

}
if((m==9)||(m==10))
{
 SDL_BlitSurface(ob5.obi,NULL,fenetre,&ob5.posob);

}
if((m==11)||(m==12))
{
 SDL_BlitSurface(ob6.obi,NULL,fenetre,&ob6.posob);

}
if((m==2)||(m==4)||(m==6)||(m==7)||(m==8)||(m==10)||(m==12)||(m==14))
{

p.img=p.vie[i] ; 
}

printf("%d \n", m)  ; 

SDL_BlitSurface(p.img,NULL,fenetre,&b.backpos);

SDL_BlitSurface(s.imgi,NULL,fenetre,&s.position);


//display de coeur
if((y==0)&&(b.campos.x<=750))
{
SDL_BlitSurface(h.heal,NULL,fenetre,&h.posheal);
}
if((y!=2)&&(b.campos.x<=3700))
{
SDL_BlitSurface(h1.heal,NULL,fenetre,&h1.posheal);
}

if((y!=3)&&(b.campos.x<=6100))
{
SDL_BlitSurface(h2.heal,NULL,fenetre,&h2.posheal);
}
printf("Y %d: \n",y) ;
if(i!=3) 
{
SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
}



deplacement (&e,  p) ;
if(b.campos.x<4000)
{
display_ennemi(&e, fenetre);
}
if(n==1)
{
SDL_BlitSurface(lv[0],NULL,fenetre,&poslv);
SDL_Delay(300);
b.campos.x=2530; 

}
  if(n==2)
{
SDL_BlitSurface(lv[1],NULL,fenetre,&poslv);
SDL_Delay(300);
b.campos.x=5060; 

}
        

SDL_Flip(fenetre);
SDL_Delay(50);
}

}
int j ; 
SDL_FreeSurface(fenetre) ; 
//liberer_player(&p) ;

for (i=0;i<=1;i++) 
{
for (j=0;j<=1;j++) 
{
SDL_FreeSurface(p.image[i][j]) ; 
}
}
SDL_FreeSurface(b.back) ; 
SDL_Quit;
return 0 ; 

}
