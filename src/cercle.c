#include "cercle.h"

//###########################################
//FONCTION creeCercle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie une variable de type cercle à partir d'un point, et d'un rayon
//
// ENTREE Le point, le rayon
//
// SORTIE Le cercle
//
// NOTE -
//*****************************************************************************************************//
tCercle creeCercle(const tPoint stPointCentral, const int nRayon){
    tCercle stCercle;
    setCerclePointCentral(&stCercle,stPointCentral);
    setCercleRayon(&stCercle,nRayon);

    return stCercle;
}

//###########################################
//PROCEDURE setCerclePointCentral
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le point central d'un type cercle
//
// ENTREE Le type, le point
//
// SORTIE Le point du cercle modifié
//
// NOTE -
//*****************************************************************************************************//
void setCerclePointCentral(tCercle *pstCercle, const tPoint stPointCentral){
    pstCercle->stPointCentral = stPointCentral;
}

//###########################################
//PROCEDURE setCercleRayon
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le rayon d'un type cercle
//
// ENTREE Le type, le rayon
//
// SORTIE Le rayon du cercle modifié
//
// NOTE -
//*****************************************************************************************************//
void setCercleRayon(tCercle *pstCercle, const int nRayon){
    pstCercle->nRayon = nRayon;
}

//###########################################
//FONCTION getCerclePointCentral
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le point central d'un cercle
//
// ENTREE La ref du cercle
//
// SORTIE La ref du point central du cercle
//
// NOTE -
//*****************************************************************************************************//
tPoint* getCerclePointCentral(tCercle *pstCercle){
    return &pstCercle->stPointCentral;
}
//###########################################
//FONCTION getCercleRayon
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le rayon d'un cercle
//
// ENTREE La ref du cercle
//
// SORTIE Le rayon du cercle
//
// NOTE -
//*****************************************************************************************************//
int getCercleRayon(tCercle *pstCercle){
    return pstCercle->nRayon;
}

//###########################################
//PROCEDURE deplacementCercle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonéés du point d'un cercle en fonction du vecteur de déplacement
//
// ENTREE La référence du cercle, le vecteur
//
// SORTIE Le point du cercle modifié.
//
// NOTE -
//*****************************************************************************************************//
void deplacementCercle(tCercle *pstCercle,const tVecteur stVecteur){
    tPoint stPoint= *getCerclePointCentral(pstCercle);
    deplacementPoint(&stPoint,stVecteur);
    setCerclePointCentral(pstCercle,stPoint);
}
