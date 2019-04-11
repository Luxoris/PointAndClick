#ifndef TOBJET_H_INCLUDED
#define TOBJET_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include "vecteur.h"
#include "rectangle.h"
#include "define.h"
#include "collision.h"
#include "renderer.h"


#define OBJET_TAILLE_CHAINE 256

//définition du type structuré
typedef struct tObjet{
    tRectangle stRectangle;
    tVecteur stVecteurVitesse;
    tVecteur stVecteurAcceleration;
}tObjet;

//DEFINITION DE L'ELEMENT OBJET
typedef struct tElementObjet tElementObjet;
struct tElementObjet{
    tObjet stObjet;
    char sNom[OBJET_TAILLE_CHAINE];
    tElementObjet *pSuivant;
};

//DEFINTITION DE LA LISTE D'OBJET
typedef struct tListeObjet{
    tElementObjet *pPremier;
    int nbElements;
}tListeObjet;


//PROTOTYPE DES METHODES DE LA LISTE
extern tListeObjet *initialisationListeObjet();
extern void insertionObjetListe(tListeObjet *pListe, tElementObjet *pElementInsetion,const tObjet stObjet,const char sNom[]);
extern void suppressionObjetListe(tListeObjet *pListe, tElementObjet *pElementSupprimer);
extern void vidageListeObjet(tListeObjet *pListe);
extern void destructionListeObjet(tListeObjet *pListe);
extern void affichageListeObjet(SDL_Renderer *pRenderer,tListeObjet *pListe);
extern tElementObjet* recupElementObjetParNom(tListeObjet *pListe,const char sNom[]);
extern tObjet* recupObjetParNom(tListeObjet *pListe,const char sNom[]);



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

extern void dessineObjet(SDL_Renderer *pRenderer,tObjet *pstObjet,tBool bRectanglePlein);


#endif // TOBJET_H_INCLUDED
