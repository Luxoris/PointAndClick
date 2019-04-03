#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#pragma once

//appel des biblioth�ques

#include "tBool.h"
#include "rectangle.h"
#include "cercle.h"

//prototype des m�thodes
extern tBool collisionPointRectangle(tPoint *pstPoint,tRectangle *pstRectangle);
extern tBool collisionRectangleRectangle(tRectangle *pstRectangle1,tRectangle *pstRectangle2);
extern tBool collisionRectangleBordDroit(tRectangle *pstRectangle, const float fX);
extern tBool collisionRectangleBordGauche(tRectangle *pstRectangle, const float fX);
extern tBool collisionRectangleBordHaut(tRectangle *pstRectangle, const float fY);
extern tBool collisionRectangleBordBas(tRectangle *pstRectangle, const float fY);


extern tBool collisionPointCercle(tPoint *pstPoint,tCercle *pstCercle);
extern tBool collisionCercleCercle(tCercle *pstCercle1,tCercle *pstCercle2);

#endif // COLLISION_H_INCLUDED
