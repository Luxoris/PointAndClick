#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#pragma once

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "tObjet.h"


//définition du type structuré
typedef struct tJoueur{
    tObjet *pstRaquette;
    int nScore;
}tJoueur;

//prototypes
extern void initJoueur(tJoueur **pstJoueur,tObjet *pstRaquette,const int nScoreDepart);
extern void freeJoueur(tJoueur *pstJoueur);

extern tObjet* getJoueurRaquette(tJoueur *pstJoueur);
extern int getJoueurScore(tJoueur *pstJoueur);
extern void setJoueurRaquette(tJoueur *pstJoueur,tObjet *pstRaquette);
extern void setJoueurScore(tJoueur *pstJoueur,const int nScore);



#endif // JOUEUR_H_INCLUDED
