#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES//
#include "bouton.h"
#include "image.h"

//DECLARATION DU TYPE STRUCTURE//

typedef struct tManaComposant{
    tListeBouton *pListeBouton;
    tListeImage *pListeImage;
    tListeObjet *pListeObjet;
    tListeTexte *pListeTexte;
    tListePropTexte *pListePropTexte;

}tManaComposant;


//PROTOTYPE DES METHODES
extern void initManaComposant(tManaComposant **ppManaComposant);
extern void initManaComposantEtComposant(tManaComposant **ppManaComposant);
extern void freeManaComposant(tManaComposant *pManaComposant);

extern void setManaComposant(tManaComposant *pManaComposant,tListeBouton *pListeBouton, tListeImage *pListeImage, tListeObjet *pListeObjet, tListeTexte *pListeTexte, tListePropTexte *pListePropTexte);
extern void setManaComposantListeBouton(tManaComposant *pManaComposant,tListeBouton *pListeBouton);
extern void setManaComposantListeImage(tManaComposant *pManaComposant,tListeImage *pListeImage);
extern void setManaComposantListeObjet(tManaComposant *pManaComposant,tListeObjet *pListeObjet);
extern void setManaComposantListeTexte(tManaComposant *pManaComposant,tListeTexte *pListeTexte);
extern void setManaComposantListePropTexte(tManaComposant *pManaComposant,tListePropTexte *pListePropTexte);

extern tListeBouton *getManaComposantListeBouton(tManaComposant *pManaComposant);
extern tListeImage *getManaComposantListeImage(tManaComposant *pManaComposant);
extern tListeObjet *getManaComposantListeObjet(tManaComposant *pManaComposant);
extern tListeTexte *getManaComposantListeTexte(tManaComposant *pManaComposant);
extern tListePropTexte *getManaComposantListePropTexte(tManaComposant *pManaComposant);


#endif // MANAGER_H_INCLUDED
