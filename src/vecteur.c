#include "vecteur.h"

//###########################################
//FONCTION creeVecteur
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui crée un élément de type tVecteur à partir de ses coordonnées
//
// ENTREE La valeur en X et en Y du Vecteur.
//
// SORTIE Le nouveau Vecteur
//
// NOTE -
//*****************************************************************************************************//
tVecteur creeVecteur(const float fX,const float fY){
    tVecteur stVecteur;
    setVecteurX(&stVecteur,fX);
    setVecteurY(&stVecteur,fY);

    return stVecteur;
}

//###########################################
//FONCTION getVecteurX
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui retourne la valeur en X du Vecteur
//
// ENTREE La référence du Vecteur
//
// SORTIE La valeur fX
//
// NOTE -
//*****************************************************************************************************//
float getVecteurX(tVecteur *pstVecteur){
    return pstVecteur->fX;
}


//###########################################
//FONCTION getVecteurY
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui retourne la valeur en Y du Vecteur
//
// ENTREE La référence du Vecteur
//
// SORTIE La valeur fY
//
// NOTE -
//*****************************************************************************************************//
float getVecteurY(tVecteur *pstVecteur){
    return pstVecteur->fY;
}

//###########################################
//PROCEDURE setVecteurX
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui change la valeur fX d'un type Vecteur
//
// ENTREE La référence du Vecteur, la valeur fX
//
// SORTIE La valeur modifié dans le Vecteur
//
// NOTE -
//*****************************************************************************************************//
void setVecteurX(tVecteur *pstVecteur,const float fX){
    pstVecteur->fX = fX;
}

//###########################################
//PROCEDURE setVecteurY
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui change la valeur fY d'un type Vecteur
//
// ENTREE La référence du Vecteur, la valeur fY
//
// SORTIE La valeur modifié dans le Vecteur
//
// NOTE -
//*****************************************************************************************************//
void setVecteurY(tVecteur *pstVecteur,const float fY){
    pstVecteur->fY = fY;
}







//###########################################
//PROCEDURE additionVectorielle
//*****************************************************************************************************//
//
// DESCRIPTION Additionne deux vecteurs et sort le resultat en argument
//
// ENTREE / Les ref des 2 vecteurs, la ref du vecteur résultat.
//
// SORTIE / La valeur obtenue à la fin
//
// NOTE On aditionne Selon X3 = X1 + X2 et Y3 = Y1 + Y2
//
//*****************************************************************************************************//
void additionVectorielle(tVecteur stVecteur1,tVecteur stVecteur2,tVecteur *pstResultat){
    setVecteurX(pstResultat,getVecteurX(&stVecteur1)+getVecteurX(&stVecteur2));
    setVecteurY(pstResultat,getVecteurY(&stVecteur1)+getVecteurY(&stVecteur2));
}

//###########################################
//PROCEDURE soustractionVectorielle
//*****************************************************************************************************//
//
// DESCRIPTION Soustrait le second vecteur au premier et sort le resultat en argument
//
// ENTREE / Les refs des 2 vecteurs, la ref du vecteur résultat.
//
// SORTIE / La valeur obtenue à la fin
//
// NOTE On aditionne Selon X3 = X1 - X2 et Y3 = Y1 - Y2
//
//*****************************************************************************************************//
void soustractionVectorielle(tVecteur stVecteur1,tVecteur stVecteur2,tVecteur *pstResultat){
    setVecteurX(pstResultat,getVecteurX(&stVecteur1)-getVecteurX(&stVecteur2));
    setVecteurY(pstResultat,getVecteurY(&stVecteur1)-getVecteurY(&stVecteur2));
}

//###########################################
//PROCEDURE multiplicationVectorielleScalaire
//*****************************************************************************************************//
//
// DESCRIPTION Multplie le vecteur par un scalaire et sort le resultat en argument
//
// ENTREE / La ref du vecteur, le scalaire, la ref du vecteur résultat.
//
// SORTIE / La valeur obtenue à la fin
//
// NOTE On aditionne Selon X2 = X1 * nScalaire et Y2 = Y1 * nScalaire
//
//*****************************************************************************************************//
void multiplicationVectorielleScalaire(tVecteur stVecteur1,const float fScalaire,tVecteur *pstResultat){
    setVecteurX(pstResultat,getVecteurX(&stVecteur1)* fScalaire);
    setVecteurY(pstResultat,getVecteurY(&stVecteur1)* fScalaire);
}

//###########################################
//PROCEDURE produitScalaire
//*****************************************************************************************************//
//
// DESCRIPTION Calcul le produit scalaire de deux vecteurs et ressort la valeur
//
// ENTREE / Les ref des 2 vecteurs, la ref du resultat
//
// SORTIE / La valeur obtenue à la fin
//
// NOTE Calcul nResultat = X1*X2 + Y1*Y2
//
//*****************************************************************************************************//
void produitScalaire(tVecteur stVecteur1,tVecteur stVecteur2,float *pnResultat){
    *pnResultat=getVecteurX(&stVecteur1)*getVecteurX(&stVecteur2)+getVecteurY(&stVecteur1)*getVecteurY(&stVecteur2);
}

//###########################################
//PROCEDURE produitVectoriel
//*****************************************************************************************************//
//
// DESCRIPTION Calcul le produit vectorielle de deux vecteurs et remplace la coordonné z par 2 constante z1 et z2
//
// ENTREE / Les refs des 2 vecteurs, la ref du resultat, les const z1 et z2
//
// SORTIE / Le vecteur resultat
//
// NOTE Calcul X3 = Y1*Z2 - Y2*Z1,  Y3 = Z1*X2 - Z2*Y1
//
//*****************************************************************************************************//
void produitVectoriel(tVecteur stVecteur1,tVecteur stVecteur2,tVecteur *pstResultat,float const nZ1,float const nZ2){
    setVecteurX(pstResultat,getVecteurY(&stVecteur1)*nZ2-nZ1*getVecteurY(&stVecteur2));
    setVecteurY(pstResultat,getVecteurX(&stVecteur2)*nZ1-nZ2*getVecteurX(&stVecteur1));
}
