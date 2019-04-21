#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "manager.h"
#include "dialogue.h"
#include "interface.h"


//DEFINITION DES TYPES STRUCTURES
typedef enum tLevel{level1,miniJeuReve, leReveil, lePetitDejeuner, laToilette, moyenLocomotion,preparation, miniJeuPanneaux, leTicket, arriveeEcole, repasMidi, miniJeuRepas, toilettes, miniJeuGrammaire, sortieEcole, devoirs, miniJeuJeuxVideo, sport, miniJeuSecourisme, diner, bonneNuit}tLevel;


//PROTOTYPE DES METHODES
extern void gestionLevel1(tManaComposant *pMana);
extern void gestionLevelMiniJeuReve(tManaComposant *pMana);
extern void gestionLevelMiniJeuPanneaux(tManaComposant *pMana);
extern void gestionLevelMiniJeuRepas(tManaComposant *pMana);
extern void gestionLevelMiniJeuGrammaire(tManaComposant *pMana);
extern void gestionLevelMiniJeuJeuxVideo(tManaComposant *pMana);
extern void gestionLevelMiniJeuSecourisme(tManaComposant *pMana);


extern void gestionLevelLeReveil(tManaComposant *pMana);
extern void gestionLevelLePetitDejeuner(tManaComposant *pMana);
extern void gestionLevelLaToilette(tManaComposant *pMana);
extern void gestionLevelMoyenLocomotion(tManaComposant *pMana);
extern void gestionLevelPreparation(tManaComposant *pMana);
extern void gestionLevelLeTicket(tManaComposant *pMana);
extern void gestionLevelArriveeEcole(tManaComposant *pMana);
extern void gestionLevelRepasMidi(tManaComposant *pMana);

extern void gestionLevelToilettes(tManaComposant *pMana);
extern void gestionLevelSortieEcole(tManaComposant *pMana);
extern void gestionLevelDevoirs(tManaComposant *pMana);
extern void gestionLevelSport(tManaComposant *pMana);
extern void gestionLevelDiner(tManaComposant *pMana);
extern void gestionLevelBonneNuit(tManaComposant *pMana);

//DECLARATION DES METHODES
extern int sauvegardePartie(const char cCheminFichier[],const tEtatJeu stEtatJeu);
extern int chargementPartie(const char cCheminFichier[],tEtatJeu *pstEtatJeu);
extern tBool actionBouton(tManaComposant *pMana,char sNomBouton[], int nValeurAvancementLevel);
extern int choixBouton(tManaComposant *pMana, int nValeurAvancementLevel);

#endif // LEVEL_H_INCLUDED
