#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "etatPartie.h"
#include "manager.h"

//DEFINITION DES MACCROS

//BOUTONS

#define HAUTEUR_BOUTON (TAILLE_POLICE_BOUTON*2)
#define LARGEUR_BOUTON (WINDOW_LARGEUR*0.12)
#define NB_BOUTON_MENU_PRINCIPAL 4
#define NB_BOUTON_MENU_JEU 3
#define NB_BOUTON_MENU_OPTION 1
#define NB_BOUTON_MENU_CHARGER 4
#define NB_BOUTON_MENU_NOUVELLE_PARTIE 4

#define TAILLE_POLICE_HORLOGE (48)
#define TAILLE_POLICE_BOUTON (30)
#define TAILLE_POLICE_DIALOGUE (32)
#define TAILLE_POLICE_TITRE (48)
#define HAUTEUR_DIALOGUE (WINDOW_HAUTEUR*0.8)
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

extern void ajoutMenuNouvellePartie(tManaComposant *pMana);
extern void supprMenuNouvellePartie(tManaComposant *pMana);

extern void ajoutMenuOptions(tManaComposant *pMana);
extern void supprMenuOptions(tManaComposant *pMana);

extern void ajoutMenuCharger(tManaComposant *pMana);
extern void supprMenuCharger(tManaComposant *pMana);

extern void ajoutInterfaceJeu(tManaComposant *pMana);
extern void supprInterfaceJeu(tManaComposant *pMana);

extern void initComposantsProgramme(tManaComposant *pManaComposant);

extern void ajoutBoutonChoix(tManaComposant *pMana,char sChoix1[], char sChoix2[]);
extern void supprBoutonChoix(tManaComposant *pMana);

extern void manaMajAffichageHorloge(tManaComposant *pMana);


#endif // INTERFACE_H_INCLUDED
