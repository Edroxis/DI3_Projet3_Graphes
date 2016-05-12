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

#include "Graphe.h"
#include "Parseur.h"
#include "GrapheRemplisseur.h"
#include <stdlib.h>
#include <iostream>
#include "Cexception.h"

using namespace std;

CGraphe::CGraphe()
{
	ppSMTGPHliste = 0;
	uiGPHtotalSommet = 0;
}

CGraphe::CGraphe(char const * const chemin)
{
	ppSMTGPHliste = 0;
	uiGPHtotalSommet = 0;

	CGrapheRemplisseur grapheRemplisseur;
	CParseur parseur(&grapheRemplisseur);

	parseur.PRSparse(chemin, this);
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

CSommet const * const * const CGraphe::GPHgetListeSommet() const{
	return ppSMTGPHliste;
}

CSommet& CGraphe::GPHgetSommet(unsigned int inumero)
{
    unsigned int uiboucle;

    for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
        if(ppSMTGPHliste[uiboucle]->SMTgetNumero() == inumero)
            return *ppSMTGPHliste[uiboucle];

    throw Cexception(EXCEPTION_SOMMET_INTROUVABLE);
}


void CGraphe::GPHprintGraphe(){
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
    {
        ppSMTGPHliste[uiboucle]->SMTprintSommet();
        cout << endl;
    }
}
