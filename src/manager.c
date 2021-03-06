#include "manager.h"




//###########################################
//PROCEDURE initManaComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un manager de composants.
//
// ENTREE /La ref�rence du pointeur de pointeur du manager de composants.
//
// SORTIE /La r�f�rence du pointeur de composants modifi�e, les valeurs du manager de composants � NULL.
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
// ENTREE /La ref�rence du pointeur de pointeur du manager de composants..
//
// SORTIE /La r�f�rence du pointeur de composants modifi�e, les valeurs du manager de composants initialis�s.
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
// DESCRIPTION PROCEDURE qui lib�res tous les �l�ments d'un manager de composants,
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La m�moire lib�r�e.
//
// NOTE -
//*****************************************************************************************************//
void vidageComposantsProgramme(tManaComposant *pManaComposant){
    vidageListeBouton(pManaComposant->pListeBouton);
    vidageListeImage(pManaComposant->pListeImage);
    vidageListeTexte(pManaComposant->pListeTexte);
    vidageListeObjet(pManaComposant->pListeObjet);
    vidageListePropTexte(pManaComposant->pListePropTexte);
    pManaComposant->pFichierDialogue = NULL;
    pManaComposant->pImageDragAndDrop = NULL;
}

//###########################################
//PROCEDURE freeManaComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui lib�res tous les �l�ments d'un manager de composants ainsi que le manager lui-m�me.
//
// ENTREE /La ref�rence du pointeur du manager de composants.
//
// SORTIE /La m�moire lib�r�e.
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
        pManaComposant->pFichierDialogue = NULL;
        pManaComposant->pImageDragAndDrop = NULL;
        //LIBERE LE COMPOSANT
        free(pManaComposant);
    }else{
        printf("Impossible de lib�rer le manager de composants, la r�f�rence est null !");
    }
}


//###########################################
//PROCEDURE setManaComposant
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui mmodifie les valeurs du manageur de composant en fonctions des param�tres.
//
// ENTREE /La ref�rence du manager de composants, les r�f�rences des �l�ments du manager.
//
// SORTIE /Les r�f�rences des �l�ments du manager modifi�es.
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
    pManaComposant->pImageDragAndDrop = NULL;
}

//###########################################
//PROCEDURE setManaComposantListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la r�f�rence de la Liste de boutons du manageur de composant.
//
// ENTREE /La ref�rence du manager de composants, la r�f�rences de la liste de boutons.
//
// SORTIE /La r�f�rences de la liste de boutons du manager modifi�e.
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
// DESCRIPTION PROCEDURE qui modifie la r�f�rence de la Liste d'Images du manageur de composant.
//
// ENTREE /La ref�rence du manager de composants, la r�f�rences de la liste d'Images.
//
// SORTIE /La r�f�rences de la liste d'Images du manager modifi�e.
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
// DESCRIPTION PROCEDURE qui modifie la r�f�rence de la Liste d'Objets du manageur de composant.
//
// ENTREE /La ref�rence du manager de composants, la r�f�rences de la liste d'Objets.
//
// SORTIE /La r�f�rences de la liste d'Objets du manager modifi�e.
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
// DESCRIPTION PROCEDURE qui modifie la r�f�rence de la Liste de Textes du manageur de composant.
//
// ENTREE /La ref�rence du manager de composants, la r�f�rences de la liste de Textes.
//
// SORTIE /La r�f�rences de la liste de Textes du manager modifi�e.
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
// DESCRIPTION PROCEDURE qui modifie la r�f�rence de la liste de PropTexte du manageur de composant.
//
// ENTREE /La ref�rence du manager de composants, la r�f�rences de la liste de PropTexte.
//
// SORTIE /La r�f�rences de la liste de PropTexte du manager modifi�e.
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
// DESCRIPTION PROCEDURE qui modifie la r�f�rence du pointeur (de la souris).
//
// ENTREE /La ref�rence du manager de composants, la r�f�rences du pointeur (de la souris).
//
// SORTIE /La r�f�rences du pointeur (de la souris) du manager modifi�e.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de la liste de boutons d'un manager de composants.
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La r�f�rences de la liste de boutons.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de la liste d'Images d'un manager de composants.
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La r�f�rences de la liste d'Images.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de la liste d'Objets d'un manager de composants.
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La r�f�rences de la liste d'Objets.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de la liste de Textes d'un manager de composants.
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La r�f�rences de la liste de Textes.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de la liste de PropTextes d'un manager de composants.
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La r�f�rences de la liste de PropTextes.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence du pointeur (de la souris) d'un manager de composants.
//
// ENTREE /La ref�rence du manager de composants.
//
// SORTIE /La r�f�rences du pointeur (de la souris).
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
// DESCRIPTION Procedure qui ajoute des minutes � l'horloge du manager de composant.
//
// ENTREE /La r�f�rence du manager de comosant, le nombre de minutes � ajouter.
//
// SORTIE /Le temps de l'horloge modifi�.
//
// NOTE -
//*****************************************************************************************************//
void manaAjoutMinute(tManaComposant *pMana, const int nMinute){
    ajoutMinute(&pMana->pEtatJeu->stHorloge,nMinute);
}

//###########################################
//PROCEDURE manaAjoutMinute
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui d�place l'image en fonction de la position de la souris.
//
// ENTREE /La r�f�rence du manager de comosant.
//
// SORTIE /La position de l'image modifi�e.
//
// NOTE -
//*****************************************************************************************************//
void manaGestionDragAndDrop(tManaComposant *pMana){
    if(pMana->pImageDragAndDrop!=NULL){
        if(pMana->pPointeur->stCliqueGauche){
            setRectanglePointCentral(getObjetRectangle(getImageObjet(pMana->pImageDragAndDrop)),*getPointeurPosition(pMana->pPointeur));
            deplacementRectangle(getObjetRectangle(getImageObjet(pMana->pImageDragAndDrop)),*getObjetVecteurVitesse(getImageObjet(pMana->pImageDragAndDrop)));
        }else{
            pMana->pImageDragAndDrop=NULL;
        }
    }

}

//###########################################
//PROCEDURE ajoutGestionDragAndDrop
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui initialise le drag and drop d'une image.
//
// ENTREE /La r�f�rence du manager de comosant, la r�f�rence de l'image
//
// SORTIE /La r�f�rnce de l'image stock�e dans le ImageDrangAndDrop du manager de composants.
//
// NOTE -
//*****************************************************************************************************//
void ajoutGestionDragAndDrop(tManaComposant *pMana, tImage *pImage,char sNom[]){
    tVecteur stVecteur;
    if(pMana->pImageDragAndDrop==NULL){
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(getImageObjet(pImage)))){
            setVecteurX(&stVecteur,-getPointX(getPointeurPosition(pMana->pPointeur))+getPointX(getRectanglePointCentral(getObjetRectangle(getImageObjet(pImage)))));
            setVecteurY(&stVecteur,-getPointY(getPointeurPosition(pMana->pPointeur))+getPointY(getRectanglePointCentral(getObjetRectangle(getImageObjet(pImage)))));
            pImage->pstObjet->stVecteurVitesse = stVecteur;


            if(strcmp(sNom,"")!=0){
                if(pMana->pListeImage->pPremier != NULL){
                    tElementImage *pElement = pMana->pListeImage->pPremier;
                    while(pElement->pSuivant!=NULL){
                        pElement = pElement->pSuivant;
                    }
                    if(&pElement->stImage!=pImage){ //si l'image n'est pas le dernier �l�ment.
                        tImage SauvegardImage;
                        setImage(&SauvegardImage,pImage->pstObjet,pImage->sEmplImage);
                        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,sNom));
                        insertionImageListe(pMana->pListeImage,pElement,SauvegardImage,sNom);
                        pMana->pImageDragAndDrop=recupImageParNom(pMana->pListeImage,sNom);
                    }else{
                         pMana->pImageDragAndDrop=pImage;
                    }
                }
            }else{
                pMana->pImageDragAndDrop=pImage;
            }


        }
    }

}
