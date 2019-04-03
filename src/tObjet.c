#include "tObjet.h"


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
        printf("Erreur d'allocation de l'objet !");
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

