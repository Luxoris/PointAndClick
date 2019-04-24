#include "FPS.h"

//###########################################
//PROCEDURE calculFPS
//*****************************************************************************************************//
//
// DESCRIPTION Calcul le nombre de FPS en fonction du Temps en D�but de boucle, et du temps en fin de boucle.
//
// ENTREE / Les ref des FPS, le temps Au debut de la boucle, le temps � la fin de la boucle
//
// SORTIE / Le nombre de FPS modifi�
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
// DESCRIPTION Appel un SDL_Delay si le nombre de FPS est sup�rieur au FPS Max.
//
// ENTREE / La valeur des FPSMax, le Temps d'ex�cution d'un cycle de boucle.
//
// SORTIE / L'appel de SDL_Delay, la modification du nombre de FPS si ce nombre est sup�rieur au FPSMax
//
// NOTE-
//
//*****************************************************************************************************//
void priseEnCompteFPSMax(float *pfFPS, const int nFPSMax, const Uint32 nTempsExecution){
    if(nFPSMax<(*pfFPS)&&(*pfFPS>=1)){
        SDL_Delay((1000/nFPSMax)-nTempsExecution);
        *pfFPS = nFPSMax;
    }
}
