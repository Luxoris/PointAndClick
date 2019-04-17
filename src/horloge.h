#ifndef HORLOGE_H_INCLUDED
#define HORLOGE_H_INCLUDED
#pragma once

#include "SDL2_texte.h"
#include <string.h>
//DEFINITION DU TYPE STRUCTURE
typedef struct tHorloge{
    int nHeure;
    int nMinute;
}tHorloge;

//PROTOTYPE DE FONCTIONS
extern void majAffichageHorloge(tTexte *pTexte, tHorloge *pHorloge);
extern void ajoutMinute(tHorloge *pHorloge,const int nMinute);

#endif // HORLOGE_H_INCLUDED
