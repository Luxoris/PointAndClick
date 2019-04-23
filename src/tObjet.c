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
// SORTIE / La référence de la liste d'objet
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
// DESCRIPTION Procedure qui insert un élément dans la liste, après la référence de l'élément. Prend NULL si insertion au début.
//
// ENTREE /La référence de la la liste, la ref de l'élément objet, la référence de l'élement d'insertion, le nom de l'objet.
//
// SORTIE / L'allocation du nouvelle élément, les réferences modifiés.
//
// NOTE -
//*****************************************************************************************************//
void insertionObjetListe(tListeObjet *pListe, tElementObjet *pElementInsetion,const tObjet stObjet,const char sNom[]){
    tElementObjet *pElement = malloc(sizeof(tElementObjet));
    if (pListe == NULL || pElement == NULL) //vérifie que l'allocation a fonctionné
    {
        printf("\nErreur lors de l'allocation d'un element de la liste d'objet.");
        exit(EXIT_FAILURE);
    }
    pElement->stObjet = stObjet;    //l'élément reçoit la référence de l'objet
    strcpy(pElement->sNom,sNom);//ajout du nom de l'élément

    if(pListe->pPremier==NULL){ //si la liste est vide
        pElement->pSuivant = NULL;
        pListe->pPremier = pElement;
    }else{ //SI pElementInsertion = NULL, insert l'élément au début de la liste
        if((pElementInsetion == NULL)){
            pElement->pSuivant = pListe->pPremier;
            pListe->pPremier = pElement;
        }else{
            //SINON INSERTION D'UN ELEMENT APRES LA REFERENCE//
            pElement->pSuivant = pElementInsetion ->pSuivant;   //l'élément récupère la référence de l'élément suivant.
            pElementInsetion->pSuivant = pElement;  //l'élément d'isnertion récupère la référence du nouvelle élément.
        }

    }

    pListe->nbElements++;   //incrémentation du nombre d'élément de la liste


}

//###########################################
//PROCEDURE suppressionObjetListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime un élément dans la liste, après la référence de l'élément.
//
// ENTREE /La référence de la la liste, la ref de l'element a supprimer.
//
// SORTIE / Les référence de la liste modifiés, la mémoire libéré.
//
// NOTE -  La référence de l'élément accepte NULL si l'élément a supprimer est le premier.
//*****************************************************************************************************//
void suppressionObjetListe(tListeObjet *pListe, tElementObjet *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste d'objet, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'élément, l'élément vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementObjet *pElement = NULL;
            //Si l'élément a suprimer est le premier de la liste.
            if(pElementSupprimer == pListe->pPremier){

                //pElement récupère la référence du premier élément de la liste
                pElement = pListe->pPremier;

                //la liste récupère le second élément, et le définit comme premier élément
                pListe->pPremier = pListe->pPremier->pSuivant; //la liste récupère la référence de l'élément suivant

                //libère l'élément a supprimer.
                free(pElement);

            }else{

            // SINON parcourt les éléments de la liste pour trouver l'élément précédent a supprimer.

                pElement = pListe->pPremier;

                while ((pElement != NULL) && (pElement->pSuivant != pElementSupprimer)){
                    pElement = pElement->pSuivant;
                }

                //raccorche l'élément précédent avec le suivant
                pElement->pSuivant = pElementSupprimer->pSuivant;

                free(pElementSupprimer);    //libère l'élément a supprimer.
            }

            pListe->nbElements--;       //décrémente le nombre d'éléments de la liste
        }else{
            printf("\nErreur lors de la suppression d'un element de la liste d'objet, la liste est vide.");
        }
    }




}

//###########################################
//PROCEDURE vidageListeObjet
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime tous les éléments de la liste.
//
// ENTREE /La référence de la la liste.
//
// SORTIE / La mémoire libéré.
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
// DESCRIPTION Procedure qui supprime tous les éléments de la liste et libère la liste.
//
// ENTREE /La référence de la la liste.
//
// SORTIE / La mémoire libéré.
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
        free(pListe);   //libère la liste
    }

}

//###########################################
//PROCEDURE affichageObjetListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les objets de la liste.
//
// ENTREE / La ref du renderer, la référence de la la liste.
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
        dessineObjet(pRenderer, &pElement->stObjet,false);    //affiche la dernière objet
    }
}

//###########################################
//FONCTION recupElementObjetParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de l'élément qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La reférence de l'éméent correspondant ou null
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

    //si le première élément correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe ne revu tous les éléments et vérifie si les noms correspondent
    do{
        pElement = pElement->pSuivant;  //on récupère l'élément suivant
        //si le nom correspond
        if(strcmp(sNom,pElement->sNom)==0){
            return pElement;
        }
    }while(pElement->pSuivant!=NULL);   //tant qu'il existe un élément suivant

    printf("\nLe nom %s,ne correspond a aucun element.",sNom);
    return NULL;




}


//###########################################
//FONCTION recupObjetParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de l'objet qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La référence de l'objet correspondant ou null.
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
// DESCRIPTION Initialise et renseigne un objet à partir d'un rectangle, d'un vecteur vitesse et d'un vecteur acceleration;
//
// ENTREE Le pointeur de pointeur d'objet, Le rectangle, le vecteur vitesse, le vecteur acceleration.
//
// SORTIE l'objet alloué, et le la référence de l'objet assignée.
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
// DESCRIPTION Libère l'objet de la mémoire.
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
// DESCRIPTION Renvoie une objet à partir d'un rectangle, d'un vecteur vitesse et d'un vecteur acceleration;
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
// SORTIE Le rectangle de l'objet modifiée
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
// SORTIE Le vecteur vitesse de l'objet modifiée
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
// SORTIE Le vecteur acceleration de l'objet modifiée
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
// DESCRIPTION Modifie les coordonnées de l'objet en fonction du vecteur vitesse, et du nombre de FPS
//
// ENTREE La ref de l'objet, le nombre de FPS
//
// SORTIE Les coordonnées de l'objet
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
// DESCRIPTION Modifie la vitesse de l'objet en fonction de l'accélération.
//
// ENTREE La ref de l'objet
//
// SORTIE Le vecteur vitesse modifié de l'objet
//
// NOTE -   On additionne le vecteur vitesse au vecteur l'accélération.
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
// SORTIE Le vecteur acceleration modifié
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
// DESCRIPTION calcul le mouvement de l'objet à partire de son point d'origine, de sa vitesse et de son accélération
//
// ENTREE La ref de l'objet, le nb de FPS
//
// SORTIE Les coordonnées de l'objet
//
// NOTE -
//*****************************************************************************************************//
void mouvementObjet(tObjet *pstObjet, const float fFPS){
    tVecteur stVecteurAcceleration = *getObjetVecteurAcceleration(pstObjet);
    if(fFPS>=1){ //si le nombre de fps est supérieur ou égale à 1, évite un déplacement très rapide en cas de ralentissement. Si le nombre de fps est inférieur à 1, les déplacments ne se feront pas à cette frame.
        deplacementObjet(pstObjet,fFPS);
        modificationVitesseObjet(pstObjet);
        modificationAccelerationObjet(pstObjet,creeVecteur(-getVecteurX(&stVecteurAcceleration),-getVecteurY(&stVecteurAcceleration)));
    }
}

//###########################################
//PROCEDURE gestionCollisionObjetBords
//*****************************************************************************************************//
//
// DESCRIPTION modifie les coordonnées de l'objet si elle est en collision avec un des bords.
//
// ENTREE La ref de l'objet, la coor en Y du bord bas, la coor en Y du bord haut
//
// SORTIE Les coordonnées de l'objet modifié si besoin
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
// ENTREE La référence du renderer, de l'objet, le booleen
//
// SORTIE L'affichage de l'objet
//
// NOTE -
//*****************************************************************************************************//
void dessineObjet(SDL_Renderer *pRenderer,tObjet *pstObjet,tBool bRectanglePlein){
    tRectangle stRectangle = *getObjetRectangle(pstObjet);
    dessineRectangle(pRenderer,&stRectangle,bRectanglePlein);

}
