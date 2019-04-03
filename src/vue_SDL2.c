#include "vue_SDL2.h"

#include <stdlib.h>
#include <stdio.h>
//###########################################
//PROCEDURE initSDL
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui initialise la SDL
//
// ENTREE /L'environnement
//
// SORTIE / L'environnement
//
// NOTE -
//*****************************************************************************************************//
void initSDL(){
    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
        {
            printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());

        }
}
