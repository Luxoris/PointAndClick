#include "bouton.h"

//###########################################
//PROCEDURE initBouton
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un bouton.
//
// ENTREE /La reférence du pointeur de pointeur du bouton, l'objet, est survolé, est cliqué, le code de l'action.
//
// SORTIE /La référence du pointeur de bouton modifiée, les valeurs du bouton modifiées.
//
// NOTE -
//*****************************************************************************************************//
void initBouton(tBouton **ppBouton,tObjet *pstObjet, const char sTexte[],const tBool stSurvole, const tBool stClique, const int nCodeAction){
    if((*ppBouton = malloc(sizeof(tBouton)))==NULL){
        printf("Erreur d'allocation du bouton !");
    }else{
        setBouton(*ppBouton,pstObjet,sTexte,stSurvole,stClique,nCodeAction);

    }

}

//###########################################
//PROCEDURE freeBouton
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui libère un bouton.
//
// ENTREE /La reférence du pointeur de pointeur du bouton.
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void freeBouton(tBouton *pstBouton){
    free(pstBouton);
}

//###########################################
//PROCEDURE setBouton
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie les valeurs d'un bouton.
//
// ENTREE /La reférence du pointeur de pointeur du bouton, l'objet, est survolé, est cliqué, le code de l'action.
//
// SORTIE /Les valeurs du bouton modifiées.
//
// NOTE -
//*****************************************************************************************************//
void setBouton(tBouton *pstBouton,tObjet *pstObjet, const char sTexte[],const tBool stSurvole, const tBool stClique, const int nCodeAction){
    setBoutonObjet(pstBouton,pstObjet);
    setBoutonTexte(pstBouton,sTexte);
    setBoutonClique(pstBouton,stClique);
    setBoutonSurvole(pstBouton,stSurvole);
    setBoutonCodeAction(pstBouton,nCodeAction);
}

//###########################################
//PROCEDURE setBoutonObjet
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie la référence de l'objet d'un bouton.
//
// ENTREE /La reférence du  pointeur du bouton, l'objet.
//
// SORTIE /La référence de l'objet modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setBoutonObjet(tBouton *pstBouton, tObjet *pstObjet){
    pstBouton->pstObjet=pstObjet;
}

//###########################################
//PROCEDURE setBoutonTexte
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie le texte d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton, le texte.
//
// SORTIE /Le texte modifié.
//
// NOTE -
//*****************************************************************************************************//
void setBoutonTexte(tBouton *pstBouton, const char sTexte[]){
    strcpy(pstBouton->sTexte,sTexte);
}

//###########################################
//PROCEDURE setBoutonSurvole
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie l'etat de survol d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton, le booléen correspondant au survol.
//
// SORTIE /Le booléen survol modifié.
//
// NOTE -
//*****************************************************************************************************//
void setBoutonSurvole(tBouton *pstBouton, const tBool stSurvole){
    pstBouton->stSurvole=stSurvole;
}

//###########################################
//PROCEDURE setBoutonClique
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie l'etat de clique d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton, le booléen correspondant au clique.
//
// SORTIE /Le booléen clique modifié.
//
// NOTE -
//*****************************************************************************************************//
void setBoutonClique(tBouton *pstBouton, const tBool stClique){
    pstBouton->stClique=stClique;
}

//###########################################
//PROCEDURE setBoutonCodeAction
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie le code de l'action d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton, le code de l'action (int).
//
// SORTIE /Le code de l'action clique modifié.
//
// NOTE -
//*****************************************************************************************************//
void setBoutonCodeAction(tBouton *pstBouton, const int nCodeAction){
    pstBouton->nCodeAction = nCodeAction;
}

//###########################################
//Fonction getBoutonObjet
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la référence de l'objet d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton.
//
// SORTIE /La ref de l'objet d'un bouton.
//
// NOTE -
//*****************************************************************************************************//
tObjet* getBoutonObjet(tBouton *pstBouton){
    return pstBouton->pstObjet;
}

//###########################################
//Fonction getBoutonTexte
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la référence du texte d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton.
//
// SORTIE /La ref du texte d'un bouton.
//
// NOTE -
//*****************************************************************************************************//
char* getBoutonTexte(tBouton *pstBouton){
    return pstBouton->sTexte;
}

//###########################################
//Fonction getBoutonSurvole
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le booléen correspondnat à l'etat de survol d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton.
//
// SORTIE /Le booléen de survole d'un bouton.
//
// NOTE -
//*****************************************************************************************************//
tBool getBoutonSurvole(tBouton *pstBouton){
    return pstBouton->stSurvole;
}

//###########################################
//Fonction getBoutonSurvole
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le booléen correspondant à l'etat de clique d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton.
//
// SORTIE /Le booléen de clique d'un bouton.
//
// NOTE -
//*****************************************************************************************************//
tBool getBoutonClique(tBouton *pstBouton){
    return pstBouton->stClique;
}

//###########################################
//Fonction getBoutonSurvole
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le code de l'action correspondant à l'etat de clique d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton.
//
// SORTIE /Le code de l'action d'un bouton.
//
// NOTE -
//*****************************************************************************************************//
int getBoutonCodeAction(tBouton *pstBouton){
    return pstBouton->nCodeAction;
}

//###########################################
//Fonction gestionBoutonPointeur
//*****************************************************************************************************//
//
// DESCRIPTION Vérifie si le bouton est survolé par le pointeur, et si il y a un clique sur le bouton.
//
// ENTREE /La reférence du pointeur du bouton, la référence du pointeur.
//
// SORTIE /Les booléens correspondnat à l'état (clique, survole) du bouton modifié.
//
// NOTE -
//*****************************************************************************************************//
void gestionBoutonPointeur(tBouton *pstBouton, tPointeur *pstPointeur){
    if(collisionPointRectangle(getPointeurPosition(pstPointeur),getObjetRectangle(getBoutonObjet(pstBouton)))){
        setBoutonSurvole(pstBouton,true);
        if(getPointeurCliqueGauche(pstPointeur)){
            setBoutonClique(pstBouton,true);
        }
    }else{
        setBoutonSurvole(pstBouton,false);
        setBoutonClique(pstBouton,false);
    }

}
