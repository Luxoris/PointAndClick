#ifndef ETATPARTIE_H_INCLUDED
#define ETATPARTIE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "manager.h"
#include "interface.h"

//déclaration du type structuré

typedef enum tEtatPartie{menu,quitter,initialisation,fin,pause,enCours}tEtatPartie;

//DEFINITON DU TYPE ACTION
typedef enum{nouvelle_partie=1,charger,options,fermerJeu,retourMenuPrincipalDepuisOptions, retourMenuPrincipalDepuisCharger,ouvrirMenuJeu,quitterPartie,reprendrePartie,sauvegarder}tAction;


//PROTOTYPE DES METHODES
extern void gestionAction(const tAction nAction, tManaComposant *pMana, tEtatPartie *pEtatPartie);
extern void gestionActionListeBouton(tManaComposant *pMana, tEtatPartie *pEtatPartie);



#endif // ETATPARTIE_H_INCLUDED


