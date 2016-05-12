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

/**************************************************
Titre: Classe de Gestion des CSommet
***************************************************
Corps de la classe CSommet.
Permet de cr�er, d�truire, un sommet et obtenir son num�ro, 
ajouter, supprimer un Arc, obtenir la liste des arcs 
arrivant et partant ainsi que leur nombre et afficher
sur la console la structure du sommet courant.
**************************************************/

#include <iostream>
#include "Sommet.h"
#include "Cexception.h"
#include <stdlib.h>
#include <cassert>

using namespace std;

/**************************************************
* CSommet
* *************************************************
* Constructeur de recopie, ne pas appeller!
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Cr�� un CSommet vide
* ************************************************/
CSommet::CSommet(const CSommet& SMTparam)
{
	//On ne souhaite pas de copie pour maintenir la coh�rence pour les arcs
	assert(false && "Don't copy a CSommet, it's a bad idea, you may burn in hell!");
}

/**************************************************
* CSommet
* *************************************************
* Constructeur de CSommet
* *************************************************
* Entr�e: num�ro du Sommet 
* Pr�-condition : Le num�ro est unique (pas d�j� pr�sent dans le graphe)
* Sortie :
* Post-condition : cr�ation d'un CSommet avec pour num�ro
* l'entier non sign� pass� en param�tre
* ************************************************/
CSommet::CSommet(unsigned int uiParam)
{
    uiSMTnumero = uiParam;
    uiSMTnbArrivant = 0;
	uiSMTnbPartant = 0;
	ppARCSMTarrivant = (CArc **) malloc(0 * sizeof(CArc *));
	ppARCSMTpartant = (CArc **) malloc(0 * sizeof(CArc *));
}

/**************************************************
* ~CSommet
* *************************************************
* Destructeur de CSommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Le sommet est d�truit
* ************************************************/
CSommet::~CSommet(void)
{
    unsigned int uiboucle;

    uiSMTnumero = 0;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant; uiboucle++)
        delete ppARCSMTarrivant[uiboucle];
    for(uiboucle = 0; uiboucle < uiSMTnbPartant; uiboucle++)
        delete ppARCSMTpartant[uiboucle];
}

/**************************************************
* SMTajouterArc
* *************************************************
* Permet d'ajouter un Arc au graphe
* *************************************************
* Entr�e: r�f�rence au sommet de d�part, r�f�rence 
* au Sommet d'arriv�e
* Pr�-condition :
* Sortie :
* Post-condition : un Arc allant du partant � l'arrivant 
* a correctement �t� ajout� dans la structure
* ************************************************/
void CSommet::SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant)
{
	if(SMTgetArc(SMTpartant, SMTarrivant) != 0)
		throw Cexception(EXCEPTION_ARC_EXISTANT);

    SMTpartant.SMTajouterArcPartant(SMTarrivant);
    SMTarrivant.SMTajouterArcArrivant(SMTpartant);
}

/**************************************************
* SMTsupprimerArc
* *************************************************
* Supprimer un Arc
* *************************************************
* Entr�e: r�f�rence au Sommet de d�part de l'arc � supprimer,
* r�f�rence au sommet d'arriv�e de l'arc � supprimer
* Pr�-condition :
* Sortie :
* Post-condition : l'Arc a correctement �t� supprim� 
* de la structure
* ************************************************/
void CSommet::SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant)
{
    SMTpartant.SMTsupprimerArcPartant(SMTarrivant);
    SMTarrivant.SMTsupprimerArcArrivant(SMTpartant);
}

/**************************************************
* SMTgetArc
* *************************************************
* Obtenir la r�f�rence d'un certain arc
* *************************************************
* Entr�e: R�f�rence au Sommet de d�part de l'arc cherch�,
* r�f�rence au sommet d'arriv�e de l'arc cherch�
* Pr�-condition :
* Sortie : pointeur vers l'arc trouv�
* Post-condition : retourne null si l'arc n'est pas trouv�
* ************************************************/
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

/**************************************************
* SMTprintSommet
* *************************************************
* Afficher sur la console les sommets pr�c�dent  et 
* suivant ce Sommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : liste des arrivant et partants 
* affich�e sur la console
* ************************************************/
void CSommet::SMTprintSommet() const
{
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiSMTnbPartant; uiboucle++)
        cout << uiSMTnumero << "->" << ppARCSMTpartant[uiboucle]->ARCgetDest().SMTgetNumero() << endl;

    for(uiboucle = 0; uiboucle < uiSMTnbArrivant; uiboucle++)
        cout << uiSMTnumero << "<-" << ppARCSMTarrivant[uiboucle]->ARCgetDest().SMTgetNumero() << endl;
}

/**************************************************
* operator=
* *************************************************
* Surcharge de l'op�rateur d'affectation, ne pas appeller!
* *************************************************
* Entr�e: Sommet � copier
* Pr�-condition :
* Sortie :
* Post-condition : cr�ation d'un sommet vide
* ************************************************/
void CSommet::operator=(const CSommet& SMTparam)
{
	//On ne souhaite pas de copie pour maintenir la coh�rence pour les arcs
	assert(false && "Don't copy a CSommet, it's a bad idea, you may burn in hell!");
}

/**************************************************
* SMTajouterArcPartant
* *************************************************
* Permet d'ajouter un arc � la liste des partant
* *************************************************
* Entr�e: Sommet de destination de l'arc
* Pr�-condition :
* Sortie :
* Post-condition : l'arc est cr�er et ajout� au 
* tableau des partant
* ************************************************/
void CSommet::SMTajouterArcPartant(CSommet& SMTdest)
{
    uiSMTnbPartant++;
    ppARCSMTpartant = (CArc **) realloc(ppARCSMTpartant, uiSMTnbPartant * sizeof (CArc *));
    ppARCSMTpartant[uiSMTnbPartant-1] = new CArc(SMTdest);
}

/**************************************************
* SMTajouterArcArrivant
* *************************************************
* Ajouter un arc � la liste des arrivant
* *************************************************
* Entr�e: Sommet d'origine de l'arc
* Pr�-condition :
* Sortie :
* Post-condition : Cr�ation et ajout de l'arc au 
* tableau des arrivant
* ************************************************/
void CSommet::SMTajouterArcArrivant(CSommet& SMTdest)
{
    uiSMTnbArrivant++;
    ppARCSMTarrivant = (CArc **) realloc(ppARCSMTarrivant, uiSMTnbArrivant * sizeof (CArc *));
    ppARCSMTarrivant[uiSMTnbArrivant-1] = new CArc(SMTdest);
}

/**************************************************
* SMTsupprimerArcPartant
* *************************************************
* Supprimer l'arc menant � un certain sommet
* *************************************************
* Entr�e: Sommet de destination de l'arc
* Pr�-condition :
* Sortie :
* Post-condition : l'arc menant vers le sommet en 
* param�tre est supprim�
* ************************************************/
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

/**************************************************
* SMTsupprimerArcArrivant
* *************************************************
* Supprimer l'arc venant d'un certain sommet
* *************************************************
* Entr�e: sommet d'origine de l'arc
* Pr�-condition :
* Sortie :
* Post-condition : l'arc ayant pour origine le sommet
* en param�tre est supprim�
* ************************************************/
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
