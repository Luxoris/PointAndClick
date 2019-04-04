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
#include "SDL2_texte.h"
#include "renderer.h"


//DEFINITION DES MACCROS

#define BOUTON_TAILLE_CHAINE 256

//DEFINITON DU TYPE ACTION
typedef enum{nouvelle_partie=1,charger,options,fermerJeu,retourMenuPrincipal,quitterPartie,sauvegarder,ouvrirMenuOptionJeu,reprendrePartie} tAction;


//DEFINITION DU TYPE BOUTON

typedef struct tBouton{
    tObjet *pstObjet;
    char sTexte[BOUTON_TAILLE_CHAINE];
    tPropTexte *pstPropTexte;
    tBool stSurvole;
    tBool stClique;
    int nCodeAction;

}tBouton;

//DEFINITION DE L'ELEMENT BOUTON
typedef struct tElementBouton tElementBouton;
struct tElementBouton{
    tBouton stBouton;
    char sNom[OBJET_TAILLE_CHAINE];
    tElementBouton *pSuivant;
};

//DEFINTITION DE LA LISTE DE BOUTONS
typedef struct tListeBouton{
    tElementBouton *pPremier;
    int nbElements;
}tListeBouton;

//PROTOTYPE DES METHODES DE LA LISTE
extern tListeBouton *initialisationListeBouton(const tBouton stBouton,const char sNom[]);
extern void insertionBoutonListe(tListeBouton *pListe, tElementBouton *pElementInsetion,const tBouton stBouton,const char sNom[]);
extern void suppressionBoutonListe(tListeBouton *pListe, tElementBouton *pElementSupprimer);
extern void vidageListeBouton(tListeBouton *pListe);
extern void destructionListeBouton(tListeBouton *pListe);
extern void affichageListeBouton(SDL_Renderer *pRenderer,tListeBouton *pListe);
extern tElementBouton* recupElementBoutonParNom(tListeBouton *pListe,const char sNom[]);
extern tBouton* recupBoutonParNom(tListeBouton *pListe,const char sNom[]);
extern void gestionListeBoutonPointeur(tListeBouton *pListe, tPointeur *pstPointeur);

//PROTOTYPE DES METHODES
extern void initBouton(tBouton **ppBouton,tObjet *pstObjet, const char sTexte[], tPropTexte *pstPropTexte,const tBool stSurvole, const tBool stClique, const int nCodeAction);
extern void freeBouton(tBouton *pstBouton);


extern void setBouton(tBouton *pstBouton,tObjet *pstObjet, const char sTexte[], tPropTexte *pstPropTexte,const tBool stSurvole, const tBool stClique, const int nCodeAction);
extern void setBoutonObjet(tBouton *pstBouton, tObjet *pstObjet);
extern void setBoutonTexte(tBouton *pstBouton, const char sTexte[]);
extern void setBoutonPropTexte(tBouton *pstBouton,tPropTexte *pstPropTexte);
extern void setBoutonSurvole(tBouton *pstBouton, const tBool stSurvole);
extern void setBoutonClique(tBouton *pstBouton, const tBool stClique);
extern void setBoutonCodeAction(tBouton *pstBouton, const int nCodeAction);

extern tBouton creeBouton(tObjet *pstObjet, const char sTexte[],tPropTexte *pstPropTexte,const tBool stSurvole, const tBool stClique, const int nCodeAction);
extern tObjet* getBoutonObjet(tBouton *pstBouton);
extern char* getBoutonTexte(tBouton *pstBouton);
extern tPropTexte* getBoutonPropTexte(tBouton *pstBouton);
extern tBool getBoutonSurvole(tBouton *pstBouton);
extern tBool getBoutonClique(tBouton *pstBouton);
extern int getBoutonCodeAction(tBouton *pstBouton);

extern void gestionBoutonPointeur(tBouton *pstBouton, tPointeur *pstPointeur);
extern void dessineBouton(SDL_Renderer *pRenderer,tBouton *pstBouton);

#endif // BOUTON_H_INCLUDED
