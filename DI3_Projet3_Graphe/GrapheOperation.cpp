/* --------------------------------------------------------------------
| Copyright (C) 2016 <Amoros Julien> <Seroux Kevin>                    \
|                                                                      |
| This program is free software: you can redistribute it and/or modify |
| it under the terms of the GNU General Public License as published by |
| the Free Software Foundation, either version 3 of the License, or    |
| (at your option) any later version.                                  |
|                                                                      |
| This program is distributed in the hope that it will be useful,      |
| but WITHOUT ANY WARRANTY; without even the implied warranty of       |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         |
| GNU General Public License for more details.                         |
|                                                                      |
| You should have received a copy of the GNU General Public License    |
| along with this program. If not, see <http://www.gnu.org/licenses/>. |
|-------------------------------------------------------------------*/

#include "GrapheOperation.h"

/**************************************************
* GOPinverserGraphe
* *************************************************
* Renvoie un graphe inverse à celui passé en paramètre
* *************************************************
* Entrée: un graphe
* Pré-condition :
* Sortie : un nouveau graphe
* Post-condition : Création d'un nouveau graphe qui 
* est l'inverse de celui en paramètre
* ************************************************/
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
