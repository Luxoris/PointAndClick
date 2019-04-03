#ifndef RAQUETTE_H_INCLUDED
#define RAQUETTE_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>
#include "vecteur.h"
#include "rectangle.h"
#include "define.h"
#include "collision.h"

//définition du type structuré
typedef struct tRaquette{
    tRectangle stRectangle;
    tVecteur stVecteurVitesse;
    tVecteur stVecteurAcceleration;
}tRaquette;



//prototype des fonctions
extern tRaquette creeRaquette(const tRectangle stRectangle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration);
extern tRectangle getRaquetteRectangle(tRaquette *pstRaquette);
extern tVecteur getRaquetteVecteurVitesse(tRaquette *pstRaquette);
extern tVecteur getRaquetteVecteurAcceleration(tRaquette *pstRaquette);

extern void setRaquetteRectangle(tRaquette *pstRaquette, const tRectangle stRectangle);
extern void setRaquetteVecteurVitesse(tRaquette *pstRaquette, const tVecteur stVecteurVitesse);
extern void setRaquetteVecteurAcceleration(tRaquette *pstRaquette, const tVecteur stVecteurAcceleration);


extern void deplacementRaquette(tRaquette *pstRaquette, const float fFPS);
extern void modificationVitesseRaquette(tRaquette *pstRaquette);
extern void modificationAccelerationRaquette(tRaquette *pstRaquette, tVecteur stFrottement);
extern void mouvementRaquette(tRaquette *pstRaquette, const float fFPS);
extern void gestionCollisionRaquetteBords(tRaquette *pstRaquette, const float fCoorYBordBas, const float fCoorYBordHaut);


#endif // RAQUETTE_H_INCLUDED
