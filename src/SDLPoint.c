#include "SDLPoint.h"

#include "point.h"
#include "math.h"

//###########################################
//FONCTION creeSDLPoint
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui crée un élément de type SDL_Point à partir de ses coordonnées
//
// ENTREE La valeur en X et en Y du point.
//
// SORTIE Le nouveau point
//
// NOTE -
//*****************************************************************************************************//
SDL_Point creeSDLPoint(const int nX,const int nY){
    SDL_Point stSDLPoint;
    setSDLPointX(&stSDLPoint,nX);
    setSDLPointY(&stSDLPoint,nY);

    return stSDLPoint;
}

//###########################################
//FONCTION getSDLPointX
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui retourne la valeur en X du point
//
// ENTREE La référence du point
//
// SORTIE La valeur nX
//
// NOTE -
//*****************************************************************************************************//
int getSDLPointX(SDL_Point *pstSDLPoint){
    return pstSDLPoint->x;
}


//###########################################
//FONCTION getSDLPointY
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui retourne la valeur en Y du tSDLPoint
//
// ENTREE La référence du point
//
// SORTIE La valeur nY
//
// NOTE -
//*****************************************************************************************************//
int getSDLPointY(SDL_Point *pstSDLPoint){
    return pstSDLPoint->y;
}

//###########################################
//PROCEDURE setSDLPointX
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui change la valeur nX d'un type tSDLPoint
//
// ENTREE La référence du point, la valeur nX
//
// SORTIE La valeur modifié dans le point
//
// NOTE -
//*****************************************************************************************************//
void setSDLPointX(SDL_Point *pstSDLPoint,const int nX){
    pstSDLPoint->x = nX;
}

//###########################################
//PROCEDURE setSDLPointY
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui change la valeur nY d'un type tSDLPoint
//
// ENTREE La référence du point, la valeur nY
//
// SORTIE La valeur modifié dans le point
//
// NOTE -
//*****************************************************************************************************//
void setSDLPointY(SDL_Point *pstSDLPoint,const int nY){
    pstSDLPoint->y = nY;
}
