#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#pragma once

//APPEL DES BIBLIOTHEQUES
#include <SDL.h>
#include <SDL_image.h>
#include "tObjet.h"
#include "string.h"

//DEFINITION DES MACCROS
#define IMAGE_TAILLE_CHAINE 256

//DEFINITION DU TYPE STRUCTURE

typedef struct tImage{
    tObjet *pstObjet;
    char sEmplImage[IMAGE_TAILLE_CHAINE];
}tImage;


//PROTOTYPE DES METHODES

extern void initSDLImage();
extern void initImage(tImage **ppstImage,tObjet *pstObjet, char sEmplImage[]);
extern void setImage(tImage *pstImage,tObjet *pstObjet, char sEmplImage[]);
extern void setImageObjet(tImage *pstImage, tObjet *pstObjet);
extern void setImageEmpl(tImage *pstImage, char sEmplImage[]);

extern tImage creeImage(tObjet *pstObjet, char sEmplImage[]);
extern tObjet * getImageObjet(tImage *pstImage);
extern char * getImageEmpl(tImage *pstImage);

extern void afficheImage(SDL_Renderer *pRenderer,tImage *pstImage);




#endif // IMAGE_H_INCLUDED
