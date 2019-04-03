#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>
#include "etatPartie.h"
#include "define.h"
#include "tObjet.h"
#include "tBool.h"
#include "balle.h"
#include "pointeur.h"

//prototype des fonctions
extern void recupEtatsClavier(Uint8* pEtatsClavier);
extern tBool testToucheAppuyer(const Uint8* pEtatsClavier, const SDL_Scancode tCodeTouche);
extern void gestionEvenements(tEtatPartie *pstEtatPartie, tPointeur *pstPointeur);
extern void recuperationInfoPointeur(tPointeur *pstPointeur);

//extern void gestionControles(tEtatPartie *pstEtatPartie, tObjet *pstObjetJ1, tObjet *pstObjetJ2);

#endif // EVENEMENT_H_INCLUDED
