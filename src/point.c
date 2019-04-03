#include "point.h"
#include "math.h"

//###########################################
//FONCTION creePoint
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui cr�e un �l�ment de tfYpe tPoint � partir de ses coordonn�es
//
// ENTREE La valeur en X et en Y du point.
//
// SORTIE Le nouveau point
//
// NOTE -
//*****************************************************************************************************//
tPoint creePoint(const float fX,const float fY){
    tPoint stPoint;
    setPointX(&stPoint,fX);
    setPointY(&stPoint,fY);

    return stPoint;
}

//###########################################
//FONCTION getPointX
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui retourne la valeur en X du point
//
// ENTREE La r�f�rence du point
//
// SORTIE La valeur fX
//
// NOTE -
//*****************************************************************************************************//
float getPointX(tPoint *pstPoint){
    return pstPoint->fX;
}


//###########################################
//FONCTION getPointY
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui retourne la valeur en Y du tPoint
//
// ENTREE La r�f�rence du point
//
// SORTIE La valeur fY
//
// NOTE -
//*****************************************************************************************************//
float getPointY(tPoint *pstPoint){
    return pstPoint->fY;
}

//###########################################
//PROCEDURE setPointX
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui change la valeur fX d'un tfYpe tPoint
//
// ENTREE La r�f�rence du point, la valeur fX
//
// SORTIE La valeur modifi� dans le point
//
// NOTE -
//*****************************************************************************************************//
void setPointX(tPoint *pstPoint,const float fX){
    pstPoint->fX = fX;
}

//###########################################
//PROCEDURE setPointY
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui change la valeur fY d'un tfYpe tPoint
//
// ENTREE La r�f�rence du point, la valeur fY
//
// SORTIE La valeur modifi� dans le point
//
// NOTE -
//*****************************************************************************************************//
void setPointY(tPoint *pstPoint,const float fY){
    pstPoint->fY = fY;
}


//###########################################
//PROCEDURE deplacementPoint
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordon��s d'un tPoint en fonction du vecteur de d�placement
//
// ENTREE La r�f�rence du point, le vecteur
//
// SORTIE Le tPoint modifi�.
//
// NOTE -
//*****************************************************************************************************//
void deplacementPoint(tPoint *pstPoint,const tVecteur stVecteur){
    pstPoint->fX+=stVecteur.fX;
    pstPoint->fY+=stVecteur.fY;
}

//###########################################
//FONCTION convertionPointVersSDL_Point
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie un SDL_Point � partir d'un tPoint
//
// ENTREE La ref du tPoint
//
// SORTIE Le SDL_Point
//
// NOTE -   Arrondi les float vers l'int le plus proche
//*****************************************************************************************************//
SDL_Point convertionPointVersSDL_Point(tPoint *pstPoint){
    SDL_Point stSDLPoint;
    stSDLPoint.x=rint(getPointX(pstPoint));
    stSDLPoint.y=rint(getPointY(pstPoint));
    return stSDLPoint;
}
