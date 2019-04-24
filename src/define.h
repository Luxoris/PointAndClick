#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#pragma once

#define NOM_DU_JEU "Nouveau Départ"
#define MUSIQUE "./son/snowflake_-_Come_Inside_1.mp3"


#define WINDOW_LARGEUR 1920
#define WINDOW_HAUTEUR 1080

#define ABRICOT_PNG "./assets/abricot.png"
#define ABRICOT_JPG "./assets/abricot.jpg"
#define CHAMBRE "./assets/chambre.jpg"
#define SALLEAMANGER "./assets/salleAManger.jpg"
#define SALLE_DE_BAIN "./assets/salleDeBain.jpg"
#define DEVANT_MAISON "./assets/devantMaison.jpg"
#define BUS "./assets/bus.jpg"
#define DANS_BUS "./assets/dansBus.jpg"
#define ARRET_BUS "./assets/arretBus.jpg"
#define NOIR "./assets/noir.jpg"
#define RUE_PANNE_BUS "./assets/rue1.png"
#define ECOLE "./assets/ecole.jpg"
#define CLASSE "./assets/classe.jpg"
#define CANTINE "./assets/cantine.jpg"
#define TOILETTES "./assets/toilettes.jpg"
#define COULOIR_1 "./assets/couloir1.png"
#define COULOIR_2 "./assets/couloir2.png"
#define TROIS_PORTES "./assets/troisPortes.png"
#define VERT "./assets/vert.jpg"
#define ROUGE "./assets/rouge.jpg"
#define BLANC "./assets/blanc.jpg"
#define RUE_1 "./assets/rue1.png"
#define RUE_2 "./assets/rue2.png"
#define RUE_21 "./assets/rue21.png"
#define RUE_22 "./assets/rue22.png"
#define RUE_221 "./assets/rue221.png"
#define RUE_222 "./assets/rue222.png"
#define EGLISE "./assets/eglise.png"
#define SORTIE_ECOLE "./assets/sortieEcole.png"
#define GYMNASE "./assets/gymnase.jpg"

#define MAMAN "./assets/maman.png"
#define PAPA "./assets/papa.png"
#define ELEVE "./assets/eleve.png"
#define SURVEILLANT "./assets/surveillant.png"
#define MONSTRE "./assets/monstre.png"
#define PREPARATION "./assets/preparation.jpg"

#define LARGEUR_PERSONNAGE 400
#define HAUTEUR_PERSONNAGE 600
#define POS_X_PERSONNAGE (WINDOW_LARGEUR -(LARGEUR_PERSONNAGE))
#define POS_Y_PERSONNAGE (WINDOW_HAUTEUR -(HAUTEUR_PERSONNAGE))

//mini jeu repas
#define LARGEUR_NOURRITURE 200
#define HAUTEUR_NOURRITURE 200
#define ENTREE_1 "./assets/repas/salade.png"
#define ENTREE_2 "./assets/repas/pain.png"
#define PLAT_1 "./assets/repas/equilibre.png"
#define PLAT_2 "./assets/repas/steak.png"
#define LAITIER_1 "./assets/repas/yaourt.png"
#define LAITIER_2 "./assets/repas/fromage.png"
#define DESSERT_1 "./assets/repas/pomme.png"
#define DESSERT_2 "./assets/repas/gateau.png"
#define BOISSON_1 "./assets/repas/eau.png"
#define BOISSON_2 "./assets/repas/soda.png"
#define REPAS_BLANC "./assets/repas/repasBlanc.png"

//mini jeu grammaire
#define LARGEUR_REPONSE 160
#define HAUTEUR_REPONSE 70
#define LARGEUR_VALIDATEUR 32
#define HAUTEUR_VALIDATEUR 32
#define LARGEUR_EXERCICE 1300
#define HAUTEUR_EXERCICE 700
#define REP_1 "./assets/grammaire/cest.png"
#define REP_2 "./assets/grammaire/ces.png"
#define REP_3 "./assets/grammaire/sest.png"
#define REP_4 "./assets/grammaire/sais.png"
#define REP_5 "./assets/grammaire/ses.png"
#define REP_6 "./assets/grammaire/sait.png"
#define CORRECT "./assets/grammaire/correct.png"
#define INCORRECT "./assets/grammaire/incorrect.png"
#define EXERCICE "./assets/grammaire/grammaire.png"
#define CORRIGE "./assets/grammaire/corrige.png"

//mini jeu jeux-video
#define EPEE "./assets/epee.png"
#define COEUR "./assets/coeur.png"
#define CAILLOU_1 "./assets/caillou1.png"
#define CAILLOU_2 "./assets/caillou2.png"
#define HAUTEUR_CAILLOU_1 720
#define LARGEUR_CAILLOU_1 1280
#define HAUTEUR_CAILLOU_2 300
#define LARGEUR_CAILLOU_2 533
#define HAUTEUR_COEUR 32
#define LARGEUR_COEUR 32
#define HAUTEUR_EPEE 640
#define LARGEUR_EPEE 320

//mini jeu secourisme
#define HAUTEUR_MANNEQUIN 120
#define LARGEUR_MANNEQUIN 400
#define HAUTEUR_TELEPHONE 340
#define LARGEUR_TELEPHONE 200
#define PLS_1 "./assets/pls1.png"
#define PLS_2 "./assets/pls2.png"
#define PLS_3 "./assets/pls3.png"
#define PLS_4 "./assets/pls4.png"
#define PORTABLE "./assets/portable.png"
#define BLANC_MANNEQUIN "./assets/blancMannequin.png"



//déclaration des définitions de la partie



#define SDL_BOUTON_CLIQUE_GAUCHE SDL_BUTTON_LEFT
#define SDL_BOUTON_CLIQUE_DROIT SDL_BUTTON_RIGHT
#define SDL_BOUTON_CLIQUE_MOLETTE SDL_BUTTON_MIDDLE

#define DELAI_CLICK_BOUTON 250
#define DELAI_REPRISE_PARTIE 1000
#define DELAI_TRANSITION 1000



#define MAX_FPS 60 //image par seconde

#endif // DEFINE_H_INCLUDED
