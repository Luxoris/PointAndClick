#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED



//appel des bibliothèques
#include <SDL.h>
#include "vecteur.h"
#include "point.h"
#include "SDLPoint.h"

//définition du type structuré
typedef struct tRectangle{
    tPoint stPointCentral;
    int nLargeur;
    int nHauteur;
}tRectangle;

//prototype des fonctions
extern tRectangle creeRectangle(const tPoint stPointCentral,const int nLargeur, const int nHauteur);
extern tPoint * getRectanglePointCentral(tRectangle *pstRectangle);
extern int getRectangleLargeur(tRectangle *pstRectangle);
extern int getRectangleHauteur(tRectangle *pstRectangle);

extern void setRectanglePointCentral(tRectangle *pstRectangle, const tPoint stPointCentral);
extern void setRectangleLargeur(tRectangle *pstRectangle, const int nLargeur);
extern void setRectangleHauteur(tRectangle *pstRectangle, const int nHauteur);

extern void deplacementRectangle(tRectangle *pstRectangle,const tVecteur stVecteur);
extern SDL_Rect conversionRectangleVersSDLRect(tRectangle *pstRectangle);

#endif // RECTANGLE_H_INCLUDED
