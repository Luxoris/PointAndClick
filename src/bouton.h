#ifndef BOUTON_H_INCLUDED
#define BOUTON_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBool.h"
#include "tObjet.h"
#include "pointeur.h"

//DEFINITION DES MACCROS

#define BOUTON_TAILLE_CHAINE 256

//DEFINITION DU TYPE BOUTON

typedef struct tBouton{
    tObjet *pstObjet;
    char sTexte[BOUTON_TAILLE_CHAINE];
    tBool stSurvole;
    tBool stClique;
    int nCodeAction;

}tBouton;

//PROTOTYPE DES METHODES
extern void initBouton(tBouton **ppBouton,tObjet *pstObjet, const char sTexte[],const tBool stSurvole, const tBool stClique, const int nCodeAction);
extern void freeBouton(tBouton *pstBouton);

extern void setBouton(tBouton *pstBouton,tObjet *pstObjet, const char sTexte[],const tBool stSurvole, const tBool stClique, const int nCodeAction);
extern void setBoutonObjet(tBouton *pstBouton, tObjet *pstObjet);
extern void setBoutonTexte(tBouton *pstBouton, const char sTexte[]);
extern void setBoutonSurvole(tBouton *pstBouton, const tBool stSurvole);
extern void setBoutonClique(tBouton *pstBouton, const tBool stClique);
extern void setBoutonCodeAction(tBouton *pstBouton, const int nCodeAction);


extern tObjet* getBoutonObjet(tBouton *pstBouton);
extern char* getBoutonTexte(tBouton *pstBouton);
extern tBool getBoutonSurvole(tBouton *pstBouton);
extern tBool getBoutonClique(tBouton *pstBouton);
extern int getBoutonCodeAction(tBouton *pstBouton);

extern void gestionBoutonPointeur(tBouton *pstBouton, tPointeur *pstPointeur);


#endif // BOUTON_H_INCLUDED
