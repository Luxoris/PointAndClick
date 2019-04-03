#ifndef SDLPOINT_H_INCLUDED
#define SDLPOINT_H_INCLUDED
#pragma once

#include <SDL.h>

//prototypes
extern SDL_Point creeSDLPoint(const int nX,const int ny);
extern int getSDLPointX(SDL_Point *psSDL_Point);
extern int getSDLPointY(SDL_Point *psSDL_Point);
extern void setSDLPointX(SDL_Point *psSDL_Point,const int fX);
extern void setSDLPointY(SDL_Point *psSDL_Point,const int fy);


#endif // SDLPOINT_H_INCLUDED
