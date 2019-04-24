#ifndef ETATPARTIE_H_INCLUDED
#define ETATPARTIE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include <SDL_mixer.h>
#include "interface.h"
#include "level.h"

//d�claration du type structur�

typedef enum tEtatPartie{menu,quitter,initialisation,fin,pause,enCours}tEtatPartie;

//DEFINITON DU TYPE ACTION
typedef enum{nouvelle_partie=1,sonOn, sonOff,nouvellePartieEmpl1,nouvellePartieEmpl2,nouvellePartieEmpl3,charger,chargerEmpl1,chargerEmpl2,chargerEmpl3,options,fermerJeu,retourMenuPrincipalDepuisOptions, retourMenuPrincipalDepuisCharger,retourMenuPrincipalDepuisNouvellePartie,ouvrirMenuJeu,quitterPartie,reprendrePartie,sauvegarder}tAction;


//PROTOTYPE DES METHODES
extern void gestionAction(const tAction nAction, tManaComposant *pMana, tEtatPartie *pEtatPartie, SDL_Window *pFenetre);
extern void gestionActionListeBouton(tManaComposant *pMana, tEtatPartie *pEtatPartie, SDL_Window *pFenetre);



#endif // ETATPARTIE_H_INCLUDED


