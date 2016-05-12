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

#include <iostream>
#include "Sommet.h"
#include "Cexception.h"
#include <stdlib.h>
#include <cassert>

using namespace std;

CSommet::CSommet(const CSommet& SMTparam)
{
	//On ne souhaite pas de copie pour maintenir la cohérence pour les arcs
	assert(false && "Don't copy a CSommet, it's a bad idea, you may burn in hell!");
}

CSommet::CSommet(unsigned int uiParam)
{
    uiSMTnumero = uiParam;
    uiSMTnbArrivant = 0;
	uiSMTnbPartant = 0;
	ppARCSMTarrivant = (CArc **) malloc(0 * sizeof(CArc *));
	ppARCSMTpartant = (CArc **) malloc(0 * sizeof(CArc *));
}

CSommet::~CSommet(void)
{
    unsigned int uiboucle;

    uiSMTnumero = 0;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant; uiboucle++)
        delete ppARCSMTarrivant[uiboucle];
    for(uiboucle = 0; uiboucle < uiSMTnbPartant; uiboucle++)
        delete ppARCSMTpartant[uiboucle];
}

unsigned int CSommet::SMTgetNumero() const{
    return uiSMTnumero;
}

CArc const * const * CSommet::SMTgetPartant() const
{
    return ppARCSMTpartant;
}

CArc const * const * CSommet::SMTgetArrivant() const
{
    return ppARCSMTarrivant;
}

unsigned int CSommet::SMTgetNbArrivant() const
{
    return uiSMTnbArrivant;
}

unsigned int CSommet::SMTgetNbPartant() const
{
    return uiSMTnbPartant;
}

void CSommet::SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant)
{
	if(SMTgetArc(SMTpartant, SMTarrivant) != 0)
		throw Cexception(EXCEPTION_ARC_EXISTANT);

    SMTpartant.SMTajouterArcPartant(SMTarrivant);
    SMTarrivant.SMTajouterArcArrivant(SMTpartant);
}

void CSommet::SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant)
{
    SMTpartant.SMTsupprimerArcPartant(SMTarrivant);
    SMTarrivant.SMTsupprimerArcArrivant(SMTpartant);
}

CArc const * const CSommet::SMTgetArc(const CSommet& SMTpartant, const CSommet& SMTarrivant)
{
	for(unsigned int uiIndexArc = 0; uiIndexArc < SMTpartant.SMTgetNbPartant(); uiIndexArc++)
	{
		CArc const * const testedArc = SMTpartant.ppARCSMTpartant[uiIndexArc];
		if(&testedArc->ARCgetDest() == &SMTarrivant)
			return testedArc;
	}

	return 0;
}

void CSommet::SMTprintSommet() const
{
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiSMTnbPartant; uiboucle++)
        cout << uiSMTnumero << "->" << ppARCSMTpartant[uiboucle]->ARCgetDest().SMTgetNumero() << endl;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant; uiboucle++)
        cout << uiSMTnumero << "<-" << ppARCSMTarrivant[uiboucle]->ARCgetDest().SMTgetNumero() << endl;
}

void CSommet::SMTajouterArcPartant(CSommet& SMTdest)
{
    uiSMTnbPartant++;
    ppARCSMTpartant = (CArc **) realloc(ppARCSMTpartant, uiSMTnbPartant * sizeof (CArc *));
    ppARCSMTpartant[uiSMTnbPartant-1] = new CArc(SMTdest);
}

void CSommet::SMTajouterArcArrivant(CSommet& SMTdest)
{
    uiSMTnbArrivant++;
    ppARCSMTarrivant = (CArc **) realloc(ppARCSMTarrivant, uiSMTnbArrivant * sizeof (CArc *));
    ppARCSMTarrivant[uiSMTnbArrivant-1] = new CArc(SMTdest);
}

void CSommet::SMTsupprimerArcPartant(CSommet& SMTdest)
{
    unsigned int uiboucle;

    uiSMTnbPartant--;

    for(uiboucle = 0; uiboucle < uiSMTnbPartant &&
		SMTdest.SMTgetNumero() != ppARCSMTpartant[uiboucle]->ARCgetDest().SMTgetNumero(); uiboucle++);

    for(; uiboucle < uiSMTnbPartant/*-1*/; uiboucle++)
        ppARCSMTpartant[uiboucle] = ppARCSMTpartant[uiboucle+1];

    ppARCSMTpartant = (CArc **) realloc(ppARCSMTpartant, uiSMTnbPartant * sizeof(CArc*));
}

void CSommet::SMTsupprimerArcArrivant(CSommet& SMTsrc)
{
    unsigned int uiboucle;

    uiSMTnbArrivant--;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant &&
		SMTsrc.SMTgetNumero() != ppARCSMTarrivant[uiboucle]->ARCgetDest().SMTgetNumero(); uiboucle++);

    for(; uiboucle < uiSMTnbArrivant/*-1*/; uiboucle++)
        ppARCSMTarrivant[uiboucle] = ppARCSMTarrivant[uiboucle+1];

    ppARCSMTarrivant = (CArc **) realloc(ppARCSMTarrivant, uiSMTnbArrivant * sizeof(CArc*));
}

void CSommet::operator=(const CSommet& SMTparam)
{
	//On ne souhaite pas de copie pour maintenir la cohérence pour les arcs
	assert(false && "Don't copy a CSommet, it's a bad idea, you may burn in hell!");
}