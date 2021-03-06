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
// ENTREE /La r�f�rence de la premi�re image de la liste, le nom de la premi�re image de la liste.
//
// SORTIE / La r�f�rence de la liste d'image
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
// DESCRIPTION Procedure qui insert un �l�ment dans la liste, apr�s la r�f�rence de l'�l�ment. Prend NULL si insertion au d�but.
//
// ENTREE /La r�f�rence de la la liste, la ref de l'�l�ment image, la r�f�rence de l'�lement d'insertion, le nom de l'image.
//
// SORTIE / L'allocation du nouvelle �l�ment, les r�ferences modifi�s.
//
// NOTE -
//*****************************************************************************************************//
void insertionImageListe(tListeImage *pListe, tElementImage *pElementInsetion,const tImage stImage,const char sNom[]){
    tElementImage *pElement = malloc(sizeof(tElementImage));
    if (pListe == NULL || pElement == NULL) //v�rifie que l'allocation a fonctionn�
    {
        printf("\nErreur lors de l'allocation d'un element de la liste d'image.");
        exit(EXIT_FAILURE);
    }
    pElement->stImage = stImage;    //l'�l�ment re�oit la r�f�rence de l'image
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
//PROCEDURE suppressionImageListe
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
void suppressionImageListe(tListeImage *pListe, tElementImage *pElementSupprimer){

    //VERIFIE SI LA LISTE EXISTE, ET QUE L'ELEMENT A SUPPRIMER NE VAUT PAS NULL
    if (pListe == NULL){
        printf("\nErreur lors de la suppression d'un element de la liste d'image, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    if(pElementSupprimer == NULL){
        printf("\nErreur lors de la supression de l'�l�ment, l'�l�ment vaut NULL");
    }else{
        //si la liste n'est pas vide
        if (pListe->pPremier != NULL){
            tElementImage *pElement = NULL;

            //Si l'�l�ment a suprimer est le premier de la liste.
            if(pElementSupprimer == pListe->pPremier){

                //pElement r�cup�re la r�f�rence du premier �l�ment de la liste
                pElement = pListe->pPremier;

                //la liste r�cup�re le second �l�ment, et le d�finit comme premier �l�ment
                pListe->pPremier = pListe->pPremier->pSuivant; //la liste r�cup�re la r�f�rence de l'�l�ment suivant

                ///lib�re l'�l�ment a supprimer.

                //d�truit la texture si l'image est supprimer
                if(pElement->stImage.pTexture!=NULL){
                    SDL_DestroyTexture(pElement->stImage.pTexture);
                    pElement->stImage.pTexture=NULL;
                }
                //lib�re l'�l�ment
                free(pElement);

            }else{

            // SINON parcourt les �l�ments de la liste pour trouver l'�l�ment pr�c�dent a supprimer.

                pElement = pListe->pPremier;

                while ((pElement != NULL) && (pElement->pSuivant != pElementSupprimer)){
                    pElement = pElement->pSuivant;
                }

                //raccorche l'l�ment pr�c�dent avec le suivant
                pElement->pSuivant = pElementSupprimer->pSuivant;

                ///lib�re l'�l�ment a supprimer.

                //d�truit la texture si l'image est supprimer
                if(pElementSupprimer->stImage.pTexture!=NULL){
                    SDL_DestroyTexture(pElementSupprimer->stImage.pTexture);
                    pElementSupprimer->stImage.pTexture=NULL;
                }
                //lib�re l'�l�ment
                free(pElementSupprimer);
            }

            pListe->nbElements--;       //d�cr�mente le nombre d'�l�ments de la liste
        }else{
            printf("\nErreur lors de la suppression d'un element de la liste d'image, la liste est vide.");
        }
    }


}

//###########################################
//PROCEDURE vidageListeImage
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
// DESCRIPTION Procedure qui supprime tous les �l�ments de la liste et lib�re la liste.
//
// ENTREE /La r�f�rence de la la liste.
//
// SORTIE / La m�moire lib�r�.
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
        free(pListe);   //lib�re la liste
    }

}

//###########################################
//PROCEDURE affichageImageListe
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche toutes les images de la liste.
//
// ENTREE / La ref du renderer, la r�f�rence de la la liste.
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
        afficheImage(pRenderer, &pElement->stImage);    //affiche la derni�re image

    }

}

//###########################################
//FONCTION recupElementImageParNom
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
tElementImage* recupElementImageParNom(tListeImage *pListe,const char sNom[]){

    //VERIFIE SI LA LISTE EXISTE, ET QU'ELLE N'EST PAS VIDE
    if (pListe == NULL || pListe->pPremier == NULL){
        printf("\nErreur, la liste n'existe pas ou est vide.");
        return NULL;
    }

    tElementImage *pElement = pListe->pPremier;

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

    printf("\nLe nom %s,ne correspond a aucun element.",sNom);
    return NULL;

}


//###########################################
//FONCTION recupImageParNom
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui r�cup�re la ref de l'image qui porte le nom.
//
// ENTREE / La r�f�rence de la la liste, la chaine correspondant au nom.
//
// SORTIE / La r�f�rence de l'image correspondant ou null.
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
// ENTREE /La r�f�rence du pointeur d'image, la r�f�rence de l'objet, la r�f�rence de la chaine de caract�re correspondant � l'emplacement du fichier image
//
// SORTIE / La r�f�rence du pointeur d'image modifi�e, les valeurs de l'image modifi�es.
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
// ENTREE /La r�f�rence de l'image, la r�f�rence de l'objet, la r�f�rence de la chaine de caract�re correspondant � l'emplacement du fichier image.
//
// SORTIE / Les valeurs de l'image modifi�es.
//
// NOTE -
//*****************************************************************************************************//
void setImage(tImage *pstImage,tObjet *pstObjet, char sEmplImage[]){
    setImageObjet(pstImage,pstObjet);
    pstImage->pTexture=NULL;
    setImageEmpl(pstImage,sEmplImage);
}


//###########################################
//PROCEDURE setImageObjet
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui modifie la r�f�rence de l'objet d'une image.
//
// ENTREE /La r�f�rence de l'image, la r�f�rence de l'objet.
//
// SORTIE / La r�f�rence de l'objet de l'image modifi�e.
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
// ENTREE /La r�f�rence de l'image, la chaine correspondant � l'emplacement de l'image.
//
// SORTIE / L'emplacement de l'image modifi�e.
//
// NOTE -
//*****************************************************************************************************//
void setImageEmpl(tImage *pstImage, char sEmplImage[]){
    strcpy(pstImage->sEmplImage,sEmplImage);
    if(pstImage->pTexture!=NULL){   //si l'image poss�de une texture, d�truit la texture;
        SDL_DestroyTexture(pstImage->pTexture);
        pstImage->pTexture=NULL;    //affecte NULL au pointeur de texture.
    }
}

//###########################################
//FONCTION creeImage
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie une image.
//
// ENTREE /La r�f�rence de l'objet, la r�f�rence de la chaine de caract�re correspondant � l'emplacement du fichier image.
//
// SORTIE / L'image avec les valeurs initialis�es.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de l'objet d'une image.
//
// ENTREE /La r�f�rence de l'image.
//
// SORTIE / La r�f�rence de l'objet de l'image.
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
// DESCRIPTION Fonction qui renvoie la r�f�rence de l'emplacement d'une image.
//
// ENTREE /La r�f�rence de l'image.
//
// SORTIE / La r�f�rence de l'emplacement de l'image.
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
// ENTREE /La r�f�rence du renderer, la r�f�rence de l'image.
//
// SORTIE / L'image affich�e.
//
// NOTE / Si la r�f�rence de la texture est NULL, cr�er la nouvelle texture en fonction de l'emplacement de l'image.
//*****************************************************************************************************//
void afficheImage(SDL_Renderer *pRenderer,tImage *pstImage){
    int nImageHauteur,nImageLargeur;
    char pcEmplImage[IMAGE_TAILLE_CHAINE]="";
    SDL_Surface *pstSurfaceImage=NULL;
    SDL_Rect stSurfaceImage;
    SDL_Point stPoint;

    strcpy(pcEmplImage,getImageEmpl(pstImage));
    //V�rification du bon chargement de la police

    if(pstImage->pTexture==NULL){   //si la texture est null, cr�ation de la surface.
        //creation de la surface de l'image
        pstSurfaceImage = IMG_Load(pcEmplImage);//Chargement de la surface de l'image
        //si la surface a �t� cr�er
        if(pstSurfaceImage==NULL){
            printf("\nImpossible de creer la surface de l'image. - %s\n", IMG_GetError());
        }else{
            //v�rifie si la texture a bien �t� cr�e
            if((pstImage->pTexture=SDL_CreateTextureFromSurface(pRenderer,pstSurfaceImage))==NULL){
                printf("\nErreur lors de la cr�ation de la texture. - %s\n", SDL_GetError());
            }else{
                SDL_FreeSurface(pstSurfaceImage);   //lib�re la surface
            }
        }
    }
    if(pstImage->pTexture!=NULL){
        SDL_QueryTexture(pstImage->pTexture,NULL,NULL,&nImageLargeur,&nImageHauteur);
        stSurfaceImage.w = nImageLargeur;
        stSurfaceImage.h = nImageHauteur;
        stPoint = convertionPointVersSDL_Point(getRectanglePointCentral(getObjetRectangle(getImageObjet(pstImage))));
        stSurfaceImage.x = getSDLPointX(&stPoint)-(nImageLargeur*0.5);
        stSurfaceImage.y = getSDLPointY(&stPoint)-(nImageHauteur*0.5);

        //applique la texture dans la surface
        SDL_RenderCopy(pRenderer,pstImage->pTexture,NULL,&stSurfaceImage); //applique la texture
    }
}

//###########################################
//FONCTION dragAndDropImage
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui g�re le glisser d�poser d'un image.
//
// ENTREE /La r�f�rence de l'image, la r�f�rence du pointeur.
//
// SORTIE / La position de l'image modifi�e, le booleen correspondant � etat du drag and drop (si drag andr dop renvoie true sinon false)
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
