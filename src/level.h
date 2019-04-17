#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "manager.h"
#include "dialogue.h"
#include "interface.h"


//DEFINITION DES TYPES STRUCTURES
typedef enum tLevel{level1, leReveil}tLevel;


//PROTOTYPE DES METHODES
extern void gestionLevel1(tManaComposant *pMana);
extern void gestionLevelLeReveil(tManaComposant *pMana);

//DECLARATION DES METHODES
extern int sauvegardePartie(const char cCheminFichier[],const tEtatJeu stEtatJeu);
extern int chargementPartie(const char cCheminFichier[],tEtatJeu *pstEtatJeu);
extern tBool actionBouton(tManaComposant *pMana,char sNomBouton[], int nValeurAvancementLevel);
extern int choixBouton(tManaComposant *pMana, int nValeurAvancementLevel);

#endif // LEVEL_H_INCLUDED
