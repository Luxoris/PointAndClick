#include "mixer.h"

//###########################################
//PROCEDURE initMixer
//*****************************************************************************************************//
//
// DESCRIPTION Initialise la SDL MIXER
//
// ENTREE - L'environnement
//
// SORTIE - L'environnement
//
// NOTE -
//*****************************************************************************************************//

void initMixer(){

    int flags=MIX_INIT_OGG|MIX_INIT_MOD|MIX_INIT_MP3;
    int initted=Mix_Init(flags);
    if((initted&flags) != flags) {
        printf("Mix_Init: Failed to init : %s\n", Mix_GetError());
        // handle error
    }else{
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
        {
            printf("Erreur d'initialisation de SDL MIXER %s", Mix_GetError());
        }

    }


}


