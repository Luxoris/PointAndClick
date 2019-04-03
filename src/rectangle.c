#include "rectangle.h"

//###########################################
//FONCTION creeRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie une variable de type rectangle à partir d'un point, d'une largeur et d'une hauteur
//
// ENTREE Le point, la largeur, la hauteur
//
// SORTIE Le rectangle en sortie
//
// NOTE -
//*****************************************************************************************************//
tRectangle creeRectangle(const tPoint stPointCentral,const int nLargeur, const int nHauteur){
    tRectangle stRectangle;
    setRectanglePointCentral(&stRectangle,stPointCentral);
    setRectangleHauteur(&stRectangle,nHauteur);
    setRectangleLargeur(&stRectangle,nLargeur);

    return stRectangle;

}

//###########################################
//FONCTION getRectanglePointCentral
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le point central d'un type rectangle
//
// ENTREE La ref du rectangle
//
// SORTIE Le point
//
// NOTE -
//*****************************************************************************************************//
tPoint * getRectanglePointCentral(tRectangle *pstRectangle){
    return &pstRectangle->stPointCentral;
}

//###########################################
//FONCTION getRectangleLargeur
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la largeur d'un type rectangle
//
// ENTREE La ref du rectangle
//
// SORTIE La largeur
//
// NOTE -
//*****************************************************************************************************//
int getRectangleLargeur(tRectangle *pstRectangle){
    return pstRectangle->nLargeur;
}

//###########################################
//FONCTION getRectangleHauteur
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la hauteur d'un type rectangle
//
// ENTREE La ref du rectangle
//
// SORTIE La hauteur
//
// NOTE -
//*****************************************************************************************************//
int getRectangleHauteur(tRectangle *pstRectangle){
    return pstRectangle->nHauteur;
}

//###########################################
//PROCEDURE setRectanglePointCentral
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le point central d'un type rectangle
//
// ENTREE La ref du rectangle, le point
//
// SORTIE Le point du rectangle modifié
//
// NOTE -
//*****************************************************************************************************//
void setRectanglePointCentral(tRectangle *pstRectangle, const tPoint stPointCentral){
    pstRectangle->stPointCentral = stPointCentral;
}

//###########################################
//PROCEDURE setRectangleLargeur
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la largeur d'un type rectangle
//
// ENTREE La ref du rectangle, la largeur
//
// SORTIE La largeur du rectangle modifiée
//
// NOTE -
//*****************************************************************************************************//
void setRectangleLargeur(tRectangle *pstRectangle, const int nLargeur){
    pstRectangle->nLargeur=nLargeur;
}

//###########################################
//PROCEDURE setRectangleHauteur
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la hauteur d'un type rectangle
//
// ENTREE La ref du rectangle, la hauteur
//
// SORTIE La hauteur du rectangle modifiée
//
// NOTE -
//*****************************************************************************************************//
void setRectangleHauteur(tRectangle *pstRectangle, const int nHauteur){
    pstRectangle->nHauteur=nHauteur;
}

//###########################################
//PROCEDURE deplacementRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonéés du point d'un rectangle en fonction du vecteur de déplacement
//
// ENTREE La référence du rectangle, le vecteur
//
// SORTIE Le point du rectangle modifié.
//
// NOTE -
//*****************************************************************************************************//
void deplacementRectangle(tRectangle *pstRectangle,const tVecteur stVecteur){
    tPoint stPoint = *getRectanglePointCentral(pstRectangle);
    deplacementPoint(&stPoint,stVecteur);
    setRectanglePointCentral(pstRectangle,stPoint);
}

//###########################################
//FONCTION conversionRectangleVersSDLRect
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le SDL_Rect correspondant au rectangle (tRectangle)
//
// ENTREE La référence du rectangle
//
// SORTIE Le SDL Rect
//
// NOTE -
//*****************************************************************************************************//
SDL_Rect conversionRectangleVersSDLRect(tRectangle *pstRectangle){
    tPoint stPoint = *getRectanglePointCentral(pstRectangle);
    SDL_Point stSDLPoint;
    SDL_Rect stRect;

    //calcul du point en haut à gauche à partir du point central.
    stPoint.fX = stPoint.fX - (getRectangleLargeur(pstRectangle)*0.5);
    stPoint.fY = stPoint.fY - (getRectangleHauteur(pstRectangle)*0.5);

    //convertion du tPoint vers SDLPoint;
    stSDLPoint = convertionPointVersSDL_Point(&stPoint);

    //creation du SDL_Rect
    stRect.x=getSDLPointX(&stSDLPoint);
    stRect.y=getSDLPointY(&stSDLPoint);
    stRect.h=getRectangleHauteur(pstRectangle);
    stRect.w=getRectangleLargeur(pstRectangle);

    return stRect;

}
