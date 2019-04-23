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



    ///INITIALISATION DE LA SDL, DE LA FENETRE, DU RENDERER, DU TTF///
    initSDL();
    initFenetre(&pFenetre,NOM_DU_JEU);
    SDL_SetWindowFullscreen(pFenetre,SDL_WINDOW_FULLSCREEN_DESKTOP);    //mise ne plein écran
    initMoteurRendu(&pFenetre,&pRenderer);
    initSDLImage();
    initTTF();
    initMixer();

    ///INITIALISATION DU MANAGER DE COMPOSANTS ET DES COMPOSANTS
    initManaComposantEtComposant(&pManaComposant);
    pManaComposant->pEtatJeu=&stEtatJeu;    //sauvegarde de la ref de l'état du jeu dans le manager de composants.

    ///DECLARATION ET INITIALISATION DE LA MUSIQUE --- LECTURE///
    Mix_Music *pMusique = Mix_LoadMUS("./assets/son/Never.wav");
    Mix_PlayMusic(pMusique, 1);


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

        gestionEvenements(&stEtatPartie,getManaComposantPointeur(pManaComposant));
        gestionActionListeBouton(pManaComposant,&stEtatPartie);
        gestionListeBoutonPointeur(pManaComposant->pListeBouton,pManaComposant->pPointeur);

        switch(stEtatPartie){
        case initialisation:
            //Définit l'état du jeu comme celui d'un nouvelle partie.
            stEtatJeu.nAvancementLevel=0;
            stEtatJeu.nNumLevel=1;
            stEtatJeu.stHorloge.nHeure=0;
            stEtatJeu.stHorloge.nMinute=0;
            //Ecrase la sauvegarde précédente de l'empl 1
            sauvegardePartie(pManaComposant->pEtatJeu->cEmplFichierSauvegarde,*pManaComposant->pEtatJeu);
            //Ajoute l'interface du jeu
            ajoutInterfaceJeu(pManaComposant);
            //Démare la partie
            stEtatPartie = enCours;
            break;
        case enCours:
            switch(stEtatJeu.nNumLevel){
                case level1 : //gestionLevel1(pManaComposant);
                    break;
                case miniJeuReve: gestionLevelMiniJeuReve(pManaComposant);
                    break;

                case leReveil: gestionLevelLeReveil(pManaComposant);
                    break;

                case lePetitDejeuner : gestionLevelLePetitDejeuner(pManaComposant);
                    break;

                case laToilette : gestionLevelLaToilette(pManaComposant);
                    break;

                case moyenLocomotion : gestionLevelMoyenLocomotion(pManaComposant);
                    break;

                case preparation : gestionLevelPreparation(pManaComposant);
                    break;

                case leTicket : gestionLevelLeTicket(pManaComposant);
                    break;

                case miniJeuPanneaux : gestionLevelMiniJeuPanneaux(pManaComposant);
                    break;

                case arriveeEcole : gestionLevelArriveeEcole(pManaComposant);
                    break;

                case repasMidi : gestionLevelRepasMidi(pManaComposant);
                    break;

                case miniJeuRepas : gestionLevelMiniJeuRepas(pManaComposant);
                    break;

                case toilettes : gestionLevelToilettes(pManaComposant);
                    break;

                case miniJeuGrammaire : gestionLevelMiniJeuGrammaire(pManaComposant);
                    break;

                case sortieEcole : gestionLevelSortieEcole(pManaComposant);
                    break;

                case devoirs : gestionLevelDevoirs(pManaComposant);
                    break;

                case miniJeuJeuxVideo : gestionLevelMiniJeuJeuxVideo(pManaComposant);
                    break;

                case sport : gestionLevelSport(pManaComposant);
                    break;

                case miniJeuSecourisme : gestionLevelMiniJeuSecourisme(pManaComposant);
                    break;

                case diner : gestionLevelDiner(pManaComposant);
                    break;

                case bonneNuit : gestionLevelBonneNuit(pManaComposant);
                    break;
            }
            break;
        case pause:
            break;
        case menu:
            break;
        case fin:
            break;
        case quitter:
            break;
        }



        ///AFFICHAGE
        //écran en noir
        SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
        SDL_RenderClear(pRenderer);
        //gestionEvenementsListeBoutons(pManaComposant->pListeBouton,&stEtatPartie);
        //

        affichageListeImage(pRenderer,pManaComposant->pListeImage);
        affichageListeTexte(pRenderer,pManaComposant->pListeTexte);
        //SDL_SetRenderDrawColor(pRenderer,255,0,255,255);
        //affichageListeObjet(pRenderer,pManaComposant->pListeObjet);
        SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
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

