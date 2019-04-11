#include "etatPartie.h"

///METHODES DES ACTIONS

//###########################################
//PROCEDURE gestionAction
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui fait les appels des méhtodes et modifie l'état de la partie en fonction des actions.
//
// ENTREE /La valeur de l'action, La réference du manager de composants, la référence de l'état de la partie.
//
// SORTIE /Les listes de composants modifiés, l'etat de la partie modifié.
//
// NOTE -
//*****************************************************************************************************//
void gestionAction(const tAction nAction, tManaComposant *pMana, tEtatPartie *pEtatPartie){
    if(nAction!=0){
        switch(nAction){
            //MENU PRINCIPALE
            case nouvelle_partie:
                supprMenuPrincipale(pMana);
                ajoutInterfaceJeu(pMana);
                *pEtatPartie = enCours;
                break;
            case charger:
                supprMenuPrincipale(pMana);
                ajoutMenuCharger(pMana);
                *pEtatPartie = enCours;
                break;
            case options:
                supprMenuPrincipale(pMana);
                ajoutMenuOptions(pMana);
                *pEtatPartie = menu;
                break;
            case fermerJeu:
                *pEtatPartie = quitter;
                break;
            //MENU CHARGER
            case retourMenuPrincipalDepuisCharger:
                supprMenuCharger(pMana);
                ajoutMenuPrincipale(pMana);
                *pEtatPartie = menu;
                break;

            //MENU OPTION
            case retourMenuPrincipalDepuisOptions:
                supprMenuOptions(pMana);
                ajoutMenuPrincipale(pMana);
                *pEtatPartie = menu;
                break;

            //MENU DU JEU
            case reprendrePartie:
                supprMenuJeu(pMana);
                ajoutInterfaceJeu(pMana);
                *pEtatPartie = enCours;
                break;
            case quitterPartie:
                supprMenuJeu(pMana);
                ajoutMenuPrincipale(pMana);
                *pEtatPartie = menu;

            case sauvegarder:
                break;

            //EN JEU
            case ouvrirMenuJeu:
                *pEtatPartie = pause;
                supprInterfaceJeu(pMana);
                ajoutMenuJeu(pMana);
                break;
        }
    }
}

//###########################################
//PROCEDURE gestionAction
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui appel la méthode qui gère les actions pour chaque bouton.
//
// ENTREE /La référence du manager de composant, la référence de l'état de la partie.
//
// SORTIE /Les listes de composants modifiés, l'etat de la partie modifié.
//
// NOTE -
//*****************************************************************************************************//
void gestionActionListeBouton(tManaComposant *pMana, tEtatPartie *pEtatPartie){

    //VERIFIE SI LA LISTE EXISTE
    if(pMana->pListeBouton == NULL){
        printf("Erreur d'affichage, la liste n'existe pas.");
        exit(EXIT_FAILURE);
    }

    //SI LA LISTE N'EST PAS VIDE
    if(pMana->pListeBouton->pPremier != NULL){
       tElementBouton *pElement = pMana->pListeBouton->pPremier;
        while(pElement->pSuivant!=NULL){
            if(pElement->stBouton.stClique){    //si le bouton a été cliqué
                gestionAction(pElement->stBouton.nCodeAction,pMana,pEtatPartie);
                SDL_Delay(DELAI_CLICK_BOUTON);
            }
            pElement = pElement->pSuivant;
        }
        if(pElement->stBouton.stClique){    // si le bouton a été cliqué
            gestionAction(pElement->stBouton.nCodeAction,pMana,pEtatPartie);    //gère les action du dernier élément de la liste
            SDL_Delay(DELAI_CLICK_BOUTON);
        }
    }

}
