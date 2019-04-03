#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED

//appel des biblioth�ques
#include <SDL.h>
#include "vecteur.h"
#include "point.h"

//d�finition du type structur�
typedef struct tCercle{
    tPoint stPointCentral;
    int nRayon;
}tCercle;



//prototype des fonctions
extern tCercle creeCercle(const tPoint stPointCentral, const int nRayon);
extern void setCerclePointCentral(tCercle *pstCercle, const tPoint stPointCentral);
extern void setCercleRayon(tCercle *pstCercle, const int nRayon);
extern tPoint* getCerclePointCentral(tCercle *pstCercle);
extern int getCercleRayon(tCercle *pstCercle);

extern void deplacementCercle(tCercle *pstCercle,const tVecteur stVecteur);


#endif // CERCLE_H_INCLUDED
