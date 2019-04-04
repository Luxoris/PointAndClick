#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#pragma once

#define NOM_DU_JEU "PointAndClick"

#define WINDOW_LARGEUR 1280
#define WINDOW_HAUTEUR 720

#define ABRICOT_PNG "./assets/abricot.png"
#define ABRICOT_JPG "./assets/abricot.jpg"


//déclaration des définitions de la partie

#define MARGE_BORD 5
#define SCORE_DEPART 0


#define SDL_BOUTON_CLIQUE_GAUCHE SDL_BUTTON_LEFT
#define SDL_BOUTON_CLIQUE_DROIT SDL_BUTTON_RIGHT
#define SDL_BOUTON_CLIQUE_MOLETTE SDL_BUTTON_MIDDLE


#define DELAI_REPRISE_PARTIE 500


///BOUTONS
#define TAILLE_POLICE_BOUTON (16)
#define HAUTEUR_BOUTON (TAILLE_POLICE_BOUTON*2)
#define LARGEUR_BOUTON (WINDOW_LARGEUR*0.12)
#define NB_BOUTON_MENU_PRINCIPAL 4



#define TAILLE_POLICE_SCORE (32)
#define TTF_FONT_VERDANA "./fonts/verdana.ttf" //emplacement du fichier de police verdana

#define MAX_FPS 60 //image par seconde

#endif // DEFINE_H_INCLUDED
