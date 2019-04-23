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

void gestionLevelMiniJeuReve(tManaComposant *pMana){
    if(pMana->pEtatJeu->nAvancementLevel==0){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),COULOIR_1),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MINI_JEU_REVE);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MONSTRE);
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Courir");
        setObjetRectangle(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON,HAUTEUR_BOUTON));
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(actionBouton(pMana,"suivant",1)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_2);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",2)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_1);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",3)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_2);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",4)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_1);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",5)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_2);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",6)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_1);
        pMana->pEtatJeu->nAvancementLevel++;
    }

        if(actionBouton(pMana,"suivant",7)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_2);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",8)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_1);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",9)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_2);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",10)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_1);
        pMana->pEtatJeu->nAvancementLevel++;
    }
    if(actionBouton(pMana,"suivant",11)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",12)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),BLANC);
        pMana->pEtatJeu->nAvancementLevel++;
    }
    if(actionBouton(pMana,"suivant",13)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",14)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),TROIS_PORTES);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"monstre");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"monstre"),MONSTRE),"monstre");
        setObjetRectangle(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*0.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON,HAUTEUR_BOUTON));
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Suivant");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    dialogueSuivant(pMana,15);
    dialogueSuivant(pMana,16);
    dialogueSuivant(pMana,17);
    dialogueSuivant(pMana,18);
    dialogueSuivant(pMana,19);
    dialogueSuivant(pMana,20);

    if(actionBouton(pMana,"suivant",21)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"monstre"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"suivant"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((LARGEUR_BOUTON*1.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON*1.5,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON*1.5,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*1.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON*1.5,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp5");
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp3"),"Lions affamés",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"rep1");
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp4"),"Serpents géants",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"rep2");
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp5"),"Arraignés vénimeuses",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"rep3");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"rep1",22)){
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),"Suivant",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"suivant");
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep1"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep2"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep3"));
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),VERT);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"rep2",22)){
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),"Suivant",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"suivant");
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep1"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep2"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep3"));
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),ROUGE);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"rep3",22)){
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),"Suivant",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"suivant");
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep1"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep2"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"rep3"));
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),ROUGE);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",23)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;  //le joueur passe au niveau suivant
        pMana->pEtatJeu->nAvancementLevel=0;
    }



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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->nNumLevel=miniJeuPanneaux;
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
        pMana->pEtatJeu->nNumLevel=miniJeuPanneaux; //le joueur passe au niveau suivant.
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->nNumLevel=miniJeuPanneaux;
        pMana->pEtatJeu->nAvancementLevel=0; //le joueur passe au mini jeu sur les panneaux.
    }
}

///
///
///
void gestionLevelMiniJeuPanneaux(tManaComposant *pMana){
    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((LARGEUR_BOUTON*1.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON*1.5,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON*1.5,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*1.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON*1.5,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"boutonEmp5");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),RUE_1),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MINI_JEU_PANNEAUX);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Avancer");
        setObjetRectangle(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON,HAUTEUR_BOUTON));
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
        pMana->pEtatJeu->nAvancementLevel++;

    }
    //Le joueur a cliquer sur suivant, il arrive dans une nouvelle rue
    //le joueur est dans la rue 1
    if(actionBouton(pMana,"suivant",1)){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_2);
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp5"),"Droite",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"droite");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    //Le joueur est dans la rue 2
    if(actionBouton(pMana,"suivant",2)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_21);
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"droite"));
        pMana->pEtatJeu->nAvancementLevel=21;
    }

    if(actionBouton(pMana,"droite",2)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_22);
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp3"),"Gauche",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"gauche");
        pMana->pEtatJeu->nAvancementLevel=22;
    }

    //Le joueur est dans la rue 21
    if(actionBouton(pMana,"suivant",21)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp5"),"Droite",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"droite");
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),EGLISE);
        pMana->pEtatJeu->nAvancementLevel=3;
    }

    //Le joueur est dans la rue 22
    if(actionBouton(pMana,"droite",22)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_222);
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"droite"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"gauche"));
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Demi-Tour");
        pMana->pEtatJeu->nAvancementLevel=222;
    }

    if(actionBouton(pMana,"suivant",22)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_221);
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"droite"));
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"gauche"));
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Demi-Tour");
        pMana->pEtatJeu->nAvancementLevel=221;
    }

    if(actionBouton(pMana,"gauche",22)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),EGLISE);
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"gauche"));
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Avancer");
        pMana->pEtatJeu->nAvancementLevel=3;
    }

    //Le joueur est dans la rue 222
    if(actionBouton(pMana,"suivant",222)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_22);
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp5"),"Droite",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"droite");
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp3"),"Gauche",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"gauche");
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Avancer");
        pMana->pEtatJeu->nAvancementLevel=22;
    }

    //Le joueur est dans la rue 221
    if(actionBouton(pMana,"suivant",221)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_22);
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp5"),"Droite",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"droite");
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp3"),"Gauche",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"gauche");
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Avancer");
        pMana->pEtatJeu->nAvancementLevel=22;
    }

    //Le joueur est dans la rue 3
    if(actionBouton(pMana,"droite",3)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),RUE_22);
        insertionBoutonListe(pMana->pListeBouton,NULL,creeBouton(recupObjetParNom(pMana->pListeObjet,"boutonEmp3"),"Gauche",recupPropTexteParNom(pMana->pListePropTexte,"boutonMenu"),false,false,0),"gauche");
        pMana->pEtatJeu->nAvancementLevel=22;
    }

    if(actionBouton(pMana,"suivant",3)){
        manaAjoutMinute(pMana,2);
        manaMajAffichageHorloge(pMana);
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),ECOLE);
        suppressionBoutonListe(pMana->pListeBouton,recupElementBoutonParNom(pMana->pListeBouton,"droite"));
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"suivant");
        setObjetRectangle(recupObjetParNom(pMana->pListeObjet,"boutonEmp2"),creeRectangle(creePoint(WINDOW_LARGEUR-(LARGEUR_BOUTON*0.5),WINDOW_HAUTEUR-(HAUTEUR_BOUTON*2)),LARGEUR_BOUTON,HAUTEUR_BOUTON));
        pMana->pEtatJeu->nAvancementLevel=4;
    }


    //Le joueur est arrivée à l'école
    if(actionBouton(pMana,"suivant",4)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel=arriveeEcole;  //le joueur passe au niveau suivant
        pMana->pEtatJeu->nAvancementLevel=0;
    }



}

///
///
///
void gestionLevelArriveeEcole(tManaComposant *pMana){

    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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

void gestionLevelMiniJeuRepas(tManaComposant *pMana){
    tRectangle *pRectangle1=NULL;
    tBool isDragging = false;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CANTINE),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MINI_JEU_REPAS);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(dialogueSuivant(pMana,1)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*1,WINDOW_HAUTEUR*0.5-2*HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*2,WINDOW_HAUTEUR*0.5-2*HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*3,WINDOW_HAUTEUR*0.5-2*HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e5");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*4,WINDOW_HAUTEUR*0.5-2*HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e7");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*5,WINDOW_HAUTEUR*0.5-2*HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e9");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*1,WINDOW_HAUTEUR*0.5-HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*2,WINDOW_HAUTEUR*0.5-HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*3,WINDOW_HAUTEUR*0.5-HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e6");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*4,WINDOW_HAUTEUR*0.5-HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e8");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*5,WINDOW_HAUTEUR*0.5-HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"e10");

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*1,WINDOW_HAUTEUR*0.5+HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"f1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*2,WINDOW_HAUTEUR*0.5+HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"f2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*3,WINDOW_HAUTEUR*0.5+HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"f3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*4,WINDOW_HAUTEUR*0.5+HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"f4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*5,WINDOW_HAUTEUR*0.5+HAUTEUR_NOURRITURE),LARGEUR_NOURRITURE,HAUTEUR_NOURRITURE),creeVecteur(0,0),creeVecteur(0,0)),"f5");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*1,WINDOW_HAUTEUR*0.5+0.5*HAUTEUR_NOURRITURE-TAILLE_POLICE_DIALOGUE),LARGEUR_NOURRITURE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"t1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*2,WINDOW_HAUTEUR*0.5+0.5*HAUTEUR_NOURRITURE-TAILLE_POLICE_DIALOGUE),LARGEUR_NOURRITURE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"t2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*3,WINDOW_HAUTEUR*0.5+0.5*HAUTEUR_NOURRITURE-TAILLE_POLICE_DIALOGUE),LARGEUR_NOURRITURE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"t3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*4,WINDOW_HAUTEUR*0.5+0.5*HAUTEUR_NOURRITURE-TAILLE_POLICE_DIALOGUE),LARGEUR_NOURRITURE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"t4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*5,WINDOW_HAUTEUR*0.5+0.5*HAUTEUR_NOURRITURE-TAILLE_POLICE_DIALOGUE),LARGEUR_NOURRITURE,HAUTEUR_DIALOGUE),creeVecteur(0,0),creeVecteur(0,0)),"t5");

        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"t1");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"t2");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"t3");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"t4");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_DIALOGUE,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_NOIR,"",TTF_Charset_Latin1,TTF_Mode_Solid),"t5");

        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Entrée",recupObjetParNom(pMana->pListeObjet,"t1"),recupPropTexteParNom(pMana->pListePropTexte,"t1")),"t1");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Plat",recupObjetParNom(pMana->pListeObjet,"t2"),recupPropTexteParNom(pMana->pListePropTexte,"t2")),"t2");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Produit Laitier",recupObjetParNom(pMana->pListeObjet,"t3"),recupPropTexteParNom(pMana->pListePropTexte,"t3")),"t3");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Dessert",recupObjetParNom(pMana->pListeObjet,"t4"),recupPropTexteParNom(pMana->pListePropTexte,"t4")),"t4");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("Boisson",recupObjetParNom(pMana->pListeObjet,"t5"),recupPropTexteParNom(pMana->pListePropTexte,"t5")),"t5");

        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e1"),ENTREE_1),"1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e2"),ENTREE_2),"-1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e3"),PLAT_1),"2");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e4"),PLAT_2),"-2");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e5"),LAITIER_1),"3");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e6"),LAITIER_2),"-3");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e7"),DESSERT_1),"4");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e8"),DESSERT_2),"-4");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e9"),BOISSON_1),"5");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e10"),BOISSON_2),"-5");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"f1"),REPAS_BLANC),"f1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"f2"),REPAS_BLANC),"f2");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"f3"),REPAS_BLANC),"f3");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"f4"),REPAS_BLANC),"f4");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"f5"),REPAS_BLANC),"f5");
    }

    if(pMana->pEtatJeu->nAvancementLevel==2){
        //ENTREE 1
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"1"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"-1"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"2"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"-2"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"3"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"-3"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"4"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"-4"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"5"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"-5"),pMana->pPointeur)){
            isDragging = true;
        }

        //si collision entre l'image et l'image d'arrivée.
        //ENTREE
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f1"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e1")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t1"),SDL_CL_JAUNE); //le texte devient jaune
        }
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e2")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t1"),SDL_CL_JAUNE); //le texte devient jaune
        }
        //PLAT
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f2"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e3")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t2"),SDL_CL_JAUNE); //le texte devient jaune
        }
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e4")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t2"),SDL_CL_JAUNE); //le texte devient jaune
        }
        //LAITAGE
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f3"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e5")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t3"),SDL_CL_JAUNE); //le texte devient jaune
        }
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e6")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t3"),SDL_CL_JAUNE); //le texte devient jaune
        }
        //DESSERT
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f4"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e7")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t4"),SDL_CL_JAUNE); //le texte devient jaune
        }
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e8")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t4"),SDL_CL_JAUNE); //le texte devient jaune
        }
        //BOISSON
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f5"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e9")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t5"),SDL_CL_JAUNE); //le texte devient jaune
        }
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e10")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t5"),SDL_CL_JAUNE); //le texte devient jaune
        }

    }

    //si le joueur appuie sur suivant, et s'il a rassemblé tous les ingrédients :
    if(actionBouton(pMana,"suivant",2)){
        SDL_Color stCouleurCompare = SDL_CL_JAUNE;
        SDL_Color *pCouleur1 = getPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t1"));
        SDL_Color *pCouleur2 = getPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t2"));
        SDL_Color *pCouleur3 = getPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t3"));
        SDL_Color *pCouleur4 = getPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t4"));
        SDL_Color *pCouleur5 = getPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t5"));
        //vérifie si tous les textes sot jaunes
        if(((pCouleur1->a==stCouleurCompare.a)&&(pCouleur1->r==stCouleurCompare.r)&&(pCouleur1->g==stCouleurCompare.g)&&(pCouleur1->b==stCouleurCompare.b))
            &&((pCouleur2->a==stCouleurCompare.a)&&(pCouleur2->r==stCouleurCompare.r)&&(pCouleur2->g==stCouleurCompare.g)&&(pCouleur2->b==stCouleurCompare.b))
            &&((pCouleur3->a==stCouleurCompare.a)&&(pCouleur3->r==stCouleurCompare.r)&&(pCouleur3->g==stCouleurCompare.g)&&(pCouleur3->b==stCouleurCompare.b))
            &&((pCouleur4->a==stCouleurCompare.a)&&(pCouleur4->r==stCouleurCompare.r)&&(pCouleur4->g==stCouleurCompare.g)&&(pCouleur4->b==stCouleurCompare.b))
            &&((pCouleur5->a==stCouleurCompare.a)&&(pCouleur5->r==stCouleurCompare.r)&&(pCouleur5->g==stCouleurCompare.g)&&(pCouleur5->b==stCouleurCompare.b))
           ){
           pMana->pEtatJeu->nAvancementLevel++;
        }
    }

    //modifie la couleur des boutons en fonctions des ingrédients selectionnés.
    if(actionBouton(pMana,"suivant",3)){
        int nBMauvais=0;
        //si collision entre l'image et l'image d'arrivée.
        //ENTREE
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f1"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e1")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t1"),SDL_CL_VERT); //le texte devient jaune
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t1"),SDL_CL_ROUGE);
            nBMauvais++;
        }
        //PLAT
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f2"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e3")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t2"),SDL_CL_VERT); //le texte devient jaune
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t2"),SDL_CL_ROUGE);
            nBMauvais++;
        }
        //LAITAGE
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f3"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e5")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t3"),SDL_CL_VERT); //le texte devient jaune
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t3"),SDL_CL_ROUGE);
            nBMauvais++;
        }
        //DESSERT
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f4"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e7")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t4"),SDL_CL_VERT); //le texte devient jaune
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t4"),SDL_CL_ROUGE);
            nBMauvais++;
        }

        //BOISSON
        pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f5"));
        if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e9")),pRectangle1)){
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t5"),SDL_CL_VERT); //le texte devient jaune
        }else{
            setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"t5"),SDL_CL_ROUGE);
            nBMauvais++;
        }

        if(nBMauvais>=2){
            manaAjoutMinute(pMana,nBMauvais*3);
            manaAjoutMinute(pMana,40);
            manaMajAffichageHorloge(pMana);
            pMana->pEtatJeu->nAvancementLevel=30;
        }else{
            manaAjoutMinute(pMana,40);
            manaMajAffichageHorloge(pMana);
            pMana->pEtatJeu->nAvancementLevel++;
        }
    }

    if(dialogueSuivant(pMana,30)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
        texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
    }

    dialogueSuivant(pMana,31);
    if(dialogueSuivant(pMana,32)){
        pMana->pEtatJeu->nAvancementLevel=5;
    }

    if(dialogueSuivant(pMana,4)){
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
    }

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
void gestionLevelToilettes(tManaComposant *pMana){
    int nChoix = 0;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(POS_X_PERSONNAGE,POS_Y_PERSONNAGE),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"surveillant");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),NOIR),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_TOILETTES);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_JOUEUR);
        pMana->pEtatJeu->nAvancementLevel=-1;

    }

    if(actionBouton(pMana,"suivant",-1)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),TOILETTES);
        pMana->pEtatJeu->nAvancementLevel=1;
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

void gestionLevelMiniJeuGrammaire(tManaComposant *pMana){
    tBool isDragging = false;

    if(pMana->pEtatJeu->nAvancementLevel==0){
        manaMajAffichageHorloge(pMana);
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),CLASSE),"bg");
        //initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MINI_JEU_GRAMMAIRE);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(actionBouton(pMana,"suivant",1)){

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*1,2*HAUTEUR_REPONSE),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"e2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*2,2*HAUTEUR_REPONSE),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"e1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*3,2*HAUTEUR_REPONSE),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"e4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*1,3.5*HAUTEUR_REPONSE),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"e3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*2,3.5*HAUTEUR_REPONSE),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"e5");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR/6)*3,3.5*HAUTEUR_REPONSE),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"e6");

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5+17,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6-283),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"f1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5-30,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6-170),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"f2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5-499,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6-64),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"f3");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5-372,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6+52),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"f4");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5+329,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6+165),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"f5");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5-422,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6+275),LARGEUR_REPONSE,HAUTEUR_REPONSE),creeVecteur(0,0),creeVecteur(0,0)),"f6");

        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e1"),REP_1),"1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e2"),REP_2),"2");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e3"),REP_3),"3");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e4"),REP_4),"4");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e5"),REP_5),"5");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"e6"),REP_6),"6");

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR-HAUTEUR_EXERCICE*0.6),LARGEUR_EXERCICE,HAUTEUR_EXERCICE),creeVecteur(0,0),creeVecteur(0,0)),"g1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"g1"),EXERCICE),"g1");
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Valider");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(pMana->pEtatJeu->nAvancementLevel==2){
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"1"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"2"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"3"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"4"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"5"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"6"),pMana->pPointeur)){
            isDragging = true;
        }
    }

    //si le joueur appuie sur suivant, et s'il a placé toutes les réponses :
    if(actionBouton(pMana,"suivant",2)){
        int nNBCollision=0;
            tRectangle *pRectangle=NULL;
            tRectangle *pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e1"));
            tRectangle *pRectangle2=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e2"));
            tRectangle *pRectangle3=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e3"));
            tRectangle *pRectangle4=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e4"));
            tRectangle *pRectangle5=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e5"));
            tRectangle *pRectangle6=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e6"));
        //si collision entre l'image et l'image d'arrivée.
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f6"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f5"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f4"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f3"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f2"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f1"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        if(nNBCollision==6){
            setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Suivant");
            pMana->pEtatJeu->nAvancementLevel=3;
        }
    }

    if(pMana->pEtatJeu->nAvancementLevel==3){
        int nNBCorrecte=0;
        tRectangle *pRectangle=NULL;
        tRectangle *pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e1"));
        tRectangle *pRectangle2=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e2"));
        tRectangle *pRectangle3=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e3"));
        tRectangle *pRectangle4=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e4"));
        tRectangle *pRectangle5=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e5"));
        tRectangle *pRectangle6=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e6"));
        //si collision entre l'image et l'image d'arrivée.
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f6"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v6");
        if(collisionRectangleRectangle(pRectangle,pRectangle6)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v6"),CORRECT),"v6");
            nNBCorrecte++;
        }else{
            setRectanglePointCentral(pRectangle6,creePoint((WINDOW_LARGEUR/6)*3,3.5*HAUTEUR_REPONSE)); //l'élément de réponse est replacé en haut.
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v6"),INCORRECT),"v6");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f5"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v5");
        if(collisionRectangleRectangle(pRectangle,pRectangle5)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v5"),CORRECT),"v5");
            nNBCorrecte++;
        }else{
            setRectanglePointCentral(pRectangle5,creePoint((WINDOW_LARGEUR/6)*2,3.5*HAUTEUR_REPONSE)); //l'élément de réponse est replacé en haut.
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v5"),INCORRECT),"v5");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f4"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v4");
        if(collisionRectangleRectangle(pRectangle,pRectangle4)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v4"),CORRECT),"v4");
            nNBCorrecte++;
        }else{
            setRectanglePointCentral(pRectangle4,creePoint((WINDOW_LARGEUR/6)*1,3.5*HAUTEUR_REPONSE)); //l'élément de réponse est replacé en haut.
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v4"),INCORRECT),"v4");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f3"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v3");
        if(collisionRectangleRectangle(pRectangle,pRectangle3)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v3"),CORRECT),"v3");
            nNBCorrecte++;
        }else{
            setRectanglePointCentral(pRectangle3,creePoint((WINDOW_LARGEUR/6)*3,2*HAUTEUR_REPONSE)); //l'élément de réponse est replacé en haut.
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v3"),INCORRECT),"v3");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f2"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v2");
        if(collisionRectangleRectangle(pRectangle,pRectangle2)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v2"),CORRECT),"v2");
            nNBCorrecte++;
        }else{
            setRectanglePointCentral(pRectangle2,creePoint((WINDOW_LARGEUR/6)*2,2*HAUTEUR_REPONSE)); //l'élément de réponse est replacé en haut.
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v2"),INCORRECT),"v2");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f1"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v1");
        if(collisionRectangleRectangle(pRectangle,pRectangle1)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v1"),CORRECT),"v1");
            nNBCorrecte++;
        }else{
            setRectanglePointCentral(pRectangle1,creePoint((WINDOW_LARGEUR/6)*1,2*HAUTEUR_REPONSE)); //l'élément de réponse est replacé en haut.
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v1"),INCORRECT),"v1");
        }

        if(nNBCorrecte==6){
            pMana->pEtatJeu->nAvancementLevel=6;
        }else{
            pMana->pEtatJeu->nAvancementLevel=50;
        }
    }

    //modifie la couleur des boutons en fonctions des ingrédients selectionnés.
    if(actionBouton(pMana,"suivant",50)){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v1"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v2"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v3"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v4"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v5"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v6"));
        suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"v1"));
        suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"v2"));
        suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"v3"));
        suppressionObjetListe(pMana->pListeObjet,recupElementObjetParNom(pMana->pListeObjet,"v4"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v5"));
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"v6"));
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Corriger");
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if(pMana->pEtatJeu->nAvancementLevel==51){
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"1"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"2"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"3"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"4"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"5"),pMana->pPointeur)){
            isDragging = true;
        }
        if(!isDragging&&dragAndDropImage(recupImageParNom(pMana->pListeImage,"6"),pMana->pPointeur)){
            isDragging = true;
        }

    }

    //si le joueur appuie sur suivant, et s'il a placé toutes les réponses :
    if(actionBouton(pMana,"suivant",51)){
        int nNBCollision=0;
        tRectangle *pRectangle=NULL;
        tRectangle *pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e1"));
        tRectangle *pRectangle2=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e2"));
        tRectangle *pRectangle3=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e3"));
        tRectangle *pRectangle4=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e4"));
        tRectangle *pRectangle5=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e5"));
        tRectangle *pRectangle6=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e6"));
        //si collision entre l'image et l'image d'arrivée.
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f6"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f5"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f4"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f3"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f2"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f1"));
        if((collisionRectangleRectangle(pRectangle,pRectangle1))
            ||(collisionRectangleRectangle(pRectangle,pRectangle2))
            ||(collisionRectangleRectangle(pRectangle,pRectangle3))
            ||(collisionRectangleRectangle(pRectangle,pRectangle4))
            ||(collisionRectangleRectangle(pRectangle,pRectangle5))
            ||(collisionRectangleRectangle(pRectangle,pRectangle6))
            ){
            nNBCollision++;
        }
        if(nNBCollision==6){
            pMana->pEtatJeu->nAvancementLevel++;
        }
    }

    if(pMana->pEtatJeu->nAvancementLevel==52){
        int nNBCorrecte=0;
        tRectangle *pRectangle=NULL;
        tRectangle *pRectangle1=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e1"));
        tRectangle *pRectangle2=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e2"));
        tRectangle *pRectangle3=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e3"));
        tRectangle *pRectangle4=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e4"));
        tRectangle *pRectangle5=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e5"));
        tRectangle *pRectangle6=getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"e6"));
        //si collision entre l'image et l'image d'arrivée.
        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f6"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v6");
        if(collisionRectangleRectangle(pRectangle,pRectangle6)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v6"),CORRECT),"v6");
            nNBCorrecte++;
        }else{
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v6"),INCORRECT),"v6");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f5"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v5");
        if(collisionRectangleRectangle(pRectangle,pRectangle5)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v5"),CORRECT),"v5");
            nNBCorrecte++;
        }else{
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v5"),INCORRECT),"v5");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f4"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v4");
        if(collisionRectangleRectangle(pRectangle,pRectangle4)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v4"),CORRECT),"v4");
            nNBCorrecte++;
        }else{
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v4"),INCORRECT),"v4");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f3"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v3");
        if(collisionRectangleRectangle(pRectangle,pRectangle3)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v3"),CORRECT),"v3");
            nNBCorrecte++;
        }else{
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v3"),INCORRECT),"v3");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f2"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v2");
        if(collisionRectangleRectangle(pRectangle,pRectangle2)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v2"),CORRECT),"v2");
            nNBCorrecte++;
        }else{
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v2"),INCORRECT),"v2");
        }

        pRectangle = getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"f1"));
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(pRectangle->stPointCentral.fX+(LARGEUR_REPONSE+LARGEUR_VALIDATEUR)*0.5,pRectangle->stPointCentral.fY+(HAUTEUR_REPONSE+HAUTEUR_VALIDATEUR)*0.5),LARGEUR_VALIDATEUR,HAUTEUR_VALIDATEUR),creeVecteur(0,0),creeVecteur(0,0)),"v1");
        if(collisionRectangleRectangle(pRectangle,pRectangle1)){
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v1"),CORRECT),"v1");
            nNBCorrecte++;
        }else{
            insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"g1"),creeImage(recupObjetParNom(pMana->pListeObjet,"v1"),INCORRECT),"v1");
        }

        if(nNBCorrecte==6){
            pMana->pEtatJeu->nAvancementLevel=6;
        }else{
            pMana->pEtatJeu->nAvancementLevel=500;
        }
    }


    if(actionBouton(pMana,"suivant",500)){
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Suivant");
        setImageObjet(recupImageParNom(pMana->pListeImage,"1"),recupObjetParNom(pMana->pListeObjet,"f1"));
        setImageObjet(recupImageParNom(pMana->pListeImage,"2"),recupObjetParNom(pMana->pListeObjet,"f2"));
        setImageObjet(recupImageParNom(pMana->pListeImage,"3"),recupObjetParNom(pMana->pListeObjet,"f3"));
        setImageObjet(recupImageParNom(pMana->pListeImage,"4"),recupObjetParNom(pMana->pListeObjet,"f4"));
        setImageObjet(recupImageParNom(pMana->pListeImage,"5"),recupObjetParNom(pMana->pListeObjet,"f5"));
        setImageObjet(recupImageParNom(pMana->pListeImage,"6"),recupObjetParNom(pMana->pListeObjet,"f6"));
        pMana->pEtatJeu->nAvancementLevel=6;
    }



    if(actionBouton(pMana,"suivant",6)){
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
void gestionLevelMiniJeuJeuxVideo(tManaComposant *pMana){
    tBool isDragging=false;
    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),NOIR),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MINI_JEU_JEUXVIDEO);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_MONSTRE);
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Suivant");
        pMana->pEtatJeu->nAvancementLevel++;

    }
    if(actionBouton(pMana,"suivant",1)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),COULOIR_1);
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if(actionBouton(pMana,"suivant",2)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.7,HAUTEUR_PERSONNAGE*0.7),LARGEUR_PERSONNAGE*0.2,HAUTEUR_PERSONNAGE*0.2),creeVecteur(0,0),creeVecteur(0,0)),"monstre");

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR)*0.7,HAUTEUR_PERSONNAGE*0.3-(HAUTEUR_COEUR*0.5)),LARGEUR_PERSONNAGE,HAUTEUR_PERSONNAGE),creeVecteur(0,0),creeVecteur(0,0)),"c2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR)*0.7-LARGEUR_COEUR*1.5,HAUTEUR_PERSONNAGE*0.3-(HAUTEUR_COEUR*0.5)),LARGEUR_COEUR,HAUTEUR_COEUR),creeVecteur(0,0),creeVecteur(0,0)),"c1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((WINDOW_LARGEUR)*0.7+LARGEUR_COEUR*1.5,HAUTEUR_PERSONNAGE*0.3-(HAUTEUR_COEUR*0.5)),LARGEUR_COEUR,HAUTEUR_COEUR),creeVecteur(0,0),creeVecteur(0,0)),"c3");

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(LARGEUR_CAILLOU_1*0.2,WINDOW_HAUTEUR-HAUTEUR_CAILLOU_1*0.5),LARGEUR_CAILLOU_1,HAUTEUR_CAILLOU_1),creeVecteur(0,0),creeVecteur(0,0)),"caillou1");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint((LARGEUR_CAILLOU_1*0.2+LARGEUR_CAILLOU_2*0.5),WINDOW_HAUTEUR-(HAUTEUR_CAILLOU_1+HAUTEUR_CAILLOU_2)*0.5),LARGEUR_CAILLOU_2,HAUTEUR_CAILLOU_2),creeVecteur(0,0),creeVecteur(0,0)),"caillou2");
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(LARGEUR_CAILLOU_1*0.2,WINDOW_HAUTEUR-HAUTEUR_CAILLOU_1*0.5),LARGEUR_EPEE,HAUTEUR_EPEE),creeVecteur(0,0),creeVecteur(0,0)),"epee");


        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"c1"),COEUR),"c1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"c2"),COEUR),"c2");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"c3"),COEUR),"c3");

        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"caillou2"),CAILLOU_2),"caillou2");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"caillou1"),CAILLOU_1),"caillou1");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"epee"),EPEE),"epee");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"monstre"),MONSTRE),"monstre");

        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",3)){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuCharger");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*2,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuCharger");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("COMBAT!",recupObjetParNom(pMana->pListeObjet,"titreMenuCharger"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuCharger")),"titreMenuCharger");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",4)){
        suppressionTexteListe(pMana->pListeTexte,recupElementTexteParNom(pMana->pListeTexte,"titreMenuCharger"));
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(pMana->pEtatJeu->nAvancementLevel==5){

        tImage *pImage=NULL;
        pImage = recupImageParNom(pMana->pListeImage,"caillou1");
        pImage = recupImageParNom(pMana->pListeImage,"caillou2");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
                if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"caillou2")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c3"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"caillou2"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
            if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"caillou1")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c3"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"caillou1"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
        pImage = recupImageParNom(pMana->pListeImage,"epee");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
            if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"epee")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c3"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"epee"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
    }

    if(pMana->pEtatJeu->nAvancementLevel==6){
        tImage *pImage=NULL;
        pImage = recupImageParNom(pMana->pListeImage,"caillou2");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
                if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"caillou2")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c2"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"caillou2"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
        pImage = recupImageParNom(pMana->pListeImage,"caillou1");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
            if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"caillou1")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c2"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"caillou1"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }

        pImage = recupImageParNom(pMana->pListeImage,"epee");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
            if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"epee")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c2"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"epee"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
    }

    if(pMana->pEtatJeu->nAvancementLevel==7){
        tImage *pImage=NULL;
        pImage = recupImageParNom(pMana->pListeImage,"caillou2");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
                if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"caillou2")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c1"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"caillou2"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
        pImage = recupImageParNom(pMana->pListeImage,"caillou1");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
            if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"caillou1")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c1"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"caillou1"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }

        pImage = recupImageParNom(pMana->pListeImage,"epee");
        if(!isDragging&&pImage!=NULL&&dragAndDropImage(pImage,pMana->pPointeur)){
            isDragging = true;
            if(collisionRectangleRectangle(getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"epee")),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"monstre")))){
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"c1"));
                suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"epee"));
                pMana->pEtatJeu->nAvancementLevel++;
            }
        }
    }

    if(pMana->pEtatJeu->nAvancementLevel==8){
        suppressionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"monstre"));
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",9)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),NOIR);
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("VOUS AVEZ GAGNE!",recupObjetParNom(pMana->pListeObjet,"titreMenuCharger"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuCharger")),"titreMenuCharger");
        pMana->pEtatJeu->nAvancementLevel++;
    }


    if(actionBouton(pMana,"suivant",10)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;  //le joueur passe au niveau suivant
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
void gestionLevelMiniJeuSecourisme(tManaComposant *pMana){
    if(pMana->pEtatJeu->nAvancementLevel==0){
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,WINDOW_HAUTEUR),creeVecteur(0,0),creeVecteur(0,0)),"bg");
        insertionImageListe(pMana->pListeImage,NULL,creeImage(recupObjetParNom(pMana->pListeObjet,"bg"),NOIR),"bg");
        initFichierDialogue(&pMana->pFichierDialogue,EMPL_DIALOGUE_MINI_JEU_SECOURISME);
        setPropTexteCouleur(recupPropTexteParNom(pMana->pListePropTexte,"dialogue"),SDL_CL_SURVEILLANT);
        setBoutonTexte(recupBoutonParNom(pMana->pListeBouton,"suivant"),"Suivant");
        pMana->pEtatJeu->nAvancementLevel++;

    }

    if(actionBouton(pMana,"suivant",1)){
        setImageEmpl(recupImageParNom(pMana->pListeImage,"bg"),GYMNASE);
        pMana->pEtatJeu->nAvancementLevel++;
    }

    (dialogueSuivant(pMana,2));
    if((dialogueSuivant(pMana,3))){
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),LARGEUR_MANEQUIN,HAUTEUR_MANEQUIN),creeVecteur(0,0),creeVecteur(0,0)),"manequin");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"manequin"),PLS_1),"manequin");

        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR-LARGEUR_TELEPHONE*0.5,WINDOW_HAUTEUR-HAUTEUR_TELEPHONE),LARGEUR_TELEPHONE,HAUTEUR_TELEPHONE),creeVecteur(0,0),creeVecteur(0,0)),"telephone");
        insertionImageListe(pMana->pListeImage,recupElementImageParNom(pMana->pListeImage,"bg"),creeImage(recupObjetParNom(pMana->pListeObjet,"telephone"),PORTABLE),"telephone");

    }


    if(pMana->pEtatJeu->nAvancementLevel==7){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"telephone")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            pMana->pEtatJeu->nAvancementLevel=8;
        }
    }

    if(pMana->pEtatJeu->nAvancementLevel==6){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"manequin")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            setImageEmpl(recupImageParNom(pMana->pListeImage,"manequin"),PLS_4);
            pMana->pEtatJeu->nAvancementLevel=7;
        }
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"telephone")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            SDL_Delay(DELAI_REPRISE_PARTIE);
            pMana->pEtatJeu->nAvancementLevel=6;
        }
    }



    if(pMana->pEtatJeu->nAvancementLevel==5){
        setTexteTexte(recupTexteParNom(pMana->pListeTexte,"dialogue"),"");
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"manequin")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            setImageEmpl(recupImageParNom(pMana->pListeImage,"manequin"),PLS_3);
            pMana->pEtatJeu->nAvancementLevel=6;
        }
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"telephone")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            SDL_Delay(DELAI_REPRISE_PARTIE);
            pMana->pEtatJeu->nAvancementLevel=5;
        }
    }



    if(pMana->pEtatJeu->nAvancementLevel==4){
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"manequin")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            setImageEmpl(recupImageParNom(pMana->pListeImage,"manequin"),PLS_2);
            pMana->pEtatJeu->nAvancementLevel=5;
        }
        if(getPointeurCliqueGauche(pMana->pPointeur)&&collisionPointRectangle(getPointeurPosition(pMana->pPointeur),getObjetRectangle(recupObjetParNom(pMana->pListeObjet,"telephone")))){
            SDL_Delay(DELAI_CLICK_BOUTON);
            texteSuivant(pMana->pFichierDialogue,recupTexteParNom(pMana->pListeTexte,"dialogue"));
            SDL_Delay(DELAI_REPRISE_PARTIE);
            pMana->pEtatJeu->nAvancementLevel=4;
        }
    }


   if(pMana->pEtatJeu->nAvancementLevel==8){
        SDL_Delay(DELAI_REPRISE_PARTIE);
        insertionObjetListe(pMana->pListeObjet,NULL,creeObjet(creeRectangle(creePoint(WINDOW_LARGEUR*0.5,WINDOW_HAUTEUR*0.5),WINDOW_LARGEUR,HAUTEUR_BOUTON),creeVecteur(0,0),creeVecteur(0,0)),"titreMenuCharger");
        insertionPropTexteListe(pMana->pListePropTexte,NULL,creePropTexte(TAILLE_POLICE_TITRE*3,TTF_FONT_VERDANA,SDL_CL_BLANC,SDL_CL_ROUGE,"",TTF_Charset_Latin1,TTF_Mode_Solid),"titreMenuCharger");
        insertionTexteListe(pMana->pListeTexte,NULL,creeTexte("VICTOIRE!",recupObjetParNom(pMana->pListeObjet,"titreMenuCharger"),recupPropTexteParNom(pMana->pListePropTexte,"titreMenuCharger")),"titreMenuCharger");
        pMana->pEtatJeu->nAvancementLevel++;
    }

    if(actionBouton(pMana,"suivant",9)){
        vidageComposantsProgramme(pMana);
        ajoutInterfaceJeu(pMana);
        pMana->pEtatJeu->nNumLevel++;  //le joueur passe au niveau suivant
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pMana->pEtatJeu->stHorlogeSauvegarde=pMana->pEtatJeu->stHorloge;
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
        pstEtatJeu->stHorloge=pstEtatJeu->stHorlogeSauvegarde;
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

