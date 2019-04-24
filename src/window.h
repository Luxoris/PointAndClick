#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>
#include <stdio.h>
#include "define.h"

//PROTOTYPE
extern void initFenetre(SDL_Window** pFenetre, const char cTitre[]);
extern void arretFenetre(SDL_Window** pFenetre);

#endif // WINDOW_H_INCLUDED
