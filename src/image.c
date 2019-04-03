#include "image.h"

#include <stdlib.h>
#include <stdio.h>
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
            printf("Erreur d'initialisation de la SDL Image JPG et PNG : %s",IMG_GetError());
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
        printf("Erreur d'allocation de l'image %s !",sEmplImage);
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
    //V�rification du bon chargement de la police


    //creation de la surface de l'image
    pstSurfaceImage = IMG_Load(pcEmplImage);//Chargement de l'image

    //si la surface a �t� cr�er
    if(pstSurfaceImage==NULL){
        printf("Impossible de creer la surface de l'image. - %s\n", IMG_GetError());
    }else{
        //v�rifie si la texture a bien �t� cr�e
        if((pstTexture=SDL_CreateTextureFromSurface(pRenderer,pstSurfaceImage))==NULL){
            printf("Erreur lors de la cr�ation de la texture. - %s\n", SDL_GetError());
        }else{
            SDL_FreeSurface(pstSurfaceImage);   //lib�re la surface

            SDL_QueryTexture(pstTexture,NULL,NULL,&nImageLargeur,&nImageHauteur);
            stSurfaceImage.w = nImageLargeur;
            stSurfaceImage.h = nImageHauteur;
            stPoint = convertionPointVersSDL_Point(getRectanglePointCentral(getObjetRectangle(getImageObjet(pstImage))));
            stSurfaceImage.x = getSDLPointX(&stPoint)-(nImageLargeur*0.5);
            stSurfaceImage.y = getSDLPointY(&stPoint)-(nImageHauteur*0.5);

                //applique la texture dans la surface
            SDL_RenderCopy(pRenderer,pstTexture,NULL,&stSurfaceImage); //applique la texture
            SDL_DestroyTexture(pstTexture);  //d�truit la texture
        }
    }
}
