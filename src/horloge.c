#include "horloge.h"

//###########################################
//PROCEDURE majAffichageHorloge
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui modifie le texte d'un élément de type texte en fonction de l'horloge.
//
// ENTREE /La référence du texte, la référence de l'horloge.
//
// SORTIE /La texte du texte modifié.
//
// NOTE -
//*****************************************************************************************************//
void majAffichageHorloge(tTexte *pTexte, tHorloge *pHorloge){
    char cTexte[6]="";
    char cHeure[3]="";
    char cMinute[3]="";
    sprintf(cHeure,"%d",pHorloge->nHeure);
    sprintf(cMinute,"%d",pHorloge->nMinute);

    if(pHorloge->nHeure<10){
        cTexte[0]='0';
    }
    strcat(cTexte,cHeure);
    cTexte[2]=':';
    if(pHorloge->nMinute<10){
        cTexte[3]='0';
    }
    strcat(cTexte,cMinute);

    setTexteTexte(pTexte,cTexte);
}

//###########################################
//PROCEDURE ajoutMinute
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui ajoute des minutes à un élément de type horloge.
//
// ENTREE /La référence de l'horloge, le in correspondant au nombre de minutes.
//
// SORTIE /Le temps de l'horloge modifié.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMinute(tHorloge *pHorloge,const int nMinute){
    int nHeure = nMinute / 60;  //on récupère le nombre d'heure à incrémenter
    int nMinuteTemp = nMinute %60;  //on récupère le nombre de minute qu'il reste sans les heures


    nMinuteTemp=pHorloge->nMinute+nMinuteTemp;

    if(nMinuteTemp>=60){   //si le nombre de minutes à ajouter + le nombre de minutes actuels sont supérieur ou égale à 60.
        nHeure = nHeure +1; //on ajoute une heure.
        nMinuteTemp=nMinuteTemp-60;   //on supprime 60 au total des minutes.
    }

    nHeure = pHorloge->nHeure + nHeure;

    pHorloge->nHeure = nHeure;
    pHorloge->nMinute = nMinuteTemp;
}
