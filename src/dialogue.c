#include "dialogue.h"

//###########################################
//PROCEDURE initFichierDialogue
//*****************************************************************************************************//
//
// DESCRIPTION Ouvre et modifie la r�f�rence du pointeur de fichier de dialogue.
//
// ENTREE / La r�f�rence du fichier, la chaine correspondant � l'emplacmeent du fichier � ouvrir.
//
// SORTIE /La r�f�rence du fichier modifi�, le fichier ouvert.
//
// NOTE -
//*****************************************************************************************************//
void initFichierDialogue(FILE **ppFile,char cEmpl[]){
    if(*ppFile!=NULL){   //ferme le fichier si le pointeur ne vaut pas null.
        fclose(*ppFile);
        *ppFile=NULL;
    }
    if((*ppFile = fopen(cEmpl,"r"))==NULL){  //ouvre le fichier et vr�fie que l'ouverture s'est effectu� correctement.
        printf("Erreur lors de l'ouverture du fichier de dialogue.\n");
    }
}


//###########################################
//PROCEDURE texteSuivant
//*****************************************************************************************************//
//
// DESCRIPTION Remplace le texte d'un �l�ment de type texte par le texte du dialogue Suivant.
//
// ENTREE / La r�f�rence du fichier, la chaine a retourner.
//
// SORTIE /La chaine modifi�
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
// DESCRIPTION Recup�re la chaine de caract�re contenu entre deux s�parateur
//
// ENTREE / La r�f�rence du fichier, la chaine a retourner.
//
// SORTIE /La chaine modifi�
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

void dialogueSuivant(tManaComposant *pMana, int nValeurAvancementLevel){
    if((pMana->pEtatJeu->nAvancementLevel==nValeurAvancementLevel)&&(recupBoutonParNom(pMana->pListeBouton,"suivant")->stClique)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        recupBoutonParNom(pMana->pListeBouton,"suivant")->stClique=false;
        SDL_Delay(DELAI_CLICK_BOUTON);
        pMana->pEtatJeu->nAvancementLevel++;
    }
}
