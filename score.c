#include"score.h"

void scor(score s){
SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Event event;
SDL_Color couleurRouge={255 , 0 , 0};
SDL_Color couleurBlanche = {255, 255, 255};
    TTF_Font *police = NULL;
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[20] = ""; /* Tableau de char suffisamment grand */

//initialisation
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    TTF_Init();
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    police = TTF_OpenFont("police.ttf", 30);   // Chargement de la police 
    /* Initialisation du temps et du texte */
    sprintf(temps, "TEMPS:%d", compteur);
    texte = TTF_RenderText_Shaded(police, temps, couleurRouge, couleurBlanche);


    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 1000) // Si 100ms au moins se sont coules 
        {
            compteur += 1; /* On rajoute 100ms au compteur */
            sprintf(temps, "TEMPS : %d", compteur); /* On écrit dans la chaine "temps" le nouveau temps */
            SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
            texte = TTF_RenderText_Shaded(police, temps, couleurRouge, couleurBlanche); /* On écrit la chaine temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met Ã  jour le tempsPrecedent */
		if(compteur == 0){continuer = 0;}
        }
        s.position.x = 100;
        s.position.y = 0;
        SDL_BlitSurface(texte, NULL, ecran, &s.position); // Blit du texte contenant le temps 
        SDL_Flip(ecran);
	SDL_Delay(150);//de 150 millie seconde pour que le texte reste afficher a l'ecran sinon il sautie
    }
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
}
int main()
{
/*
putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(400,563,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));//pour remplir l'ecran
SDL_Flip(fenetre);

//creation backgroud
SDL_Surface* background;
background=IMG_Load("background.jpg");


SDL_Rect backgroundpos;
backgroundpos.x=0;
backgroundpos.y=0;
SDL_BlitSurface(background,NULL,fenetre,&backgroundpos);*/

score s ;
scor(s);


}
