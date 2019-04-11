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

    //DECLARATION DES OBJETS
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

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreJeu"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp4"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp3"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mPpEmp1"));


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

    //DECLARATION DES OBJETS
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

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuJeu"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mJeuEmp3"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mJeuEmp2"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mJeuEmp1"));


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

    //DECLARATION DES OBJETS
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

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuOptions"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp1"));


    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"retourMenuDepuisOptions"));

    //SUPPRESSION DES IMAGES
    suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuOptions"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreMenuOptions"));

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

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))*2),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"mEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,(WINDOW_HAUTEUR/(NB_BOUTON_MENU_CHARGER+2))),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuCharger");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"mEmp1"),"Retour",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,retourMenuPrincipalDepuisCharger),"retourMenuDepuisCharger");

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

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"titreMenuCharger"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"mEmp1"));

    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"retourMenuDepuisCharger"));

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
    insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"dialogue");

    //DECLARATION DES OBJETS
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*0.5),HAUTEUR_BOUTON*0.5),LARGEUR_BOUTON,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp1");
    insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR-HAUTEUR_DIALOGUE),LARGEUR_DIALOGUE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"dialogue");

    //INSERTION DES BOUTONS
    insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp1"),"Menu",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,ouvrirMenuJeu),"ouvrirMenuJeu");

    //DECLARATION DES IMAGES
    //insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"centre"),ABRICOT_JPG),"fondEcranMenuOptions");

    //DECLARATION DES TEXTES
    insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Dialogue de Test un peu long pour voir comment ça rend parce que c'est compliqué a voir.",recupObjetParNom(pMana->pListeObjet,"dialogue"),recupPropTexteParNom(pMana->pListePropTexte,"dialogue")),"dialogue");
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

    //SUPPRESSION DES OBJETS
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"dialogue"));
    suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"boutonEmp1"));

    //SUPPRESSION DES BOUTONS
    suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"ouvrirMenuJeu"));

    //SUPPRESSION DES IMAGES
    //suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"fondEcranMenuCharger"));

    //SUPPRESSION DES TEXTES
    suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"dialogue"));
}
