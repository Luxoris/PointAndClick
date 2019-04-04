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



int main( int argc, char* args[]/*, char * env[]*/ )
{

    ///DECLARATION ET INITIALISATION DES VARIABLES///
    SDL_Window *pFenetre;
    SDL_Renderer *pRenderer;
    float fFPS=1;    //le nombre de FPS est initialisé à 0.1 pour le premier passage
    Uint32 nTempsDebutBoucle=0;
    Uint32 nTempsFinBoucle=0;
    tEtatPartie stEtatPartie=enCours;
    tManaComposant *pManaComposant = NULL;

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
    initManaComposant(&pManaComposant,NULL,NULL,NULL,NULL,NULL);

    ///DECLARATION ET INITIALISATION DE LA MUSIQUE --- LECTURE///
    Mix_Music *pMusique = Mix_LoadMUS("./assets/son/Never.wav");
    Mix_PlayMusic(pMusique, 1);


    ///INITIALISATION ET DECLARATION DE LA LISTE DES PROPRIETES DES TEXTES:
    pManaComposant->pListePropTexte = initialisationListePropTexte(creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");
    insertionPropTexteListe(pManaComposant->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_SCORE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreJeu");
    insertionPropTexteListe(pManaComposant->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_SCORE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"dialogue");

    ///INITIALISATION ET DECLARATION DE LA LISTE D'OBJET
    pManaComposant->pListeObjet = initialisationListeObjet(creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+1)),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp1");
    insertionObjetListe(pManaComposant->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+1))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp2");
    insertionObjetListe(pManaComposant->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+1))*3),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp3");
    insertionObjetListe(pManaComposant->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+1))*4),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp4");
    insertionObjetListe(pManaComposant->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR-100,WINDOW_HAUTEUR-50),creeVecteur(0,0),creeVecteur(0,0)),"titreJeu");
    insertionObjetListe(pManaComposant->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"centre");

    ///INITIALISATION ET DECLARATION DE LA LISTE DE BOUTONS
    pManaComposant->pListeBouton = initialisationListeBouton(creeBouton(recupObjetParNom(pManaComposant->pListeObjet,"mPpEmp1"),"Nouvelle Partie",recupPropTexteParNom(pManaComposant->pListePropTexte,"boutonMenu"),false,false,nouvelle_partie),"nouvellePartie");
    insertionBoutonListe(pManaComposant->pListeBouton,NULL,creeBouton(recupObjetParNom(pManaComposant->pListeObjet,"mPpEmp2"),"Charger",recupPropTexteParNom(pManaComposant->pListePropTexte,"boutonMenu"),false,false,charger),"charger");
    insertionBoutonListe(pManaComposant->pListeBouton,NULL,creeBouton(recupObjetParNom(pManaComposant->pListeObjet,"mPpEmp3"),"Options",recupPropTexteParNom(pManaComposant->pListePropTexte,"boutonMenu"),false,false,options),"options");
    insertionBoutonListe(pManaComposant->pListeBouton,NULL,creeBouton(recupObjetParNom(pManaComposant->pListeObjet,"mPpEmp4"),"Quitter",recupPropTexteParNom(pManaComposant->pListePropTexte,"boutonMenu"),false,false,fermerJeu),"fermerJeu");


    ///INITIALISATION ET DECLARATION DES IMAGES
    pManaComposant->pListeImage=initialisationListeImage(creeImage(recupObjetParNom(pManaComposant->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuPrincipale");

    ///INITIALISATION ET DECLARATION DES TEXTES
    pManaComposant->pListeTexte=initialisationListeTexte(creeTexte(NOM_DU_JEU,recupObjetParNom(pManaComposant->pListeObjet,"titreJeu"),recupPropTexteParNom(pManaComposant->pListePropTexte,"titreJeu")),"titreJeu");


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
        gestionListeBoutonPointeur(pManaComposant->pListeBouton,pstPointeur);



        SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
        //affichageListeImage(pRenderer,pManaComposant->pListeImage);
        //affichageListeTexte(pRenderer,pManaComposant->pListeTexte);
        //affichageListeObjet(pRenderer,pManaComposant->pListeObjet);
        affichageListeBouton(pRenderer,pManaComposant->pListeBouton);


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

