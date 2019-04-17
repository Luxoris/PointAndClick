#include "dialogue.h"

//###########################################
//PROCEDURE initFichierDialogue
//*****************************************************************************************************//
//
// DESCRIPTION Ouvre et modifie la référence du pointeur de fichier de dialogue.
//
// ENTREE / La référence du fichier, la chaine correspondant à l'emplacmeent du fichier à ouvrir.
//
// SORTIE /La référence du fichier modifié, le fichier ouvert.
//
// NOTE -
//*****************************************************************************************************//
void initFichierDialogue(FILE **ppFile,char cEmpl[]){
    if(*ppFile!=NULL){   //ferme le fichier si le pointeur ne vaut pas null.
        fclose(*ppFile);
        *ppFile=NULL;
    }
    if((*ppFile = fopen(cEmpl,"r"))==NULL){  //ouvre le fichier et vréfie que l'ouverture s'est effectué correctement.
        printf("Erreur lors de l'ouverture du fichier de dialogue.\n");
    }
}


//###########################################
//PROCEDURE texteSuivant
//*****************************************************************************************************//
//
// DESCRIPTION Remplace le texte d'un élément de type texte par le texte du dialogue Suivant.
//
// ENTREE / La référence du fichier, la chaine a retourner.
//
// SORTIE /La chaine modifié
//
// NOTE -
//*****************************************************************************************************//
void texteSuivant(FILE *pFile,tTexte *pTexte){
    char cChaine[TAILLE_MAX_LIGNE_DIALOGUE];
    recuperationChaine(pFile,cChaine);
    setTexteTexte(pTexte,cChaine);
}


//###########################################
//PROCEDURE recuperationChaine
//*****************************************************************************************************//
//
// DESCRIPTION Recupère la chaine de caractère contenu entre deux séparateur
//
// ENTREE / La référence du fichier, la chaine a retourner.
//
// SORTIE /La chaine modifié
//
// NOTE -
//*****************************************************************************************************//


void recuperationChaine(FILE *pFile,char cChaine[]){
    char cChar;
    if(pFile!=NULL){
        strcpy(cChaine,"");
        do{
          cChar = fgetc(pFile);
          if(cChar==EOF){
            fclose(pFile);
            pFile = NULL;
            break;
          }
          if(cChar!=SEPARATEUR){
            strncat(cChaine,&cChar,1);
          }
        }while(cChar!=SEPARATEUR);
    }
}

tBool dialogueSuivant(tManaComposant *pMana, int nValeurAvancementLevel){
    if((pMana->pEtatJeu->nAvancementLevel==nValeurAvancementLevel)&&(recupBoutonParNom(pMana->pListeBouton,"suivant")->stClique)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        recupBoutonParNom(pMana->pListeBouton,"suivant")->stClique=false;
        SDL_Delay(DELAI_CLICK_BOUTON);
        pMana->pEtatJeu->nAvancementLevel++;

        return true;
    }else{
        return false;
    }
}
