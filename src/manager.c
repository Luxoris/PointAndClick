#include "manager.h"




//###########################################
//PROCEDURE initManaComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un manager de composants.
//
// ENTREE /La reférence du pointeur de pointeur du manager de composants.
//
// SORTIE /La référence du pointeur de composants modifiée, les valeurs du manager de composants à NULL.
//
// NOTE -
//*****************************************************************************************************//
void initManaComposant(tManaComposant **ppManaComposant){
    if((*ppManaComposant = malloc(sizeof(tManaComposant)))==NULL){
        printf("Erreur d'allocation du manager de composants !");
    }else{
        setManaComposant(*ppManaComposant,NULL,NULL,NULL,NULL,NULL,NULL);
    }

}

//###########################################
//PROCEDURE initManaComposantEtComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un manager de composants ainsi que ses composants.
//
// ENTREE /La reférence du pointeur de pointeur du manager de composants..
//
// SORTIE /La référence du pointeur de composants modifiée, les valeurs du manager de composants initialisés.
//
// NOTE -
//*****************************************************************************************************//
void initManaComposantEtComposant(tManaComposant **ppManaComposant){
    if((*ppManaComposant = malloc(sizeof(tManaComposant)))==NULL){
        printf("Erreur d'allocation du manager de composants !");
    }else{
        (*ppManaComposant)->pListeBouton = initialisationListeBouton();
        (*ppManaComposant)->pListeImage = initialisationListeImage();
        (*ppManaComposant)->pListeTexte = initialisationListeTexte();
        (*ppManaComposant)->pListePropTexte = initialisationListePropTexte();
        (*ppManaComposant)->pListeObjet = initialisationListeObjet();
        initPointeur(&(*ppManaComposant)->pPointeur,creePoint(0,0),false,false,false);
        (*ppManaComposant)->pFichierDialogue=NULL;
    }

}

//###########################################
//PROCEDURE vidageComposantsProgramme
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui libères tous les éléments d'un manager de composants,
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La mémoire libérée.
//
// NOTE -
//*****************************************************************************************************//
void vidageComposantsProgramme(tManaComposant *pManaComposant){
    vidageListeBouton(pManaComposant->pListeBouton);
    vidageListeImage(pManaComposant->pListeImage);
    vidageListeTexte(pManaComposant->pListeTexte);
    vidageListeObjet(pManaComposant->pListeObjet);
    vidageListePropTexte(pManaComposant->pListePropTexte);
}

//###########################################
//PROCEDURE freeManaComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui libères tous les éléments d'un manager de composants ainsi que le manager lui-même.
//
// ENTREE /La reférence du pointeur du manager de composants.
//
// SORTIE /La mémoire libérée.
//
// NOTE -
//*****************************************************************************************************//
void freeManaComposant(tManaComposant *pManaComposant){
    if(pManaComposant!=NULL){   //si le pointeur n'est pas null
        //DETRUIT TOUTES LES LISTES SI ELLES EXISTENT
        if(getManaComposantListeBouton(pManaComposant)!=NULL){
            destructionListeBouton(getManaComposantListeBouton(pManaComposant));
        }
        if(getManaComposantListeImage(pManaComposant)!=NULL){
            destructionListeImage(getManaComposantListeImage(pManaComposant));
        }
        if(getManaComposantListeTexte(pManaComposant)!=NULL){
            destructionListeTexte(getManaComposantListeTexte(pManaComposant));
        }
        if(getManaComposantListePropTexte(pManaComposant)!=NULL){
            destructionListePropTexte(getManaComposantListePropTexte(pManaComposant));
        }
        if(getManaComposantListeObjet(pManaComposant)!=NULL){
            destructionListeObjet(getManaComposantListeObjet(pManaComposant));
        }
        if(getManaComposantPointeur(pManaComposant)!=NULL){
            freePointeur(getManaComposantPointeur(pManaComposant));
        }
        //LIBERE LE COMPOSANT
        free(pManaComposant);
    }else{
        printf("Impossible de libérer le manager de composants, la référence est null !");
    }
}


//###########################################
//PROCEDURE setManaComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui mmodifie les valeurs du manageur de composant en fonctions des paramètres.
//
// ENTREE /La reférence du manager de composants, les références des éléments du manager.
//
// SORTIE /Les références des éléments du manager modifiées.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposant(tManaComposant *pManaComposant,tListeBouton *pListeBouton, tListeImage *pListeImage, tListeObjet *pListeObjet, tListeTexte *pListeTexte, tListePropTexte *pListePropTexte, tPointeur *pPointeur){
    setManaComposantListeImage(pManaComposant,pListeImage);
    setManaComposantListeBouton(pManaComposant,pListeBouton);
    setManaComposantListeObjet(pManaComposant,pListeObjet);
    setManaComposantListeTexte(pManaComposant,pListeTexte);
    setManaComposantListePropTexte(pManaComposant,pListePropTexte);
    setManaComposantPointeur(pManaComposant,pPointeur);
}

//###########################################
//PROCEDURE setManaComposantListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence de la Liste de boutons du manageur de composant.
//
// ENTREE /La reférence du manager de composants, la références de la liste de boutons.
//
// SORTIE /La références de la liste de boutons du manager modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposantListeBouton(tManaComposant *pManaComposant,tListeBouton *pListeBouton){
    pManaComposant->pListeBouton=pListeBouton;
}

//###########################################
//PROCEDURE setManaComposantListeImage
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence de la Liste d'Images du manageur de composant.
//
// ENTREE /La reférence du manager de composants, la références de la liste d'Images.
//
// SORTIE /La références de la liste d'Images du manager modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposantListeImage(tManaComposant *pManaComposant,tListeImage *pListeImage){
    pManaComposant->pListeImage=pListeImage;
}

//###########################################
//PROCEDURE setManaComposantListeObjet
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence de la Liste d'Objets du manageur de composant.
//
// ENTREE /La reférence du manager de composants, la références de la liste d'Objets.
//
// SORTIE /La références de la liste d'Objets du manager modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposantListeObjet(tManaComposant *pManaComposant,tListeObjet *pListeObjet){
    pManaComposant->pListeObjet=pListeObjet;
}

//###########################################
//PROCEDURE setManaComposantListeTexte
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence de la Liste de Textes du manageur de composant.
//
// ENTREE /La reférence du manager de composants, la références de la liste de Textes.
//
// SORTIE /La références de la liste de Textes du manager modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposantListeTexte(tManaComposant *pManaComposant,tListeTexte *pListeTexte){
    pManaComposant->pListeTexte=pListeTexte;
}

//###########################################
//PROCEDURE setManaComposantListePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence de la liste de PropTexte du manageur de composant.
//
// ENTREE /La reférence du manager de composants, la références de la liste de PropTexte.
//
// SORTIE /La références de la liste de PropTexte du manager modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposantListePropTexte(tManaComposant *pManaComposant,tListePropTexte *pListePropTexte){
    pManaComposant->pListePropTexte=pListePropTexte;
}

//###########################################
//PROCEDURE setManaComposantPointeur
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence du pointeur (de la souris).
//
// ENTREE /La reférence du manager de composants, la références du pointeur (de la souris).
//
// SORTIE /La références du pointeur (de la souris) du manager modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setManaComposantPointeur(tManaComposant *pManaComposant, tPointeur *pPointeur){
    pManaComposant->pPointeur=pPointeur;
}


//###########################################
//FONCTION getManaComposantListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de la liste de boutons d'un manager de composants.
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La références de la liste de boutons.
//
// NOTE -
//*****************************************************************************************************//
tListeBouton* getManaComposantListeBouton(tManaComposant *pManaComposant){
    return pManaComposant->pListeBouton;
}

//###########################################
//FONCTION getManaComposantListeImage
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de la liste d'Images d'un manager de composants.
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La références de la liste d'Images.
//
// NOTE -
//*****************************************************************************************************//
tListeImage* getManaComposantListeImage(tManaComposant *pManaComposant){
    return pManaComposant->pListeImage;
}

//###########################################
//FONCTION getManaComposantListeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de la liste d'Objets d'un manager de composants.
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La références de la liste d'Objets.
//
// NOTE -
//*****************************************************************************************************//
tListeObjet* getManaComposantListeObjet(tManaComposant *pManaComposant){
    return pManaComposant->pListeObjet;
}

//###########################################
//FONCTION getManaComposantListeTexte
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de la liste de Textes d'un manager de composants.
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La références de la liste de Textes.
//
// NOTE -
//*****************************************************************************************************//
tListeTexte* getManaComposantListeTexte(tManaComposant *pManaComposant){
    return pManaComposant->pListeTexte;
}

//###########################################
//FONCTION getManaComposantListePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de la liste de PropTextes d'un manager de composants.
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La références de la liste de PropTextes.
//
// NOTE -
//*****************************************************************************************************//
tListePropTexte* getManaComposantListePropTexte(tManaComposant *pManaComposant){
    return pManaComposant->pListePropTexte;
}


//###########################################
//FONCTION getManaComposantListePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence du pointeur (de la souris) d'un manager de composants.
//
// ENTREE /La reférence du manager de composants.
//
// SORTIE /La références du pointeur (de la souris).
//
// NOTE -
//*****************************************************************************************************//
tPointeur *getManaComposantPointeur(tManaComposant *pManaComposant){
    return pManaComposant->pPointeur;
}


//###########################################
//PROCEDURE manaAjoutMinute
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoute des minutes à l'horloge du manager de composant.
//
// ENTREE /La référence du manager de comosant, le nombre de minutes à ajouter.
//
// SORTIE /Le temps de l'horloge modifié.
//
// NOTE -
//*****************************************************************************************************//
void manaAjoutMinute(tManaComposant *pMana, const int nMinute){
    ajoutMinute(&pMana->pEtatJeu->stHorloge,nMinute);
}
