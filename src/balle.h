#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>
#include "cercle.h"
#include "vecteur.h"
#include "rectangle.h"
#include "collision.h"
#include "tObjet.h"
#include "tBool.h"
#include "joueur.h"

//définition du type structuré
typedef struct tBalle{
    tCercle stCercle;
    tVecteur stVecteurVitesse;
    tVecteur stVecteurAcceleration;
}tBalle;



//prototype des fonctions
extern tBalle creeBalle(const tCercle stCercle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration);
extern void setBalleCercle(tBalle *pstBalle, const tCercle stCercle);
extern void setBalleVecteurVitesse(tBalle *pstBalle, const tVecteur stVecteurVitesse);
extern void setBalleVecteurAcceleration(tBalle *pstBalle, const tVecteur stVecteurAcceleration);
extern tCercle getBalleCercle(tBalle *pstBalle);
extern tVecteur getBalleVecteurVitesse(tBalle *pstBalle);
extern tVecteur getBalleVecteurAcceleration(tBalle *pstBalle);


extern void deplacementBalle(tBalle *pstBalle, const float fFPS);
extern void modificationVitesseBalle(tBalle *pstBalle);
extern void modificationAccelerationBalle(tBalle *pstBalle, tVecteur stFrottement);
extern void mouvementBalle(tBalle *pstBalle, const float fFPS);
extern void gestionCollisionBalleBords(tBalle *pstBalle, const float fCoorYBordBas, const float fCoorYBordHaut);
extern void gestionBalleSort(tBalle *pstBalle, tJoueur *pstJoueur1, tJoueur *pstJoueur2,const float fCoorYBordDroit, const float fCoorYBordGauche, const tBalle stBalleRepositionner);
extern void gestionCollisionBalleObjet(tBalle *pstBalle, tObjet *pstObjet);



#endif // BALLE_H_INCLUDED
