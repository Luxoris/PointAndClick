#include "window.h"

//###########################################
//PROCEDURE initFenetre
//*****************************************************************************************************//
//
// DESCRIPTION Procedure cree la fenetre, renvoie le pointeur de fenetre, défini un titre à la fenetre
//
// ENTREE /Le pointeur de fenetre
//
// SORTIE / Le pointeur de fenetre
//
// NOTE -
//*****************************************************************************************************//
void initFenetre(SDL_Window** pFenetre, const char cTitre[]){
    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
        {
            printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());

        }
    // Création de la fenêtre :
    *(pFenetre) = SDL_CreateWindow(cTitre , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOW_LARGEUR , WINDOW_HAUTEUR, SDL_WINDOW_RESIZABLE);
    if(*(pFenetre) == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());

    }
}
//###########################################
//PROCEDURE arretAffichage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ferme la fenetre
//
// ENTREE /Le pointeur de fenetre
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void arretFenetre(SDL_Window** pFenetre){
    SDL_DestroyWindow(*(pFenetre));
}
