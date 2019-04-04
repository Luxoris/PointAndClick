#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>
#include <stdio.h>
#include "tBool.h"
#include "SDLPoint.h"
#include "rectangle.h"




//PROTOTYPE
extern void initMoteurRendu(SDL_Window** pFenetre, SDL_Renderer** pRenderer);
extern void arretMoteurRendu(SDL_Renderer** pRenderer);
extern void dessineSDLRectangle(SDL_Renderer* pRenderer,SDL_Point tCoor,const int nLargeur,const int nHauteur,const tBool tRectanglePlein);
extern void dessineRectanglePointCentre(SDL_Renderer* pRenderer,SDL_Point tCoor,const int nLargeur,const int nHauteur,const tBool tRectanglePlein);
extern void dessinePointille(SDL_Renderer* pRenderer,SDL_Point tCoorDebut,SDL_Point tCoorFin, const int nLongueurTraitPlein, const int nLongueurTraitVide);
extern void dessineCercle(SDL_Renderer* pRenderer,SDL_Point tPointCentre,const int nRayon);
extern void dessineCerclePlein(SDL_Renderer* pRenderer,SDL_Point tPointCentre,const int nRayon);

extern void dessineRectangle(SDL_Renderer *pRenderer,tRectangle *pstRectangle,tBool bRectanglePlein);




#endif // RENDERER_H_INCLUDED
