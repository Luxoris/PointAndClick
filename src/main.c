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
#include "manager.h"
#include "interface.h"
#include "level.h"



int main( int argc, char* args[]/*, char * env[]*/ )
{

    ///DECLARATION ET INITIALISATION DES VARIABLES///
    SDL_Window *pFenetre;
    SDL_Renderer *pRenderer;
    float fFPS=1;    //le nombre de FPS est initialisé à 0.1 pour le premier passage
    Uint32 nTempsDebutBoucle=0;
    Uint32 nTempsFinBoucle=0;
    tEtatPartie stEtatPartie=0;
    tManaComposant *pManaComposant = NULL;
    tEtatJeu stEtatJeu = {level1,0};

    ///INITIALISATION ET DECLARATION DU POINTEUR DE LA SOURIS///
     tPointeur *pstPointeur=NULL;
     initPointeur(&pstPointeur,creePoint(0,0),false,false,false);

    ///INITIALISATION DE LA SDL, DE LA FENETRE, DU RENDERER, DU TTF///
    initSDL();
    initFenetre(&pFenetre,NOM_DU_JEU);
    initMoteurRendu(&pFenetre,&pRenderer);
    initSDLImage();
    initTTF();
    initMixer();

    ///INITIALISATION DU MANAGER DE COMPOSANTS ET DES COMPOSANTS
    initManaComposantEtComposant(&pManaComposant);

    ///DECLARATION ET INITIALISATION DE LA MUSIQUE --- LECTURE///
    Mix_Music *pMusique = Mix_LoadMUS("./assets/son/Never.wav");
    Mix_PlayMusic(pMusique, 1);


    ///DECLARATION DE LA LISTE DES PROPRIETES DES TEXTES DU JEU
    insertionPropTexteListe(pManaComposant->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");
    insertionPropTexteListe(pManaComposant->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"dialogue");

    ///DECLARATION DE LA LISTE D'OBJET PAR DEFAUT
    insertionObjetListe(pManaComposant->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"centre");


    ///AJOUT DES ELEMENTS DU MENU PRINCIPAL
    ajoutMenuPrincipale(pManaComposant);

    //Test Des Menu
    /*supprMenuPrincipale(pManaComposant);
    ajoutInterfaceJeu(pManaComposant);
    supprInterfaceJeu(pManaComposant);
    ajoutMenuCharger(pManaComposant);
    supprMenuCharger(pManaComposant);
    ajoutMenuOptions(pManaComposant);
    supprMenuOptions(pManaComposant);
    ajoutMenuJeu(pManaComposant);
    supprMenuJeu(pManaComposant);*/


    stEtatPartie = menu;


    ///BOUCLE DE JEU///
    while(stEtatPartie!=quitter){


        ///DEBUT DE LA BOUCLE DE JEU
        //affectation de la valeur du timer pour connaitre le temps d'exécution d'exécution du programme au début de l'intérration
        nTempsDebutBoucle = SDL_GetTicks();

        switch(stEtatPartie){
        case enCours:
            switch(stEtatJeu.stLevel){
                case level1 : //gestionLevel1(pManaComposant,&stEtatJeu);
                    break;
                /*case  level2 :
                    break;
                */
            }
            break;
        case menu:
            break;
        }

        gestionActionListeBouton(pManaComposant,&stEtatPartie);

        ///AFFICHAGE
        //écran en noir
        SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
        SDL_RenderClear(pRenderer);

        gestionEvenements(&stEtatPartie,pstPointeur);
        gestionListeBoutonPointeur(pManaComposant->pListeBouton,pstPointeur);


        //gestionEvenementsListeBoutons(pManaComposant->pListeBouton,&stEtatPartie);


        //
        SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
        affichageListeImage(pRenderer,pManaComposant->pListeImage);
        affichageListeTexte(pRenderer,pManaComposant->pListeTexte);
        //affichageListeObjet(pRenderer,pManaComposant->pListeObjet);
        affichageListeBouton(pRenderer,pManaComposant->pListeBouton);



        ///RENDU

        //RENDU DE L'IMAGE
        SDL_RenderPresent(pRenderer);

        //affectation de la valeur du timer pour connaitre le temps d'exécution d'exécution du programme à la quitter de l'intérration
        nTempsFinBoucle = SDL_GetTicks();
        calculFPS(&fFPS,nTempsDebutBoucle,nTempsFinBoucle);
        priseEnCompteFPSMax(&fFPS,MAX_FPS,nTempsFinBoucle-nTempsDebutBoucle);

    }



    ///LIBERATION DES OBJETS///
    freeManaComposant(pManaComposant);


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

