#include "level.h"

void gestionLevel1(tManaComposant *pMana){
    if(pMana->pEtatJeu->nAvancementLevel==0||pMana->pEtatJeu->nAvancementLevel<=pMana->pEtatJeu->nAvancementLevelSauvegarde){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(193*0.5,100*0.5),193,100),creeVecteur(0,0),creeVecteur(0,0)),"testDragDrop");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"testDragDrop"),ABRICOT_JPG),"imgTest");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LEVEL1);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;
    }
    if(pMana->pEtatJeu->nAvancementLevel>=1||pMana->pEtatJeu->nAvancementLevel<=pMana->pEtatJeu->nAvancementLevelSauvegarde){
        dragAndDropImage(recupImageParNom(pMana->pListeImage,"imgTest"),pMana->pPointeur);
    }
    dialogueSuivant(pMana,1);
    dialogueSuivant(pMana,2);
    dialogueSuivant(pMana,3);
    dialogueSuivant(pMana,4);
    dialogueSuivant(pMana,5);
    dialogueSuivant(pMana,6);
    /*if(pEtatJeu->nAvancementLevel==1||pEtatJeu->nAvancementLevel<=pEtatJeu->nAvancementLevelSauvegarde){

    }*/

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
