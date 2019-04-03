#ifndef VECTEUR_H_INCLUDED
#define VECTEUR_H_INCLUDED
#pragma once

#include <SDL.h>

//STRUCTURE
typedef struct tVecteur{
    float fX;
    float fY;
}tVecteur;

//PROTOTYPE
extern tVecteur creeVecteur(const float fX,const float fY);
extern float getVecteurX(tVecteur *pstVecteur);
extern float getVecteurY(tVecteur *pstVecteur);
extern void setVecteurX(tVecteur *pstVecteur,const float fX);
extern void setVecteurY(tVecteur *pstVecteur,const float fY);



extern void additionVectorielle(tVecteur stVecteur1,tVecteur stVecteur2,tVecteur *pstResultat);
extern void soustractionVectorielle(tVecteur stVecteur1,tVecteur stVecteur2,tVecteur *pstResultat);
extern void multiplicationVectorielleScalaire(tVecteur stVecteur1,const float fScalaire,tVecteur *pstResultat);
extern void produitScalaire(tVecteur stVecteur1,tVecteur stVecteur2,float *pnResultat);
extern void produitVectoriel(tVecteur stVecteur1,tVecteur stVecteur2,tVecteur *pstResultat,float const nZ1,float const nZ2);

#endif // VECTEUR_H_INCLUDED
