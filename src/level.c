#include "level.h"

void gestionLevel1(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=7;
        pMana->pEtatJeu->stHorloge.nMinute=0;

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"testDragDrop");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"testDragDrop"),CHAMBRE_JPG),"imgTest");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LEVEL1);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;
        ajoutBoutonChoix(pMana,"Choix1","Choix2");
    }
    if(pMana->pEtatJeu->nAvancementLevel>=1){
        //dragAndDropImage(recupImageParNom(pMana->pListeImage,"imgTest"),pMana->pPointeur);
    }


    if((nChoix = choixBouton(pMana,1))>0){
        if(nChoix==1){
            manaAjoutMinute(pMana,61);
            manaMajAffichageHorloge(pMana);
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        }else{
            manaAjoutMinute(pMana,61);
            manaMajAffichageHorloge(pMana);
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        }
        pMana->pEtatJeu->nAvancementLevel++;
    }

    dialogueSuivant(pMana,2);
    dialogueSuivant(pMana,3);
    dialogueSuivant(pMana,4);
    dialogueSuivant(pMana,5);
    dialogueSuivant(pMana,6);

}

void gestionLevelLeReveil(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=7;
        pMana->pEtatJeu->stHorloge.nMinute=0;

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CHAMBRE_JPG),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LEREVEIL);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;

    }

    dialogueSuivant(pMana,1);

    if(actionBouton(pMana,"suivant",2)){
        ajoutBoutonChoix(pMana,"Eteindre le réveil et se lever","Eteindre le réveil et se recoucher");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,3))>0){
        if(nChoix==1){
            manaAjoutMinute(pMana,1);
            manaMajAffichageHorloge(pMana);
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=10;
        }else{
            manaAjoutMinute(pMana,8);
            manaMajAffichageHorloge(pMana);
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=20;
        }

    }

    //si le joueur a fait le choix 1
    dialogueSuivant(pMana,10);
    if(actionBouton(pMana,"suivant",11)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=0;
        pMana->pEtatJeu->nAvancementLevel=0;    //le joueur passe au niveau suivants
    }

    //si le joueur a fait le choix 2
    if(dialogueSuivant(pMana,20)){
        //afficher image mère.
    }

    if(actionBouton(pMana,"suivant",21)){   //le joueur passe au niveau suivant
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=0;
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}

//###########################################
//FONCTION sauvegardetPartie
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui sauvegarde l'état du jeu dans un fichier binaire.
//
// ENTREE /Le chemin du fichier, la référence de l'état du jeu.
//
// SORTIE /Le fichier de sauvegarde créer.
//
// NOTE -
//*****************************************************************************************************//
int sauvegardePartie(const char cCheminFichier[],const tEtatJeu stEtatJeu){
    FILE *pFile;

    if((pFile = fopen(cCheminFichier,"wb"))==NULL){
        printf("Erreur d'ouverture du fichier, accès refuse.\n");
        return 0;
    }else{
        fwrite(&stEtatJeu,sizeof(stEtatJeu),1,pFile);
        fclose(pFile);
        return 1;
    }
}

//###########################################
//FONCTION chargementPartie
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui récupère l'état du jeu à partir d'un fichier binaire.
//
// ENTREE /Le chemin du fichier, la référence de l'état du jeu.
//
// SORTIE /L'etat du jeu modifié.
//
// NOTE -
//*****************************************************************************************************//
int chargementPartie(const char cCheminFichier[],tEtatJeu *pstEtatJeu){
    FILE *pFile;

    if((pFile = fopen(cCheminFichier,"rb"))==NULL){
        printf("Erreur de chargement du fichier.\n");
        return 0;
    }else{
        fread(pstEtatJeu,sizeof(*pstEtatJeu),1,pFile);
        fclose(pFile);
        return 1;
    }

}


//###########################################
//FONCTION actionBouton
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui retourne false si pas de clique à l'acancement de la partie, ou true si clique.
//
// ENTREE /La reférence du manager de composant, le nom du bouton, la valeur d''avancement.
//
// SORTIE /Le bool correspondant à l'état du jeu.
//
// NOTE -
//*****************************************************************************************************//
tBool actionBouton(tManaComposant *pMana,char sNomBouton[], int nValeurAvancementLevel){
    if((pMana->pEtatJeu->nAvancementLevel==nValeurAvancementLevel)&&(recupBoutonParNom(pMana->pListeBouton,sNomBouton)->stClique)){
        recupBoutonParNom(pMana->pListeBouton,sNomBouton)->stClique=false;
        SDL_Delay(DELAI_CLICK_BOUTON);
        return true;
    }else{
        return false;
    }
}

//###########################################
//FONCTION choixBouton
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui retourne 0 si pas de clique, 1 si choix 1 et 2 si choix 2.
//
// ENTREE /La reférence du manager de composant, la valeur d''avancement.
//
// SORTIE /Le bool correspondant au choix.
//
// NOTE -
//*****************************************************************************************************//
int choixBouton(tManaComposant *pMana, int nValeurAvancementLevel){
    if(actionBouton(pMana,"choix1",nValeurAvancementLevel)){
        return 1;
    }else{
        if(actionBouton(pMana,"choix2",nValeurAvancementLevel)){
            return 2;
        }else{
            return 0;
        }
    }
}

