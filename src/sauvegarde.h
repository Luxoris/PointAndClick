#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include "stdio.h"
#include "etatPartie.h"
#include "tBool.h"

//DECLARATION DES MACCROS
#define EPMPLACEMENT_SAUVEGARDE_1 "save1.bin"
#define EPMPLACEMENT_SAUVEGARDE_1 "save2.bin"
#define EPMPLACEMENT_SAUVEGARDE_1 "save3.bin"
#define NB_CHOIX_JOUEUR 1
//DEFINTION DU TYPE SAUVEGARDE
typedef struct tSauvegarde{
    tEtatPartie stEtatPartie;
    tBool stTabBool[NB_CHOIX_JOUEUR];
}tSauvegarde;


//DECLARATION DES METHODES
extern void sauvegarder(tSauvegarde stSauvegarde, char cEmplacement[]);
extern void charger(tSauvegarde stSauvegarde, char cEmplacement[]);



#endif // SAUVEGARDE_H_INCLUDED
