#include "horloge.h"

//###########################################
//PROCEDURE majAffichageHorloge
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui modifie le texte d'un �l�ment de type texte en fonction de l'horloge.
//
// ENTREE /La r�f�rence du texte, la r�f�rence de l'horloge.
//
// SORTIE /La texte du texte modifi�.
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
// DESCRIPTION Procedure qui ajoute des minutes � un �l�ment de type horloge.
//
// ENTREE /La r�f�rence de l'horloge, le in correspondant au nombre de minutes.
//
// SORTIE /Le temps de l'horloge modifi�.
//
// NOTE -
//*****************************************************************************************************//
void ajoutMinute(tHorloge *pHorloge,const int nMinute){
    int nHeure = nMinute / 60;  //on r�cup�re le nombre d'heure � incr�menter
    int nMinuteTemp = nMinute %60;  //on r�cup�re le nombre de minute qu'il reste sans les heures


    nMinuteTemp=pHorloge->nMinute+nMinuteTemp;

    if(nMinuteTemp>=60){   //si le nombre de minutes � ajouter + le nombre de minutes actuels sont sup�rieur ou �gale � 60.
        nHeure = nHeure +1; //on ajoute une heure.
        nMinuteTemp=nMinuteTemp-60;   //on supprime 60 au total des minutes.
    }

    nHeure = pHorloge->nHeure + nHeure;

    pHorloge->nHeure = nHeure;
    pHorloge->nMinute = nMinuteTemp;
}
