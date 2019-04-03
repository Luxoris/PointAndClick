#include "FPS.h"

//###########################################
//PROCEDURE calculFPS
//*****************************************************************************************************//
//
// DESCRIPTION Calcul le nombre de FPS en fonction du Temps en Début de boucle, et du temps en fin de boucle.
//
// ENTREE / Les ref des FPS, le temps Au debut de la boucle, le temps à la fin de la boucle
//
// SORTIE / Le nombre de FPS modifié
//
// NOTE-
//
//*****************************************************************************************************//
void calculFPS(float * pfFPS, const Uint32 nTempsDebutBoucle, const Uint32 nTempsFinBoucle){
    *pfFPS = (1000/(nTempsFinBoucle-nTempsDebutBoucle));
}

//###########################################
//PROCEDURE priseEnCompteFPSMax
//*****************************************************************************************************//
//
// DESCRIPTION Appel un SDL_Delay si le nombre de FPS est supérieur au FPS Max.
//
// ENTREE / La valeur des FPSMax, le Temps d'exécution d'un cycle de boucle.
//
// SORTIE / L'appel de SDL_Delay, la modification du nombre de FPS si ce nombre est supérieur au FPSMax
//
// NOTE-
//
//*****************************************************************************************************//
void priseEnCompteFPSMax(float *pfFPS, const int nFPSMax, const Uint32 nTempsExecution){
    if(nFPSMax<(*pfFPS)){
        SDL_Delay((1000/nFPSMax)-nTempsExecution);
        *pfFPS = nFPSMax;
    }
}
