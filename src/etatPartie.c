#include "etatPartie.h"

///METHODES DES ACTIONS

//###########################################
//PROCEDURE gestionAction
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui fait les appels des m�htodes et modifie l'�tat de la partie en fonction des actions.
//
// ENTREE /La valeur de l'action, La r�ference du manager de composants, la r�f�rence de l'�tat de la partie.
//
// SORTIE /Les listes de composants modifi�s, l'etat de la partie modifi�.
//
// NOTE -
//*****************************************************************************************************//
void gestionAction(const tAction nAction, tManaComposant *pMana, tEtatPartie *pEtatPartie){
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
                    ajoutInterfaceJeu(pMana);
                    vidageComposantsProgramme(pMana);
                    *pEtatPartie = enCours;
                }
                break;
            case chargerEmpl3:
                if(chargementPartie(EMPL_FICHIER_SAUVEGARDE_3,pMana->pEtatJeu)){
                    ajoutInterfaceJeu(pMana);
                    vidageComposantsProgramme(pMana);
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
                *pEtatPartie = enCours;
                break;
            case quitterPartie:
                vidageComposantsProgramme(pMana);
                ajoutMenuPrincipale(pMana);
                *pEtatPartie = menu;

            case sauvegarder:
                pMana->pEtatJeu->nAvancementLevel = 0;
                sauvegardePartie(pMana->pEtatJeu->cEmplFichierSauvegarde,*pMana->pEtatJeu);
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
// DESCRIPTION Procedure qui appel la m�thode qui g�re les actions pour chaque bouton.
//
// ENTREE /La r�f�rence du manager de composant, la r�f�rence de l'�tat de la partie.
//
// SORTIE /Les listes de composants modifi�s, l'etat de la partie modifi�.
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
        while(pElement->pSuivant!=NULL&&nCodeAction==0){    //si aucune action n'a �t� enregistrer.
            if(pElement->stBouton.stClique){    //si le bouton a �t� cliqu�
                nCodeAction = pElement->stBouton.nCodeAction;
            }
            pElement = pElement->pSuivant;
        }
        //g�re les action du dernier �l�ment de la liste
        if(nCodeAction==0&&pElement->stBouton.stClique){    // si le bouton a �t� cliqu�
            nCodeAction = pElement->stBouton.nCodeAction;

        }
        if(nCodeAction!=0){
            gestionAction(nCodeAction,pMana,pEtatPartie);
            pMana->pPointeur->stCliqueGauche = false; // �vite que l'on clique sur un bouton qui va r�aparraitre
            SDL_Delay(DELAI_CLICK_BOUTON);
        }
    }
}
