#include "joueur.h"


//###########################################
//PROCEDURE initJoueur
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un joueur.
//
// ENTREE /La réference de la raquette du joueur, le score du joueur.
//
// SORTIE /Le type joueur compléter
//
// NOTE -
//*****************************************************************************************************//
void initJoueur(tJoueur **pstJoueur,tObjet *pstRaquette,const int nScoreDepart){
    if((*pstJoueur = malloc(sizeof(tJoueur)))==NULL){
        printf("Erreur d'allocation du joueur !");
    }else{
        setJoueurRaquette(*pstJoueur,pstRaquette);
        setJoueurScore(*pstJoueur,nScoreDepart);

    }
}

//###########################################
//PROCEDURE freeJoueur
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui libère le joueur de la mémoire.
//
// ENTREE /La réference de du joueur.
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void freeJoueur(tJoueur *pstJoueur){
    free(pstJoueur);
}


//###########################################
//FONCTION getJoueurObjet
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la référence de la raquette d'un joueur
//
// ENTREE /La ref du joueur
//
// SORTIE /La ref de la raquette
//
// NOTE -
//*****************************************************************************************************//
tObjet* getJoueurRaquette(tJoueur *pstJoueur){
    return pstJoueur->pstRaquette;

}

//###########################################
//FONCTION getJoueurScore
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie lee score d'un type joueur
//
// ENTREE /La ref du joueur
//
// SORTIE /Le score du joueur
//
// NOTE -
//*****************************************************************************************************//
int getJoueurScore(tJoueur *pstJoueur){
    return pstJoueur->nScore;
}

//###########################################
//PROCEDURE setJoueurObjet
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la référence de la raquette dans le type joueur
//
// ENTREE /La ref du joueur, la ref de la raquette
//
// SORTIE /La ref de la raquette modifiée dans le type joueur.
//
// NOTE -
//*****************************************************************************************************//
void setJoueurRaquette(tJoueur *pstJoueur,tObjet *pstRaquette){
    pstJoueur->pstRaquette = pstRaquette;
}


//###########################################
//PROCEDURE setJoueurScore
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le score du joueur
//
// ENTREE /La ref du joueur, la valeur du score
//
// SORTIE /Le score du joueur modifié
//
// NOTE -
//*****************************************************************************************************//
void setJoueurScore(tJoueur *pJoueur,const int nScore){
    pJoueur->nScore=nScore;
}
