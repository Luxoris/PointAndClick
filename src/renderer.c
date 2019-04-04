#include "renderer.h"

//###########################################
//PROCEDURE initMoteurRendu
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui initialise le renderer et renvoie la référence du renderer
//
// ENTREE /L'adresse du pointeur de renderer, L'adresse du pointeur de Fenetre
//
// SORTIE / L'adresse du pointeur de renderer
//
// NOTE -
//*****************************************************************************************************//
void initMoteurRendu(SDL_Window** pFenetre, SDL_Renderer** pRenderer){
    //creation du moteur de rendu
    *(pRenderer) = SDL_CreateRenderer(*(pFenetre), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
    if(*(pRenderer) == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());

    }
}

//###########################################
//PROCEDURE arretMoteurRendu
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui détruit le renderer
//
// ENTREE /L'adresse du pointeur de renderer
//
// SORTIE /
//
// NOTE -
//*****************************************************************************************************//
void arretMoteurRendu(SDL_Renderer** pRenderer){
    //destruction du moteur de rendu
    SDL_DestroyRenderer(*(pRenderer));
}
//###########################################
//PROCEDURE dessineRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui déssine un rectable dans le renderer
//
// ENTREE /L'adresse du pointeur de renderer, le centre du rectangle,la largeur du rectangle, sa hauteur, si on veut déssiner un rectangle plein.
//
// SORTIE /Le dessin
//
// NOTE -
//*****************************************************************************************************//
void dessineSDLRectangle(SDL_Renderer* pRenderer, SDL_Point tCoor,const int nLargeur,const int nHauteur,const tBool tRectanglePlein){
    SDL_Rect rectangle;

    //affectation des valeurs au rectangle
    rectangle.h=nHauteur;
    rectangle.w=nLargeur;
    rectangle.x = getSDLPointX(&tCoor);
    rectangle.y = getSDLPointY(&tCoor);

    //dessin du contour du rectangle
    SDL_RenderDrawRect(pRenderer,&rectangle);
    if(tRectanglePlein){
        SDL_RenderFillRect(pRenderer,&rectangle);   //dessin de l'interieur du rectangle
    }

}

//###########################################
//PROCEDURE dessineRectanglePointCentre
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui déssine un rectangle à partir de ses coordonées.
//
// ENTREE /L'adresse du pointeur de renderer, le centre du rectangle,la largeur du rectangle, sa hauteur, si on veut déssiner un rectangle plein.
//
// SORTIE /Le dessin
//
// NOTE - Le rectangle est tracé autour de son centre.
//*****************************************************************************************************//
void dessineRectanglePointCentre(SDL_Renderer* pRenderer,SDL_Point tCoor,const int nLargeur,const int nHauteur,const tBool tRectanglePlein){
    SDL_Point stPointDepartRect;
    setSDLPointX(&stPointDepartRect,getSDLPointX(&tCoor)-nLargeur/2);
    setSDLPointY(&stPointDepartRect,getSDLPointY(&tCoor)-nHauteur/2);
    dessineSDLRectangle(pRenderer,stPointDepartRect,nLargeur,nHauteur,tRectanglePlein);


}

//###########################################
//PROCEDURE dessinePointille
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui déssine une ligne en pointilé entre deux points.
//
// ENTREE /L'adresse du pointeur de renderer, les coordonnées des deux points, la longeur du trait plein, la longueur du trait vide.
//
// SORTIE /Le dessin
//
// NOTE - Le programme se base sur l'algorithme de Bresenham pour le tracé d'un segement
//*****************************************************************************************************//
void dessinePointille(SDL_Renderer* pRenderer,SDL_Point tCoorDebut,SDL_Point tCoorFin, const int nLongueurTraitPlein, const int nLongueurTraitVide){
    int nDx, nDy, nX1, nX2, nY1, nY2, nCptTrait=0;
    int nE; //valeur d'erreur
    nX1 = getSDLPointX(&tCoorDebut);
    nX2 = getSDLPointX(&tCoorFin);
    nY1 = getSDLPointY(&tCoorDebut);
    nY2 = getSDLPointY(&tCoorFin);

    nDx = nX2-nX1;
    if(nDx!=0){
        if(nDx>0){
            nDy = nY2 - nY1;
            if(nDy != 0){
                if(nDy>0){
                    //vecteur oblique dans le 1er quadran

                    if(nDx>nDy){
                        //vecteur diagonal ou oblique proche de l'horizontale, dans le 1er octant
                        nE = nDx;
                        nDx = nE * 2;   //nE est positif
                        nDy = nDy * 2;
                        while(1){
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nX1++;
                            if(nX1==nX2){
                                break;  //interromp la boucle
                            }
                            nE=nE-nDy;
                            if(nE<0){
                                nY1++; //déplacement diagonal
                                nE=nE+nDx;
                            }
                        }
                    }else{
                        //vecteur oblique proche de la verticale dans le 2nd octant
                        nE = nDy;
                        nDy = nE * 2;
                        nDx = nDx * 2;  //nE est positif
                        while(1){
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nY1++;
                            if(nY1==nY2){
                                break;  //interromp la boucle
                            }
                            nE=nE-nDx;
                            if(nE<0){
                                nX1++; //déplacement diagonal
                                nE=nE+nDy;
                            }
                        }

                    }

                }else{  //dy<0 (et dx>0)
                    //vecteur oblique dans le 4e cadran

                    if(nDx>=-nDy){
                        //vecteur diagonal ou oblique proche de l'horizontale, dans le 8e octant
                        nE = nDx;
                        nDx = nE * 2;   //nE est positif
                        nDy = nDy * 2;
                        while(1){
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nX1++;
                            if(nX1==nX2){
                                break;  //interromp la boucle
                            }
                            nE=nE+nDy;
                            if(nE<0){
                                nY1--; //déplacement diagonal
                                nE=nE+nDx;
                            }
                        }

                    }else{
                        //vecteur oblique proche de la verticale, dans le 7e octant
                        nE = nDy;
                        nDy = nE * 2;
                        nDx = nDx * 2;  //nE est positif
                        while(1){
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nY1--;
                            if(nY1==nY2){
                                break;  //interromp la boucle
                            }
                            nE=nE+nDx;
                            if(nE>0){
                                nX1++; //déplacement diagonal
                                nE=nE+nDy;
                            }
                        }
                    }


                }

           }else{   //nDy = 0 (et nDx > 0)

           //vecteur horizontal vers la droite
            do{
                nCptTrait++;
                if(nCptTrait<=nLongueurTraitPlein){
                    SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                }
                if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                    nCptTrait=0;
                }
                nX1++;
            }while(nX1!=nX2);
           }
        }else{
            nDy = nY2-nY1;
            if(nDy!=0){
                if(nDy>0){
                    //vecteur oblique dans le 2nd quadran

                    if(-nDx>=nDy){
                        //vecteur diagonal ou oblique proche de l'horizontale, dans le 4e octant
                        nE = nDx;
                        nDx = nE * 2;
                        nDy = nDy * 2;  //nE est négatif
                        while(1){
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nX1--;
                            if(nX1==nX2){
                                break;  //interromp la boucle
                            }
                            nE=nE+nDy;
                            if(nE>=0){
                                nY1++; //déplacement diagonal
                                nE=nE+nDx;
                            }
                        }
                    }else{  //vecteur oblique proche de la verticale dans le 3e octant
                        nE = nDy;
                        nDy = nE * 2;
                        nDx = nDx * 2;  //nE est positif
                        while(1){   //déplacmeents verticaux
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nY1++;
                            if(nY1==nY2){
                                break;  //interromp la boucle
                            }
                            nE=nE+nDx;
                            if(nE<=0){
                                nX1--; //déplacement diagonal
                                nE=nE+nDy;
                            }
                        }
                    }
                }else{  //nDy < 0 (et nDx < 0)
                    //vecteur oblique dans le 3e cadran

                    if(nDx<=nDy){
                        //vecteur diagonal ou oblique proche de l'horizontale, dans le 5e octant
                        nE = nDx;
                        nDx = nE * 2;
                        nDy = nDy * 2;  //nE est négatif
                        while(1){   //déplacmeents horizontaux
                            nCptTrait++;
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nX1--;
                            if(nX1==nX2){
                                break;  //interromp la boucle
                            }
                            nE=nE-nDy;
                            if(nE>=0){
                                nY1--; //déplacement diagonal
                                nE=nE+nDx;
                            }
                        }

                    }else{  //vecteur oblique proche de la verticale dans le 6e octant
                        nE = nDy;
                        nDy = nE * 2;
                        nDx = nDx * 2;  //nE est négatif
                        while(1){   //déplacmeents horizontaux
                            nCptTrait++;
                            if(nCptTrait<=nLongueurTraitPlein){
                                SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                            }
                            if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                                nCptTrait=0;
                            }
                            nY1--;
                            if(nY1==nY2){
                                break;  //interromp la boucle
                            }
                            nE=nE-nDx;
                            if(nE>=0){
                                nX1--; //déplacement diagonal
                                nE=nE+nDy;
                            }
                        }

                    }


                }

            }else{  //dy = 0 (et dx <0)
                //vecteur horizontal vers la gauche
                do{
                    nCptTrait++;
                    if(nCptTrait<=nLongueurTraitPlein){
                        SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                    }
                    if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                        nCptTrait=0;
                    }
                    nX1--;
                }while(nX1!=nX2);

            }
        }
    }   //dx = 0
        nDy = nY2-nY1;
        if(nDy != 0){
            if(nDy>0){
                //vecteur vertical croissant
                do{
                    nCptTrait++;
                    if(nCptTrait<=nLongueurTraitPlein){
                        SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                    }
                    if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                        nCptTrait=0;
                    }
                    nY1++;
                }while(nY1!=nY2);
            }else{  //dy <0 (et dx = 0)
                //vecteur vertical décroissant
                do{
                    nCptTrait++;
                    if(nCptTrait<=nLongueurTraitPlein){
                        SDL_RenderDrawPoint(pRenderer,nX1,nY1);
                    }
                    if(nCptTrait==nLongueurTraitPlein+nLongueurTraitVide){
                        nCptTrait=0;
                    }
                    nY1--;
                }while(nY1!=nY2);

            }
        }
    //le pixel final (x2,y2) n'est pas tracé.
}



//###########################################
//PROCEDURE dessineCercle
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui déssine un cercle.
//
// ENTREE /L'adresse du pointeur de renderer, les coordonnées du point central, le rayon
//
// SORTIE /Le dessin
//
// NOTE - Le programme se base sur l'algorithme de tracé d'arc cercle d'Andres
//*****************************************************************************************************//
void dessineCercle(SDL_Renderer* pRenderer,SDL_Point tPointCentre,const int nRayon){
    int nX, nY, nD;
    nX=0;
    nY=nRayon;  //on se place en haut du cercle

    nD = nRayon - 1;   //initialisation

    while(nY>=nX){
        SDL_RenderDrawPoint(pRenderer,nX+getSDLPointX(&tPointCentre),nY+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,nY+getSDLPointX(&tPointCentre),nX+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,-nX+getSDLPointX(&tPointCentre),nY+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,-nY+getSDLPointX(&tPointCentre),nX+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,nX+getSDLPointX(&tPointCentre),-nY+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,nY+getSDLPointX(&tPointCentre),-nX+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,-nX+getSDLPointX(&tPointCentre),-nY+getSDLPointY(&tPointCentre));
        SDL_RenderDrawPoint(pRenderer,-nY+getSDLPointX(&tPointCentre),-nX+getSDLPointY(&tPointCentre));
        if(nD>=(2*nX)){   //choix du point F
            nD = nD - 2* nX -1;
            nX++;
        }else if(nD<2*(nRayon-nY)){
            nD = nD+ 2 * nY - 1;
            nY--;
        }else{
            nD = nD+(2*(nY-nX-1));
            nY--;
            nX++;
        }
    }
}

//###########################################
//PROCEDURE dessineCerclePlein
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui déssine un cercle plein.
//
// ENTREE /L'adresse du pointeur de renderer, les coordonnées du point central, le rayon
//
// SORTIE /Le dessin
//
// NOTE -
//*****************************************************************************************************//
void dessineCerclePlein(SDL_Renderer* pRenderer,SDL_Point tPointCentre,const int nRayon){
    int nX=0;

    SDL_RenderDrawPoint(pRenderer,getSDLPointX(&tPointCentre),getSDLPointY(&tPointCentre));
    do{  //tant qu'on est dans le second octant
        nX++;
        dessineCercle(pRenderer,tPointCentre,nX);
    }while(nX<nRayon);
}


//###########################################
//PROCEDURE dessineRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Dessine un rectangle de type tRectangle, un booleen indique si le rectangle est plein ou vide.
//
// ENTREE La référence du renderer, du rectangle, le booleen
//
// SORTIE L'affichage du rectangle
//
// NOTE -
//*****************************************************************************************************//
void dessineRectangle(SDL_Renderer *pRenderer,tRectangle *pstRectangle,tBool bRectanglePlein){
    dessineRectanglePointCentre(pRenderer,convertionPointVersSDL_Point(getRectanglePointCentral(pstRectangle)),getRectangleLargeur(pstRectangle),getRectangleHauteur(pstRectangle),bRectanglePlein);
}




