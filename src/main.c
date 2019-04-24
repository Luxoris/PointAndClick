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
    float fFPS=1;    //le nombre de FPS est initialis� � 0.1 pour le premier passage
    Uint32 nTempsDebutBoucle=0;
    Uint32 nTempsFinBoucle=0;
    tEtatPartie stEtatPartie=0;
    tManaComposant *pManaComposant = NULL;
    tEtatJeu stEtatJeu = {miniJeuReve,0};



    ///INITIALISATION DE LA SDL, DE LA FENETRE, DU RENDERER, DU TTF///
    initSDL();
    initFenetre(&pFenetre,NOM_DU_JEU);
    //SDL_SetWindowFullscreen(pFenetre,SDL_WINDOW_FULLSCREEN_DESKTOP);    //mise ne plein �cran
    initMoteurRendu(&pFenetre,&pRenderer);
    initSDLImage();
    initTTF();
    initMixer();

    ///INITIALISATION DU MANAGER DE COMPOSANTS ET DES COMPOSANTS
    initManaComposantEtComposant(&pManaComposant);
    pManaComposant->pEtatJeu=&stEtatJeu;    //sauvegarde de la ref de l'�tat du jeu dans le manager de composants.

    ///DECLARATION ET INITIALISATION DE LA MUSIQUE --- LECTURE///
    Mix_Music *pMusique = Mix_LoadMUS(MUSIQUE);
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
        //affectation de la valeur du timer pour connaitre le temps d'ex�cution d'ex�cution du programme au d�but de l'int�rration
        nTempsDebutBoucle = SDL_GetTicks();

        gestionEvenements(&stEtatPartie,getManaComposantPointeur(pManaComposant));
        gestionActionListeBouton(pManaComposant,&stEtatPartie,pFenetre);
        gestionListeBoutonPointeur(pManaComposant->pListeBouton,pManaComposant->pPointeur);

        switch(stEtatPartie){
        case initialisation:
            //D�finit l'�tat du jeu comme celui d'un nouvelle partie.
            stEtatJeu.nAvancementLevel=0;
            stEtatJeu.nNumLevel=miniJeuReve;
            stEtatJeu.stHorloge.nHeure=0;
            stEtatJeu.stHorloge.nMinute=0;
            //Ecrase la sauvegarde pr�c�dente de l'empl 1
            sauvegardePartie(pManaComposant->pEtatJeu->cEmplFichierSauvegarde,*pManaComposant->pEtatJeu);
            //Ajoute l'interface du jeu
            ajoutInterfaceJeu(pManaComposant);
            //D�mare la partie
            stEtatPartie = enCours;
            break;
        case enCours:
            switch(stEtatJeu.nNumLevel){
                case level1 : //gestionLevel1(pManaComposant);
                    break;
                case miniJeuReve:
                        ajoutTransition(pManaComposant,0,0,"Minijeu : R�ve");
                        gestionLevelMiniJeuReve(pManaComposant);
                    break;

                case leReveil:
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Le R�veil");
                        gestionLevelLeReveil(pManaComposant);
                    break;

                case lePetitDejeuner :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Le Petit D�jeuner");
                        gestionLevelLePetitDejeuner(pManaComposant);
                    break;

                case laToilette :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : La toilette");
                        gestionLevelLaToilette(pManaComposant);
                    break;

                case moyenLocomotion :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Moyen de locomotion");
                        gestionLevelMoyenLocomotion(pManaComposant);
                    break;

                case preparation :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Pr�paration");
                        gestionLevelPreparation(pManaComposant);
                    break;

                case leTicket :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Le Bus");
                        gestionLevelLeTicket(pManaComposant);
                    break;

                case miniJeuPanneaux :
                        ajoutTransition(pManaComposant,0,0,"Mini-Jeu : Orientation");
                        gestionLevelMiniJeuPanneaux(pManaComposant);
                    break;

                case arriveeEcole :
                        gestionLevelArriveeEcole(pManaComposant);
                    break;

                case repasMidi :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Repas de midi");
                        gestionLevelRepasMidi(pManaComposant);
                    break;

                case miniJeuRepas :
                        ajoutTransition(pManaComposant,0,0,"Mini-Jeu : Choix du menu");
                        gestionLevelMiniJeuRepas(pManaComposant);
                    break;

                case toilettes : gestionLevelToilettes(pManaComposant);
                    break;

                case miniJeuGrammaire :
                        ajoutTransition(pManaComposant,0,0,"Mini-Jeu : Grammaire");
                        gestionLevelMiniJeuGrammaire(pManaComposant);
                    break;

                case sortieEcole :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Sortie de l'�cole");
                        gestionLevelSortieEcole(pManaComposant);
                    break;

                case devoirs :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Devoirs");
                        gestionLevelDevoirs(pManaComposant);
                    break;

                case miniJeuJeuxVideo :
                        ajoutTransition(pManaComposant,0,0,"Mini-Jeu : Jeux-Vid�o");
                        gestionLevelMiniJeuJeuxVideo(pManaComposant);
                    break;

                case sport :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Partir au sport");
                        gestionLevelSport(pManaComposant);
                    break;

                case miniJeuSecourisme :
                        ajoutTransition(pManaComposant,0,0,"Mini-Jeu : Secourisme");
                        gestionLevelMiniJeuSecourisme(pManaComposant);
                    break;

                case diner :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Le Diner");
                        gestionLevelDiner(pManaComposant);
                    break;

                case bonneNuit :
                        ajoutTransition(pManaComposant,0,0,"Sc�ne : Bonne nuit");
                        gestionLevelBonneNuit(pManaComposant);
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

        manaGestionDragAndDrop(pManaComposant);

        ///AFFICHAGE
        //�cran en noir
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

        //affectation de la valeur du timer pour connaitre le temps d'ex�cution d'ex�cution du programme � la quitter de l'int�rration
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

