#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED
#pragma once

//appel des biblioth�ques
#include <SDL.h>

//prototypes des m�thodes
extern void calculFPS(float * pfFPS, const Uint32 nTempsDebutBoucle, const Uint32 nTempsFinBoucle);
extern void priseEnCompteFPSMax(float *fFPS, const int nFPSMax, const Uint32 nTempsExecution);

#endif // FPS_H_INCLUDED
