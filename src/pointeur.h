#ifndef POINTEUR_H_INCLUDED
#define POINTEUR_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include <stdlib.h>
#include <stdio.h>
#include "tBool.h"
#include "point.h"

//DEFINITION DES MACCROS
#define LARGEUR_SOURIS 20
#define HAUTEUR_SOURIS 20

//DEFINITION DU TYPE POINTEUR

typedef struct tPointeur{
    tPoint stPosition;
    tBool stCliqueDroit;
    tBool stCliqueGauche;
    tBool stCliqueMolette;

}tPointeur;

//DEFINITION DES METHODES
extern void initPointeur(tPointeur **ppPointeur, const tPoint stPosition,const tBool stCliqueDroit, const tBool stCliqueGauche, const tBool stCliqueMolette);
extern void freePointeur(tPointeur *pstPointeur);

extern void setPointeur(tPointeur *pstPointeur, const tPoint stPosition,const tBool stCliqueDroit, const tBool stCliqueGauche, const tBool stCliqueMolette);
extern void setPointeurPosition(tPointeur *pstPointeur, const tPoint stPosition);
extern void setPointeurCliqueDroit(tPointeur *pstPointeur, const tBool stCliqueDroit);
extern void setPointeurCliqueGauche(tPointeur *pstPointeur, const tBool stCliqueGauche);
extern void setPointeurCliqueMolette(tPointeur *pstPointeur, const tBool stCliqueMolette);

extern tPoint* getPointeurPosition(tPointeur *pstPointeur);
extern tBool getPointeurCliqueDroit(tPointeur *pstPointeur);
extern tBool getPointeurCliqueGauche(tPointeur *pstPointeur);
extern tBool getPointeurCliqueMolette(tPointeur *pstPointeur);



#endif // POINTEUR_H_INCLUDED
