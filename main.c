#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>


typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_texture;
     SDL_Surface *g_surface;


}game;

typedef struct gameState{

    int g_bRunning;


}gameState;

typedef struct font{

    TTF_Font *g_font;

}font;


typedef struct coordonnees{

    double x;
    double y;



}coordonnees;


int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame,font *mFont);
void handleEvents(gameState *state);
void cutBitmapTexture(game *myGame,gameState state);
void writeSDL(game *myGame,font mFont);
int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);
void destroyTexture(game *myGame);
void destroyFont(font *mFont);
void destroy(game *myGame);

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
//int argc est le compteur d'arguments
//char args représente les arguments en question
//cahr env stock les variables d'environnement
int main( int argc, char* args[]/*, char * env[]*/ )
{
    game myGame;
    gameState state;
    font mFont;
    int myBool = 0 ;
    Mix_Music *myMusique;
    if(init("Test SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame,&mFont)){

                state.g_bRunning=1;


    }else{

            return 1;//something's wrong

    }
    myMusique = Mix_LoadMUS("./Assets/son/Never.wav");
    while(state.g_bRunning){
        handleEvents(&state);
        if (myBool == 0){
            writeSDL(&myGame,mFont);
            cutBitmapTexture(&myGame,state);
            Mix_PlayMusic(myMusique, 1);
            myBool = 1;
        }

    }
	//Destroy window
	Mix_FreeChunk(myMusique);
	destroy(&myGame);
	destroyFont(&mFont);

	//Quit SDL subsystems
	TTF_Quit();
	SDL_Quit();


	return 0;
}


int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame, font *mFont){


    //initialize SDL

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //if succeeded create our window
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);
            //if succeeded create window, create our render
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_ACCELERATED);

            }

    }else{


        return 0;
    }

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    mFont->g_font=TTF_OpenFont("./Fonts/verdana.ttf",65);

    if(!mFont->g_font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        SDL_Delay(5000);
        exit(EXIT_FAILURE);
    }

     SDL_Color fontColor={255,0,0};

     myGame->g_surface=TTF_RenderText_Blended(mFont->g_font, "La SDL c'est fun !!!!", fontColor);//Charge la police

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
       printf("%s", Mix_GetError());
    }

    return 1;


}

void handleEvents(gameState *state){


    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_LEFT: ; break;
                                case SDLK_RIGHT: ; break;
                                case SDLK_UP:    ; break;
                                case SDLK_DOWN:  ; break;
                            }
                            break;

        case SDL_KEYUP:;break;

        default:break;

        }
    }


}
void cutBitmapTexture(game *myGame,gameState state){

        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;


        myGame->g_surface = IMG_Load("./Assets/meme.png");//Chargement de l'image png

        if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(myGame->g_surface){


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){

                    rectangleSource.x=0;
                    rectangleSource.y=0;
                    rectangleSource.w=500;//1 image = w:128 et h:82
                    rectangleSource.h=500;

                    SDL_QueryTexture(myGame->g_texture,NULL,NULL,NULL,NULL);

                    //Définition du rectangle dest pour dessiner Bitmap
                    rectangleDest.x=SCREEN_WIDTH/2-rectangleSource.w/2;//debut x
                    rectangleDest.y=150;//debut y
                    rectangleDest.w=rectangleSource.w; //Largeur
                    rectangleDest.h=rectangleSource.h; //Hauteur

                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest);


                    //SDL_FLIP_NONE
                    //SDL_FLIP_HORIZONTAL
                    //SDL_FLIP_VERTICAL



                    SDL_RenderPresent(myGame->g_pRenderer); // Affichage

                    SDL_RenderClear(myGame->g_pRenderer);


                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }


    destroyTexture(myGame);

}

void writeSDL(game *myGame,font mFont) {




        if(myGame->g_surface){


                //Définition du rectangle dest pour blitter la chaine
                SDL_Rect rectangle;
                rectangle.x=SCREEN_WIDTH/2-300;//debut x
                rectangle.y=0;//debut y
                rectangle.w=600; //Largeur
                rectangle.h=150; //Hauteur


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation de la texture pour la chaine
                // Libération de la ressource occupée par le sprite
                if(!myGame->g_surface)
                    SDL_FreeSurface(myGame->g_surface);


                 if(myGame->g_texture){

                        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,NULL,&rectangle); // Copie du sprite grâce au SDL_Renderer
                        SDL_RenderPresent(myGame->g_pRenderer); // Affichage
                        //TODO out of memory sdl texture
                 }
                 else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de creation surface pour chaine (%s)\n",SDL_GetError());
        }

        destroyTexture(myGame);


}
void destroy(game *myGame){

    //Destroy render
    if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);


    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}

void destroyFont(font *mFont){
    if(mFont->g_font!=NULL){
        TTF_CloseFont(mFont->g_font);
        mFont->g_font=NULL;
    }

}

void destroyTexture(game *myGame){

    //Destroy texture
    if(myGame->g_texture!=NULL)
            SDL_DestroyTexture(myGame->g_texture);


}

