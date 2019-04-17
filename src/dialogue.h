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


//PROTOTYPE DES METHODES
extern void initFichierDialogue(FILE **ppFile,char cEmpl[]);
extern void recuperationChaine(FILE *pFile,char cChaine[]);
extern void texteSuivant(FILE *pFile,tTexte *pTexte);
extern tBool dialogueSuivant(tManaComposant *pMana, int nValeurAvancementLevel);


#endif // DIALOGUE_H_INCLUDED
