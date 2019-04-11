#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "manager.h"

//DEFINITION DES TYPES STRUCTURES
typedef enum tLevel{level1, level2, level3, level4, level5}tLevel;

typedef struct tEtatJeu{
    tLevel stLevel;
    int nAvancementLevel;
}tEtatJeu;

//PROTOTYPE DES METHODES
extern void gestionLevel1(tManaComposant *pMana, tEtatJeu *pEtatJeu);


#endif // LEVEL_H_INCLUDED
