#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#pragma once

#include <SDL.h>
#include "vecteur.h"

//définition du type point
typedef struct tPoint{
    float fX;
    float fY;
}tPoint;

//prototypes
extern tPoint creePoint(const float fX,const float fy);
extern float getPointX(tPoint *pstPoint);
extern float getPointY(tPoint *pstPoint);
extern void setPointX(tPoint *pstPoint,const float fX);
extern void setPointY(tPoint *pstPoint,const float fy);

extern void deplacementPoint(tPoint *pstPoint,const tVecteur stVecteur);
extern SDL_Point convertionPointVersSDL_Point(tPoint *pstPoint);

#endif // POINT_H_INCLUDED
