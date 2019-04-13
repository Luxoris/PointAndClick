#ifndef ETATPARTIE_H_INCLUDED
#define ETATPARTIE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "interface.h"
#include "level.h"

//déclaration du type structuré

typedef enum tEtatPartie{menu,quitter,initialisation,fin,pause,enCours}tEtatPartie;

//DEFINITON DU TYPE ACTION
typedef enum{nouvelle_partie=1,nouvellePartieEmpl1,nouvellePartieEmpl2,nouvellePartieEmpl3,charger,chargerEmpl1,chargerEmpl2,chargerEmpl3,options,fermerJeu,retourMenuPrincipalDepuisOptions, retourMenuPrincipalDepuisCharger,retourMenuPrincipalDepuisNouvellePartie,ouvrirMenuJeu,quitterPartie,reprendrePartie,sauvegarder}tAction;


//PROTOTYPE DES METHODES
extern void gestionAction(const tAction nAction, tManaComposant *pMana, tEtatPartie *pEtatPartie);
extern void gestionActionListeBouton(tManaComposant *pMana, tEtatPartie *pEtatPartie);



#endif // ETATPARTIE_H_INCLUDED


