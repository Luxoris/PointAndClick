#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES


//DEFINITION DES TYPES STRUCTURES
typedef enum{level1, level2, level3, level4, level5}tLevel;


//PROTOTYPE DES METHODES

void afficheMenu(tLevel * pLevel, tPileBouton * PileBouton);

void gestionCollisionsBoutons();
void gestionActionsBoutons(tPileBoutons *pBoutons);
void affichageTextes(tPileTexte *pTexte);
void afficheImages(tPileImage *pImage);

/*
image : estInvisble
image : estSurvole
image : estCliqué
image : nom

bouton : nom

texte : nom

*/

#endif // LEVEL_H_INCLUDED
