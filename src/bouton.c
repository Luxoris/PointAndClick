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
// SORTIE / La r�f�rence de la liste de bouton
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
// DESCRIPTION Procedure qui insert un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment. Prend NULL si insertion au d�but.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'�l�ment bouton, la r�f�rence de l'�lement d'insertion, le nom de le bouton.
//
// SORTIE / L'allocation du nouvelle �l�ment, les r�ferences modifi�s.
//
// NOTE -
//*****************************************************************************************************//
void insertionBoutonListe(tListeBouton *pListe, tElementBouton *pElementInsetion,const tBouton stBouton,const char sNom[]){
    tElementBouton *pElement = malloc(sizeof(tElementBouton));
    if (pListe == NULL || pElement == NULL) //v�rifie que l'allocation a fonctionn�
    {
        printf("\nErreur lors de l'allocation d'un element de la liste de bouton.");
        exit(EXIT_FAILURE);
    }
    pElement->stBouton = stBouton;    //l'�l�ment re�oit la r�f�rence de le bouton
    strcpy(pElement->sNom,sNom);//ajout du nom de l'�l�ment

    if(pListe->pPremier==NULL){ //si la liste est vide
        pElement->pSuivant = NULL;
        pListe->pPremier = pElement;
    }else{ //SI pElementInsertion = NULL, insert l'�l�ment au d�but de la liste
        if((pElementInsetion == NULL)){
            pElement->pSuivant = pListe->pPremier;
            pListe->pPremier = pElement;
        }else{
            //SINON INSERTION D'UN ELEMENT APRES LA REFERENCE//
            pElement->pSuivant = pElementInsetion ->pSuivant;   //l'�l�ment r�cup�re la r�f�rence de l'�l�ment suivant.
            pElementInsetion->pSuivant = pElement;  //l'�l�ment d'isnertion r�cup�re la r�f�rence du nouvelle �l�ment.
        }

    }

    pListe->nbElements++;   //incr�mentation du nombre d'�l�ment de la liste


}

//###########################################
//PROCEDURE suppressionBoutonListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'element a supprimer.
//
// SORTIE / Les r�f�rence de la liste modifi�s, la m�moire lib�r�.
//
// NOTE -  La r�f�rence de l'�l�ment accepte NULL si l'�l�ment a supprimer est le premier.
//*****************************************************************************************************//
void suppressionBoutonListe(tListeBouton *pListe, tElementBouton *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste de bouton, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'�l�ment, l'�l�ment vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementBouton *pElement = NULL;

            //Si l'�l�ment a suprimer est le premier de la liste.
            if(pElementSupprimer == pListe->pPremier){
                //pElement r�cup�re la r�f�rence du premier �l�ment de la liste
                pElement = pListe->pPremier;

                //la liste r�cup�re le second �l�ment, et le d�finit comme premier �l�ment
                pListe->pPremier = pListe->pPremier->pSuivant; //la liste r�cup�re la r�f�rence de l'�l�ment suivant

                //lib�re l'�l�ment a supprimer.
                free(pElement);
            }else{

            // SINON parcourt les �l�ments de la liste pour trouver l'�l�ment pr�c�dent a supprimer.

                pElement = pListe->pPremier;

                while ((pElement != NULL) && (pElement->pSuivant != pElementSupprimer)){
                    pElement = pElement->pSuivant;
                }

                //raccorche l'l�ment pr�c�dent avec le suivant
                pElement->pSuivant = pElementSupprimer->pSuivant;

                free(pElementSupprimer);    //lib�re l'�l�ment a supprimer.
            }

            pListe->nbElements--;       //d�cr�mente le nombre d'�l�ments de la liste
        }else{
            printf("\nErreur lors de la suppression d'un element de la liste de bouton, la liste est vide.");
        }
    }

}

//###########################################
//PROCEDURE vidageListeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime tous les �l�ments de la liste.
//
// ENTREE /La r�f�rence de la la liste.
//
// SORTIE / La m�moire lib�r�.
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
// DESCRIPTION Procedure qui supprime tous les �l�ments de la liste et lib�re la liste.
//
// ENTREE /La r�f�rence de la la liste.
//
// SORTIE / La m�moire lib�r�.
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
        free(pListe);   //lib�re la liste
    }

}

//###########################################
//PROCEDURE affichageBoutonListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les boutons de la liste.
//
// ENTREE / La ref du renderer, la r�f�rence de la la liste.
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
// DESCRIPTION Fonction qui r�cup�re la ref de l'�l�ment qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La ref�rence de l'�m�ent correspondant ou null
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

    //si le premi�re �l�ment correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe ne revu tous les �l�ments et v�rifie si les noms correspondent
    do{
        pElement = pElement->pSuivant;  //on r�cup�re l'�l�ment suivant
        //si le nom correspond
        if(strcmp(sNom,pElement->sNom)==0){
            return pElement;
        }
    }while(pElement->pSuivant!=NULL);   //tant qu'il existe un �l�ment suivant

    printf("\nLe nom ne correspond a aucun �l�ment");
    return NULL;

}


//###########################################
//FONCTION recupBoutonParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui r�cup�re la ref de le bouton qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La r�f�rence de le bouton correspondant ou null.
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
// DESCRIPTION Procedure qui g�re l'�tats de la liste de boutons en fonction de la position du pointeur.
//
// ENTREE / La ref de la liste de boutons, la r�f�rence du pointeur.
//
// SORTIE / L'�tats des boutons modifi�.
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
// ENTREE /La ref�rence du pointeur de pointeur du bouton, l'objet, est survol�, est cliqu�, le code de l'action.
//
// SORTIE /La r�f�rence du pointeur de bouton modifi�e, les valeurs du bouton modifi�es.
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
//PROCEDURE setBoutonPropTexte
//*****************************************************************************************************//
//
// DESCRIPTION PROCEDURE qui modifie ls propri�t�s du texte d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton, la r�f�rence de la propri�t� du texte.
//
// SORTIE /La prop du texte modifi�.
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
//FONCTION creeBouton
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie un bouton initialis� avec les valeurs pass�es en param�tre.
//
// ENTREE /L'objet,le texte, la propri�t� du texte, est survol�, est cliqu�, le code de l'action.
//
// SORTIE /Le bouton initialis�.
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
//Fonction getBoutonPropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la r�f�rence de la propri�t� du texte d'un bouton.
//
// ENTREE /La ref�rence du pointeur du bouton.
//
// SORTIE /La ref de la propri�t� du texte d'un bouton.
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
//PROCEDURE dessineBouton
//*****************************************************************************************************//
//
// DESCRIPTION Dessine le bouton en fonction de la propri�t� du texte.
//
// ENTREE La r�f�rence du renderer, du bouton, de la propri�t� du texte.
//
// SORTIE L'affichage du bouton, diff�rent selon qu'il est survol� ou non.
//
// NOTE -
//*****************************************************************************************************//
void dessineBouton(SDL_Renderer *pRenderer,tBouton *pstBouton){
    tPropTexte stPropTexteSurvol;
    dessineObjet(pRenderer,getBoutonObjet(pstBouton),getBoutonSurvole(pstBouton));  //affiche un rectangle plein si survol�
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
// DESCRIPTION V�rifie si le bouton est survol� par le pointeur, et si il y a un clique sur le bouton.
//
// ENTREE /La ref�rence du pointeur du bouton, la r�f�rence du pointeur.
//
// SORTIE /Les bool�ens correspondnat � l'�tat (clique, survole) du bouton modifi�.
//
// NOTE -
//*****************************************************************************************************//
void gestionBoutonPointeur(tBouton *pstBouton, tPointeur *pstPointeur){
    tRectangle stRectangleSouris = creeRectangle(*getPointeurPosition(pstPointeur),LARGEUR_SOURIS,HAUTEUR_SOURIS);
    if(collisionRectangleRectangle(&stRectangleSouris,getObjetRectangle(getBoutonObjet(pstBouton)))){
        setBoutonSurvole(pstBouton,true);
        if(getPointeurCliqueGauche(pstPointeur)){
            setBoutonClique(pstBouton,true);
        }
    }else{
        setBoutonSurvole(pstBouton,false);
        setBoutonClique(pstBouton,false);
    }

}
