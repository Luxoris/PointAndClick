#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>

//prototypes des méthodes
extern void calculFPS(float * pfFPS, const Uint32 nTempsDebutBoucle, const Uint32 nTempsFinBoucle);
extern void priseEnCompteFPSMax(float *fFPS, const int nFPSMax, const Uint32 nTempsExecution);

#endif // FPS_H_INCLUDED
