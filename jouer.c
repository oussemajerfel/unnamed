#include"jouer.h"

// les fonctions de l'initialisation
#define LARGEUR_SPRITE 32    
#define HAUTEUR_SPRITE 32
void init_inter( inter* i)
{
	i->rectangle = NULL;
	i->radar=IMG_Load("pos.png");
    	i->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 300, 32, 0, 255, 255, 0);
    
    	i->posradar.x=0;
    	i->posradar.y=580;
    	i->posradar.h=5;
    	i->posradar.w=5;


    	i->position.x = 0; 
    	i->position.y = 520;

}
void affichage_inter( inter i,SDL_Surface* screen)
{
SDL_Event event;
int continuer=1;

while(continuer)
{
int x=100;
SDL_Delay(x);
	if (i.posradar.x<220||i.posradar.y<720)
 	{
	SDL_PollEvent(&event);
	switch(event.type)
	{
    		case SDL_QUIT:
        	continuer = 0;
        	break;
    		case SDL_KEYDOWN:
        		switch(event.key.keysym.sym)
        		{
            		case SDLK_UP:    
                		i.posradar.y=i.posradar.y-1;
                		x = 50;
                		break; 
            		case SDLK_DOWN:
                
                		i.posradar.y=i.posradar.y+1;
                 		x = 50;
                		break;
            		case SDLK_RIGHT:
                		x = 50;
                 		i.posradar.x=i.posradar.x+1;             
                	break;
            		case SDLK_LEFT:
                		i.posradar.x=i.posradar.x-1;
                		x = 50;
                    
                       
                		break;

        		break;
			}
	}


  
    SDL_BlitSurface(i.rectangle, NULL, screen, &i.position); 
    SDL_BlitSurface(i.radar,NULL,screen,&i.posradar);
    }

   else
{
   i.posradar.x=0;
   i.posradar.y=580;
}
   }
}
void liberation_inter(inter* i,SDL_Surface* screen )
{
	  SDL_FreeSurface(i->radar);
  	  SDL_FreeSurface(screen);
  	  SDL_FreeSurface(i->rectangle); 
}

void initback( back* b)
{
//creation background
	b->back=IMG_Load("map.jpg") ; 
	b->backpos.x=0;
	b->backpos.y=0; 
	b->campos.x=0;
	b->campos.y=0;
	b->campos.w=704 ;
	b->campos.h=430;
}

void initscore( score* s)
{
s->score[0]=IMG_Load("8.png") ; 
s->score[1]=IMG_Load("1.png") ; 
s->score[2]=IMG_Load("2.png") ; 
s->score[3]=IMG_Load("3.png") ; 
s->score[4]=IMG_Load("4.png") ; 
s->score[5]=IMG_Load("5.png") ; 
s->score[6]=IMG_Load("6.png") ; 
s->position.x= 0; 
s->position.y= 0; 
s->imgi=s->score[0] ;

}

void initperso( perso* p)
{
	 p->image[0][0]= IMG_Load("persoright.png");
         p->image[0][1]= IMG_Load("persoright2.png");
         
         p->image[1][0]= IMG_Load("persoleft.png");
         p->image[1][1]= IMG_Load("persoleft1.png");
        
         p->pospersonnage.x=0;
         p->pospersonnage.y=300;
         
         p->img_int=p->image[0][0] ;

	 p->vie[0]=IMG_Load("vie0.png") ; 
	 p->vie[1]=IMG_Load("vie1.png") ; 
	 p->vie[2]=IMG_Load("vie2.png") ; 
	 p->vie[3]=IMG_Load("GameOver.png") ; 
	 p->img=p->vie[0] ;
	 p->s = STAT_SOL;
    	 p->vx = p->vy = 0.0f;
}

void initialiser_obstacle(obstacle* ob)
{   
	ob->ob=IMG_Load("rock.png");
	ob->posob.x=400;
	ob->posob.y=300; 

}

void initialiser_obstacl1(obstacl* ob1)
{   
	ob1->obi=IMG_Load("rocki.png");
	ob1->posob.x=900;
	ob1->posob.y=300; 
}

void initialiser_obstacl2(obstacl*ob2)
{   

	ob2->obi=IMG_Load("car.png");
	ob2->posob.x=1500;
	ob2->posob.y=300; 
}

void initialiser_obstacl3(obstacl*ob3)
{   

	ob3->obi=IMG_Load("rock.png");
	ob3->posob.x=2700;
	ob3->posob.y=300;  
}

void initialiser_obstacl4(obstacl*ob4)
{   

	ob4->obi=IMG_Load("rock.png");
	ob4->posob.x=3500;
	ob4->posob.y=300; 
  
}

void initialiser_obstacl5(obstacl*ob5)
{   

	ob5->obi=IMG_Load("rock.png");
	ob5->posob.x=5000;
	ob5->posob.y=300;
  
}

void initialiser_obstacl6(obstacl*ob6)
{   

	ob6->obi=IMG_Load("rock.png");
	ob6->posob.x=5500;
	ob6->posob.y=300; 
  
}

void affichage_map( back back,SDL_Surface* fenetre)
{
	SDL_BlitSurface(back.back,NULL,fenetre,&(back.backpos));
}

void afficher_pers(SDL_Surface* fenetre,perso p) 
{
	SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
}

//***********intialisation de coeur*********************
void initialiser_coeur(heal* h)
{
h->heal=IMG_Load("coeur.png");
h->posheal.x=750; 
h->posheal.y=350; 

}
void initialiser_coeur1(heal* h1)
{

h1->heal=IMG_Load("coeur.png");
h1->posheal.x=3000; 
h1->posheal.y=350; 
 
}

void initialiser_coeur2(heal* h2)
{

h2->heal=IMG_Load("coeur.png");
h2->posheal.x=4800; 
h2->posheal.y=350;
 
}


void Saute(perso* p,float impulsion)
{
    p->vy = -impulsion;
    p->s = STAT_AIR;
}

void ControleSol(perso* p)
{
    if (p->pospersonnage.y>250.0f)
    {
        p->pospersonnage.y = 250.0f;
        if (p->vy>0)
            p->vy = 0.0f;
        p->s = STAT_SOL;
    }
}

void Gravite(perso* p,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (p->s == STAT_AIR && keys[SDLK_SPACE])
        factgravite/=factsautmaintenu;
    p->vy += factgravite;
}
void Evolue(perso* p,Uint8* keys)
{
    float lateralspeed = 0.5f;
    float airlateralspeedfacteur = 0.5f;
    float maxhspeed = 3.0f;
    float adherance = 1.5f;
    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
// controle lateral
    if (p->s == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (keys[SDLK_LEFT]) // (*1)
        p->vx-=lateralspeed;
    if (keys[SDLK_RIGHT])
        p->vx+=lateralspeed;
    if (p->s == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
        p->vx/=adherance;
// limite vitesse
    if (p->vx>maxhspeed) // (*4)
        p->vx = maxhspeed;
    if (p->vx<-maxhspeed)
        p->vx = -maxhspeed;
// saut
    if (keys[SDLK_SPACE] && p->s == STAT_SOL)
        Saute(p,impulsion);
    Gravite(p,factgravite,factsautmaintenu,keys);
    ControleSol(p);
// application du vecteur à la position.
    p->pospersonnage.x +=p->vx;
    p->pospersonnage.y +=p->vy;
}

//initialisation ennemie  
void init (ennemie *e)
{
e->imag[0][0]=IMG_Load("right.png");
e->imag[0][1]=IMG_Load("right2.png");
e->imag[1][0]=IMG_Load("left1.png");
e->imag[1][1]=IMG_Load("left2.png");
e->posen.x=6500 ;
e->posen.y=250;
e->direction=0; 
e->frame=0 ; 
e->img_in=e->imag[0][0];
}
//***********************************

void deplacement (ennemie *e, perso p)
{

if (e->posen.x>p.pospersonnage.x)
{
e->direction=1 ;
 
 if(e->frame==0) 
   {
 e->frame=1 ; 
  } 
  else
   {
 e->frame=0 ;  
}
 e->img_in=e->imag[e->direction][e->frame] ; 
 e->posen.x-=20; 
} else if (e->posen.x<p.pospersonnage.x)

{
  e->direction=0 ; 
   if(e->frame==0) 
   {
 e->frame=1 ; 
  } 
  else
   {
 e->frame=0 ;  
}

 e->img_in=e->imag[e->direction][e->frame] ; 
 e->posen.x-=2; 

}

else 
{
 e->posen.x-=250; 
}
}
  // afiichage ennemie 
void display_ennemi(ennemie *e, SDL_Surface* fenetre)
 {
	SDL_BlitSurface(e->img_in,NULL,fenetre,&e->posen);
 }  









