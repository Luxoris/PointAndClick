#ifndef SDL2_TEXTE_H_INCLUDED
#define SDL2_TEXTE_H_INCLUDED
#pragma once

//appel des bibliothèques
#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include <string.h>
#include "tObjet.h"




//definition des constantes :

#define TTF_TAILLE_CHAINE 256
#define TTF_NB_FONT_STYLE 3 //b : bold, u: underline, i : italic, par defaut normal.

extern const SDL_Color SDL_Cl_Blanc;
extern const SDL_Color SDL_CL_BLANC;
extern const SDL_Color SDL_CL_NOIR;
extern const SDL_Color SDL_CL_ROUGE;
extern const SDL_Color SDL_CL_BLEU;
extern const SDL_Color SDL_CL_VERT;
extern const SDL_Color SDL_CL_MAGENTA;
extern const SDL_Color SDL_CL_JAUNE;
extern const SDL_Color SDL_CL_CYAN;


///définition des types structurés

typedef enum tTTF_Mode{TTF_Mode_Solid,TTF_Mode_Shaded,TTF_Mode_Blended} tTTF_Mode;

typedef enum tTTF_Charset{TTF_Charset_Latin1,TTF_Charset_UTF8,/*TTF_Charset_Unicode,TTF_Charset_UnicodeGlyph*/} tTTF_Charset;   //Unicode et UnicodeGlyph ne sont pas gérés pour l'instant


//définition du type propTexte
typedef struct tPropTexte{
    int nTaille;
    char sEmplPolice[TTF_TAILLE_CHAINE];
    SDL_Color stCouleur;
    SDL_Color stCouleurAPlan;
    char cStyle[TTF_NB_FONT_STYLE];
    tTTF_Charset stCharset;
    tTTF_Mode stMode;

}tPropTexte;

//définition du type Texte
typedef struct tTexte{
    char sTexte[TTF_TAILLE_CHAINE];
    tObjet *pstObjet;
    tPropTexte *pPropTexte;

}tTexte;




//prototypes des méthodes de tPropTexte

extern void setPropTexte(tPropTexte *pstPropTexte,const int nTaille, const char sEmplPolice[], const SDL_Color stCouleur,const SDL_Color stCouleurAPlan, const char cStyle[],const tTTF_Charset stCharset, const tTTF_Mode stMode);
extern void setPropTexteTaille(tPropTexte *pstPropTexte,const int nTaille);
extern void setPropTexteEmplpolice(tPropTexte *pstPropTexte,const char sEmplPolice[]);
extern void setPropTexteCharset(tPropTexte *pstPropTexte,const tTTF_Charset stCharset);
extern void setPropTexteMode(tPropTexte *pstPropTexte,const tTTF_Mode stMode);
extern void setPropTexteStyle(tPropTexte *pstPropTexte,const char cStyle[TTF_NB_FONT_STYLE]);
extern void setPropTexteCouleur(tPropTexte *pstPropTexte,SDL_Color stCouleur);
extern void setPropTexteCouleurAPlan(tPropTexte *pstPropTexte,SDL_Color stCouleur);

extern int getPropTexteTaille(tPropTexte *pstPropTexte);
extern char* getPropTexteEmplpolice(tPropTexte *pstPropTexte);
extern tTTF_Charset getPropTexteCharset(tPropTexte *pstPropTexte);
extern tTTF_Mode getPropTexteMode(tPropTexte *pstPropTexte);
extern char* getPropTexteStyle(tPropTexte *pstPropTexte);
extern SDL_Color *getPropTexteCouleur(tPropTexte *pstPropTexte);
extern SDL_Color *getPropTexteCouleurAPlan(tPropTexte *pstPropTexte);

//prototype de méthodes de tTexte
extern void setTexte(tTexte* pTexte,char pcTexte[], tObjet *pstObjet, tPropTexte *pPropTexte);
extern void setTexteTexte(tTexte* pTexte, char pcTexte[]);
extern void setTexteObjet(tTexte* pTexte, tObjet *pstObjet);
extern void setTextePropTexte(tTexte* pTexte, tPropTexte *pPropTexte);

extern char* getTexteTexte(tTexte* pTexte);
extern tObjet* getTexteObjet(tTexte* pTexte);
extern tPropTexte* getTextPropTexte(tTexte* pTexte);


//prototype des méthodes de TFF
extern void arretTTF();
extern void initTTF();
extern void ecrireTexte(SDL_Renderer* pRenderer, tTexte * pstTexte);
extern void ecrireChaine(SDL_Renderer* pRenderer, char cChaine[], tObjet *pstObjet, tPropTexte * pstPropTexte);

#endif // SDL2_TEXTE_H_INCLUDED
