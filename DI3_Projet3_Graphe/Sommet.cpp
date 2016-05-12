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
Permet de créer, détruire, un sommet et obtenir son numéro, 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Créé un CSommet vide
* ************************************************/
CSommet::CSommet(const CSommet& SMTparam)
{
	//On ne souhaite pas de copie pour maintenir la cohérence pour les arcs
	assert(false && "Don't copy a CSommet, it's a bad idea, you may burn in hell!");
}

/**************************************************
* CSommet
* *************************************************
* Constructeur de CSommet
* *************************************************
* Entrée: numéro du Sommet 
* Pré-condition : Le numéro est unique (pas déjà présent dans le graphe)
* Sortie :
* Post-condition : création d'un CSommet avec pour numéro
* l'entier non signé passé en paramètre
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Le sommet est détruit
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
* Entrée: référence au sommet de départ, référence 
* au Sommet d'arrivée
* Pré-condition :
* Sortie :
* Post-condition : un Arc allant du partant à l'arrivant 
* a correctement été ajouté dans la structure
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
* Entrée: référence au Sommet de départ de l'arc à supprimer,
* référence au sommet d'arrivée de l'arc à supprimer
* Pré-condition :
* Sortie :
* Post-condition : l'Arc a correctement été supprimé 
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
* Obtenir la référence d'un certain arc
* *************************************************
* Entrée: Référence au Sommet de départ de l'arc cherché,
* référence au sommet d'arrivée de l'arc cherché
* Pré-condition :
* Sortie : pointeur vers l'arc trouvé
* Post-condition : retourne null si l'arc n'est pas trouvé
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
* Afficher sur la console les sommets précédent  et 
* suivant ce Sommet
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : liste des arrivant et partants 
* affichée sur la console
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
* Surcharge de l'opérateur d'affectation, ne pas appeller!
* *************************************************
* Entrée: Sommet à copier
* Pré-condition :
* Sortie :
* Post-condition : création d'un sommet vide
* ************************************************/
void CSommet::operator=(const CSommet& SMTparam)
{
	//On ne souhaite pas de copie pour maintenir la cohérence pour les arcs
	assert(false && "Don't copy a CSommet, it's a bad idea, you may burn in hell!");
}

/**************************************************
* SMTajouterArcPartant
* *************************************************
* Permet d'ajouter un arc à la liste des partant
* *************************************************
* Entrée: Sommet de destination de l'arc
* Pré-condition :
* Sortie :
* Post-condition : l'arc est créer et ajouté au 
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
* Ajouter un arc à la liste des arrivant
* *************************************************
* Entrée: Sommet d'origine de l'arc
* Pré-condition :
* Sortie :
* Post-condition : Création et ajout de l'arc au 
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
* Supprimer l'arc menant à un certain sommet
* *************************************************
* Entrée: Sommet de destination de l'arc
* Pré-condition :
* Sortie :
* Post-condition : l'arc menant vers le sommet en 
* paramètre est supprimé
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
* Entrée: sommet d'origine de l'arc
* Pré-condition :
* Sortie :
* Post-condition : l'arc ayant pour origine le sommet
* en paramètre est supprimé
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
