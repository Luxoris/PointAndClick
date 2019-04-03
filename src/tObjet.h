#ifndef TOBJET_H_INCLUDED
#define TOBJET_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "vecteur.h"
#include "rectangle.h"
#include "define.h"
#include "collision.h"



//définition du type structuré
typedef struct tObjet{
    tRectangle stRectangle;
    tVecteur stVecteurVitesse;
    tVecteur stVecteurAcceleration;
}tObjet;



//prototype des fonctions
extern void initObjet(tObjet **ppObjet, const tRectangle stRectangle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration);
extern void freeObjet(tObjet *pstObjet);

extern tObjet creeObjet(const tRectangle stRectangle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration);
extern tRectangle* getObjetRectangle(tObjet *pstObjet);
extern tVecteur* getObjetVecteurVitesse(tObjet *pstObjet);
extern tVecteur* getObjetVecteurAcceleration(tObjet *pstObjet);

extern void setObjetRectangle(tObjet *pstObjet, const tRectangle stRectangle);
extern void setObjetVecteurVitesse(tObjet *pstObjet, const tVecteur stVecteurVitesse);
extern void setObjetVecteurAcceleration(tObjet *pstObjet, const tVecteur stVecteurAcceleration);


extern void deplacementObjet(tObjet *pstObjet, const float fFPS);
extern void modificationVitesseObjet(tObjet *pstObjet);
extern void modificationAccelerationObjet(tObjet *pstObjet, tVecteur stFrottement);
extern void mouvementObjet(tObjet *pstObjet, const float fFPS);
extern void gestionCollisionObjetBords(tObjet *pstObjet, const float fCoorYBordBas, const float fCoorYBordHaut);


#endif // TOBJET_H_INCLUDED
