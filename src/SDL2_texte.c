#include "SDL2_texte.h"

//Doc lib : http://sdl.beuc.net/sdl.wiki/SDL_ttf

const SDL_Color SDL_CL_BLANC = {255,255,255,255};
const SDL_Color SDL_CL_NOIR = {0,0,0,255};
const SDL_Color SDL_CL_ROUGE = {0,0,255,255};
const SDL_Color SDL_CL_BLEU = {255,0,0,255};
const SDL_Color SDL_CL_VERT = {0,255,0,255};
const SDL_Color SDL_CL_MAGENTA = {255,0,255,255};
const SDL_Color SDL_CL_JAUNE = {0,255,255,255};
const SDL_Color SDL_CL_CYAN = {255,255,0,255};

///METHODES DE LA LISTE DE PROPTEXTE///

//###########################################
//FONCTION initialisationListePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui initialise une liste de propTexte.
//
// ENTREE /
//
// SORTIE / La r�f�rence de la liste de propTexte
//
// NOTE -
//*****************************************************************************************************//
tListePropTexte *initialisationListePropTexte(){

    tListePropTexte *pListe = malloc(sizeof(tListePropTexte));

    if (pListe == NULL){
        printf("\nErreur lors de l'initialisation de la liste de propTexte.");
        exit(EXIT_FAILURE);
    }else{
        pListe->nbElements = 0;
        pListe->pPremier = NULL;
    }
    return pListe;
}

//###########################################
//PROCEDURE insertionPropTexteListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui insert un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment. Prend NULL si insertion au d�but.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'�l�ment propTexte, la r�f�rence de l'�lement d'insertion, le nom de le propTexte.
//
// SORTIE / L'allocation du nouvelle �l�ment, les r�ferences modifi�s.
//
// NOTE -
//*****************************************************************************************************//
void insertionPropTexteListe(tListePropTexte *pListe, tElementPropTexte *pElementInsetion,const tPropTexte stPropTexte,const char sNom[]){
    tElementPropTexte *pElement = malloc(sizeof(tElementPropTexte));
    if (pListe == NULL || pElement == NULL) //v�rifie que l'allocation a fonctionn�
    {
        printf("\nErreur lors de l'allocation d'un element de la liste de propTexte.");
        exit(EXIT_FAILURE);
    }
    pElement->stPropTexte = stPropTexte;    //l'�l�ment re�oit la r�f�rence de le propTexte
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
//PROCEDURE suppressionPropTexteListe
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
void suppressionPropTexteListe(tListePropTexte *pListe, tElementPropTexte *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste de propTexte, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'�l�ment, l'�l�ment vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementPropTexte *pElement = NULL;
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
            printf("\nErreur lors de la suppression d'un element de la liste de propTexte, la liste est vide.");
        }

    }


}

//###########################################
//PROCEDURE vidageListePropTexte
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
void vidageListePropTexte(tListePropTexte *pListe){
    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur la liste n'existe pas ou est vide.");
        exit(EXIT_FAILURE);
    }

    while(pListe->pPremier!=NULL){
        suppressionPropTexteListe(pListe,pListe->pPremier);
    }
}
//###########################################
//PROCEDURE destructionListePropTexte
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
void destructionListePropTexte(tListePropTexte *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }else{

        if(pListe->pPremier != NULL){   //si la liste n'est pas vide, la vide.
            vidageListePropTexte(pListe);
        }
        free(pListe);   //lib�re la liste
    }

}


//###########################################
//FONCTION recupElementPropTexteParNom
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
tElementPropTexte* recupElementPropTexteParNom(tListePropTexte *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }

    tElementPropTexte *pElement = pListe->pPremier;

    //si le premi�re �l�ment correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe en revu tous les �l�ments et v�rifie si les noms correspondent
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
//FONCTION recupPropTexteParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui r�cup�re la ref de le propTexte qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La r�f�rence de le propTexte correspondant ou null.
//
// NOTE -
//*****************************************************************************************************//
tPropTexte* recupPropTexteParNom(tListePropTexte *pListe,const char sNom[]){
    tElementPropTexte *pElement = recupElementPropTexteParNom(pListe,sNom);
    if(pElement==NULL){
        return NULL;
    }else{
        return &(pElement->stPropTexte);
    }
}


///METHODES DE LA LISTE DE TEXTES///

//###########################################
//FONCTION initialisationListeTexte
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui initialise une liste de texte.
//
// ENTREE /
//
// SORTIE / La r�f�rence de la liste de texte
//
// NOTE -
//*****************************************************************************************************//
tListeTexte *initialisationListeTexte(){

    tListeTexte *pListe = malloc(sizeof(tListeTexte));

    if (pListe == NULL){
        printf("\nErreur lors de l'initialisation de la liste de texte.");
        exit(EXIT_FAILURE);
    }else{
        pListe->nbElements = 0;
        pListe->pPremier = NULL;
    }
    return pListe;
}

//###########################################
//PROCEDURE insertionTexteListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui insert un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment. Prend NULL si insertion au d�but.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'�l�ment texte, la r�f�rence de l'�lement d'insertion, le nom de le texte.
//
// SORTIE / L'allocation du nouvelle �l�ment, les r�ferences modifi�s.
//
// NOTE -
//*****************************************************************************************************//
void insertionTexteListe(tListeTexte *pListe, tElementTexte *pElementInsetion,const tTexte stTexte,const char sNom[]){
    tElementTexte *pElement = malloc(sizeof(tElementTexte));
    if (pListe == NULL || pElement == NULL) //v�rifie que l'allocation a fonctionn�
    {
        printf("\nErreur lors de l'allocation d'un element de la liste de texte.");
        exit(EXIT_FAILURE);
    }
    pElement->stTexte = stTexte;    //l'�l�ment re�oit la r�f�rence de le texte
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
//PROCEDURE suppressionTexteListe
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
void suppressionTexteListe(tListeTexte *pListe, tElementTexte *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste de texte, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'�l�ment, l'�l�ment vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){

            tElementTexte *pElement=NULL;

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
            printf("\nErreur lors de la suppression d'un element de la liste de texte, la liste est vide.");
        }
    }

}

//###########################################
//PROCEDURE vidageListeTexte
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
void vidageListeTexte(tListeTexte *pListe){
    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur la liste n'existe pas ou est vide.");
        exit(EXIT_FAILURE);
    }

    while(pListe->pPremier!=NULL){
        suppressionTexteListe(pListe,pListe->pPremier);
    }
}
//###########################################
//PROCEDURE destructionListeTexte
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
void destructionListeTexte(tListeTexte *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }else{

        if(pListe->pPremier != NULL){   //si la liste n'est pas vide, la vide.
            vidageListeTexte(pListe);
        }
        free(pListe);   //lib�re la liste
    }

}

//###########################################
//PROCEDURE affichageTexteListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les textes de la liste.
//
// ENTREE / La ref du renderer, la r�f�rence de la la liste.
//
// SORTIE / L'affichage des textes.
//
// NOTE -
//*****************************************************************************************************//
void affichageListeTexte(SDL_Renderer *pRenderer,tListeTexte *pListe){
    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur d'affichage, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    //SI LA LISTE N'EST PAS VIDE
    if(pListe->pPremier != NULL){
        tElementTexte *pElement = pListe->pPremier;
        while(pElement->pSuivant!=NULL){
            ecrireTexte(pRenderer, &pElement->stTexte);
            pElement = pElement->pSuivant;
        }
        ecrireTexte(pRenderer, &pElement->stTexte);    //affiche le derner texte
    }

}

//###########################################
//FONCTION recupElementTexteParNom
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
tElementTexte* recupElementTexteParNom(tListeTexte *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }

    tElementTexte *pElement = pListe->pPremier;

    //si le premi�re �l�ment correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe ne revu tous les �l�ments et v�rifie si les noms correspondent
    do{
        pElement = pElement->pSuivant;  //on r�cup�re l'�l�ment suivant
        //si le nom correspond
        if((strcmp(sNom,pElement->sNom)==0)){
            return pElement;
        }
    }while(pElement->pSuivant!=NULL);   //tant qu'il existe un �l�ment suivant

    printf("\nLe nom ne correspond a aucun �l�ment");
    return NULL;

}


//###########################################
//FONCTION recupTexteParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui r�cup�re la ref de le texte qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La r�f�rence de le texte correspondant ou null.
//
// NOTE -
//*****************************************************************************************************//
tTexte* recupTexteParNom(tListeTexte *pListe,const char sNom[]){
    tElementTexte *pElement = recupElementTexteParNom(pListe,sNom);
    if(pElement==NULL){
        return NULL;
    }else{
        return &(pElement->stTexte);
    }
}


///AUTRES METHODES///



//###########################################
//PROCEDURE initTTF
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui initilise SDL_TTF
//
// ENTREE /
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void initTTF(){

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    }

}


//###########################################
//PROCEDURE arretTTF
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui arrete SDL_TTF
//
// ENTREE / Environnement
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void arretTTF(){
    //Arret de SDL_TTF
    TTF_Quit();
}


///GET ET SET DE tPropTexte///


//###########################################
//PROCEDURE setPropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les valeurs d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), la taille (int), l'emplacement de la police (char *), la couleur (SDL_Color), la couleur de l'arri�re plan(SDL_Color), le style (tTTF_Style), le jeu de caract�re (tTTF_Charset), le mode (tTTF_Mode).
//
// SORTIE Les champs de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexte(tPropTexte *pstPropTexte,const int nTaille, const char sEmplPolice[], const SDL_Color stCouleur,const SDL_Color stCouleurAPlan, const char cStyle[],const tTTF_Charset stCharset, const tTTF_Mode stMode){
    setPropTexteTaille(pstPropTexte,nTaille);
    setPropTexteEmplpolice(pstPropTexte,sEmplPolice);
    setPropTexteCouleur(pstPropTexte,stCouleur);
    setPropTexteCouleurAPlan(pstPropTexte,stCouleurAPlan);
    setPropTexteStyle(pstPropTexte,cStyle);
    setPropTexteCharset(pstPropTexte,stCharset);
    setPropTexteMode(pstPropTexte,stMode);
}

//###########################################
//PROCEDURE setPropTexteTaille
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la taille d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), la taille (int).
//
// SORTIE La taille de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteTaille(tPropTexte *pstPropTexte,const int nTaille){
    pstPropTexte->nTaille=nTaille;
}


//###########################################
//PROCEDURE setPropTexteSurface
//*****************************************************************************************************//
//
// DESCRIPTION Modifie l'emplacement de la police d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), l'emplacement de la police (char *).
//
// SORTIE L'emplacement de la police de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteEmplpolice(tPropTexte *pstPropTexte,const char sEmplPolice[]){
    strcpy(pstPropTexte->sEmplPolice,sEmplPolice);
}

//###########################################
//PROCEDURE setPropTexteCharset
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le charset d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), le charset (tTTF_Charset).
//
// SORTIE Le charset de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteCharset(tPropTexte *pstPropTexte,const tTTF_Charset stCharset){
    pstPropTexte->stCharset=stCharset;
}

//###########################################
//PROCEDURE setPropTexteMode
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le mode d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), le Mode(tTTF_Mode).
//
// SORTIE Le mode de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteMode(tPropTexte *pstPropTexte,const tTTF_Mode stMode){
    pstPropTexte->stMode=stMode;
}
//###########################################
//PROCEDURE setPropTexteStyle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le style d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), le tableau de char correspondant au style a appliquer
//
// SORTIE Le style de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteStyle(tPropTexte *pstPropTexte,const char cStyle[TTF_NB_FONT_STYLE]){
    strcpy(pstPropTexte->cStyle,cStyle);
}

//###########################################
//PROCEDURE setPropTexteCouleur
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la couleur d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), la couleur (SDL_Color).
//
// SORTIE La couleur de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteCouleur(tPropTexte *pstPropTexte,SDL_Color stCouleur){
    pstPropTexte->stCouleur=stCouleur;
}

//###########################################
//PROCEDURE setPropTexteCouleurAPlan
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la couleur de l'arri�re plan d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte), la couleur (SDL_Color).
//
// SORTIE La couleur APlan de tPropTexte Modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setPropTexteCouleurAPlan(tPropTexte *pstPropTexte,SDL_Color stCouleur){
    pstPropTexte->stCouleurAPlan=stCouleur;
}

//###########################################
//Fonction creePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie une PropTexte avec les valeurs renseing�es.
//
// ENTREE La taille (int), l'emplacement de la police (char *), la couleur (SDL_Color), la couleur de l'arri�re plan(SDL_Color), le style (tTTF_Style), le jeu de caract�re (tTTF_Charset), le mode (tTTF_Mode).
//
// SORTIE LA propTexte avec les valeurs renseign�es.
//
// NOTE -
//*****************************************************************************************************//
tPropTexte creePropTexte(const int nTaille, const char sEmplPolice[], const SDL_Color stCouleur,const SDL_Color stCouleurAPlan, const char cStyle[],const tTTF_Charset stCharset, const tTTF_Mode stMode){
    tPropTexte stPropTexte;
    setPropTexte(&stPropTexte,nTaille,sEmplPolice,stCouleur,stCouleurAPlan,cStyle,stCharset,stMode);
    return stPropTexte;
}


//###########################################
//FONCTION getPropTexteTaille
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la taille d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte).
//
// SORTIE La taille
//
// NOTE -
//*****************************************************************************************************//
int getPropTexteTaille(tPropTexte *pstPropTexte){
    return pstPropTexte->nTaille;
}


//###########################################
//PROCEDURE getPropTexteEmplPolice
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie l'emplacement de la police d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte).
//
// SORTIE La ref correspondant � l'emplacment de la police.
//
// NOTE -
//*****************************************************************************************************//
char* getPropTexteEmplpolice(tPropTexte *pstPropTexte){
    return pstPropTexte->sEmplPolice;
}

//###########################################
//FONCTION getPropTexteCharset
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le charset d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte).
//
// SORTIE Le charset (tTTF_Charset)
//
// NOTE -
//*****************************************************************************************************//
tTTF_Charset getPropTexteCharset(tPropTexte *pstPropTexte){
    return pstPropTexte->stCharset;
}

//###########################################
//FONCTION getPropTexteMode
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le mode d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte).
//
// SORTIE Le mode (tTTF_Mode)
//
// NOTE -
//*****************************************************************************************************//
tTTF_Mode getPropTexteMode(tPropTexte *pstPropTexte){
    return pstPropTexte->stMode;
}

//###########################################
//PROCEUDRE getPropTexteStyle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le Style d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte)
//
// SORTIE La ref du tableau de caract�re correspondant au style a appliquer
//
// NOTE - //code correspondant aux style � appliquer, b : bold, u: underline, i : italic, par defaut normal.
//*****************************************************************************************************//
char* getPropTexteStyle(tPropTexte *pstPropTexte){
    return pstPropTexte->cStyle;
}

//###########################################
//FONCTION getPropTexteCouleur
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la couleur d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte).
//
// SORTIE La ref de la couleur (SDL_Color)
//
// NOTE - L'unicode et le glyph ne sont pas encore g�rer
//*****************************************************************************************************//
SDL_Color *getPropTexteCouleur(tPropTexte *pstPropTexte){
    return &pstPropTexte->stCouleur;
}

//###########################################
//FONCTION getPropTexteCouleurAPlan
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie la couleur d'un element de type tPropTexte
//
// ENTREE La ref de la propri�t� du Texte (tPropTexte).
//
// SORTIE La ref de la couleur de l'arri�re plan (SDL_Color)
//
// NOTE -
//*****************************************************************************************************//
SDL_Color *getPropTexteCouleurAPlan(tPropTexte *pstPropTexte){
    return &pstPropTexte->stCouleurAPlan;
}


///GET ET SET DE tTEXTE///

//###########################################
//PROCEDURE setTexte
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les valeurs d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la chaine de caractere (char *), l'objet (tObjet), la ref de la propri�t� du texte (tPropTexte *)
//
// SORTIE Les champs de tTexte modifi�es
//
// NOTE -
//*****************************************************************************************************//
void setTexte(tTexte* pTexte,char pcTexte[], tObjet *pstObjet, tPropTexte *pPropTexte){
    setTexteTexte(pTexte,pcTexte);
    setTexteObjet(pTexte,pstObjet);
    setTextePropTexte(pTexte,pPropTexte);
}

//###########################################
//PROCEDURE setTexteTexte
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la chaine de caract�re.
//
// SORTIE Le texte de tTexte modifi�
//
// NOTE -
//*****************************************************************************************************//
void setTexteTexte(tTexte* pTexte, char pcTexte[]){
    strcpy(pTexte->sTexte,pcTexte);
}

//###########################################
//PROCEDURE setTexteObjet
//*****************************************************************************************************//
//
// DESCRIPTION Modifie l'objet d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), l'objet
//
// SORTIE L'objet  de tTexte modifi�
//
// NOTE -
//*****************************************************************************************************//
void setTexteObjet(tTexte* pTexte, tObjet *pstObjet){
    pTexte->pstObjet = pstObjet;

}

//###########################################
//PROCEDURE setTextePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la r�f�rence de la propri�t� du texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la r�f�rence de la propri�t� du texte
//
// SORTIE La r�f�rence de la propri�t� du texte de tTexte modifi�e
//
// NOTE -
//*****************************************************************************************************//
void setTextePropTexte(tTexte* pTexte, tPropTexte *pPropTexte){
    pTexte->pPropTexte = pPropTexte;
}


//###########################################
//FONCTION creeTexte
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie un �l�ment de type texte avec les valeurs renseign�es.
//
// ENTREE La chaine de caractere (char *), l'objet (tObjet), la ref de la propri�t� du texte (tPropTexte *)
//
// SORTIE Le tTexte avec les valeurs renseign�es.
//
// NOTE -
//*****************************************************************************************************//
tTexte creeTexte(char pcTexte[], tObjet *pstObjet, tPropTexte *pPropTexte){
    tTexte stTexte;
    setTexte(&stTexte,pcTexte,pstObjet,pPropTexte);
    return stTexte;
}


//###########################################
//FONCTION getTexteTexte
//*****************************************************************************************************//
//
// DESCRIPTION R�cup�re le texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la r�f�rence de la chaine retourn�e
//
// SORTIE La r�f�rence de la chaine retourn�e
//
// NOTE -
//*****************************************************************************************************//
char* getTexteTexte(tTexte *pTexte){
    return pTexte->sTexte;
}

//###########################################
//FONCTION getTexteObjet
//*****************************************************************************************************//
//
// DESCRIPTION R�cup�re la ref de l'objet d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la r�f�rence de l'objet retourn�e
//
// SORTIE La r�f�rence de l'objet retourn�e
//
// NOTE -
//*****************************************************************************************************//
extern tObjet* getTexteObjet(tTexte* pTexte){
    return pTexte->pstObjet;
}

//###########################################
//FONCTION getTextePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION R�cup�re la ref de la prop du texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la r�f�rence de la prop du texte retourn�e
//
// SORTIE La r�f�rence de la prop du texte retourn�e
//
// NOTE -
//*****************************************************************************************************//
tPropTexte* getTextPropTexte(tTexte* pTexte){
    return pTexte->pPropTexte;
}



///AUTRES METHODES///

//###########################################
//PROCEDURE ecrireTexte
//*****************************************************************************************************//
//
// DESCRIPTION Ecrit le texte d'un �l�ment de type texte dans la zone de l'objet.
//
// ENTREE La ref du Texte (tTexte).
//
// SORTIE Le texte affich�
//
// NOTE -
//*****************************************************************************************************//
void ecrireTexte(SDL_Renderer* pRenderer, tTexte * pstTexte){
    int nI=0, nTexteHauteur,nTexteLargeur;
    char pcEmplPolice[255]="",cStyle[TTF_NB_FONT_STYLE]="";
    SDL_Surface *pstSurfaceTexte=NULL;
    TTF_Font *pstPolice=NULL;
    SDL_Texture *pstTexture;
    SDL_Rect stSurfaceDuTexte;
    SDL_Point stPoint;
    tPropTexte *pstPropTexte = getTextPropTexte(pstTexte);

    //r�cup�ration de la chiane du texte
    //getTexteTexte(pstTexte,getTexteTexte(pstTexte));

    strcpy(pcEmplPolice,getPropTexteEmplpolice(pstPropTexte));
    //V�rification du bon chargement de la police
    if((pstPolice=TTF_OpenFont(pcEmplPolice,getPropTexteTaille(pstPropTexte)))==NULL){
        printf("\nImpossible de charger la police : %s - TTF_OpenFont: %s\n",pcEmplPolice, TTF_GetError());
    }else{
        while(cStyle[nI]!='\0'){
            switch(cStyle[nI]){
            case 'u': TTF_SetFontStyle(pstPolice,TTF_STYLE_UNDERLINE);break;
            case 'i': TTF_SetFontStyle(pstPolice,TTF_STYLE_ITALIC);break;
            case 'b': TTF_SetFontStyle(pstPolice,TTF_STYLE_BOLD);break;
            }
        }


        switch(getPropTexteCharset(pstPropTexte)){
            case TTF_Charset_Latin1:
                switch (getPropTexteMode(pstPropTexte)){
                    case TTF_Mode_Solid: pstSurfaceTexte=TTF_RenderText_Solid(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Shaded: pstSurfaceTexte=TTF_RenderText_Shaded(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Blended: pstSurfaceTexte=TTF_RenderText_Blended(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                }
                break;
            case TTF_Charset_UTF8:
                switch (getPropTexteMode(pstPropTexte)){
                    case TTF_Mode_Solid: pstSurfaceTexte=TTF_RenderUTF8_Solid(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Shaded: pstSurfaceTexte=TTF_RenderUTF8_Shaded(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Blended: pstSurfaceTexte=TTF_RenderUTF8_Blended(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                }
                break;
            /*case TTF_Charset_Unicode:
                switch (getPropTexteMode(pstPropTexte)){
                    case TTF_Mode_Solid: pstSurfaceTexte=TTF_RenderUNICODE_Solid(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Shaded: pstSurfaceTexte=TTF_RenderUNICODE_Shaded(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Blended: pstSurfaceTexte=TTF_RenderUNICODE_Blended(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                }
                break;
            case TTF_Charset_UnicodeGlyph:
                switch (getPropTexteMode(pstPropTexte)){
                    case TTF_Mode_Solid: pstSurfaceTexte=TTF_RenderGlyph_Solid(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Shaded: pstSurfaceTexte=TTF_RenderGlyph_Shaded(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte),*getPropTexteCouleur(pstPropTexte)); break;
                    case TTF_Mode_Blended: pstSurfaceTexte=TTF_RenderGlyph_Blended(pstPolice,getTexteTexte(pstTexte),*getPropTexteCouleur(pstPropTexte)); break;
                }
                break;*/
            }

        TTF_CloseFont(pstPolice);   //fermeture de la police

        //si la surface a �t� cr�er
        if(pstSurfaceTexte==NULL){
            printf("\nImpossible de creer la surface du texte. - %s\n", TTF_GetError());
        }else{
            //v�rifie si la texture a bien �t� cr�e
            if((pstTexture=SDL_CreateTextureFromSurface(pRenderer,pstSurfaceTexte))==NULL){
                printf("\nErreur lors de la cr�ation de la texture. - %s\n", SDL_GetError());
            }else{
                SDL_FreeSurface(pstSurfaceTexte);   //lib�re la surface

                SDL_QueryTexture(pstTexture,NULL,NULL,&nTexteLargeur,&nTexteHauteur);
                stSurfaceDuTexte.w = nTexteLargeur;
                stSurfaceDuTexte.h = nTexteHauteur;
                stPoint = convertionPointVersSDL_Point(getRectanglePointCentral(getObjetRectangle(getTexteObjet(pstTexte))));
                stSurfaceDuTexte.x = getSDLPointX(&stPoint)-(nTexteLargeur*0.5);
                stSurfaceDuTexte.y = getSDLPointY(&stPoint)-(nTexteHauteur*0.5);


                    //applique la texture dans la surface
                SDL_RenderCopy(pRenderer,pstTexture,NULL,&stSurfaceDuTexte); //applique la texture
                SDL_DestroyTexture(pstTexture);  //d�truit la texture

            }
        }

    }
}

//###########################################
//PROCEDURE ecrireChaine
//*****************************************************************************************************//
//
// DESCRIPTION Ecrit la chaine de caract�re � partir, d'un �l�ment objet, et d'un �l�ment propri�t� du texte.
//
// ENTREE La chaine, la ref de l'objet, la ref de la propri�t� du texte
//
// SORTIE Le texte affich�
//
// NOTE -
//*****************************************************************************************************//
void ecrireChaine(SDL_Renderer* pRenderer, char cChaine[], tObjet *pstObjet, tPropTexte * pstPropTexte){
    tTexte stTexte;
    setTexte(&stTexte,cChaine,pstObjet,pstPropTexte);
    ecrireTexte(pRenderer,&stTexte);

}
