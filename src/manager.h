#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES//
#include "bouton.h"
#include "image.h"
#include "horloge.h"

//DECLARATION DES MACROS
#define NB_CHOIX_JOUEUR 1
#define TAILLE_NOM_FICHIER_SAUVEGARDE_MAX 30
#define EMPL_FICHIER_SAUVEGARDE_1 "./save/save1.b"
#define EMPL_FICHIER_SAUVEGARDE_2 "./save/save2.b"
#define EMPL_FICHIER_SAUVEGARDE_3 "./save/save3.b"

//DECLARATION DU TYPE STRUCTURE//
typedef struct tEtatJeu{
    int nNumLevel;
    int nAvancementLevel;
    tHorloge stHorloge;
    tHorloge stHorlogeSauvegarde;
    char cEmplFichierSauvegarde[TAILLE_NOM_FICHIER_SAUVEGARDE_MAX];
}tEtatJeu;

typedef struct tManaComposant{
    tListeBouton *pListeBouton;
    tListeImage *pListeImage;
    tListeObjet *pListeObjet;
    tListeTexte *pListeTexte;
    tListePropTexte *pListePropTexte;
    tPointeur *pPointeur;
    tEtatJeu *pEtatJeu;
    FILE *pFichierDialogue;
    tImage *pImageDragAndDrop;
}tManaComposant;


//PROTOTYPE DES METHODES
extern void initManaComposant(tManaComposant **ppManaComposant);
extern void initManaComposantEtComposant(tManaComposant **ppManaComposant);
extern void vidageComposantsProgramme(tManaComposant *pManaComposant);
extern void freeManaComposant(tManaComposant *pManaComposant);

extern void setManaComposant(tManaComposant *pManaComposant,tListeBouton *pListeBouton, tListeImage *pListeImage, tListeObjet *pListeObjet, tListeTexte *pListeTexte, tListePropTexte *pListePropTexte, tPointeur *pPointeur);
extern void setManaComposantListeBouton(tManaComposant *pManaComposant,tListeBouton *pListeBouton);
extern void setManaComposantListeImage(tManaComposant *pManaComposant,tListeImage *pListeImage);
extern void setManaComposantListeObjet(tManaComposant *pManaComposant,tListeObjet *pListeObjet);
extern void setManaComposantListeTexte(tManaComposant *pManaComposant,tListeTexte *pListeTexte);
extern void setManaComposantListePropTexte(tManaComposant *pManaComposant,tListePropTexte *pListePropTexte);
extern void setManaComposantPointeur(tManaComposant *pManaComposant, tPointeur *pPointeur);

extern tListeBouton *getManaComposantListeBouton(tManaComposant *pManaComposant);
extern tListeImage *getManaComposantListeImage(tManaComposant *pManaComposant);
extern tListeObjet *getManaComposantListeObjet(tManaComposant *pManaComposant);
extern tListeTexte *getManaComposantListeTexte(tManaComposant *pManaComposant);
extern tListePropTexte *getManaComposantListePropTexte(tManaComposant *pManaComposant);
extern tPointeur *getManaComposantPointeur(tManaComposant *pManaComposant);

extern void manaAjoutMinute(tManaComposant *pMana, const int nMinute);
extern void manaGestionDragAndDrop(tManaComposant *pMana);
extern void ajoutGestionDragAndDrop(tManaComposant *pMana, tImage *pImage,char sNom[]);


#endif // MANAGER_H_INCLUDED
