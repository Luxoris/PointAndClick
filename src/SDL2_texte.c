#include "SDL2_texte.h"

//Doc lib : http://sdl.beuc.net/sdl.wiki/SDL_ttf

const SDL_Color SDL_CL_BLANC = {255,255,255,255};
const SDL_Color SDL_CL_NOIR = {0,0,0,255};
const SDL_Color SDL_CL_ROUGE = {255,0,0,255};
const SDL_Color SDL_CL_BLEU = {0,0,255,255};
const SDL_Color SDL_CL_VERT = {0,255,0,255};
const SDL_Color SDL_CL_MAGENTA = {255,0,255,255};
const SDL_Color SDL_CL_JAUNE = {255,255,0,255};
const SDL_Color SDL_CL_CYAN = {0,255,255,255};
const SDL_Color SDL_CL_MERE = {255,0,255,255};
const SDL_Color SDL_CL_PERE = {0,255,0,255};
const SDL_Color SDL_CL_JOUEUR = {255,255,255,255};
const SDL_Color SDL_CL_CHAUFFEUR = {0,255,255,255};
const SDL_Color SDL_CL_SURVEILLANT = {0,255,255,255};
const SDL_Color SDL_CL_ELEVE = {255,255,0,255};
const SDL_Color SDL_CL_MONSTRE = {255,0,255,255};

///METHODES DE LA LISTE DE PROPTEXTE///

//###########################################
//FONCTION initialisationListePropTexte
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui initialise une liste de propTexte.
//
// ENTREE /
//
// SORTIE / La référence de la liste de propTexte
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
// DESCRIPTION Procedure qui insert un élément dans la liste, après la référence de l'élément. Prend NULL si insertion au début.
//
// ENTREE /La référence de la la liste, la ref de l'élément propTexte, la référence de l'élement d'insertion, le nom de le propTexte.
//
// SORTIE / L'allocation du nouvelle élément, les réferences modifiés.
//
// NOTE -
//*****************************************************************************************************//
void insertionPropTexteListe(tListePropTexte *pListe, tElementPropTexte *pElementInsetion,const tPropTexte stPropTexte,const char sNom[]){
    tElementPropTexte *pElement = malloc(sizeof(tElementPropTexte));
    if (pListe == NULL || pElement == NULL) //vérifie que l'allocation a fonctionné
    {
        printf("\nErreur lors de l'allocation d'un element de la liste de propTexte.");
        exit(EXIT_FAILURE);
    }
    pElement->stPropTexte = stPropTexte;    //l'élément reçoit la référence de le propTexte
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
//PROCEDURE suppressionPropTexteListe
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
void suppressionPropTexteListe(tListePropTexte *pListe, tElementPropTexte *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste de propTexte, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'élément, l'élément vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementPropTexte *pElement = NULL;
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
            printf("\nErreur lors de la suppression d'un element de la liste de propTexte, la liste est vide.");
        }

    }


}

//###########################################
//PROCEDURE vidageListePropTexte
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
// DESCRIPTION Procedure qui supprime tous les éléments de la liste et libère la liste.
//
// ENTREE /La référence de la la liste.
//
// SORTIE / La mémoire libéré.
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
        free(pListe);   //libère la liste
    }

}


//###########################################
//FONCTION recupElementPropTexteParNom
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
tElementPropTexte* recupElementPropTexteParNom(tListePropTexte *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }

    tElementPropTexte *pElement = pListe->pPremier;

    //si le première élément correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe en revu tous les éléments et vérifie si les noms correspondent
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
//FONCTION recupPropTexteParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de le propTexte qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La référence de le propTexte correspondant ou null.
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
// SORTIE / La référence de la liste de texte
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
// DESCRIPTION Procedure qui insert un élément dans la liste, après la référence de l'élément. Prend NULL si insertion au début.
//
// ENTREE /La référence de la la liste, la ref de l'élément texte, la référence de l'élement d'insertion, le nom de le texte.
//
// SORTIE / L'allocation du nouvelle élément, les réferences modifiés.
//
// NOTE -
//*****************************************************************************************************//
void insertionTexteListe(tListeTexte *pListe, tElementTexte *pElementInsetion,const tTexte stTexte,const char sNom[]){
    tElementTexte *pElement = malloc(sizeof(tElementTexte));
    if (pListe == NULL || pElement == NULL) //vérifie que l'allocation a fonctionné
    {
        printf("\nErreur lors de l'allocation d'un element de la liste de texte.");
        exit(EXIT_FAILURE);
    }
    pElement->stTexte = stTexte;    //l'élément reçoit la référence de le texte
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
//PROCEDURE suppressionTexteListe
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
void suppressionTexteListe(tListeTexte *pListe, tElementTexte *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste de texte, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'élément, l'élément vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){

            tElementTexte *pElement=NULL;

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
            printf("\nErreur lors de la suppression d'un element de la liste de texte, la liste est vide.");
        }
    }

}

//###########################################
//PROCEDURE vidageListeTexte
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
// DESCRIPTION Procedure qui supprime tous les éléments de la liste et libère la liste.
//
// ENTREE /La référence de la la liste.
//
// SORTIE / La mémoire libéré.
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
        free(pListe);   //libère la liste
    }

}

//###########################################
//PROCEDURE affichageTexteListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les textes de la liste.
//
// ENTREE / La ref du renderer, la référence de la la liste.
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
// DESCRIPTION Fonction qui récupère la ref de l'élément qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La reférence de l'éméent correspondant ou null
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

    //si le première élément correspond au nom
    if(strcmp(sNom,pElement->sNom)==0){
        return pElement;
    }

    //POUR LES ELEMENTS SUIVANTS
    //passe ne revu tous les éléments et vérifie si les noms correspondent
    do{
        pElement = pElement->pSuivant;  //on récupère l'élément suivant
        //si le nom correspond
        if((strcmp(sNom,pElement->sNom)==0)){
            return pElement;
        }
    }while(pElement->pSuivant!=NULL);   //tant qu'il existe un élément suivant

    printf("\nLe nom ne correspond a aucun élément");
    return NULL;

}


//###########################################
//FONCTION recupTexteParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de le texte qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La référence de le texte correspondant ou null.
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
// ENTREE La ref de la propriété du Texte (tPropTexte), la taille (int), l'emplacement de la police (char *), la couleur (SDL_Color), la couleur de l'arrière plan(SDL_Color), le style (tTTF_Style), le jeu de caractère (tTTF_Charset), le mode (tTTF_Mode).
//
// SORTIE Les champs de tPropTexte Modifiée
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
// ENTREE La ref de la propriété du Texte (tPropTexte), la taille (int).
//
// SORTIE La taille de tPropTexte Modifiée
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
// ENTREE La ref de la propriété du Texte (tPropTexte), l'emplacement de la police (char *).
//
// SORTIE L'emplacement de la police de tPropTexte Modifiée
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
// ENTREE La ref de la propriété du Texte (tPropTexte), le charset (tTTF_Charset).
//
// SORTIE Le charset de tPropTexte Modifiée
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
// ENTREE La ref de la propriété du Texte (tPropTexte), le Mode(tTTF_Mode).
//
// SORTIE Le mode de tPropTexte Modifiée
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
// ENTREE La ref de la propriété du Texte (tPropTexte), le tableau de char correspondant au style a appliquer
//
// SORTIE Le style de tPropTexte Modifiée
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
// ENTREE La ref de la propriété du Texte (tPropTexte), la couleur (SDL_Color).
//
// SORTIE La couleur de tPropTexte Modifiée
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
// DESCRIPTION Modifie la couleur de l'arrière plan d'un element de type tPropTexte
//
// ENTREE La ref de la propriété du Texte (tPropTexte), la couleur (SDL_Color).
//
// SORTIE La couleur APlan de tPropTexte Modifiée
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
// DESCRIPTION Renvoie une PropTexte avec les valeurs renseingées.
//
// ENTREE La taille (int), l'emplacement de la police (char *), la couleur (SDL_Color), la couleur de l'arrière plan(SDL_Color), le style (tTTF_Style), le jeu de caractère (tTTF_Charset), le mode (tTTF_Mode).
//
// SORTIE LA propTexte avec les valeurs renseignées.
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
// ENTREE La ref de la propriété du Texte (tPropTexte).
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
// ENTREE La ref de la propriété du Texte (tPropTexte).
//
// SORTIE La ref correspondant à l'emplacment de la police.
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
// ENTREE La ref de la propriété du Texte (tPropTexte).
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
// ENTREE La ref de la propriété du Texte (tPropTexte).
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
// ENTREE La ref de la propriété du Texte (tPropTexte)
//
// SORTIE La ref du tableau de caractère correspondant au style a appliquer
//
// NOTE - //code correspondant aux style à appliquer, b : bold, u: underline, i : italic, par defaut normal.
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
// ENTREE La ref de la propriété du Texte (tPropTexte).
//
// SORTIE La ref de la couleur (SDL_Color)
//
// NOTE - L'unicode et le glyph ne sont pas encore gérer
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
// ENTREE La ref de la propriété du Texte (tPropTexte).
//
// SORTIE La ref de la couleur de l'arrière plan (SDL_Color)
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
// ENTREE La ref du Texte (tTexte), la chaine de caractere (char *), l'objet (tObjet), la ref de la propriété du texte (tPropTexte *)
//
// SORTIE Les champs de tTexte modifiées
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
// ENTREE La ref du Texte (tTexte), la chaine de caractère.
//
// SORTIE Le texte de tTexte modifié
//
// NOTE -
//*****************************************************************************************************//
void setTexteTexte(tTexte* pTexte, char pcTexte[]){
    strncpy(pTexte->sTexte,pcTexte,TTF_TAILLE_CHAINE);
}

//###########################################
//PROCEDURE setTexteObjet
//*****************************************************************************************************//
//
// DESCRIPTION Modifie l'objet d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), l'objet
//
// SORTIE L'objet  de tTexte modifié
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
// DESCRIPTION Modifie la référence de la propriété du texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la référence de la propriété du texte
//
// SORTIE La référence de la propriété du texte de tTexte modifiée
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
// DESCRIPTION Renvoie un élément de type texte avec les valeurs renseignées.
//
// ENTREE La chaine de caractere (char *), l'objet (tObjet), la ref de la propriété du texte (tPropTexte *)
//
// SORTIE Le tTexte avec les valeurs renseignées.
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
// DESCRIPTION Récupère le texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la référence de la chaine retournée
//
// SORTIE La référence de la chaine retournée
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
// DESCRIPTION Récupère la ref de l'objet d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la référence de l'objet retournée
//
// SORTIE La référence de l'objet retournée
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
// DESCRIPTION Récupère la ref de la prop du texte d'un element de type tTexte
//
// ENTREE La ref du Texte (tTexte), la référence de la prop du texte retournée
//
// SORTIE La référence de la prop du texte retournée
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
// DESCRIPTION Ecrit le texte d'un élément de type texte dans la zone de l'objet.
//
// ENTREE La ref du Texte (tTexte).
//
// SORTIE Le texte affiché
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

    //récupération de la chiane du texte
    //getTexteTexte(pstTexte,getTexteTexte(pstTexte));

    if(!(strcmp(getTexteTexte(pstTexte),"")==0)){   //si le texte n'est pas vide
        strcpy(pcEmplPolice,getPropTexteEmplpolice(pstPropTexte));
        //Vérification du bon chargement de la police
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

            //si la surface a été créer
            if(pstSurfaceTexte==NULL){
                printf("\nImpossible de creer la surface du texte. - %s\n", TTF_GetError());
            }else{
                //vérifie si la texture a bien été crée
                if((pstTexture=SDL_CreateTextureFromSurface(pRenderer,pstSurfaceTexte))==NULL){
                    printf("\nErreur lors de la création de la texture. - %s\n", SDL_GetError());
                }else{
                    SDL_FreeSurface(pstSurfaceTexte);   //libère la surface

                    SDL_QueryTexture(pstTexture,NULL,NULL,&nTexteLargeur,&nTexteHauteur);
                    stSurfaceDuTexte.w = nTexteLargeur;
                    stSurfaceDuTexte.h = nTexteHauteur;
                    stPoint = convertionPointVersSDL_Point(getRectanglePointCentral(getObjetRectangle(getTexteObjet(pstTexte))));
                    stSurfaceDuTexte.x = getSDLPointX(&stPoint)-(nTexteLargeur*0.5);
                    stSurfaceDuTexte.y = getSDLPointY(&stPoint)-(nTexteHauteur*0.5);


                        //applique la texture dans la surface
                    SDL_RenderCopy(pRenderer,pstTexture,NULL,&stSurfaceDuTexte); //applique la texture
                    SDL_DestroyTexture(pstTexture);  //détruit la texture

                }
            }

        }
    }

}

//###########################################
//PROCEDURE ecrireChaine
//*****************************************************************************************************//
//
// DESCRIPTION Ecrit la chaine de caractère à partir, d'un élément objet, et d'un élément propriété du texte.
//
// ENTREE La chaine, la ref de l'objet, la ref de la propriété du texte
//
// SORTIE Le texte affiché
//
// NOTE -
//*****************************************************************************************************//
void ecrireChaine(SDL_Renderer* pRenderer, char cChaine[], tObjet *pstObjet, tPropTexte * pstPropTexte){
    tTexte stTexte;
    setTexte(&stTexte,cChaine,pstObjet,pstPropTexte);
    ecrireTexte(pRenderer,&stTexte);

}
