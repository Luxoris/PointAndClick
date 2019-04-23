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
    tEtatJeu stEtatJeu;
    if(nAction!=0){
        switch(nAction){
            //MENU PRINCIPALE
            case nouvelle_partie:
                vidageComposantsProgramme(pMana);
                ajoutMenuNouvellePartie(pMana);
                *pEtatPartie = menu;
                break;
            case charger:
                vidageComposantsProgramme(pMana);
                ajoutMenuCharger(pMana);
                *pEtatPartie = menu;
                break;
            case options:
                vidageComposantsProgramme(pMana);
                ajoutMenuOptions(pMana);
                *pEtatPartie = menu;
                break;
            case fermerJeu:
                *pEtatPartie = quitter;
                break;
            //MENU NOUVELLE PARTIE
            case nouvellePartieEmpl1:
                vidageComposantsProgramme(pMana);
                strcpy(pMana->pEtatJeu->cEmplFichierSauvegarde,EMPL_FICHIER_SAUVEGARDE_1);
                *pEtatPartie = initialisation;
                break;
            case nouvellePartieEmpl2:
                vidageComposantsProgramme(pMana);
                strcpy(pMana->pEtatJeu->cEmplFichierSauvegarde,EMPL_FICHIER_SAUVEGARDE_2);
                *pEtatPartie = initialisation;
                break;
            case nouvellePartieEmpl3:
                vidageComposantsProgramme(pMana);
                strcpy(pMana->pEtatJeu->cEmplFichierSauvegarde,EMPL_FICHIER_SAUVEGARDE_3);
                *pEtatPartie = initialisation;
                break;
            case retourMenuPrincipalDepuisNouvellePartie:
                vidageComposantsProgramme(pMana);
                ajoutMenuPrincipale(pMana);
                *pEtatPartie = menu;
                break;
            //MENU CHARGER
            case chargerEmpl1:
                if(chargementPartie(EMPL_FICHIER_SAUVEGARDE_1,pMana->pEtatJeu)){
                    vidageComposantsProgramme(pMana);
                    ajoutInterfaceJeu(pMana);
                    *pEtatPartie = enCours;
                }
                break;
            case chargerEmpl2:
                if(chargementPartie(EMPL_FICHIER_SAUVEGARDE_2,pMana->pEtatJeu)){
                    vidageComposantsProgramme(pMana);
                    ajoutInterfaceJeu(pMana);
                    *pEtatPartie = enCours;
                }
                break;
            case chargerEmpl3:
                if(chargementPartie(EMPL_FICHIER_SAUVEGARDE_3,pMana->pEtatJeu)){
                    vidageComposantsProgramme(pMana);
                    ajoutInterfaceJeu(pMana);
                    *pEtatPartie = enCours;
                }
                break;
            case retourMenuPrincipalDepuisCharger:
                vidageComposantsProgramme(pMana);
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
                manaMajAffichageHorloge(pMana);
                *pEtatPartie = enCours;
                break;
            case quitterPartie:
                vidageComposantsProgramme(pMana);
                ajoutMenuPrincipale(pMana);
                *pEtatPartie = menu;

            case sauvegarder:
                stEtatJeu = *pMana->pEtatJeu;
                stEtatJeu.nAvancementLevel = 0;
                sauvegardePartie(pMana->pEtatJeu->cEmplFichierSauvegarde,stEtatJeu);
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
       int nCodeAction = 0;
        while(pElement->pSuivant!=NULL&&nCodeAction==0){    //si aucune action n'a été enregistrer.
            if(pElement->stBouton.stClique){    //si le bouton a été cliqué
                nCodeAction = pElement->stBouton.nCodeAction;
            }
            pElement = pElement->pSuivant;
        }
        //gère les action du dernier élément de la liste
        if(nCodeAction==0&&pElement->stBouton.stClique){    // si le bouton a été cliqué
            nCodeAction = pElement->stBouton.nCodeAction;

        }
        if(nCodeAction!=0){
            gestionAction(nCodeAction,pMana,pEtatPartie);
            pMana->pPointeur->stCliqueGauche = false; // évite que l'on clique sur un bouton qui va réaparraitre
            SDL_Delay(DELAI_CLICK_BOUTON);
        }
    }
}
