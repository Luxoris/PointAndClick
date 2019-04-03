#include "collision.h"


//###########################################
//Fonction collisionPointRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un point est contenu dans un rectangle, renvoie un bool�en (vrai ou faux)
//
// ENTREE /La r�f�rence du point, la r�f�rence du rectangle;
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//
tBool collisionPointRectangle(tPoint *pstPoint,tRectangle *pstRectangle){
    //Calcul du point en haut � gauche du rectangle.
    tPoint stPointRectangle = *getRectanglePointCentral(pstRectangle);
    setPointX(&stPointRectangle,getPointX(&stPointRectangle)-(getRectangleLargeur(pstRectangle)*0.5));
    setPointY(&stPointRectangle,getPointY(&stPointRectangle)-(getRectangleHauteur(pstRectangle)*0.5));

    if(getPointX(pstPoint)>=getPointX(&stPointRectangle)
       &&getPointX(pstPoint)<(getPointX(&stPointRectangle)+getRectangleLargeur(pstRectangle))
       &&getPointY(pstPoint)>=getPointY(&stPointRectangle)
       &&getPointY(pstPoint)<(getPointY(&stPointRectangle)+getRectangleHauteur(pstRectangle))){

        return true;
    }else{
        return false;
    }

}

//###########################################
//Fonction collisionRectangleRectangle
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un rectangle est en collision avec un deuxi�me rectangle, renvoie un bool�en (vrai ou faux)
//
// ENTREE /La r�f�rence du rectangle 1, la r�f�rence du rectangle 2;
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//

tBool collisionRectangleRectangle(tRectangle *pstRectangle1, tRectangle *pstRectangle2){
    //Calcul du point en haut � gauche du rectangle 1
    tPoint stPointRectangle1 = *getRectanglePointCentral(pstRectangle1);
    setPointX(&stPointRectangle1,getPointX(&stPointRectangle1)-(getRectangleLargeur(pstRectangle1)*0.5));
    setPointY(&stPointRectangle1,getPointY(&stPointRectangle1)-(getRectangleHauteur(pstRectangle1)*0.5));


    //Calcul du point en haut � gauche du rectangle 2.
    tPoint stPointRectangle2 = *getRectanglePointCentral(pstRectangle2);
    setPointX(&stPointRectangle2,getPointX(&stPointRectangle2)-(getRectangleLargeur(pstRectangle2)*0.5));
    setPointY(&stPointRectangle2,getPointY(&stPointRectangle2)-(getRectangleHauteur(pstRectangle2)*0.5));

    if(getPointX(&stPointRectangle2)>=(getPointX(&stPointRectangle1)+getRectangleLargeur(pstRectangle1))    //trop � droite
        ||(getPointX(&stPointRectangle2)+getRectangleLargeur(pstRectangle2))<=getPointX(&stPointRectangle1) //trop � gauche
        ||getPointY(&stPointRectangle2)>=(getPointY(&stPointRectangle1)+getRectangleHauteur(pstRectangle1))  //trop en bas
        ||(getPointY(&stPointRectangle2)+getRectangleHauteur(pstRectangle2))<=getPointY(&stPointRectangle1) //trop en haut
    ){
        return false;
    }else{
        return true;
    }
}

//###########################################
//Fonction collisionRectangleBordDroit
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un rectangle entre en collision avec le bord droit de l'�cran
//
// ENTREE /La r�f�rence de rectangle, la coordonn�e en X du bord droit
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//
tBool collisionRectangleBordDroit(tRectangle *pstRectangle, const float fX){
    tPoint stPointRectangle= *getRectanglePointCentral(pstRectangle);

    if((getPointX(&stPointRectangle)+(getRectangleLargeur(pstRectangle)*0.5))>=fX){
        return true;
    }else{
        return false;
    }
}

//###########################################
//Fonction collisionRectangleBordGauche
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un rectangle entre en collision avec le bord gauche de l'�cran
//
// ENTREE /La r�f�rence de rectangle, la coordonn�e en X du bord gauche
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//
tBool collisionRectangleBordGauche(tRectangle *pstRectangle, const float fX){
    tPoint stPointRectangle= *getRectanglePointCentral(pstRectangle);

    if((getPointX(&stPointRectangle)-(getRectangleLargeur(pstRectangle)*0.5))<=fX){
        return true;
    }else{
        return false;
    }
}

//###########################################
//Fonction collisionRectangleBordHaut
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un rectangle entre en collision avec le bord haut de l'�cran
//
// ENTREE /La r�f�rence de rectangle, la coordonn�e en X du bord haut
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//
tBool collisionRectangleBordHaut(tRectangle *pstRectangle, const float fY){
    tPoint stPointRectangle= *getRectanglePointCentral(pstRectangle);

    if((getPointY(&stPointRectangle)-(getRectangleHauteur(pstRectangle)*0.5))<=fY){
        return true;
    }else{
        return false;
    }

}

//###########################################
//Fonction collisionRectangleBordBas
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un rectangle entre en collision avec le bord bas de l'�cran
//
// ENTREE /La r�f�rence de rectangle, la coordonn�e en X du bord bas
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//
tBool collisionRectangleBordBas(tRectangle *pstRectangle, const float fY){
    tPoint stPointRectangle= *getRectanglePointCentral(pstRectangle);

    if((getPointY(&stPointRectangle)+(getRectangleHauteur(pstRectangle)*0.5))>=fY){
        return true;
    }else{
        return false;
    }

}



//###########################################
//Fonction collisionPointCercle
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un point est contenu dans un cercle, renvoie un bool�en (vrai ou faux)
//
// ENTREE /La r�f�rence du point, la r�f�rence du cercle;
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//
tBool collisionPointCercle(tPoint *pstPoint,tCercle *pstCercle){
    tPoint stPointCercle = *getCerclePointCentral(pstCercle);
    float fDistancePow2 = ((getPointX(pstPoint)-getPointX(&stPointCercle))*(getPointX(pstPoint)-getPointX(&stPointCercle)))+((getPointY(pstPoint)-getPointY(&stPointCercle))*(getPointY(pstPoint)-getPointY(&stPointCercle)));

    if(fDistancePow2>(getCercleRayon(pstCercle)*getCercleRayon(pstCercle))){
        return false;
    }else{
        return true;
    }
}


//###########################################
//Fonction collisionCercleCercle
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui v�rifie si un cercle est en collision avec un deuxi�me cercle, renvoie un bool�en (vrai ou faux)
//
// ENTREE /La r�f�rence du cercle 1, la r�f�rence du cercle 2;
//
// SORTIE /Le bool�en
//
// NOTE -
//*****************************************************************************************************//

tBool collisionCercleCercle(tCercle *pstCercle1,tCercle *pstCercle2){
    tPoint stPointCercle1 = *getCerclePointCentral(pstCercle1);
    tPoint stPointCercle2 = *getCerclePointCentral(pstCercle2);

    float fDistancePow2 = ((getPointX(&stPointCercle1)-getPointX(&stPointCercle2))*(getPointX(&stPointCercle1)-getPointX(&stPointCercle2)))+((getPointY(&stPointCercle1)-getPointY(&stPointCercle2))*(getPointY(&stPointCercle1)-getPointY(&stPointCercle2)));

    if(fDistancePow2>((getCercleRayon(pstCercle1)+getCercleRayon(pstCercle2))*(getCercleRayon(pstCercle1)+getCercleRayon(pstCercle2)))){
        return false;
    }else{
        return true;
    }
}




