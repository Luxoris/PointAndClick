#include "image.h"

#include <stdlib.h>
#include <stdio.h>

///METHODES DE LA LISTE D'IMAGE///

//###########################################
//FONCTION initialisationListeImage
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui initialise une liste d'image.
//
// ENTREE /La référence de la première image de la liste, le nom de la première image de la liste.
//
// SORTIE / La référence de la liste d'image
//
// NOTE -
//*****************************************************************************************************//
tListeImage *initialisationListeImage(){

    tListeImage *pListe = malloc(sizeof(tListeImage));

    if (pListe == NULL)
    {
        printf("\nErreur lors de l'initialisation de la liste d'image.");
        exit(EXIT_FAILURE);
    }else{
        pListe->nbElements = 0;
        pListe->pPremier = NULL;
    }
    return pListe;
}

//###########################################
//PROCEDURE insertionImageListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui insert un élément dans la liste, après la référence de l'élément. Prend NULL si insertion au début.
//
// ENTREE /La référence de la la liste, la ref de l'élément image, la référence de l'élement d'insertion, le nom de l'image.
//
// SORTIE / L'allocation du nouvelle élément, les réferences modifiés.
//
// NOTE -
//*****************************************************************************************************//
void insertionImageListe(tListeImage *pListe, tElementImage *pElementInsetion,const tImage stImage,const char sNom[]){
    tElementImage *pElement = malloc(sizeof(tElementImage));
    if (pListe == NULL || pElement == NULL) //vérifie que l'allocation a fonctionné
    {
        printf("\nErreur lors de l'allocation d'un element de la liste d'image.");
        exit(EXIT_FAILURE);
    }
    pElement->stImage = stImage;    //l'élément reçoit la référence de l'image
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
//PROCEDURE suppressionImageListe
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
void suppressionImageListe(tListeImage *pListe, tElementImage *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste d'image, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'élément, l'élément vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementImage *pElement = NULL;

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
            printf("\nErreur lors de la suppression d'un element de la liste d'image, la liste est vide.");
        }
    }


}

//###########################################
//PROCEDURE vidageListeImage
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
void vidageListeImage(tListeImage *pListe){
    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur la liste n'existe pas ou est vide.");
        exit(EXIT_FAILURE);
    }

    while(pListe->pPremier!=NULL){
        suppressionImageListe(pListe,pListe->pPremier);
    }
}
//###########################################
//PROCEDURE destructionListeImage
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
void destructionListeImage(tListeImage *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }else{

        if(pListe->pPremier != NULL){   //si la liste n'est pas vide, la vide.
            vidageListeImage(pListe);
        }
        free(pListe);   //libère la liste
    }

}

//###########################################
//PROCEDURE affichageImageListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les images de la liste.
//
// ENTREE / La ref du renderer, la référence de la la liste.
//
// SORTIE / L'affichage des images.
//
// NOTE -
//*****************************************************************************************************//
void affichageListeImage(SDL_Renderer *pRenderer,tListeImage *pListe){
    //VERIFIE SI LA LISTE EXISTE
    if (pListe == NULL){
        printf("\nErreur d'affichage, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    //SI LA LISTE N'EST PAS VIDE
    if(pListe->pPremier != NULL){
        tElementImage *pElement = pListe->pPremier;
        while(pElement->pSuivant!=NULL){
            afficheImage(pRenderer, &pElement->stImage);
            pElement = pElement->pSuivant;
        }
        afficheImage(pRenderer, &pElement->stImage);    //affiche la dernière image

    }

}

//###########################################
//FONCTION recupElementImageParNom
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
tElementImage* recupElementImageParNom(tListeImage *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }

    tElementImage *pElement = pListe->pPremier;

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
//FONCTION recupImageParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère la ref de l'image qui porte le nom.
//
// ENTREE / La référence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La référence de l'image correspondant ou null.
//
// NOTE -
//*****************************************************************************************************//
tImage* recupImageParNom(tListeImage *pListe,const char sNom[]){
    tElementImage *pElement = recupElementImageParNom(pListe,sNom);
    if(pElement==NULL){
        return NULL;
    }else{
        return &(pElement->stImage);
    }
}

///AUTRES METHODES///
//###########################################
//PROCEDURE initSDLImage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui initialise la SDL Image avec les PNG et les JPG.
//
// ENTREE /L'environnement
//
// SORTIE / L'environnement
//
// NOTE -
//*****************************************************************************************************//
void initSDLImage(){
    int flags = IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    int initted = IMG_Init(flags);  //initialise SDL_Image pour les PNG et les JPG

    if((initted&flags) != flags){ // Initialisation de la SDL
            printf("\nErreur d'initialisation de la SDL Image JPG et PNG : %s",IMG_GetError());
    }
}


//###########################################
//PROCEDURE initImage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui alloue et initialise d'une image.
//
// ENTREE /La référence du pointeur d'image, la référence de l'objet, la référence de la chaine de caractère correspondant à l'emplacement du fichier image
//
// SORTIE / La référence du pointeur d'image modifiée, les valeurs de l'image modifiées.
//
// NOTE -
//*****************************************************************************************************//
void initImage(tImage **ppstImage,tObjet *pstObjet, char sEmplImage[]){
    if((*ppstImage = malloc(sizeof(tImage)))==NULL){
        printf("\nErreur d'allocation de l'image %s !",sEmplImage);
    }else{
       setImage(*ppstImage,pstObjet, sEmplImage);
    }
}

//###########################################
//PROCEDURE setImage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui modifie les valeurs d'une image.
//
// ENTREE /La référence de l'image, la référence de l'objet, la référence de la chaine de caractère correspondant à l'emplacement du fichier image.
//
// SORTIE / Les valeurs de l'image modifiées.
//
// NOTE -
//*****************************************************************************************************//
void setImage(tImage *pstImage,tObjet *pstObjet, char sEmplImage[]){
    setImageObjet(pstImage,pstObjet);
    setImageEmpl(pstImage,sEmplImage);
}


//###########################################
//PROCEDURE setImageObjet
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui modifie la référence de l'objet d'une image.
//
// ENTREE /La référence de l'image, la référence de l'objet.
//
// SORTIE / La référence de l'objet de l'image modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setImageObjet(tImage *pstImage, tObjet *pstObjet){
    pstImage->pstObjet=pstObjet;
}

//###########################################
//PROCEDURE setImageEmpl
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui modifie l'emplacement d'une image.
//
// ENTREE /La référence de l'image, la chaine correspondant à l'emplacement de l'image.
//
// SORTIE / L'emplacement de l'image modifiée.
//
// NOTE -
//*****************************************************************************************************//
void setImageEmpl(tImage *pstImage, char sEmplImage[]){
    strcpy(pstImage->sEmplImage,sEmplImage);
}

//###########################################
//FONCTION creeImage
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie une image.
//
// ENTREE /La référence de l'objet, la référence de la chaine de caractère correspondant à l'emplacement du fichier image.
//
// SORTIE / L'image avec les valeurs initialisées.
//
// NOTE -
//*****************************************************************************************************//
tImage creeImage(tObjet *pstObjet, char sEmplImage[]){
    tImage stImage;
    setImage(&stImage,pstObjet,sEmplImage);
    return stImage;
}

//###########################################
//FONCTION getImageObjet
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de l'objet d'une image.
//
// ENTREE /La référence de l'image.
//
// SORTIE / La référence de l'objet de l'image.
//
// NOTE -
//*****************************************************************************************************//
tObjet * getImageObjet(tImage *pstImage){
    return pstImage->pstObjet;
}

//###########################################
//FONCTION getImageEmpl
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la référence de l'emplacement d'une image.
//
// ENTREE /La référence de l'image.
//
// SORTIE / La référence de l'emplacement de l'image.
//
// NOTE -
//*****************************************************************************************************//
char * getImageEmpl(tImage *pstImage){
    return pstImage->sEmplImage;
}


//###########################################
//PROCEDURE afficheImage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche une image
//
// ENTREE /La référence du renderer, la référence de l'image.
//
// SORTIE / L'image affichée.
//
// NOTE -
//*****************************************************************************************************//
void afficheImage(SDL_Renderer *pRenderer,tImage *pstImage){
    int nImageHauteur,nImageLargeur;
    char pcEmplImage[IMAGE_TAILLE_CHAINE]="";
    SDL_Surface *pstSurfaceImage=NULL;
    SDL_Texture *pstTexture;
    SDL_Rect stSurfaceImage;
    SDL_Point stPoint;

    strcpy(pcEmplImage,getImageEmpl(pstImage));
    //Vérification du bon chargement de la police


    //creation de la surface de l'image
    pstSurfaceImage = IMG_Load(pcEmplImage);//Chargement de l'image

    //si la surface a été créer
    if(pstSurfaceImage==NULL){
        printf("\nImpossible de creer la surface de l'image. - %s\n", IMG_GetError());
    }else{
        //vérifie si la texture a bien été crée
        if((pstTexture=SDL_CreateTextureFromSurface(pRenderer,pstSurfaceImage))==NULL){
            printf("\nErreur lors de la création de la texture. - %s\n", SDL_GetError());
        }else{
            SDL_FreeSurface(pstSurfaceImage);   //libère la surface

            SDL_QueryTexture(pstTexture,NULL,NULL,&nImageLargeur,&nImageHauteur);
            stSurfaceImage.w = nImageLargeur;
            stSurfaceImage.h = nImageHauteur;
            stPoint = convertionPointVersSDL_Point(getRectanglePointCentral(getObjetRectangle(getImageObjet(pstImage))));
            stSurfaceImage.x = getSDLPointX(&stPoint)-(nImageLargeur*0.5);
            stSurfaceImage.y = getSDLPointY(&stPoint)-(nImageHauteur*0.5);

                //applique la texture dans la surface
            SDL_RenderCopy(pRenderer,pstTexture,NULL,&stSurfaceImage); //applique la texture
            SDL_DestroyTexture(pstTexture);  //détruit la texture
        }
    }
}

//###########################################
//FONCTION dragAndDropImage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui gère le glisser déposer d'un image.
//
// ENTREE /La référence de l'image, la référence du pointeur.
//
// SORTIE / La position de l'image modifiée, le booleen correspondant à etat du drag and drop (si drag andr dop renvoie true sinon false)
//
// NOTE -
//*****************************************************************************************************//
tBool dragAndDropImage(tImage *pstImage, tPointeur *pstPointeur){
    tRectangle stRectangleSouris = creeRectangle(*getPointeurPosition(pstPointeur),LARGEUR_SOURIS,HAUTEUR_SOURIS);
    if(getPointeurCliqueGauche(pstPointeur)&&collisionRectangleRectangle(&stRectangleSouris,getObjetRectangle(getImageObjet(pstImage)))){
        setRectanglePointCentral(getObjetRectangle(getImageObjet(pstImage)),*getPointeurPosition(pstPointeur));
        return true;
    }else{
        return false;
    }
}
