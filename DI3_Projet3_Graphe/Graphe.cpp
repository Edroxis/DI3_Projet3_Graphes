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
Titre: Classe de Gestion des Graphes
***************************************************
Corps de la classe CGraphe.
Permet de créer un graphe, ajouter, supprimer un sommet
obtenir la liste des sommets, le nombre total et 
afficher la structure sur la console.
**************************************************/

#include "Graphe.h"
#include "Parseur.h"
#include "GrapheRemplisseur.h"
#include <stdlib.h>
#include <iostream>
#include "Cexception.h"

using namespace std;

/**************************************************
* CGraphe
* *************************************************
* Constructeur de Cgraphe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Construction d'un CGraphe vide
* ************************************************/
CGraphe::CGraphe()
{
	ppSMTGPHliste = 0;
	uiGPHtotalSommet = 0;
}

/**************************************************
* CGraphe
* *************************************************
* Initialise un graphe à partir d'un fichier
* *************************************************
* Entrée: chemin vers le fichier
* Pré-condition : le fichier est valide
* Sortie :
* Post-condition : un graphe est créer suivant les 
* données du fichier
* ************************************************/
CGraphe::CGraphe(char const * const chemin)
{
	ppSMTGPHliste = 0;
	uiGPHtotalSommet = 0;

	CGrapheRemplisseur grapheRemplisseur;
	CParseur parseur(&grapheRemplisseur);

	parseur.PRSparse(chemin, this);
}

/**************************************************
* ~CGraphe
* *************************************************
* Destructeur de CGraphe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : le Graphe est correctement détruit
* ************************************************/
CGraphe::~CGraphe()
{
	free(ppSMTGPHliste);
}

/**************************************************
* GPHajouterSommet
* *************************************************
* Permet d'ajouter un sommet au graphe
* *************************************************
* Entrée: pointeur sur un CSommet, alloué par new
* Pré-condition :
* Sortie :
* Post-condition : le Sommet à été ajouté au graphe
* ************************************************/
void CGraphe::GPHajouterSommet(CSommet* SMTparam)
{
	if(GPHexistantSommet(SMTparam->SMTgetNumero()))
		throw Cexception(EXCEPTION_SOMMET_EXISTANT);

    uiGPHtotalSommet++;

    ppSMTGPHliste = (CSommet **) realloc(ppSMTGPHliste, uiGPHtotalSommet * sizeof(CSommet *));
    ppSMTGPHliste[uiGPHtotalSommet-1] = SMTparam;
}

/**************************************************
* GPHsupprimerSommet
* *************************************************
* Permet de Supprimer un Sommet
* *************************************************
* Entrée: référence du sommet à supprimer
* Pré-condition :
* Sortie :
* Post-condition : le sommet à correctement été sipprimé
* ************************************************/
void CGraphe::GPHsupprimerSommet(CSommet& SMTparam)
{
	//On supprime les arcs partant de ce sommet
	const CArc* const * arcPartants = SMTparam.SMTgetPartant();
	for(unsigned int uiArc = 0; uiArc < SMTparam.SMTgetNbPartant(); uiArc++)
		CSommet::SMTsupprimerArc(SMTparam, arcPartants[uiArc]->ARCgetDest());

	//Puis les arcs arrivants à ce sommet
	const CArc* const * arcArrivants = SMTparam.SMTgetArrivant();
	for(unsigned int uiArc = 0; uiArc < SMTparam.SMTgetNbArrivant(); uiArc++)
		CSommet::SMTsupprimerArc(arcArrivants[uiArc]->ARCgetDest(), SMTparam);

    unsigned int uiboucle;
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

/**************************************************
* GPHexistantSommet
* *************************************************
* Test l'existance d'un sommet dans le graphe à partir
* de son numéro
* *************************************************
* Entrée: numéro du sommet
* Pré-condition :
* Sortie : true si le Sommet est présent, faux sinon
* Post-condition : 
* ************************************************/
bool CGraphe::GPHexistantSommet(unsigned int inumero) const
{
	unsigned int uiboucle;

	for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
		if(ppSMTGPHliste[uiboucle]->SMTgetNumero() == inumero)
			return true;

	return false;
}

/**************************************************
* GPHgetSommet
* *************************************************
* Obtenir la réfrence d'un sommet à partir de son numéro
* *************************************************
* Entrée: numéro du noeud cherché
* Pré-condition :
* Sortie : référence vers le sommet portant le numéro 
* en paramètre
* Post-condition : renvoie une exception si sommet introuvable
* ************************************************/
CSommet& CGraphe::GPHgetSommet(unsigned int inumero)
{
    unsigned int uiboucle;

    for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
        if(ppSMTGPHliste[uiboucle]->SMTgetNumero() == inumero)
            return *ppSMTGPHliste[uiboucle];

    throw Cexception(EXCEPTION_SOMMET_INTROUVABLE);
}

/**************************************************
* GPHprintGraphe
* *************************************************
* Affiche la Structure entière du graphe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : La structure du graphe est affichée 
* dans la console
* ************************************************/
void CGraphe::GPHprintGraphe(){
    unsigned int uiboucle;
    for(uiboucle = 0; uiboucle < uiGPHtotalSommet; uiboucle++)
    {
        ppSMTGPHliste[uiboucle]->SMTprintSommet();
        cout << endl;
    }
}
