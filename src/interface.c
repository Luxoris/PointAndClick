#include "interface.h"

///METHODES DES MENUS

//###########################################
//PROCEDURE ajoutMenuPrincipale
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les composants du menu principale.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMenuPrincipale(tManaComposant *pMana){
    //DECLARATION DES PROPRIETES DES TEXTES
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*2,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreJeu");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+2))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+2))*3),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp2");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+2))*4),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp3");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+2))*5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mPpEmp4");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_PRINCIPAL+2))),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreJeu");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mPpEmp1"),"Nouvelle Partie",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,nouvelle_partie),"nouvellePartie");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mPpEmp2"),"Charger",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,charger),"charger");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mPpEmp3"),"Options",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,options),"options");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mPpEmp4"),"Quitter",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,fermerJeu),"fermerJeu");

    //DECLARATION DES IMAGES
    insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuPrincipale");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte(NOM_DU_JEU,recupObjetParNom(pMana->pListeObjet,"titreJeu"),recupPropTexteParNom(pMana->pListePropTexte,"titreJeu")),"titreJeu");

}

//###########################################
//PROCEDURE supprMenuPrincipale
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime les composants du menu principale.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprMenuPrincipale(tManaComposant *pMana){

    //SUPPRESSION DES PROPRIETES DES TEXTES
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"titreJeu"));
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"boutonMenu"));

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreJeu"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp4"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp3"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp1"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"centre"));


    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"fermerJeu"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"options"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"charger"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"nouvellePartie"));

    //SUPPRESSION DES IMAGES
    suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuPrincipale"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreJeu"));
}

//###########################################
//PROCEDURE ajoutMenuJeu
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les composants du menu du jeu.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMenuJeu(tManaComposant *pMana){
    //DECLARATION DES PROPRIETES DES TEXTES
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*2,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuJeu");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_JEU+2))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mJeuEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_JEU+2))*3),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mJeuEmp2");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_JEU+2))*4),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mJeuEmp3");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_JEU+2))),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuJeu");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mJeuEmp1"),"Reprendre",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,reprendrePartie),"reprendreJeu");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mJeuEmp2"),"Sauvegarder",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,sauvegarder),"sauvegarder");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mJeuEmp3"),"Quitter",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,quitterPartie),"quitterJeu");

    //DECLARATION DES IMAGES
    insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuJeu");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Partie en Pause",recupObjetParNom(pMana->pListeObjet,"titreMenuJeu"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuJeu")),"titreMenuJeu");
}



//###########################################
//PROCEDURE supprMenuJeu
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime les composants du menu du jeu.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprMenuJeu(tManaComposant *pMana){

    //SUPPRESSION DES PROPRIETES DES TEXTES
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"titreMenuJeu"));
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"boutonMenu"));

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuJeu"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mJeuEmp3"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mJeuEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mJeuEmp1"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"centre"));


    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"reprendreJeu"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"sauvegarder"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"quitterJeu"));

    //SUPPRESSION DES IMAGES
    suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuJeu"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreMenuJeu"));
}

//###########################################
//PROCEDURE ajoutMenuOptions
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les composants du menu des options.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMenuOptions(tManaComposant *pMana){
    //DECLARATION DES PROPRIETES DES TEXTES
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*2,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuOptions");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_OPTION+2))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_OPTION+2))),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuOptions");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp1"),"Retour",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,retourMenuPrincipalDepuisOptions),"retourMenuDepuisOptions");

    //DECLARATION DES IMAGES
    insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuOptions");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Options",recupObjetParNom(pMana->pListeObjet,"titreMenuOptions"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuOptions")),"titreMenuOptions");
}

//###########################################
//PROCEDURE supprMenuOptions
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime les composants du menu options du jeu.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprMenuOptions(tManaComposant *pMana){

    //SUPPRESSION DES PROPRIETES DES TEXTES
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"titreMenuOptions"));
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"boutonMenu"));

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuOptions"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp1"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"centre"));


    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"retourMenuDepuisOptions"));

    //SUPPRESSION DES IMAGES
    suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuOptions"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreMenuOptions"));

}

//###########################################
//PROCEDURE ajoutMenuNouvellePartie
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les composants du menu nouvelle partie.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMenuNouvellePartie(tManaComposant *pMana){
    //DECLARATION DES PROPRIETES DES TEXTES
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*2,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuNouvellePartie");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_NOUVELLE_PARTIE+2))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_NOUVELLE_PARTIE+2))*3),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp2");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_NOUVELLE_PARTIE+2))*4),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp3");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_NOUVELLE_PARTIE+2))*5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp4");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_NOUVELLE_PARTIE+2))),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuNouvellePartie");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp1"),"Empl 1",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,nouvellePartieEmpl1),"nouvellePartieEmpl1");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp2"),"Empl 2",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,nouvellePartieEmpl2),"nouvellePartieEmpl2");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp3"),"Empl 3",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,nouvellePartieEmpl3),"nouvellePartieEmpl3");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp4"),"Retour",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,retourMenuPrincipalDepuisNouvellePartie),"retourMenuDepuisNouvellePartie");

    //DECLARATION DES IMAGES
    insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuNouvellePartie");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Empl de sauvegarde ?",recupObjetParNom(pMana->pListeObjet,"titreMenuNouvellePartie"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuNouvellePartie")),"titreMenuNouvellePartie");
}

//###########################################
//PROCEDURE supprMenuNouvellePartie
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime les composants du menu nouvelle partie.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprMenuNouvellePartie(tManaComposant *pMana){

    //SUPPRESSION DES PROPRIETES DES TEXTES
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"titreMenuNouvellePartie"));
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"boutonMenu"));

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuNouvellePartie"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp1"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp3"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp4"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"centre"));

    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"retourMenuDepuisNouvellePartie"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"nouvellePartieEmpl1"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"nouvellePartieEmpl2"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"nouvellePartieEmpl3"));

    //SUPPRESSION DES IMAGES
    suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuNouvellePartie"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreMenuNouvellePartie"));

}


//###########################################
//PROCEDURE ajoutMenuCharger
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les composants du menu charger.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMenuCharger(tManaComposant *pMana){
    //DECLARATION DES PROPRIETES DES TEXTES
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*2,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuCharger");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))*3),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp2");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))*4),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp3");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))*5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp4");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuCharger");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp1"),"Empl 1",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,chargerEmpl1),"chargerEmpl1");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp2"),"Empl 2",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,chargerEmpl2),"chargerEmpl2");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp3"),"Empl 3",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,chargerEmpl3),"chargerEmpl3");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp4"),"Retour",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,retourMenuPrincipalDepuisCharger),"retourMenuDepuisCharger");

    //DECLARATION DES IMAGES
    insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuCharger");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Charger",recupObjetParNom(pMana->pListeObjet,"titreMenuCharger"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuCharger")),"titreMenuCharger");
}

//###########################################
//PROCEDURE supprMenuCharger
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime les composants du menu charger.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprMenuCharger(tManaComposant *pMana){

    //SUPPRESSION DES PROPRIETES DES TEXTES
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"titreMenuCharger"));
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"boutonMenu"));

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuCharger"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp1"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp3"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp4"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"centre"));

    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"retourMenuDepuisCharger"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"chargerEmpl1"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"chargerEmpl2"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"chargerEmpl3"));


    //SUPPRESSION DES IMAGES
    suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuCharger"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreMenuCharger"));

}


//###########################################
//PROCEDURE ajoutInterfaceJeu
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les composants de l'interface du jeu.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutInterfaceJeu(tManaComposant *pMana){
    //DECLARATION DES PROPRIETES DES TEXTES
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"dialogue");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_HORLOGE,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"horloge");


    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*0.5),HAUTEUR_BOUTON*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp1");
    if(recupElementObjetParNom(pMana->pListeObjet,"boutonEmp2")==NULL){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*0.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp2");
    }
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,HAUTEUR_DIALOGUE),LARGEUR_DIALOGUE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"dialogue");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"centre");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(LARGEUR_BOUTON*0.5,HAUTEUR_BOUTON*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"horloge");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp1"),"Menu",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,ouvrirMenuJeu),"ouvrirMenuJeu");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),"Suivant",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"suivant");

    //DECLARATION DES IMAGES
    //insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"imgTest");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("",recupObjetParNom(pMana->pListeObjet,"dialogue"),recupPropTexteParNom(pMana->pListePropTexte,"dialogue")),"dialogue");
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("",recupObjetParNom(pMana->pListeObjet,"horloge"),recupPropTexteParNom(pMana->pListePropTexte,"horloge")),"horloge");
}

//###########################################
//PROCEDURE supprInterfaceJeu
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprime les composants de l'interface du jeu.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprInterfaceJeu(tManaComposant *pMana){

    //SUPPRESSION DES PROPRIETES DES TEXTES
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"dialogue"));
    suppressionPropTexteListe(pMana->pListePropTexte,recupElementPropTexteParNom(pMana->pListePropTexte,"boutonMenu"));

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"dialogue"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"boutonEmp1"));
    //suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"boutonEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"centre"));

    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"ouvrirMenuJeu"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"suivant"));

    //SUPPRESSION DES IMAGES
    //suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuCharger"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"dialogue"));
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"horloge"));
}

//###########################################
//PROCEDURE initComposantsProgramme
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoute les composants de base du programme.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void initComposantsProgramme(tManaComposant *pManaComposant){
    //DECLARATION DE LA LISTE DES PROPRIETES DES TEXTES DU JEU
    //insertionPropTexteListe(pManaComposant->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_BOUTON,TTF_FONT_VERDANA,SDL_CL_ROUGE,SDL_CL_BLEU,"",TTF_Charset_Latin1,TTF_Mode_Solid),"boutonMenu");
}


//###########################################
//PROCEDURE ajoutBoutonChoix
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoutes les deux boutons de choix.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void ajoutBoutonChoix(tManaComposant *pMana,char sChoix1[], char sChoix2[]){
//DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5+(HAUTEUR_BOUTON*2)),WINDOW_LARGEUR-MARGE_BORD,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonChoixEmp2");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5-(HAUTEUR_BOUTON*2)),WINDOW_LARGEUR-MARGE_BORD,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonChoixEmp1");

//INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonChoixEmp1"),sChoix1,recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"choix1");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonChoixEmp2"),sChoix2,recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"choix2");

//SUPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"suivant"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"ouvrirMenuJeu"));
}

//###########################################
//PROCEDURE supprBoutonChoix
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui supprim les deux boutons de choix.
//
// ENTREE /La réference du manager de composants.
//
// SORTIE /Les listes de composants modifiés.
//
// NOTE -
//*****************************************************************************************************//
void supprBoutonChoix(tManaComposant *pMana){
    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"boutonChoixEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"boutonChoixEmp1"));

    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"choix1"));
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"choix2"));

    //AJOUT DES BOUTONS D'INTERFACE
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp1"),"Menu",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,ouvrirMenuJeu),"ouvrirMenuJeu");
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),"Suivant",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"suivant");


}


//###########################################
//PROCEDURE manaMajAffichageHorloge
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui met à jour l'affichage de l'heure.
//
// ENTREE /La référence du manager de composants.
//
// SORTIE /La texte de l'horloge modifié.
//
// NOTE -
//*****************************************************************************************************//
void manaMajAffichageHorloge(tManaComposant *pMana){
    majAffichageHorloge(recupTexteParNom(pMana->pListeTexte,"horloge"),&pMana->pEtatJeu->stHorloge);

}







