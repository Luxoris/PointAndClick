#include "evenement.h"
#include <string.h>

//###########################################
//PROCEDURE gestionControles
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui en fonction des touches pressé, déclenche les évenements et modifie l'état des objets.
//
// ENTREE - La référence de tEtatPartie, la référence de l'objet du J1, la référence de l'objet du joueur 2.
//
// SORTIE - La modification de l'état des objets
//
// NOTE - Utilise SDL_PollEvent
//*****************************************************************************************************//
/*void gestionControles(tEtatPartie *pstEtatPartie, tObjet *pstObjetJ1, tObjet *pstObjetJ2){

    SDL_Event tEvenement;

    while(SDL_PollEvent(&tEvenement)==1){
        switch(tEvenement.type){
        case SDL_QUIT:
              *pstEtatPartie=quitter;break;
        case SDL_KEYDOWN:
            switch (tEvenement.key.keysym.scancode)
                {
                case J1_HAUT:   setObjetVecteurVitesse(pstObjetJ1,creeVecteur(0,-VITESSE_DEPLACEMENT_RAQUETTE));
                                setObjetVecteurAcceleration(pstObjetJ1,creeVecteur(0,VITESSE_DEPLACEMENT_RAQUETTE));
                                break;
                case J1_BAS:    setObjetVecteurVitesse(pstObjetJ1,creeVecteur(0,+VITESSE_DEPLACEMENT_RAQUETTE)) ;
                                setObjetVecteurAcceleration(pstObjetJ1,creeVecteur(0,-VITESSE_DEPLACEMENT_RAQUETTE));
                                break;
                case J2_HAUT:   setObjetVecteurVitesse(pstObjetJ2,creeVecteur(0,-VITESSE_DEPLACEMENT_RAQUETTE));
                                setObjetVecteurAcceleration(pstObjetJ2,creeVecteur(0,VITESSE_DEPLACEMENT_RAQUETTE));
                                break;
                case J2_BAS:    setObjetVecteurVitesse(pstObjetJ2,creeVecteur(0,+VITESSE_DEPLACEMENT_RAQUETTE)) ;
                                setObjetVecteurAcceleration(pstObjetJ2,creeVecteur(0,-VITESSE_DEPLACEMENT_RAQUETTE));
                                break;
                case SDL_SCANCODE_ESCAPE:
                    if((*pstEtatPartie)==pause){
                        *pstEtatPartie=enCours;
                    }else{
                        *pstEtatPartie=pause;
                    }
                    break;
                case SDL_SCANCODE_F4: *pstEtatPartie=quitter;break;
            }
        break;
        }
    }

}*/

//###########################################
//FONCTION testToucheAppuyer
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui en fonction des etats du clavier, renvoi un booleen valant true, si la touche en argument est enfoncé.
//
// ENTREE - La référence des EtatsClavier et le le code physique de la touche de type SDL_Scancode.
//
// SORTIE - Le booléen
//
// NOTE - Utilise SDL_PumpsEvents
//*****************************************************************************************************//
tBool testToucheAppuyer(const Uint8* pEtatsClavier, const SDL_Scancode tCodeTouche){
    if ( pEtatsClavier[tCodeTouche] ){
        return true;
    }else{
        return false;
    }

}

//###########################################
//PROCEDURE gestionEvenements
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui en fonction des touches pressées, déclenche les évenements et modifie l'état des objets.
//
// ENTREE - La référence de tEtatPartie, la référence de l'objet du J1, la référence de l'objet du joueur 2.
//
// SORTIE - La modification de l'état des objets
//
// NOTE - Utilise SDL_PumpsEvents
//*****************************************************************************************************//
void gestionEvenements(tEtatPartie *pstEtatPartie, tPointeur *pstPointeur){

    SDL_PumpEvents(); // On demande à la SDL de mettre à jour les états sur les périphériques

    const Uint8* pEtatsClavier= SDL_GetKeyboardState(NULL);   //pEtatsClavier recoit l'etat des périphériques


    ///TEST TOUCHES SPECIALES///

    //test echap (change l'etat de la partie de en cours à en pause, ou inversement.
    if(testToucheAppuyer(pEtatsClavier,SDL_SCANCODE_ESCAPE)){
        if((*(pstEtatPartie))==enCours){
            *pstEtatPartie=pause;
            SDL_Delay(DELAI_REPRISE_PARTIE);
        }else{
            *pstEtatPartie=enCours;
            SDL_Delay(DELAI_REPRISE_PARTIE);

        }
    }
    //test F4, passe l'etat de la partie à quitter
    if(testToucheAppuyer(pEtatsClavier,SDL_SCANCODE_F4)){
        *pstEtatPartie=quitter;
    }

    recuperationInfoPointeur(pstPointeur);
}



void recuperationInfoPointeur(tPointeur *pstPointeur){
    int nX, nY;
    SDL_GetMouseState(&nX,&nY);  //récupère la position du pointeur

    setPointeurPosition(pstPointeur,creePoint(nX,nY));   //affecte la position du pointeur au pointeur

    if(SDL_GetMouseState(NULL,NULL)&&SDL_BUTTON(SDL_BOUTON_CLIQUE_GAUCHE)){
        setPointeurCliqueGauche(pstPointeur,true);  //si clique gauche, affecte vrai au booleen stCliqueGauche
    }else{
        setPointeurCliqueGauche(pstPointeur,false);
    }

    if(SDL_GetMouseState(NULL,NULL)&&SDL_BUTTON(SDL_BOUTON_CLIQUE_DROIT)){
        setPointeurCliqueDroit(pstPointeur,true);  //idem stCliqueDroit
    }else{
        setPointeurCliqueDroit(pstPointeur,false);
    }

    if(SDL_GetMouseState(NULL,NULL)&&SDL_BUTTON(SDL_BOUTON_CLIQUE_MOLETTE)){
        setPointeurCliqueMolette(pstPointeur,true);  //idem stCliqueMolette
    }else{
        setPointeurCliqueMolette(pstPointeur,false);
    }
}

