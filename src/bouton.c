#include "bouton.h"

///METHODES DE LA LISTE DE BOUTONS///

//###########################################
//FONCTION initialisationListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui initialise une liste de bouton.
//
// ENTREE /
//
// SORTIE / La référence de la liste de bouton
//
// NOTE -
//*****************************************************************************************************//
tListeBouton *initialisationListeBouton(){

    tListeBouton *pListe = malloc(sizeof(tListeBouton));

    if (pListe == NULL){
        printf("\nErreur lors de l'initialisation de la liste de bouton.");
        exit(EXIT_FAILURE);
    }else{
        pListe->nbElements = 0;
        pListe->pPremier = NULL;
    }
    return pListe;
}

//###########################################
//PROCEDURE insertionBoutonListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui insert un élément dans la liste, après la référence de l'élément. Prend NULL si insertion au début.
//
// ENTREE /La référence de la la liste, la ref de l'élément bouton, la référence de l'élement d'insertion, le nom de le bouton.
//
// SORTIE / L'allocation du nouvelle élément, les réferences modifiés.
//
// NOTE -
//*****************************************************************************************************//
void insertionBoutonListe(tListeBouton *pListe, tElementBouton *pElementInsetion,const tBouton stBouton,const char sNom[]){
    tElementBouton *pElement = malloc(sizeof(tElementBouton));
    if (pListe == NULL || pElement == NULL) //vérifie que l'allocation a fonctionné
    {
        printf("\nErreur lors de l'allocation d'un element de la liste de bouton.");
        exit(EXIT_FAILURE);
    }
    pElement->stBouton = stBouton;    //l'élément reçoit la référence de le bouton
    strcpy(pElement->sNom,sNom);//ajout du nom de l'élément

    if(pListe->pPremier==NULL){ //si la liste est vide
        pElement->pSuivant = NULL;
        pListe->pPremier = pElement;
    }else{ //SI pElementInsertion = NULL, insert l'élément au début de la liste
        if((pElementInsetion == NULL)){
            pElement->pSuivant = pListe->pPremier;
            pListe->pPremier = pElement;
        }else{
            //SINON INSERTION D'UN ELEMENT APRES LA REFERENCE//
            pElement->pSuivant = pElementInsetion ->pSuivant;   //l'élément récupère la référence de l'élément suivant.
            pElementInsetion->pSuivant = pElement;  //l'élément d'isnertion récupère la référence du nouvelle élément.
        }

    }

    pListe->nbElements++;   //incrémentation du nombre d'élément de la liste


}

//###########################################
//PROCEDURE suppressionBoutonListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime un élément dans la liste, après la référence de l'élément.
//
// ENTREE /La référence de la la liste, la ref de l'element a supprimer.
//
// SORTIE / Les référence de la liste modifiés, la mémoire libéré.
//
// NOTE -  La référence de l'élément accepte NULL si l'élément a supprimer est le premier.
//*****************************************************************************************************//
void suppressionBoutonListe(tListeBouton *pListe, tElementBouton *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste de bouton, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'élément, l'élément vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementBouton *pElement = NULL;

            //Si l'élément a suprimer est le premier de la liste.
            if(pElementSupprimer == pListe->pPremier){
                //pElement récupère la référence du premier élément de la liste
                pElement = pListe->pPremier;

                //la liste récupère le second élément, et le définit comme premier élément
                pListe->pPremier = pListe->pPremier->pSuivant; //la liste récupère la référence de l'élément suivant

                //libère l'élément a supprimer.
                free(pElement);
            }else{

            // SINON parcourt les éléments de la liste pour trouver l'élément précédent a supprimer.

                pElement = pListe->pPremier;

                while ((pElement != NULL) && (pElement->pSuivant != pElementSupprimer)){
                    pElement = pElement->pSuivant;
                }

                //raccorche l'lément précédent avec le suivant
                pElement->pSuivant = pElementSupprimer->pSuivant;

                free(pElementSupprimer);    //libère l'élément a supprimer.
            }

            pListe->nbElements--;       //décrémente le nombre d'éléments de la liste
        }else{
            printf("\nErreur lors de la suppression d'un element de la liste de bouton, la liste est vide.");
        }
    }

}

//###########################################
//PROCEDURE vidageListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime tous les éléments de la liste.
//
// ENTREE /La référence de la la liste.
//
// SORTIE / La mémoire libéré.
//
// NOTE -
//*****************************************************************************************************//
void vidageListeBouton(tListeBouton *pListe){
    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur la liste n'existe pas ou est vide.");
        exit(EXIT_FAILURE);
    }

    while(pListe->pPremier!=NULL){
        suppressionBoutonListe(pListe,pListe->pPremier);
    }
}
//###########################################
//PROCEDURE destructionListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime tous les éléments de la liste et libère la liste.
//
// ENTREE /La référence de la la liste.
//
// SORTIE / La mémoire libéré.
//
// NOTE -
//*****************************************************************************************************//
void destructionListeBouton(tListeBouton *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }else{

        if(pListe->pPremier != NULL){   //si la liste n'est pas vide, la vide.
            vidageListeBouton(pListe);
        }
        free(pListe);   //libère la liste
    }

}

//###########################################
//PROCEDURE affichageBoutonListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les boutons de la liste.
//
// ENTREE / La ref du renderer, la référence de la la liste.
//
// SORTIE / L'affichage des boutons.
//
// NOTE -
//*****************************************************************************************************//
void affichageListeBouton(SDL_Renderer *pRenderer,tListeBouton *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur d'affichage, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    //SI LA LISTE N'EST PAS VIDE
    if(pListe->pPremier != NULL){
       tElementBouton *pElement = pListe->pPremier;
        while(pElement->pSuivant!=NULL){
            dessineBouton(pRenderer, &pElement->stBouton);
            pElement = pElement->pSuivant;
        }
        dessineBouton(pRenderer, &pElement->stBouton);    //affiche le dernier bouton
    }

}

//###########################################
//FONCTION recupElementBoutonParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de l'élément qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La reférence de l'éméent correspondant ou null
//
// NOTE -
//*****************************************************************************************************//
tElementBouton* recupElementBoutonParNom(tListeBouton *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }

    tElementBouton *pElement = pListe->pPremier;

    //si le première élément correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe ne revu tous les éléments et vérifie si les noms correspondent
    do{
        pElement = pElement->pSuivant;  //on récupère l'élément suivant
        //si le nom correspond
        if(strcmp(sNom,pElement->sNom)==0){
            return pElement;
        }
    }while(pElement->pSuivant!=NULL);   //tant qu'il existe un élément suivant

    printf("\nLe nom ne correspond a aucun élément");
    return NULL;

}


//###########################################
//FONCTION recupBoutonParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de le bouton qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La référence de le bouton correspondant ou null.
//
// NOTE -
//*****************************************************************************************************//
tBouton* recupBoutonParNom(tListeBouton *pListe,const char sNom[]){
    tElementBouton *pElement = recupElementBoutonParNom(pListe,sNom);
    if(pElement==NULL){
        return NULL;
    }else{
        return &(pElement->stBouton);
    }
}

//###########################################
//PROCEDURE gestionListeBoutonPointeur
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui gère l'états de la liste de boutons en fonction de la position du pointeur.
//
// ENTREE / La ref de la liste de boutons, la référence du pointeur.
//
// SORTIE / L'états des boutons modifié.
//
// NOTE -
//*****************************************************************************************************//
void gestionListeBoutonPointeur(tListeBouton *pListe, tPointeur *pstPointeur){
    //PASSE EN REVUE TOUS LES ELEMENTS DE LA LISTE

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL){
        printf("\nErreur lors de la gestion de la liste de bouton, la liste n'existe pas.");
    }

    if(pListe->pPremier != NULL){
        tElementBouton *pElement = pListe->pPremier;
        gestionBoutonPointeur(&pElement->stBouton,pstPointeur);
        while(pElement->pSuivant!=NULL){
            pElement = pElement->pSuivant;
            gestionBoutonPointeur(&pElement->stBouton,pstPointeur);
        }
    }
}




///AUTRES METHODES///

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
void initBouton(tBouton **ppBouton,tObjet *pstObjet, const char sTexte[],tPropTexte *pstPropTexte,const tBool stSurvole, const tBool stClique, const int nCodeAction){
    if((*ppBouton = malloc(sizeof(tBouton)))==NULL){
        printf("\nErreur d'allocation du bouton !");
    }else{
        setBouton(*ppBouton,pstObjet,sTexte,pstPropTexte,stSurvole,stClique,nCodeAction);

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
void setBouton(tBouton *pstBouton,tObjet *pstObjet, const char sTexte[], tPropTexte *pstPropTexte,const tBool stSurvole, const tBool stClique, const int nCodeAction){
    setBoutonObjet(pstBouton,pstObjet);
    setBoutonPropTexte(pstBouton,pstPropTexte);
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
//PROCEDURE setBoutonPropTexte
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie ls propriétés du texte d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton, la référence de la propriété du texte.
//
// SORTIE /La prop du texte modifié.
//
// NOTE -
//*****************************************************************************************************//
void setBoutonPropTexte(tBouton *pstBouton, tPropTexte *pstPropTexte){
    pstBouton->pstPropTexte = pstPropTexte;
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
//FONCTION creeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie un bouton initialisé avec les valeurs passées en paramètre.
//
// ENTREE /L'objet,le texte, la propriété du texte, est survolé, est cliqué, le code de l'action.
//
// SORTIE /Le bouton initialisé.
//
// NOTE -
//*****************************************************************************************************//
tBouton creeBouton(tObjet *pstObjet, const char sTexte[], tPropTexte *pstPropTexte,const tBool stSurvole, const tBool stClique, const int nCodeAction){
    tBouton stBouton;
    setBouton(&stBouton,pstObjet,sTexte,pstPropTexte,stSurvole,stClique,nCodeAction);
    return stBouton;
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
//Fonction getBoutonPropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la référence de la propriété du texte d'un bouton.
//
// ENTREE /La reférence du pointeur du bouton.
//
// SORTIE /La ref de la propriété du texte d'un bouton.
//
// NOTE -
//*****************************************************************************************************//
tPropTexte* getBoutonPropTexte(tBouton *pstBouton){
    return pstBouton->pstPropTexte;
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
//PROCEDURE dessineBouton
//*****************************************************************************************************//
//
// DESCRIPTION Dessine le bouton en fonction de la propriété du texte.
//
// ENTREE La référence du renderer, du bouton, de la propriété du texte.
//
// SORTIE L'affichage du bouton, différent selon qu'il est survolé ou non.
//
// NOTE -
//*****************************************************************************************************//
void dessineBouton(SDL_Renderer *pRenderer,tBouton *pstBouton){
    tPropTexte stPropTexteSurvol;
    dessineObjet(pRenderer,getBoutonObjet(pstBouton),getBoutonSurvole(pstBouton));  //affiche un rectangle plein si survolé
    if(!getBoutonSurvole(pstBouton)){
        ecrireChaine(pRenderer,getBoutonTexte(pstBouton),getBoutonObjet(pstBouton),getBoutonPropTexte(pstBouton));   //affiche le texte
    }else{
        setPropTexte(&stPropTexteSurvol,getPropTexteTaille(getBoutonPropTexte(pstBouton)),getPropTexteEmplpolice(getBoutonPropTexte(pstBouton)),*getPropTexteCouleurAPlan(getBoutonPropTexte(pstBouton)),*getPropTexteCouleur(getBoutonPropTexte(pstBouton)),getPropTexteStyle(getBoutonPropTexte(pstBouton)),getPropTexteCharset(getBoutonPropTexte(pstBouton)),getPropTexteMode(getBoutonPropTexte(pstBouton)));
        ecrireChaine(pRenderer,getBoutonTexte(pstBouton),getBoutonObjet(pstBouton),&stPropTexteSurvol);
    }

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
