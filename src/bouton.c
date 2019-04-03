#include "bouton.h"

//###########################################
//PROCEDURE initBouton
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui initialise et alloue un bouton.
//
// ENTREE /La ref�rence du pointeur de pointeur du bouton, l'objet, est survol�, est cliqu�, le code de l'action.
//
// SORTIE /La r�f�rence du pointeur de bouton modifi�e, les valeurs du bouton modifi�es.
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
// DESCRIPTION PROCEDURE qui lib�re un bouton.
//
// ENTREE /La ref�rence du pointeur de pointeur du bouton.
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
// ENTREE /La ref�rence du pointeur de pointeur du bouton, l'objet, est survol�, est cliqu�, le code de l'action.
//
// SORTIE /Les valeurs du bouton modifi�es.
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
// DESCRIPTION PROCEDURE qui modifie la r�f�rence de l'objet d'un bouton.
//
// ENTREE /La ref�rence du  pointeur du bouton, l'objet.
//
// SORTIE /La r�f�rence de l'objet modifi�e.
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
// ENTREE /La ref�rence du pointeur du bouton, le texte.
//
// SORTIE /Le texte modifi�.
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
// ENTREE /La ref�rence du pointeur du bouton, le bool�en correspondant au survol.
//
// SORTIE /Le bool�en survol modifi�.
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
// ENTREE /La ref�rence du pointeur du bouton, le bool�en correspondant au clique.
//
// SORTIE /Le bool�en clique modifi�.
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
// ENTREE /La ref�rence du pointeur du bouton, le code de l'action (int).
//
// SORTIE /Le code de l'action clique modifi�.
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
// DESCRIPTION Renvoie la r�f�rence de l'objet d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton.
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
// DESCRIPTION Renvoie la r�f�rence du texte d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton.
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
// DESCRIPTION Renvoie le bool�en correspondnat � l'etat de survol d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton.
//
// SORTIE /Le bool�en de survole d'un bouton.
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
// DESCRIPTION Renvoie le bool�en correspondant � l'etat de clique d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton.
//
// SORTIE /Le bool�en de clique d'un bouton.
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
// DESCRIPTION Renvoie le code de l'action correspondant � l'etat de clique d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton.
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
// DESCRIPTION V�rifie si le bouton est survol� par le pointeur, et si il y a un clique sur le bouton.
//
// ENTREE /La ref�rence du pointeur du bouton, la r�f�rence du pointeur.
//
// SORTIE /Les bool�ens correspondnat � l'�tat (clique, survole) du bouton modifi�.
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
