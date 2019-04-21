#ifndef DIALOGUE_H_INCLUDED
#define DIALOGUE_H_INCLUDED
#pragma once

#include <stdio.h>
#include "SDL2_texte.h"
#include "manager.h"


//DEFINITION DES MACCROS
#define SEPARATEUR '\n'
#define TAILLE_MAX_LIGNE_DIALOGUE 256
#define EMPL_DIALOGUE_LEVEL1 "./dialogue/level1.txt"
#define EMPL_DIALOGUE_LEREVEIL "./dialogue/leReveil.txt"
#define EMPL_DIALOGUE_LEPETITDEJEUNER "./dialogue/lePetitDejeuner.txt"
#define EMPL_DIALOGUE_LATOILETTE "./dialogue/laToilette.txt"
#define EMPL_DIALOGUE_MOYENLOCOMOTION "./dialogue/moyenDeLocomotion.txt"
#define EMPL_DIALOGUE_PREPARATION "./dialogue/preparation.txt"
#define EMPL_DIALOGUE_LETICKET "./dialogue/leTicket.txt"
#define EMPL_DIALOGUE_ARRRIVEEECOLE "./dialogue/arriveeEcole.txt"
#define EMPL_DIALOGUE_BONNENUIT "./dialogue/bonneNuit.txt"
#define EMPL_DIALOGUE_DEVOIRS "./dialogue/devoirs.txt"
#define EMPL_DIALOGUE_DINER "./dialogue/diner.txt"
#define EMPL_DIALOGUE_SORTIEECOLE "./dialogue/sortieEcole.txt"
#define EMPL_DIALOGUE_SPORT "./dialogue/sport.txt"
#define EMPL_DIALOGUE_TOILETTES "./dialogue/toilettes.txt"
#define EMPL_DIALOGUE_REPASMIDI "./dialogue/repasMidi.txt"
#define EMPL_DIALOGUE_MINI_JEU_REVE "./dialogue/miniJeuReve.txt"
#define EMPL_DIALOGUE_MINI_JEU_PANNEAUX "./dialogue/miniJeuPanneaux.txt"
#define EMPL_DIALOGUE_MINI_JEU_REPAS "./dialogue/miniJeuRepas.txt"
#define EMPL_DIALOGUE_MINI_JEU_GRAMMAIRE "./dialogue/miniJeuGrammaire.txt"
#define EMPL_DIALOGUE_MINI_JEU_JEUXVIDEO "./dialogue/miniJeuJeuxVideo.txt"
#define EMPL_DIALOGUE_MINI_JEU_SECOURISME "./dialogue/miniJeuSecourisme.txt"



//PROTOTYPE DES METHODES
extern void initFichierDialogue(FILE **ppFile,char cEmpl[]);
extern void recuperationChaine(FILE *pFile,char cChaine[]);
extern void texteSuivant(FILE *pFile,tTexte *pTexte);
extern tBool dialogueSuivant(tManaComposant *pMana, int nValeurAvancementLevel);


#endif // DIALOGUE_H_INCLUDED
