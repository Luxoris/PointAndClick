#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include "window.h"
#include "renderer.h"
#include "VUE_SDL2.h"
#include "joueur.h"
#include "etatPartie.h"
#include "evenement.h"
#include "FPS.h"
#include "SDL2_texte.h"
#include "pointeur.h"
#include "image.h"
#include "mixer.h"



int main( int argc, char* args[]/*, char * env[]*/ )
{


    ///DECLARATION ET INITIALISATION DES VARIABLES///
    SDL_Window *pFenetre;
    SDL_Renderer *pRenderer;
    float fFPS=1;    //le nombre de FPS est initialisé à 0.1 pour le premier passage
    Uint32 nTempsDebutBoucle=0;
    Uint32 nTempsFinBoucle=0;
    tEtatPartie stEtatPartie=enCours;


    ///INITIALISATION ET DECLARATION DU POINTEUR DE LA SOURIS///
     tPointeur *pstPointeur=NULL;
     initPointeur(&pstPointeur,creePoint(0,0),false,false,false);

    ///INITIALISATION ET DECLARATION DU TEXTE///
    //initilisation des propriétés du texte:
    tPropTexte stPropTexte, stPropTexteBouton;
    setPropTexte(&stPropTexte,TAILLE_POLICE_SCORE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid);
    setPropTexte(&stPropTexteBouton,TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid);

    ///CREATION, ALLOCATION, INITIALISATION DES BOUTONS///


    ///INITIALISATION DE LA SDL, DE LA FENETRE, DU RENDERER, DU TTF///
    initSDL();
    initFenetre(&pFenetre,NOM_DU_JEU);
    initMoteurRendu(&pFenetre,&pRenderer);
    initSDLImage();
    initTTF();
    initMixer();

    ///DECLARATION ET INITIALISATION DE LA MUSIQUE --- LECTURE///
    Mix_Music *pMusique = Mix_LoadMUS("./assets/son/Never.wav");
    Mix_PlayMusic(pMusique, 1);


    ///BOUCLE DE JEU///
    while(stEtatPartie!=quitter){


        ///DEBUT DE LA BOUCLE DE JEU
        //affectation de la valeur du timer pour connaitre le temps d'exécution d'exécution du programme au début de l'intérration
        nTempsDebutBoucle = SDL_GetTicks();

        ///AFFICHAGE
        //écran en noir
        SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
        SDL_RenderClear(pRenderer);

        gestionEvenements(&stEtatPartie,pstPointeur);

       /* switch(stLevel){
            case level1 :
                break;
            case level2 :
                break;
        }*/






        ///AFFICHAGE

        //RENDU DE L'IMAGE
        SDL_RenderPresent(pRenderer);

        //affectation de la valeur du timer pour connaitre le temps d'exécution d'exécution du programme à la quitter de l'intérration
        nTempsFinBoucle = SDL_GetTicks();
        calculFPS(&fFPS,nTempsDebutBoucle,nTempsFinBoucle);
        priseEnCompteFPSMax(&fFPS,MAX_FPS,nTempsFinBoucle-nTempsDebutBoucle);

    }



    ///LIBERATION DES OBJETS///



    ///ARRET TTF, RENDERER, FENETRE, SDL///
    Mix_FreeMusic(pMusique);
    Mix_CloseAudio();

    IMG_Quit();
    arretTTF();
    arretMoteurRendu(&pRenderer);
    arretFenetre(&pFenetre);
    SDL_Quit();

    return 0;
}

