#include "Graphe.h"
#include "GrapheChargeurFichier.h"
#include <stdlib.h>

CGraphe::CGraphe()
{
	ppSMTGPHliste = 0;
	uiGPHtotalSommet = 0;
}

CGraphe::CGraphe(char const * const chemin)
{
    unsigned int uiindexSommet, uiindexArc, uitotalArc;
    CGrapheChargeurFichier chargeur;
    chargeur.GCFchargeFichier(chemin);
    uiGPHtotalSommet = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("NBSommets")));
    uitotalArc = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("NBArcs")));
    //std::cout << uiGPHtotalSommet << std::endl << uitotalArc;

    uiindexSommet = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("Sommets")));
    uiindexArc = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("Arcs")));

    //TODO lire sommets
    //TODO remplir table des sommets
    //TODO lire arcs
    //TODO ajouter arcs
}

CGraphe::~CGraphe()
{
}

void CGraphe::GPHajouterSommet(CSommet* SMTparam)
{
    //TODO exception si sommet existe déjà

    uiGPHtotalSommet++;

    ppSMTGPHliste = (CSommet **) realloc(ppSMTGPHliste, uiGPHtotalSommet * sizeof(CSommet *));
    ppSMTGPHliste[uiGPHtotalSommet-1] = SMTparam;
}

void CGraphe::GPHsupprimerSommet(CSommet& SMTparam){
    unsigned int uiboucle;

    //TODO supp arcs partant et arrivant de SMTparam

    for(uiboucle = 0; uiboucle < uiGPHtotalSommet && SMTparam.SMTgetNumero() != ppSMTGPHliste[uiboucle]->SMTgetNumero(); uiboucle++);
    for(; uiboucle < uiGPHtotalSommet/*-1*/; uiboucle++)
        ppSMTGPHliste[uiboucle] = ppSMTGPHliste[uiboucle+1];
    ppSMTGPHliste = (CSommet **) realloc(ppSMTGPHliste, uiGPHtotalSommet * sizeof(CSommet *));
    SMTparam.~CSommet();
}

CSommet& CGraphe::GPHgetSommet(unsigned int inumero){
    unsigned int uiboucle;
    CSommet SMTnull = NULL;

    for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
        if(ppSMTGPHliste[uiboucle]->SMTgetNumero() == inumero)
            return *ppSMTGPHliste[uiboucle];

    return SMTnull;
}
