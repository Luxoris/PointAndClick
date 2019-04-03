#include "raquette.h"


//###########################################
//FONCTION creeRaquette
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie une raquette à partir d'un rectangle, d'un vecteur vitesse et d'un vecteur acceleration;
//
// ENTREE Le rectangle, le vecteur vitesse, le vecteur acceleration.
//
// SORTIE La raquette
//
// NOTE -
//*****************************************************************************************************//
tRaquette creeRaquette(const tRectangle stRectangle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration){
    tRaquette stRaquette;
    setRaquetteRectangle(&stRaquette,stRectangle);
    setRaquetteVecteurVitesse(&stRaquette,stVecteurVitesse);
    setRaquetteVecteurVitesse(&stRaquette,stVecteurAcceleration);

    return stRaquette;
}
//###########################################
//FONCTION getRaquetteRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le rectangle d'un type raquette
//
// ENTREE La ref de la raquette
//
// SORTIE Le rectangle
//
// NOTE -
//*****************************************************************************************************//
tRectangle getRaquetteRectangle(tRaquette *pstRaquette){
    return pstRaquette->stRectangle;
}
//###########################################
//FONCTION getRaquetteVecteurVitesse
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le VecteurVitesse d'un type raquette
//
// ENTREE La ref de la raquette
//
// SORTIE Le VecteurVitesse
//
// NOTE -
//*****************************************************************************************************//
tVecteur getRaquetteVecteurVitesse(tRaquette *pstRaquette){
    return pstRaquette->stVecteurVitesse;
}
//###########################################
//FONCTION getRaquetteVecteurAcceleration
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le VecteurAcceleration d'un type raquette
//
// ENTREE La ref de la raquette
//
// SORTIE Le VecteurAcceleration
//
// NOTE -
//*****************************************************************************************************//
tVecteur getRaquetteVecteurAcceleration(tRaquette *pstRaquette){
    return pstRaquette->stVecteurAcceleration;
}
//###########################################
//PROCEDURE setRaquetteRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le rectangle d'un type balle
//
// ENTREE La ref de la balle, le rectangle
//
// SORTIE Le rectangle de la raquette modifiée
//
// NOTE -
//*****************************************************************************************************//
void setRaquetteRectangle(tRaquette *pstRaquette, const tRectangle stRectangle){
    pstRaquette->stRectangle=stRectangle;
}
//###########################################
//PROCEDURE setRaquetteVecteurVitesse
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le vecteur vitesse d'un type balle
//
// ENTREE La ref de le vecteur vitesse, le cercle
//
// SORTIE Le vecteur vitesse de la raquette modifiée
//
// NOTE -
//*****************************************************************************************************//
void setRaquetteVecteurVitesse(tRaquette *pstRaquette, const tVecteur stVecteurVitesse){
    pstRaquette->stVecteurVitesse=stVecteurVitesse;
}

//###########################################
//PROCEDURE setRaquetteVecteurAcceleration
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le vecteur acceleration d'un type balle
//
// ENTREE La ref de le vecteur acceleration, le cercle
//
// SORTIE Le vecteur acceleration de la raquette modifiée
//
// NOTE -
//*****************************************************************************************************//
void setRaquetteVecteurAcceleration(tRaquette *pstRaquette, const tVecteur stVecteurAcceleration){
    pstRaquette->stVecteurAcceleration=stVecteurAcceleration;
}

//###########################################
//PROCEDURE deplacementRaquette
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonnées de la raquette en fonction du vecteur vitesse, et du nombre de FPS
//
// ENTREE La ref de la raquette, le nombre de FPS
//
// SORTIE Les coordonnées de la raquette
//
// NOTE -
//*****************************************************************************************************//
void deplacementRaquette(tRaquette *pstRaquette, const float fFPS){
    tRectangle stRectangle = getRaquetteRectangle(pstRaquette);
    tVecteur stVecteurDeplacement;
    multiplicationVectorielleScalaire(getRaquetteVecteurVitesse(pstRaquette),(1/(fFPS)),&stVecteurDeplacement);

    deplacementRectangle(&stRectangle,stVecteurDeplacement);
    setRaquetteRectangle(pstRaquette,stRectangle);
}

//###########################################
//PROCEDURE modificationVitesseRaquette
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la vitesse de la raquette en fonction de l'accélération.
//
// ENTREE La ref de la raquette
//
// SORTIE Le vecteur vitesse modifié de la raquette
//
// NOTE -   On additionne le vecteur vitesse au vecteur l'accélération.
//*****************************************************************************************************//
void modificationVitesseRaquette(tRaquette *pstRaquette){
    tVecteur stVecteurVitesse;
    additionVectorielle(getRaquetteVecteurVitesse(pstRaquette),getRaquetteVecteurAcceleration(pstRaquette),&stVecteurVitesse);

    setRaquetteVecteurVitesse(pstRaquette,stVecteurVitesse);
}

//###########################################
//PROCEDURE modificationAccelerationRaquette
//*****************************************************************************************************//
//
// DESCRIPTION Modifie l'accceleration de la raquette en fonction du vecteur frottement.
//
// ENTREE La ref de la raquette, le vecteur frottement
//
// SORTIE Le vecteur acceleration modifié
//
// NOTE -   On additionne le vecteur acceleration au vecteur frottement
//*****************************************************************************************************//
void modificationAccelerationRaquette(tRaquette *pstRaquette, tVecteur stFrottement){
    tVecteur stVecteurAcceleration;
    additionVectorielle(getRaquetteVecteurAcceleration(pstRaquette),stFrottement,&stVecteurAcceleration);

    setRaquetteVecteurAcceleration(pstRaquette,stVecteurAcceleration);
}

//###########################################
//PROCEDURE mouvementRaquette
//*****************************************************************************************************//
//
// DESCRIPTION calcul le mouvement de la raquette à partire de son point d'origine, de sa vitesse et de son accélération
//
// ENTREE La ref de la raquette, le nb de FPS
//
// SORTIE Les coordonnées de la raquette
//
// NOTE -
//*****************************************************************************************************//
void mouvementRaquette(tRaquette *pstRaquette, const float fFPS){
    tVecteur stVecteurAcceleration = getRaquetteVecteurAcceleration(pstRaquette);
    deplacementRaquette(pstRaquette,fFPS);
    modificationVitesseRaquette(pstRaquette);
    modificationAccelerationRaquette(pstRaquette,creeVecteur(-getVecteurX(&stVecteurAcceleration),-getVecteurY(&stVecteurAcceleration)));
}

//###########################################
//PROCEDURE gestionCollisionRaquetteBords
//*****************************************************************************************************//
//
// DESCRIPTION modifie les coordonnées de la raquette si elle est en collision avec un des bords.
//
// ENTREE La ref de la raquette, la coor en Y du bord bas, la coor en Y du bord haut
//
// SORTIE Les coordonnées de la raquette modifié si besoin
//
// NOTE -
//*****************************************************************************************************//
void gestionCollisionRaquetteBords(tRaquette *pstRaquette, const float fCoorYBordBas, const float fCoorYBordHaut){
    tRectangle stRectangleRaquette = getRaquetteRectangle(pstRaquette);
    tPoint stPointRaquette= *getRectanglePointCentral(&stRectangleRaquette);

    if(collisionRectangleBordBas(&stRectangleRaquette,fCoorYBordBas)){
        setPointY(&stPointRaquette,fCoorYBordBas-getRectangleHauteur(&stRectangleRaquette)*0.5);
        setRectanglePointCentral(&stRectangleRaquette,stPointRaquette);
        setRaquetteRectangle(pstRaquette,stRectangleRaquette);
    }
    if(collisionRectangleBordHaut(&stRectangleRaquette,fCoorYBordHaut)){
        setPointY(&stPointRaquette,fCoorYBordHaut+getRectangleHauteur(&stRectangleRaquette)*0.5);
        setRectanglePointCentral(&stRectangleRaquette,stPointRaquette);
        setRaquetteRectangle(pstRaquette,stRectangleRaquette);
    }
}

