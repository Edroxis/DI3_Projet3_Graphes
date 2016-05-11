#include "GrapheOperation.h"

CGraphe* CGrapheOperation::GOPinverserGraphe(CGraphe& GPHparam)
{
    CGraphe* GPHres = new CGraphe();
	unsigned int uiboucleSommet, uiboucleArc;
    //Lire tous les sommets et ajouter
	for(uiboucleSommet = 0; uiboucleSommet < GPHparam.GPHgetTotalSommet(); uiboucleSommet++) 
		GPHres->GPHajouterSommet(new CSommet(GPHparam.GPHgetListeSommet()[uiboucleSommet]->SMTgetNumero()));
    //Lire tous les arcs et ajouter
	for(uiboucleSommet = 0; uiboucleSommet < GPHparam.GPHgetTotalSommet(); uiboucleSommet++)
	{
		CSommet const * const pSMTtemp = GPHparam.GPHgetListeSommet()[uiboucleSommet];
		for(uiboucleArc = 0; uiboucleArc < pSMTtemp->SMTgetNbArrivant(); uiboucleArc++)
		{
			CSommet::SMTajouterArc	(	GPHres->GPHgetSommet	(
											pSMTtemp->SMTgetNumero()
															), 
										GPHres->GPHgetSommet	(
											pSMTtemp->SMTgetArrivant()[uiboucleArc]->ARCgetDest().SMTgetNumero()
															)
									);
		}
	}
    return GPHres;
}
