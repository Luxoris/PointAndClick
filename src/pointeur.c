#include "pointeur.h"

//###########################################
//PROCEDURE initPointeur
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un pointeur.
//
// ENTREE /La reférence du pointeur de pointeur de tPointeur, la position (tPoint), l'état des clique droit, gauche et molette (tBool).
//
// SORTIE /La référence du pointeur de tPointeur modifiée, les valeurs du tPointeur modifiées.
//
// NOTE -
//*****************************************************************************************************//
void initPointeur(tPointeur **ppPointeur, const tPoint stPosition,const tBool stCliqueDroit, const tBool stCliqueGauche, const tBool stCliqueMolette){
    if((*ppPointeur = malloc(sizeof(tPointeur)))==NULL){
        printf("Erreur d'allocation du pointeur !");
    }else{
        setPointeur(*ppPointeur,stPosition,stCliqueDroit,stCliqueGauche,stCliqueMolette);

    }
}

//###########################################
//PROCEDURE freePointeur
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui libère le tPointeur,
//
// ENTREE /La reférence du pointeur de pointeur de tPointeur.
//
// SORTIE / -
//
// NOTE -
//*****************************************************************************************************//
void freePointeur(tPointeur *pstPointeur){
    free(pstPointeur);
}

//###########################################
//PROCEDURE setPointeur
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie les valeurs d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur, la position (tPoint), l'état des clique droit, gauche et molette (tBool).
//
// SORTIE /Les valeurs du tPointeur modifiées.
//
// NOTE -
//*****************************************************************************************************//
void setPointeur(tPointeur *pstPointeur, const tPoint stPosition,const tBool stCliqueDroit, const tBool stCliqueGauche, const tBool stCliqueMolette){
    setPointeurPosition(pstPointeur,stPosition);
    setPointeurCliqueDroit(pstPointeur,stCliqueDroit);
    setPointeurCliqueGauche(pstPointeur,stCliqueGauche);
    setPointeurCliqueMolette(pstPointeur,stCliqueMolette);
}

//###########################################
//PROCEDURE setPointeurPosition
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la position d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur, la position (tPoint).
//
// SORTIE /La position du tPointeur modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setPointeurPosition(tPointeur *pstPointeur, const tPoint stPosition){
    pstPointeur->stPosition=stPosition;
}

//###########################################
//PROCEDURE setPointeurCliqueDroit
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie l'etat du clique droit d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur, l'etat du clique droit.
//
// SORTIE /L'etat du clique droit du tPointeur modifié.
//
// NOTE -
//*****************************************************************************************************//
void setPointeurCliqueDroit(tPointeur *pstPointeur, const tBool stCliqueDroit){
    pstPointeur->stCliqueDroit=stCliqueDroit;
}

//###########################################
//PROCEDURE setPointeurCliqueGauche
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie l'etat du clique gauche d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur, l'etat du clique gauche.
//
// SORTIE /L'etat du clique gauche du tPointeur modifié.
//
// NOTE -
//*****************************************************************************************************//
void setPointeurCliqueGauche(tPointeur *pstPointeur, const tBool stCliqueGauche){
    pstPointeur->stCliqueGauche=stCliqueGauche;
}

//###########################################
//PROCEDURE setPointeurCliqueMolette
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie l'etat du clique molette d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur, l'etat du clique molette.
//
// SORTIE /L'etat du clique molette du tPointeur modifié.
//
// NOTE -
//*****************************************************************************************************//
void setPointeurCliqueMolette(tPointeur *pstPointeur, const tBool stCliqueMolette){
    pstPointeur->stCliqueMolette=stCliqueMolette;

}

//###########################################
//FONCTION getPointeurPosition
//*****************************************************************************************************//
//
// DESCRIPTION retourne la référence de la position d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur.
//
// SORTIE /La référence de la position du tPointeur..
//
// NOTE -
//*****************************************************************************************************//
tPoint* getPointeurPosition(tPointeur *pstPointeur){
    return &pstPointeur->stPosition;
}

//###########################################
//FONCTION getPointeurCliqueDroit
//*****************************************************************************************************//
//
// DESCRIPTION retourne l'état du clic droit d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur.
//
// SORTIE /L'état du clique droit.
//
// NOTE -
//*****************************************************************************************************//
tBool getPointeurCliqueDroit(tPointeur *pstPointeur){
    return pstPointeur->stCliqueDroit;
}

//###########################################
//FONCTION getPointeurCliqueGauche
//*****************************************************************************************************//
//
// DESCRIPTION retourne l'état du clic gauche d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur.
//
// SORTIE /L'état du clique gauche.
//
// NOTE -
//*****************************************************************************************************//
tBool getPointeurCliqueGauche(tPointeur *pstPointeur){
    return pstPointeur->stCliqueGauche;
}

//###########################################
//FONCTION getPointeurCliqueMolette
//*****************************************************************************************************//
//
// DESCRIPTION retourne l'état du clic molette d'un tPointeur
//
// ENTREE /La reférence du pointeur de tPointeur.
//
// SORTIE /L'état du clique molette.
//
// NOTE -
//*****************************************************************************************************//
tBool getPointeurCliqueMolette(tPointeur *pstPointeur){
    return pstPointeur->stCliqueMolette;
}
