#include "Graphe.h"
#include "GrapheChargeurFichier.h"
#include <stdlib.h>
#include "Cexception.h"

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
	free(ppSMTGPHliste);
}

void CGraphe::GPHajouterSommet(CSommet* SMTparam)
{
	if(GPHexistantSommet(SMTparam->SMTgetNumero()))
		throw Cexception(EXCEPTION_SOMMET_EXISTANT);

    uiGPHtotalSommet++;

    ppSMTGPHliste = (CSommet **) realloc(ppSMTGPHliste, uiGPHtotalSommet * sizeof(CSommet *));
    ppSMTGPHliste[uiGPHtotalSommet-1] = SMTparam;
}

void CGraphe::GPHsupprimerSommet(CSommet& SMTparam)
{
    unsigned int uiboucle;

    //TODO supp arcs partant et arrivant de SMTparam

	/* On incrémente uiboucle tant que le sommet n'est pas trouvé,
	dès qu'il est trouvé uiboucle fait référence à l'index du sommet */
    for(uiboucle = 0; uiboucle < uiGPHtotalSommet &&
		SMTparam.SMTgetNumero() != ppSMTGPHliste[uiboucle]->SMTgetNumero(); uiboucle++);

	if(uiboucle == uiGPHtotalSommet)
		throw Cexception(EXCEPTION_SOMMET_INTROUVABLE);

	//TODO: A virer si CGraphe ne gère pas la durée de vie nos CSommet
	//delete ppSMTGPHliste[uiboucle];

    for(; uiboucle < uiGPHtotalSommet - 1; uiboucle++)
        ppSMTGPHliste[uiboucle] = ppSMTGPHliste[uiboucle+1];

	uiGPHtotalSommet--;
    ppSMTGPHliste = (CSommet **) realloc(ppSMTGPHliste, uiGPHtotalSommet * sizeof(CSommet *));
}

bool CGraphe::GPHexistantSommet(unsigned int inumero) const
{
	unsigned int uiboucle;

	for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
		if(ppSMTGPHliste[uiboucle]->SMTgetNumero() == inumero)
			return true;

	return false;
}

CSommet& CGraphe::GPHgetSommet(unsigned int inumero)
{
    unsigned int uiboucle;

    for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
        if(ppSMTGPHliste[uiboucle]->SMTgetNumero() == inumero)
            return *ppSMTGPHliste[uiboucle];

    throw Cexception(EXCEPTION_SOMMET_INTROUVABLE);
}
