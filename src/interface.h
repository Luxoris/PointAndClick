#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "etatPartie.h"

//DEFINITION DES MACCROS

//BOUTONS

#define HAUTEUR_BOUTON (TAILLE_POLICE_BOUTON*2)
#define LARGEUR_BOUTON (WINDOW_LARGEUR*0.12)
#define NB_BOUTON_MENU_PRINCIPAL 4
#define NB_BOUTON_MENU_JEU 3
#define NB_BOUTON_MENU_OPTION 1
#define NB_BOUTON_MENU_CHARGER 1

#define TAILLE_POLICE_BOUTON (16)
#define TAILLE_POLICE_DIALOGUE (16)
#define TAILLE_POLICE_TITRE (32)
#define HAUTEUR_DIALOGUE (WINDOW_HAUTEUR*0.6)
#define LARGEUR_DIALOGUE (WINDOW_LARGEUR)
#define TTF_FONT_VERDANA "./fonts/verdana.ttf" //emplacement du fichier de police verdana
#define MARGE_BORD 5
#define SCORE_DEPART 0



///PROTOTYPE DES METHODES

//INTERFACES DES MENUS
extern void ajoutMenuPrincipale(tManaComposant *pMana);
extern void supprMenuPrincipale(tManaComposant *pMana);

extern void ajoutMenuJeu(tManaComposant *pMana);
extern void supprMenuJeu(tManaComposant *pMana);

extern void ajoutMenuOptions(tManaComposant *pMana);
extern void supprMenuOptions(tManaComposant *pMana);

extern void ajoutMenuCharger(tManaComposant *pMana);
extern void supprMenuCharger(tManaComposant *pMana);

extern void ajoutInterfaceJeu(tManaComposant *pMana);
extern void supprInterfaceJeu(tManaComposant *pMana);



#endif // INTERFACE_H_INCLUDED
