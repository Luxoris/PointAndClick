#include "balle.h"

//###########################################
//FONCTION creeBalle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie une balle à partir d'un cercle, d'un vecteur vitesse et d'un vecteur acceleration;
//
// ENTREE Le cercle, le vecteur vitesse, le vecteur acceleration.
//
// SORTIE La balle
//
// NOTE -
//*****************************************************************************************************//
tBalle creeBalle(const tCercle stCercle, const tVecteur stVecteurVitesse, const tVecteur stVecteurAcceleration){
    tBalle stBalle;
    setBalleCercle(&stBalle,stCercle);
    setBalleVecteurVitesse(&stBalle,stVecteurVitesse);
    setBalleVecteurAcceleration(&stBalle,stVecteurAcceleration);

    return stBalle;
}

//###########################################
//PROCEDURE setBalleCercle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le cercle d'un type balle
//
// ENTREE La ref de la balle, le cercle
//
// SORTIE Le cercle de la balle modifié
//
// NOTE -
//*****************************************************************************************************//
void setBalleCercle(tBalle *pstBalle, const tCercle stCercle){
    pstBalle->stCercle = stCercle;
}
//###########################################
//PROCEDURE setBalleVecteurVitesse
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le vecteur vitesse d'un type balle
//
// ENTREE La ref de la balle, le vecteur vitesse
//
// SORTIE Le vecteur vitesse de la balle modifié
//
// NOTE -
//*****************************************************************************************************//
void setBalleVecteurVitesse(tBalle *pstBalle, const tVecteur stVecteurVitesse){
    pstBalle->stVecteurVitesse = stVecteurVitesse;
}
//###########################################
//PROCEDURE setBalleVecteurAcceleration
//*****************************************************************************************************//
//
// DESCRIPTION Modifie le vecteur Acceleration d'un type balle
//
// ENTREE La ref de la balle, le vecteur Acceleration
//
// SORTIE Le vecteur Acceleration de la balle modifié
//
// NOTE -
//*****************************************************************************************************//
void setBalleVecteurAcceleration(tBalle *pstBalle, const tVecteur stVecteurAcceleration){
    pstBalle->stVecteurAcceleration = stVecteurAcceleration;
}
//###########################################
//FONCTION getBalleCercle
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le cercle d'un type balle
//
// ENTREE La ref de la balle
//
// SORTIE Le cercle
//
// NOTE -
//*****************************************************************************************************//
tCercle getBalleCercle(tBalle *pstBalle){
    return pstBalle->stCercle;
}
//###########################################
//FONCTION getBalleVecteurVitesse
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le vecteur vitesse d'un type balle
//
// ENTREE La ref de la balle
//
// SORTIE Le vecteur vitesse
//
// NOTE -
//*****************************************************************************************************//
tVecteur getBalleVecteurVitesse(tBalle *pstBalle){
    return pstBalle->stVecteurVitesse;
}

//###########################################
//FONCTION getBalleVecteurAcceleration
//*****************************************************************************************************//
//
// DESCRIPTION Renvoie le vecteur acceleration d'un type balle
//
// ENTREE La ref de la balle
//
// SORTIE Le vecteur acceleration
//
// NOTE -
//*****************************************************************************************************//
tVecteur getBalleVecteurAcceleration(tBalle *pstBalle){
    return pstBalle->stVecteurAcceleration;
}



//###########################################
//PROCEDURE deplacementBalle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie les coordonnées de la balle en fonction du vecteur vitesse, et du nombre de FPS
//
// ENTREE La ref de la balle, le nombre de FPS
//
// SORTIE Les coordonnées de la balle
//
// NOTE -
//*****************************************************************************************************//
void deplacementBalle(tBalle *pstBalle, const float fFPS){
    tCercle stCercle = getBalleCercle(pstBalle);
    tVecteur stVecteurDeplacement;
    multiplicationVectorielleScalaire(getBalleVecteurVitesse(pstBalle),(1/(fFPS)),&stVecteurDeplacement);

    deplacementCercle(&stCercle,stVecteurDeplacement);
    setBalleCercle(pstBalle,stCercle);
}

//###########################################
//PROCEDURE modificationVitesseBalle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la vitesse de la balle en fonction de l'accélération.
//
// ENTREE La ref de la balle
//
// SORTIE Le vecteur vitesse modifié de la balle
//
// NOTE -   On additionne le vecteur vitesse au vecteur l'accélération.
//*****************************************************************************************************//
void modificationVitesseBalle(tBalle *pstBalle){
    tVecteur stVecteurVitesse;
    additionVectorielle(getBalleVecteurVitesse(pstBalle),getBalleVecteurAcceleration(pstBalle),&stVecteurVitesse);

    setBalleVecteurVitesse(pstBalle,stVecteurVitesse);
}

//###########################################
//PROCEDURE modificationAccelerationBalle
//*****************************************************************************************************//
//
// DESCRIPTION Modifie l'accceleration de la balle en fonction du vecteur frottement.
//
// ENTREE La ref de la balle, le vecteur frottement
//
// SORTIE Le vecteur acceleration modifié
//
// NOTE -   On additionne le vecteur acceleration au vecteur frottement
//*****************************************************************************************************//
void modificationAccelerationBalle(tBalle *pstBalle, tVecteur stFrottement){
    tVecteur stVecteurAcceleration;
    additionVectorielle(getBalleVecteurAcceleration(pstBalle),stFrottement,&stVecteurAcceleration);

    setBalleVecteurAcceleration(pstBalle,stVecteurAcceleration);
}

//###########################################
//PROCEDURE mouvementBalle
//*****************************************************************************************************//
//
// DESCRIPTION calcul le mouvement de la balle à partire de son point d'origine, de sa vitesse et de son accélération
//
// ENTREE La ref de la balle, le nb de FPS
//
// SORTIE Les coordonnées de la balle.
//
// NOTE -
//*****************************************************************************************************//
void mouvementBalle(tBalle *pstBalle, const float fFPS){
    if(fFPS>=1){ //si le nombre de fps est supérieur ou égale à 1, évite un déplacement très rapide en cas de ralentissement. Si le nombre de fps est inférieur à 1, les déplacments ne se feront pas à cette frame.
        deplacementBalle(pstBalle,fFPS);
        modificationVitesseBalle(pstBalle);
        modificationAccelerationBalle(pstBalle,creeVecteur(0,0));
    }
}

//###########################################
//PROCEDURE gestionCollisionBalleBords
//*****************************************************************************************************//
//
// DESCRIPTION modifie le vecteur vitesse de la balle si elle est en collision avec un des bords.
//
// ENTREE La ref de la balle, la coor en Y du bord bas, la coor en Y du bord haut
//
// SORTIE Le vecteur vitesse de la balle modifié si besoin
//
// NOTE -
//*****************************************************************************************************//
void gestionCollisionBalleBords(tBalle *pstBalle, const float fCoorYBordBas, const float fCoorYBordHaut){
    tCercle stCercleBalle = getBalleCercle(pstBalle);
    const int nDiametre = getCercleRayon(&stCercleBalle) * 2;
    tRectangle stRectangleBalle = creeRectangle(*getCerclePointCentral(&stCercleBalle),nDiametre,nDiametre);
    tVecteur stVecteurVitesse, stVecteurAcceleration;

    if(collisionRectangleBordBas(&stRectangleBalle,fCoorYBordBas)||collisionRectangleBordHaut(&stRectangleBalle,fCoorYBordHaut)){
        //modification de la direction en Y du vecteur vitesse
        stVecteurVitesse = getBalleVecteurVitesse(pstBalle);
        setVecteurY(&stVecteurVitesse,getVecteurY(&stVecteurVitesse)*-1);
        setBalleVecteurVitesse(pstBalle,stVecteurVitesse);

        //modification de la direction en Y du vecteur acceleration
        stVecteurAcceleration = getBalleVecteurAcceleration(pstBalle);
        setVecteurY(&stVecteurAcceleration,getVecteurY(&stVecteurAcceleration)*-1);
        setBalleVecteurAcceleration(pstBalle,stVecteurAcceleration);
    }
}

//###########################################
//PROCEDURE gestionCollisionBalleObjet
//*****************************************************************************************************//
//
// DESCRIPTION modifie le vecteur vitesse et acceleration de la balle si elle est en collision avec une des objets
//
// ENTREE La ref de la balle, la ref de la objet
//
// SORTIE Le vecteur vitesse de la balle modifié si besoin
//
// NOTE -
//*****************************************************************************************************//
void gestionCollisionBalleObjet(tBalle *pstBalle, tObjet *pstObjet){
    tCercle stCercleBalle = getBalleCercle(pstBalle);
    const int nDiametre = getCercleRayon(&stCercleBalle) * 2;
    tRectangle stRectangleBalle = creeRectangle(*getCerclePointCentral(&stCercleBalle),nDiametre,nDiametre);
    tRectangle stRectangleObjet = *getObjetRectangle(pstObjet);
    tVecteur stVecteurVitesse, stVecteurAcceleration;


    if(collisionRectangleRectangle(&stRectangleBalle,&stRectangleObjet)){
        //modification de la direction en X du vecteur vitesse
        stVecteurVitesse = getBalleVecteurVitesse(pstBalle);
        setVecteurX(&stVecteurVitesse,getVecteurX(&stVecteurVitesse)*-1);
        setBalleVecteurVitesse(pstBalle,stVecteurVitesse);

        //modification de la direction en X du vecteur acceleration
        stVecteurAcceleration = getBalleVecteurAcceleration(pstBalle);
        setVecteurX(&stVecteurAcceleration,getVecteurX(&stVecteurAcceleration)*-1);
        setBalleVecteurAcceleration(pstBalle,stVecteurAcceleration);

    }
}

void gestionBalleSort(tBalle *pstBalle, tJoueur *pstJoueur1, tJoueur *pstJoueur2,const float fCoorYBordDroit, const float fCoorYBordGauche, const tBalle stBalleRepositionner){
    tCercle stCercleBalle = getBalleCercle(pstBalle);
    const int nDiametre = getCercleRayon(&stCercleBalle) * 2;
    tRectangle stRectangleBalle = creeRectangle(*getCerclePointCentral(&stCercleBalle),nDiametre,nDiametre);
    tVecteur stVecteurVitesse, stVecteurAcceleration;

    if(collisionRectangleBordDroit(&stRectangleBalle,fCoorYBordDroit)){
       setJoueurScore(pstJoueur1,getJoueurScore(pstJoueur1)+1); //la balle sort du coté du joueur 2, le joueur 1 marque 1 point

        //la balle repart du milieu en direction du joueur qui viens de marquer le point. (donc le joueur 1 ici)

        *pstBalle = stBalleRepositionner;   //ici la balle par du mauvais côté

        //INVERSION DES COORDONNEES EN X DES VECTEURS
        //modification de la direction en X du vecteur vitesse
        stVecteurVitesse = getBalleVecteurVitesse(pstBalle);
        setVecteurX(&stVecteurVitesse,getVecteurX(&stVecteurVitesse)*-1);
        setBalleVecteurVitesse(pstBalle,stVecteurVitesse);

        //modification de la direction en X du vecteur acceleration
        stVecteurAcceleration = getBalleVecteurAcceleration(pstBalle);
        setVecteurX(&stVecteurAcceleration,getVecteurX(&stVecteurAcceleration)*-1);
        setBalleVecteurAcceleration(pstBalle,stVecteurAcceleration);

    }else{
        if(collisionRectangleBordGauche(&stRectangleBalle,fCoorYBordGauche)){

        setJoueurScore(pstJoueur2,getJoueurScore(pstJoueur2)+1); //la balle sort du coté du joueur 1, le joueur 2 marque 1 point

        //la balle repart du milieu en direction du joueur qui viens de marquer le point. (donc le joueur 2 ici)
        *pstBalle = stBalleRepositionner;
        }
    }
}

