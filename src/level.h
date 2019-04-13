#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "manager.h"
#include "dialogue.h"


//DEFINITION DES TYPES STRUCTURES
typedef enum tLevel{level1, level2, level3, level4, level5}tLevel;


//PROTOTYPE DES METHODES
extern void gestionLevel1(tManaComposant *pMana);
//DECLARATION DES METHODES
extern int sauvegardePartie(const char cCheminFichier[],const tEtatJeu stEtatJeu);
extern int chargementPartie(const char cCheminFichier[],tEtatJeu *pstEtatJeu);

#endif // LEVEL_H_INCLUDED
