#include "tObjet.h"


///METHODES DE LA LISTE D'OBJETS///

//###########################################
//FONCTION initialisationListeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui initialise une liste d'objet.
//
// ENTREE /
//
// SORTIE / La r�f�rence de la liste d'objet
//
// NOTE -
//*****************************************************************************************************//
tListeObjet *initialisationListeObjet(){

    tListeObjet *pListe = malloc(sizeof(tListeObjet));

    if (pListe == NULL){
        printf("\nErreur lors de l'initialisation de la liste d'objet.");
        exit(EXIT_FAILURE);
    }else{
        pListe->nbElements = 0;
        pListe->pPremier = NULL;
    }
    return pListe;
}

//###########################################
//PROCEDURE insertionObjetListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui insert un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment. Prend NULL si insertion au d�but.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'�l�ment objet, la r�f�rence de l'�lement d'insertion, le nom de l'objet.
//
// SORTIE / L'allocation du nouvelle �l�ment, les r�ferences modifi�s.
//
// NOTE -
//*****************************************************************************************************//
void insertionObjetListe(tListeObjet *pListe, tElementObjet *pElementInsetion,const tObjet stObjet,const char sNom[]){
    tElementObjet *pElement = malloc(sizeof(tElementObjet));
    if (pListe == NULL || pElement == NULL) //v�rifie que l'allocation a fonctionn�
    {
        printf("\nErreur lors de l'allocation d'un element de la liste d'objet.");
        exit(EXIT_FAILURE);
    }
    pElement->stObjet = stObjet;    //l'�l�ment re�oit la r�f�rence de l'objet
    strcpy(pElement->sNom,sNom);//ajout du nom de l'�l�ment

    if(pListe->pPremier==NULL){ //si la liste est vide
        pElement->pSuivant = NULL;
        pListe->pPremier = pElement;
    }else{ //SI pElementInsertion = NULL, insert l'�l�ment au d�but de la liste
        if((pElementInsetion == NULL)){
            pElement->pSuivant = pListe->pPremier;
            pListe->pPremier = pElement;
        }else{
            //SINON INSERTION D'UN ELEMENT APRES LA REFERENCE//
            pElement->pSuivant = pElementInsetion ->pSuivant;   //l'�l�ment r�cup�re la r�f�rence de l'�l�ment suivant.
            pElementInsetion->pSuivant = pElement;  //l'�l�ment d'isnertion r�cup�re la r�f�rence du nouvelle �l�ment.
        }

    }

    pListe->nbElements++;   //incr�mentation du nombre d'�l�ment de la liste


}

//###########################################
//PROCEDURE suppressionObjetListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'element a supprimer.
//
// SORTIE / Les r�f�rence de la liste modifi�s, la m�moire lib�r�.
//
// NOTE -  La r�f�rence de l'�l�ment accepte NULL si l'�l�ment a supprimer est le premier.
//*****************************************************************************************************//
void suppressionObjetListe(tListeObjet *pListe, tElementObjet *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste d'objet, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'�l�ment, l'�l�ment vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementObjet *pElement = NULL;
            //Si l'�l�ment a suprimer est le premier de la liste.
            if(pElementSupprimer == pListe->pPremier){

                //pElement r�cup�re la r�f�rence du premier �l�ment de la liste
                pElement = pListe->pPremier;

                //la liste r�cup�re le second �l�ment, et le d�finit comme premier �l�ment
                pListe->pPremier = pListe->pPremier->pSuivant; //la liste r�cup�re la r�f�rence de l'�l�ment suivant

                //lib�re l'�l�ment a supprimer.
                free(pElement);

            }else{

            // SINON parcourt les �l�ments de la liste pour trouver l'�l�ment pr�c�dent a supprimer.

                pElement = pListe->pPremier;

                while ((pElement != NULL) && (pElement->pSuivant != pElementSupprimer)){
                    pElement = pElement->pSuivant;
                }

                //raccorche l'�l�ment pr�c�dent avec le suivant
                pElement->pSuivant = pElementSupprimer->pSuivant;

                free(pElementSupprimer);    //lib�re l'�l�ment a supprimer.
            }

            pListe->nbElements--;       //d�cr�mente le nombre d'�l�ments de la liste
        }else{
            printf("\nErreur lors de la suppression d'un element de la liste d'objet, la liste est vide.");
        }
    }




}

//###########################################
//PROCEDURE vidageListeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime tous les �l�ments de la liste.
//
// ENTREE /La r�f�rence de la la liste.
//
// SORTIE / La m�moire lib�r�.
//
// NOTE -
//*****************************************************************************************************//
void vidageListeObjet(tListeObjet *pListe){
    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur la liste n'existe pas ou est vide.");
        exit(EXIT_FAILURE);
    }

    while(pListe->pPremier!=NULL){
        suppressionObjetListe(pListe,pListe->pPremier);
    }
}
//###########################################
//PROCEDURE destructionListeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime tous les �l�ments de la liste et lib�re la liste.
//
// ENTREE /La r�f�rence de la la liste.
//
// SORTIE / La m�moire lib�r�.
//
// NOTE -
//*****************************************************************************************************//
void destructionListeObjet(tListeObjet *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }else{

        if(pListe->pPremier != NULL){   //si la liste n'est pas vide, la vide.
            vidageListeObjet(pListe);
        }
        free(pListe);   //lib�re la liste
    }

}

//###########################################
//PROCEDURE affichageObjetListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les objets de la liste.
//
// ENTREE / La ref du renderer, la r�f�rence de la la liste.
//
// SORTIE / L'affichage des objets.
//
// NOTE -
//*****************************************************************************************************//
void affichageListeObjet(SDL_Renderer *pRenderer,tListeObjet *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur d'affichage, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    //SI LA LISTE N'EST PAS VIDE AFFICHE LES OBJETS
    if(pListe->pPremier != NULL){
        tElementObjet *pElement = pListe->pPremier;
        while(pElement->pSuivant!=NULL){
            dessineObjet(pRenderer, &pElement->stObjet,false);
            pElement = pElement->pSuivant;
        }
        dessineObjet(pRenderer, &pElement->stObjet,false);    //affiche la derni�re objet
    }
}

//###########################################
//FONCTION recupElementObjetParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui r�cup�re la ref de l'�l�ment qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La ref�rence de l'�m�ent correspondant ou null
//
// NOTE -
//*****************************************************************************************************//
tElementObjet* recupElementObjetParNom(tListeObjet *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }
    tElementObjet *pElement = pListe->pPremier;

    //si le premi�re �l�ment correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe ne revu tous les �l�ments et v�rifie si les noms correspondent
    do{
        pElement = pElement->pSuivant;  //on r�cup�re l'�l�ment suivant
        //si le nom correspond
        if(strcmp(sNom,pElement->sNom)==0){
            return pElement;
        }
    }while(pElement->pSuivant!=NULL);   //tant qu'il existe un �l�ment suivant

    printf("\nLe nom %s,ne correspond a aucun element.",sNom);
    return NULL;




}


//###########################################
//FONCTION recupObjetParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui r�cup�re la ref de l'objet qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La r�f�rence de l'objet correspondant ou null.
//
// NOTE -
//*****************************************************************************************************//
tObjet* recupObjetParNom(tListeObjet *pListe,const char sNom[]){
    tElementObjet *pElement = recupElementObjetParNom(pListe,sNom);
    if(pElement==NULL){
        return NULL;
    }else{
        return &(pElement->stObjet);
    }
}




//###########################################
//PROCEDURE initObjet
//*****************************************************************************************************//
//
// DESCRIPTION Initialise et renseigne un objet � partir d'un rectangle, d'un vecteur vitesse et d'un vecteur acceleration;
//
// ENTREE Le pointeur de pointeur d'objet, Le rectangle, le vecteur vitesse, le vecteur acceleration.
//
// SORTIE l'objet allou�, et le la r�f�rence de l'objet assign�e.
//
// NOTE -
//*****************************************************************************************************//
void initObjet(tObjet **ppObjet, const tRectangle stRectangle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration){
    if((*ppObjet = malloc(sizeof(tObjet)))==NULL){
        printf("\nErreur d'allocation de l'objet !");
    }else{
        setObjetRectangle(*ppObjet,stRectangle);
        setObjetVecteurVitesse(*ppObjet,stVecteurVitesse);
        setObjetVecteurAcceleration(*ppObjet,stVecteurAcceleration);
    }
}

//###########################################
//PROCEDURE freeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Lib�re l'objet de la m�moire.
//
// ENTREE Le pointeur de l'objet.
//
// SORTIE -
//
// NOTE -
//*****************************************************************************************************//
void freeObjet(tObjet *pstObjet){
    free(pstObjet);
}

//###########################################
//FONCTION creeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie une objet � partir d'un rectangle, d'un vecteur vitesse et d'un vecteur acceleration;
//
// ENTREE Le rectangle, le vecteur vitesse, le vecteur acceleration.
//
// SORTIE l'objet
//
// NOTE -
//*****************************************************************************************************//
tObjet creeObjet(const tRectangle stRectangle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration){
    tObjet stObjet;
    setObjetRectangle(&stObjet,stRectangle);
    setObjetVecteurVitesse(&stObjet,stVecteurVitesse);
    setObjetVecteurAcceleration(&stObjet,stVecteurAcceleration);

    return stObjet;
}
//###########################################
//FONCTION getObjetRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le rectangle d'un type objet
//
// ENTREE La ref de l'objet
//
// SORTIE La ref du rectangle
//
// NOTE -
//*****************************************************************************************************//
tRectangle* getObjetRectangle(tObjet *pstObjet){
    return &pstObjet->stRectangle;
}
//###########################################
//FONCTION getObjetVecteurVitesse
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le VecteurVitesse d'un type objet
//
// ENTREE La ref de l'objet
//
// SORTIE La ref du VecteurVitesse
//
// NOTE -
//*****************************************************************************************************//
tVecteur* getObjetVecteurVitesse(tObjet *pstObjet){
    return &pstObjet->stVecteurVitesse;
}
//###########################################
//FONCTION getObjetVecteurAcceleration
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le VecteurAcceleration d'un type objet
//
// ENTREE La ref de l'objet
//
// SORTIE La ref du VecteurAcceleration
//
// NOTE -
//*****************************************************************************************************//
tVecteur* getObjetVecteurAcceleration(tObjet *pstObjet){
    return &pstObjet->stVecteurAcceleration;
}
//###########################################
//PROCEDURE setObjetRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le rectangle d'un type balle
//
// ENTREE La ref de la balle, le rectangle
//
// SORTIE Le rectangle de l'objet modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setObjetRectangle(tObjet *pstObjet, const tRectangle stRectangle){
    pstObjet->stRectangle=stRectangle;
}
//###########################################
//PROCEDURE setObjetVecteurVitesse
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le vecteur vitesse d'un type balle
//
// ENTREE La ref de le vecteur vitesse, le cercle
//
// SORTIE Le vecteur vitesse de l'objet modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setObjetVecteurVitesse(tObjet *pstObjet, const tVecteur stVecteurVitesse){
    pstObjet->stVecteurVitesse=stVecteurVitesse;
}

//###########################################
//PROCEDURE setObjetVecteurAcceleration
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le vecteur acceleration d'un type balle
//
// ENTREE La ref de le vecteur acceleration, le cercle
//
// SORTIE Le vecteur acceleration de l'objet modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setObjetVecteurAcceleration(tObjet *pstObjet, const tVecteur stVecteurAcceleration){
    pstObjet->stVecteurAcceleration=stVecteurAcceleration;
}

//###########################################
//PROCEDURE deplacementObjet
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonn�es de l'objet en fonction du vecteur vitesse, et du nombre de FPS
//
// ENTREE La ref de l'objet, le nombre de FPS
//
// SORTIE Les coordonn�es de l'objet
//
// NOTE -
//*****************************************************************************************************//
void deplacementObjet(tObjet *pstObjet, const float fFPS){
    tRectangle stRectangle = *getObjetRectangle(pstObjet);
    tVecteur stVecteurDeplacement;
    multiplicationVectorielleScalaire(*getObjetVecteurVitesse(pstObjet),(1/(fFPS)),&stVecteurDeplacement);

    deplacementRectangle(&stRectangle,stVecteurDeplacement);
    setObjetRectangle(pstObjet,stRectangle);
}

//###########################################
//PROCEDURE modificationVitesseObjet
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la vitesse de l'objet en fonction de l'acc�l�ration.
//
// ENTREE La ref de l'objet
//
// SORTIE Le vecteur vitesse modifi� de l'objet
//
// NOTE -   On additionne le vecteur vitesse au vecteur l'acc�l�ration.
//*****************************************************************************************************//
void modificationVitesseObjet(tObjet *pstObjet){
    tVecteur stVecteurVitesse;
    additionVectorielle(*getObjetVecteurVitesse(pstObjet),*getObjetVecteurAcceleration(pstObjet),&stVecteurVitesse);

    setObjetVecteurVitesse(pstObjet,stVecteurVitesse);
}

//###########################################
//PROCEDURE modificationAccelerationObjet
//*****************************************************************************************************//
//
// DESCRIPTION Modifie l'accceleration de l'objet en fonction du vecteur frottement.
//
// ENTREE La ref de l'objet, le vecteur frottement
//
// SORTIE Le vecteur acceleration modifi�
//
// NOTE -   On additionne le vecteur acceleration au vecteur frottement
//*****************************************************************************************************//
void modificationAccelerationObjet(tObjet *pstObjet, tVecteur stFrottement){
    tVecteur stVecteurAcceleration;
    additionVectorielle(*getObjetVecteurAcceleration(pstObjet),stFrottement,&stVecteurAcceleration);

    setObjetVecteurAcceleration(pstObjet,stVecteurAcceleration);
}

//###########################################
//PROCEDURE mouvementObjet
//*****************************************************************************************************//
//
// DESCRIPTION calcul le mouvement de l'objet � partire de son point d'origine, de sa vitesse et de son acc�l�ration
//
// ENTREE La ref de l'objet, le nb de FPS
//
// SORTIE Les coordonn�es de l'objet
//
// NOTE -
//*****************************************************************************************************//
void mouvementObjet(tObjet *pstObjet, const float fFPS){
    tVecteur stVecteurAcceleration = *getObjetVecteurAcceleration(pstObjet);
    if(fFPS>=1){ //si le nombre de fps est sup�rieur ou �gale � 1, �vite un d�placement tr�s rapide en cas de ralentissement. Si le nombre de fps est inf�rieur � 1, les d�placments ne se feront pas � cette frame.
        deplacementObjet(pstObjet,fFPS);
        modificationVitesseObjet(pstObjet);
        modificationAccelerationObjet(pstObjet,creeVecteur(-getVecteurX(&stVecteurAcceleration),-getVecteurY(&stVecteurAcceleration)));
    }
}

//###########################################
//PROCEDURE gestionCollisionObjetBords
//*****************************************************************************************************//
//
// DESCRIPTION modifie les coordonn�es de l'objet si elle est en collision avec un des bords.
//
// ENTREE La ref de l'objet, la coor en Y du bord bas, la coor en Y du bord haut
//
// SORTIE Les coordonn�es de l'objet modifi� si besoin
//
// NOTE -
//*****************************************************************************************************//
void gestionCollisionObjetBords(tObjet *pstObjet, const float fCoorYBordBas, const float fCoorYBordHaut){
    tRectangle stRectangleObjet = *getObjetRectangle(pstObjet);
    tPoint stPointObjet= *getRectanglePointCentral(&stRectangleObjet);

    if(collisionRectangleBordBas(&stRectangleObjet,fCoorYBordBas)){
        setPointY(&stPointObjet,fCoorYBordBas-getRectangleHauteur(&stRectangleObjet)*0.5);
        setRectanglePointCentral(&stRectangleObjet,stPointObjet);
        setObjetRectangle(pstObjet,stRectangleObjet);
    }
    if(collisionRectangleBordHaut(&stRectangleObjet,fCoorYBordHaut)){
        setPointY(&stPointObjet,fCoorYBordHaut+getRectangleHauteur(&stRectangleObjet)*0.5);
        setRectanglePointCentral(&stRectangleObjet,stPointObjet);
        setObjetRectangle(pstObjet,stRectangleObjet);
    }
}

//###########################################
//PROCEDURE dessineObjet
//*****************************************************************************************************//
//
// DESCRIPTION Dessine un objet, un booleen indique si l'objet est pleine ou vide.
//
// ENTREE La r�f�rence du renderer, de l'objet, le booleen
//
// SORTIE L'affichage de l'objet
//
// NOTE -
//*****************************************************************************************************//
void dessineObjet(SDL_Renderer *pRenderer,tObjet *pstObjet,tBool bRectanglePlein){
    tRectangle stRectangle = *getObjetRectangle(pstObjet);
    dessineRectangle(pRenderer,&stRectangle,bRectanglePlein);

}
