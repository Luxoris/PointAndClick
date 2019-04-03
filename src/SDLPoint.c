#include "SDLPoint.h"

#include "point.h"
#include "math.h"

//###########################################
//FONCTION creeSDLPoint
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui cr�e un �l�ment de type SDL_Point � partir de ses coordonn�es
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
// ENTREE La r�f�rence du point
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
// ENTREE La r�f�rence du point
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
// ENTREE La r�f�rence du point, la valeur nX
//
// SORTIE La valeur modifi� dans le point
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
// ENTREE La r�f�rence du point, la valeur nY
//
// SORTIE La valeur modifi� dans le point
//
// NOTE -
//*****************************************************************************************************//
void setSDLPointY(SDL_Point *pstSDLPoint,const int nY){
    pstSDLPoint->y = nY;
}
