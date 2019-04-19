#include "level.h"

void gestionLevel1(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=7;
        pMana->pEtatJeu->stHorloge.nMinute=0;

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"testDragDrop");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"testDragDrop"),CHAMBRE),"imgTest");
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
///
///
///
void gestionLevelLeReveil(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=7;
        pMana->pEtatJeu->stHorloge.nMinute=0;
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CHAMBRE),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LEREVEIL);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
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

    ///si le joueur a fait le choix 1
    dialogueSuivant(pMana,10);
    if(actionBouton(pMana,"suivant",11)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;    //le joueur passe au niveau suivant
        pMana->pEtatJeu->nAvancementLevel=0;
    }

    ///si le joueur a fait le choix 2
    if(dialogueSuivant(pMana,20)){
        manaAjoutMinute(pMana,1);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"maman");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
    }

    if(actionBouton(pMana,"suivant",21)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;  //le joueur passe au niveau suivant
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}
///
///
///
void gestionLevelLePetitDejeuner(tManaComposant *pMana){
        int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),SALLEAMANGER),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"maman");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LEPETITDEJEUNER);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;

    }
    if(dialogueSuivant(pMana,1)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
    }

    if(dialogueSuivant(pMana,2)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
    }

    if(actionBouton(pMana,"suivant",3)){
        ajoutBoutonChoix(pMana,"Jus d'orange et Muesli","Pâte à tartiner et chocoloat chaud.");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,4))>0){
        if(nChoix==1){
            manaAjoutMinute(pMana,10);
            manaMajAffichageHorloge(pMana);
            supprBoutonChoix(pMana);
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=7;
        }else{
            manaAjoutMinute(pMana,10);
            manaMajAffichageHorloge(pMana);
            supprBoutonChoix(pMana);
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel++;
        }
    }

    ///si le joueur a fait le choix 2
    if(dialogueSuivant(pMana,5)){
        manaAjoutMinute(pMana,2);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
    }

    dialogueSuivant(pMana,6);

    ///si le joueur a fait le choix 1 et 2
    if(actionBouton(pMana,"suivant",7)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;  //le joueur passe au niveau suivant
        pMana->pEtatJeu->nAvancementLevel=0;
    }



}

///
///
///

void gestionLevelLaToilette(tManaComposant *pMana){
        int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),SALLEAMANGER),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"maman");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LATOILETTE);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;

    }
    if(dialogueSuivant(pMana,1)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
    }

    if(actionBouton(pMana,"suivant",2)){
        ajoutBoutonChoix(pMana,"Prendre une douche.","Faire semblant de prendre une douche.");
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,3))>0){
        if(nChoix==1){
            supprBoutonChoix(pMana);
            pMana->pEtatJeu->nAvancementLevel=100;
        }else{
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=200;
        }

    }

    ///si le joueur a fait le choix 1
    if(dialogueSuivant(pMana,100)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
    }

    if(actionBouton(pMana,"suivant",101)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLE_DE_BAIN);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",102)){
        manaAjoutMinute(pMana,19);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",103)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe au niveau suivant
    }

    ///si le joueur a fait le choix 2
    if(dialogueSuivant(pMana,200)){
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
    }

    if(actionBouton(pMana,"suivant",201)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLE_DE_BAIN);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",202)){
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,203)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
    }

    dialogueSuivant(pMana,204);
    if(dialogueSuivant(pMana,205)){
        manaAjoutMinute(pMana,3);
        manaMajAffichageHorloge(pMana);
    }

    if(actionBouton(pMana,"suivant",206)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",207)){
        manaAjoutMinute(pMana,19);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",208)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe au niveau suivant
    }


}

///
///
///

void gestionLevelMoyenLocomotion(tManaComposant *pMana){
        int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),DEVANT_MAISON),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MOYENLOCOMOTION);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;

    }
    dialogueSuivant(pMana,1);

    if(actionBouton(pMana,"suivant",2)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Prendre le vélo.","Prendre le bus.");
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,3))>0){
        if(nChoix==1){
            supprBoutonChoix(pMana);
            pMana->pEtatJeu->nAvancementLevel=100;
        }else{
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=200;
        }

    }

    if(actionBouton(pMana,"suivant",100)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=preparation;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe à la préparation
    }

    if(actionBouton(pMana,"suivant",200)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=leTicket;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe au niveau leTicket

    }
}

///
///
///

void gestionLevelPreparation(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),DEVANT_MAISON),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_PREPARATION);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }
    dialogueSuivant(pMana,1);
    dialogueSuivant(pMana,2);

    if(actionBouton(pMana,"suivant",3)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Mettre le casque et les gants","Ne rien mettre et partir");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,4))>0){
        if(nChoix==1){
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=100;
        }else{
            supprBoutonChoix(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=200;
        }

    }

    ///si choix 1
    dialogueSuivant(pMana,100);
    dialogueSuivant(pMana,101);
    if(dialogueSuivant(pMana,102)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
    }

    if(actionBouton(pMana,"suivant",103)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,3);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",104)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=arriveeEcole;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe à la préparation
    }

    ///si choix 2

    if(actionBouton(pMana,"suivant",200)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",201)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"papa");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"papa"),PAPA),"papa");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,202)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
    }
    dialogueSuivant(pMana,203);
    if(dialogueSuivant(pMana,204)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
    }

    if(dialogueSuivant(pMana,205)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
    }

    if(actionBouton(pMana,"suivant",206)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,3);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,207)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
    }

    if(actionBouton(pMana,"suivant",208)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=arriveeEcole; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;

    }
}

///
///
///
void gestionLevelLeTicket(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),ARRET_BUS),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_LETICKET);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(dialogueSuivant(pMana,1)){
        //si il est avant ou 7h38.
        if(pMana->pEtatJeu->stHorloge.nHeure<=7&&pMana->pEtatJeu->stHorloge.nMinute<=38){
            pMana->pEtatJeu->stHorloge.nHeure=7;
            pMana->pEtatJeu->stHorloge.nMinute=38;
            manaMajAffichageHorloge(pMana);
            setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),BUS);
            pMana->pEtatJeu->nAvancementLevel=2;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=100;
        }
    }

    //si le joueur arrive à temps
    if(actionBouton(pMana,"suivant",2)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    //si on le joueur n'arrive pas à temps:
    if(actionBouton(pMana,"suivant",100)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Retourner à la maison prendre le vélo","Attendre le bus Suivant");
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if((nChoix = choixBouton(pMana,101))>0){
        if(nChoix==1){
            manaAjoutMinute(pMana,2);
            manaMajAffichageHorloge(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=1000;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=2000;
        }
        supprBoutonChoix(pMana);
    }
    //le joueur retourne chez lui prendre son vélo.
    if(actionBouton(pMana,"suivant",1000)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),DEVANT_MAISON);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",1001)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=preparation; //le joueur passe à la préparation
        pMana->pEtatJeu->nAvancementLevel=0;
    }

    //le joueur attend le bus
    if(actionBouton(pMana,"suivant",2000)){
        manaAjoutMinute(pMana,5);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),DEVANT_MAISON);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",2001)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),BUS);
        pMana->pEtatJeu->nAvancementLevel=3;
    }

    //le joueur rentre dans le bus
    if(actionBouton(pMana,"suivant",3)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),DANS_BUS);
        ajoutBoutonChoix(pMana,"Prendre un ticket","Frauder le Bus");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,4))>0){
        if(nChoix==1){
            manaAjoutMinute(pMana,2);
            manaMajAffichageHorloge(pMana);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=40;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=400;
        }
        supprBoutonChoix(pMana);
    }

    //si le joueur paye le bus
    if(actionBouton(pMana,"suivant",40)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",41)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_PANNE_BUS);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,42)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
    }

    //si le joueur ne paye pas le bus
    if(dialogueSuivant(pMana,400)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_CHAUFFEUR);
    }

    if(actionBouton(pMana,"suivant",401)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",402)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",403)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_PANNE_BUS);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,404)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
    }

    if(actionBouton(pMana,"suivant",405)){
        pMana->pEtatJeu->nAvancementLevel=43;
    }

    //le joueur passe au mini-jeu suivant
    if(actionBouton(pMana,"suivant",43)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=arriveeEcole;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe au mini jeu sur les panneaux.
    }
}

///
///
///
void gestionLevelArriveeEcole(tManaComposant *pMana){

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),ECOLE),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"surveillant");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"surveillant"),SURVEILLANT),"surveillant");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_ARRRIVEEECOLE);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    //si le joueur arrive à temps
    if(actionBouton(pMana,"suivant",1)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        //si le joueur arrive à l'heure
        if((pMana->pEtatJeu->stHorloge.nHeure<8)||((pMana->pEtatJeu->stHorloge.nHeure==8)&&(pMana->pEtatJeu->stHorloge.nMinute==0))){
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=2;
        }else{  //sinon
            pMana->pEtatJeu->nAvancementLevel=10;
        }
    }

    if(actionBouton(pMana,"suivant",2)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"surveillant"));
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    dialogueSuivant(pMana,10);
    dialogueSuivant(pMana,11);
    if(actionBouton(pMana,"suivant",12)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"surveillant"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel=3;
    }


    if(dialogueSuivant(pMana,3)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        pMana->pEtatJeu->stHorloge.nHeure=12;
        pMana->pEtatJeu->stHorloge.nMinute=00;
        manaMajAffichageHorloge(pMana);
    }

    //le joueur passe au niveau suivant
    if(actionBouton(pMana,"suivant",4)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant
        pMana->pEtatJeu->nAvancementLevel=0;
    }
}

///
///
///
void gestionLevelRepasMidi(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CLASSE),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_REPASMIDI);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(dialogueSuivant(pMana,1)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_ELEVE);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE-(2*LARGEUR_PERSONNAGE),POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"eleve");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"eleve"),ELEVE),"eleve");
    }
    if(dialogueSuivant(pMana,2)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        ajoutBoutonChoix(pMana,"Manger à la cantine","Manger dehors");
    }

    if((nChoix = choixBouton(pMana,3))>0){
        if(nChoix==1){
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=30;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=300;
        }
        supprBoutonChoix(pMana);
    }

    ///si le joueur reste manger à la cantine
    dialogueSuivant(pMana,30);

    if(actionBouton(pMana,"suivant",31)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"eleve"));
        pMana->pEtatJeu->nAvancementLevel++;
    }

    ///SINON
    if(dialogueSuivant(pMana,300)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
    }
    if(actionBouton(pMana,"suivant",301)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"surveillant");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"surveillant"),SURVEILLANT),"surveillant");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,302)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
    }

    dialogueSuivant(pMana,303);
    dialogueSuivant(pMana,304);
    dialogueSuivant(pMana,305);

    if(actionBouton(pMana,"suivant",306)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"surveillant"));
        pMana->pEtatJeu->nAvancementLevel=32;
    }


    ///LE JOUEUR VAS A LA CANTINE ET FAIT LE MINI-JEU REPAS
    if(actionBouton(pMana,"suivant",32)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),CANTINE);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",33)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}

///
///
///
void gestionLevelToilettes(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"surveillant");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),TOILETTES),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_TOILETTES);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    dialogueSuivant(pMana,1);

    if(actionBouton(pMana,"suivant",2)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Se laver les mains.","Ne pas se laver les mains.");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,3))>0){
        if(nChoix==1){
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=30;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=300;
        }
        supprBoutonChoix(pMana);
    }

    ///SI LE JOUEUR SE LAVE LES MAINS
    if(actionBouton(pMana,"suivant",30)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",31)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

   ///SI LE JOUEUR NE SE LAVE PAS LES MAINS
    if(actionBouton(pMana,"suivant",300)){
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"surveillant"),SURVEILLANT),"surveillant");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,301)){

        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
    }

    if(dialogueSuivant(pMana,302)){
        manaAjoutMinute(pMana,3);
        manaMajAffichageHorloge(pMana);
    }

    if(actionBouton(pMana,"suivant",303)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",304)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"surveillant"));
        pMana->pEtatJeu->nAvancementLevel=32;
    }

    //L'ELEVE REPART EN CLASSE
    if(actionBouton(pMana,"suivant",32)){
        manaAjoutMinute(pMana,3);
        manaMajAffichageHorloge(pMana);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),CLASSE);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    //si le joueur arrive à temps
    if(actionBouton(pMana,"suivant",33)){
        //si le joueur arrive à l'heure
        if((pMana->pEtatJeu->stHorloge.nHeure<13)||((pMana->pEtatJeu->stHorloge.nHeure==13)&&(pMana->pEtatJeu->stHorloge.nMinute==0))){
            pMana->pEtatJeu->nAvancementLevel=34;
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        }else{  //sinon
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=3400;
        }
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"surveillant"),SURVEILLANT),"surveillant");
    }

    if(dialogueSuivant(pMana,3400)){
         pMana->pEtatJeu->nAvancementLevel=34;
    }

    if(actionBouton(pMana,"suivant",34)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"surveillant"));
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,35)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        pMana->pEtatJeu->stHorloge.nHeure=14;
        pMana->pEtatJeu->stHorloge.nMinute=00;
    }

    if(actionBouton(pMana,"suivant",36)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),CLASSE);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",37)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}

///
///
///
void gestionLevelSortieEcole(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),NOIR),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_SORTIEECOLE);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(dialogueSuivant(pMana,1)){
        pMana->pEtatJeu->stHorloge.nHeure=16;
        pMana->pEtatJeu->stHorloge.nMinute=00;
        manaMajAffichageHorloge(pMana);
    }

    if(actionBouton(pMana,"suivant",2)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),ECOLE);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",3)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"eleve");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"eleve"),ELEVE),"eleve");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,4)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_ELEVE);
    }

    if(dialogueSuivant(pMana,5)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
    }

    if(actionBouton(pMana,"suivant",6)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Rentrer plus tard pour jouer aux cartes.","Rentrer tout de suite.");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,7))>0){
        if(nChoix==1){
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=700;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=70;
        }
        supprBoutonChoix(pMana);
    }

    ///SI LE JOUEUR RENTRE TOUT DE SUITE
    if(actionBouton(pMana,"suivant",70)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"eleve"));
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",71)){
        manaAjoutMinute(pMana,10);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",72)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),DEVANT_MAISON);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,73)){
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        pMana->pEtatJeu->nAvancementLevel=8;
    }


    ///SI LE JOUEUR RESTE JOUER AUX CARTES
    if(actionBouton(pMana,"suivant",700)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"eleve"));
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",701)){
        manaAjoutMinute(pMana,30);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",702)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),DEVANT_MAISON);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",703)){
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"eleve"),MAMAN),"maman");
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),DEVANT_MAISON);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    dialogueSuivant(pMana,704);
    dialogueSuivant(pMana,705);
    if(dialogueSuivant(pMana,706)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        pMana->pEtatJeu->nAvancementLevel=8;
    }

    ///Le JOUEUR MONTE DANS SA CHAMBRE
    if(actionBouton(pMana,"suivant",8)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),CHAMBRE);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",9)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}

///
///
///
void gestionLevelDevoirs(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CHAMBRE),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_DEVOIRS);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    dialogueSuivant(pMana,1);
    dialogueSuivant(pMana,2);


    if(actionBouton(pMana,"suivant",3)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Faire les devoirs.","Jouer à la console.");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,4))>0){
        if(nChoix==1){
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));

            pMana->pEtatJeu->nAvancementLevel=40;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=5;
        }
        supprBoutonChoix(pMana);
    }

    ///SI LE JOUEUR LE FAIT SES DEVOIRS
    if(actionBouton(pMana,"suivant",40)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,20);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if(actionBouton(pMana,"suivant",41)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),CHAMBRE);
        pMana->pEtatJeu->nAvancementLevel=5;
    }

    ///LE JOUEUR JOUE A LA CONSOLE

    if(actionBouton(pMana,"suivant",5)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}


///
///
///
void gestionLevelSport(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=17;
        pMana->pEtatJeu->stHorloge.nMinute=20;
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CHAMBRE),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_SPORT);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    dialogueSuivant(pMana,1);

    if(actionBouton(pMana,"suivant",2)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Aller au sport.","Prétexter d'être malade.");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if((nChoix = choixBouton(pMana,3))>0){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        if(nChoix==1){
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=40;
        }else{
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=400;
        }
        supprBoutonChoix(pMana);
    }

    ///SI LE JOUEUR VA DIRECTEMENT AU SPORT
    if(actionBouton(pMana,"suivant",40)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",41)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        manaAjoutMinute(pMana,8);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel=5;
    }

    ///SI LE JOUEUR NE VA DIRECTEMENT AU SPORT
    if(actionBouton(pMana,"suivant",400)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"papa");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"papa"),PAPA),"papa");
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,401)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
    }

    dialogueSuivant(pMana,402);
    if(dialogueSuivant(pMana,403)){
        manaAjoutMinute(pMana,3);
        manaMajAffichageHorloge(pMana);
    }

    if(actionBouton(pMana,"suivant",404)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"papa"));
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",405)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        manaAjoutMinute(pMana,8);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel=5;
    }

    ///LE JOUEUR VA AU SPORT

    if(actionBouton(pMana,"suivant",5)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}

///
///
///
void gestionLevelDiner(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=19;
        pMana->pEtatJeu->stHorloge.nMinute=30;
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CHAMBRE),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_DINER);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    dialogueSuivant(pMana,1);

    if(actionBouton(pMana,"suivant",2)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",3)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLEAMANGER);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"papa");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"papa"),PAPA),"papa");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE-(2*LARGEUR_PERSONNAGE),POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"maman");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",4)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"papa"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        manaAjoutMinute(pMana,10);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",5)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLEAMANGER);
        ajoutBoutonChoix(pMana,"Finir mon assiette.","Laisser les restes.");
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"papa"),PAPA),"papa");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if((nChoix = choixBouton(pMana,6))>0){
        if(nChoix==1){
            pMana->pEtatJeu->nAvancementLevel=60;
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=600;
        }
        supprBoutonChoix(pMana);
    }

    ///LE JOUEUR FINI DIRECTEMENT SON ASSIETTE.

    if(actionBouton(pMana,"suivant",60)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"papa"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        manaAjoutMinute(pMana,10);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",61)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLEAMANGER);
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"papa"),PAPA),"papa");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(dialogueSuivant(pMana,62)){
        pMana->pEtatJeu->nAvancementLevel=7;
    }

    ///SI LE JOUEUR NE FINI PAS DIRECTEMENT SON ASSIETTE.

    if(dialogueSuivant(pMana,600)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_PERE);
    }

    if(dialogueSuivant(pMana,601)){
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
    }


    if(actionBouton(pMana,"suivant",602)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"papa"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        manaAjoutMinute(pMana,10);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",603)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLEAMANGER);
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"papa"),PAPA),"papa");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        pMana->pEtatJeu->nAvancementLevel=7;
    }


    //le joueur passe au niveau suivant.

    if(actionBouton(pMana,"suivant",7)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++; //le joueur passe au niveau suivant.
        pMana->pEtatJeu->nAvancementLevel=0;
    }

}

///
///
///
void gestionLevelBonneNuit(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorloge.nHeure=21;
        pMana->pEtatJeu->stHorloge.nMinute=00;
        manaMajAffichageHorloge(pMana);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CHAMBRE),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"maman");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"maman"),MAMAN),"maman");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_BONNENUIT);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    dialogueSuivant(pMana,1);

    if(actionBouton(pMana,"suivant",2)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLEAMANGER);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        ajoutBoutonChoix(pMana,"Aller se préparer.","Continuer de jouer sur le portable.");
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if((nChoix = choixBouton(pMana,3))>0){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        if(nChoix==1){
            pMana->pEtatJeu->nAvancementLevel=4;
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            pMana->pEtatJeu->nAvancementLevel=30;
        }
        supprBoutonChoix(pMana);
    }

    ///LE JOUEUR NE VA PAS SE DEBARBOUILLER
    if(dialogueSuivant(pMana,30)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MERE);
    }

    if(dialogueSuivant(pMana,31)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel=4;
    }


    ///LE JOUEUR VA SE DEBARBOUILLER

    if(actionBouton(pMana,"suivant",4)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"maman"));
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",5)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLE_DE_BAIN);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",6)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        manaAjoutMinute(pMana,10);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",7)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),SALLE_DE_BAIN);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",8)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        manaAjoutMinute(pMana,1);
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",9)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),CHAMBRE);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",10)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuCharger");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*4,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuCharger");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("FIN !",recupObjetParNom(pMana->pListeObjet,"titreMenuCharger"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuCharger")),"titreMenuCharger");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",11)){
        vidageComposantsProgramme(pMana);
        ajoutMenuPrincipale(pMana);
        pMana->pEtatJeu->nNumLevel=-1; //le joueur passe au niveau suivant.
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

