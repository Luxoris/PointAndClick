#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#pragma once

#define NOM_DU_JEU "PointAndClick"

#define WINDOW_LARGEUR 1920//1280
#define WINDOW_HAUTEUR 1080//720

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
#define RUE_PANNE_BUS "./assets/ruePanneBus.jpg"
#define ECOLE "./assets/ecole.jpg"
#define CLASSE "./assets/classe.jpg"
#define CANTINE "./assets/cantine.jpg"
#define TOILETTES "./assets/toilettes.jpg"

#define MAMAN "./assets/maman.jpg"
#define PAPA "./assets/papa.jpg"
#define ELEVE "./assets/eleve.jpg"
#define SURVEILLANT "./assets/surveillant.jpg"
#define CHAUFFEUR "./assets/chauffeur.jpg"

#define LARGEUR_PERSONNAGE 400
#define HAUTEUR_PERSONNAGE 600
#define POS_X_PERSONNAGE (WINDOW_LARGEUR -(LARGEUR_PERSONNAGE))
#define POS_Y_PERSONNAGE (WINDOW_HAUTEUR -(HAUTEUR_PERSONNAGE))
//déclaration des définitions de la partie



#define SDL_BOUTON_CLIQUE_GAUCHE SDL_BUTTON_LEFT
#define SDL_BOUTON_CLIQUE_DROIT SDL_BUTTON_RIGHT
#define SDL_BOUTON_CLIQUE_MOLETTE SDL_BUTTON_MIDDLE

#define DELAI_CLICK_BOUTON 250
#define DELAI_REPRISE_PARTIE 500



#define MAX_FPS 60 //image par seconde

#endif // DEFINE_H_INCLUDED
