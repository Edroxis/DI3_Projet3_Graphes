#include "Graphe.h"
#include "GrapheChargeurFichier.h"
#include <stdlib.h>

CGraphe::CGraphe(void)
{
}


CGraphe::CGraphe(char * chemin)
{
    unsigned int uiindexSommet, uiindexArc;
    CGrapheChargeurFichier chargeur;
    chargeur.GCFchargeFichier(chemin);
    uiGPHtotalSommet = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("NBSommets")));
    uiGPHtotalArc = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("NBArcs")));
    //std::cout << uiGPHtotalSommet << std::endl << uiGPHtotalArc;

    uiindexSommet = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("Sommets")));
    uiindexArc = atoi(chargeur.GCFtrouverValeur(chargeur.GCFtrouverCle("Arcs")));

    //TODO lire sommets
    //TODO remplir table des sommets
    //TODO lire arcs
    //TODO ajouter arcs
}

CGraphe::~CGraphe(void)
{
}
