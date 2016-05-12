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
Interface de la classe CGraphe.
Permet de créer un graphe, ajouter, supprimer un sommet
obtenir la liste des sommets, le nombre total et 
afficher la structure sur la console.
**************************************************/

#ifndef GRAPHE_H
#define GRAPHE_H

#include "Sommet.h"
#include <iostream>

#define EXCEPTION_SOMMET_INTROUVABLE 1
#define EXCEPTION_SOMMET_EXISTANT 2

class CGraphe
{
private:
	CSommet ** ppSMTGPHliste;	//Liste des Sommets, tableau dynamique
	unsigned int uiGPHtotalSommet;	//Nombre total de Sommets dans le tableau

public:
/**************************************************
* CGraphe
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CGraphe();

/**************************************************
* CGraphe
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CGraphe(char const * const chemin);

/**************************************************
* ~CGraphe
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	~CGraphe();

/**************************************************
* GPHajouterSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void GPHajouterSommet(CSommet* SMTparam);

/**************************************************
* GPHsupprimerSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void GPHsupprimerSommet(CSommet& SMTparam);

/**************************************************
* GPHexistantSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	bool GPHexistantSommet(unsigned int inumero) const;

/**************************************************
* GPHgetSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CSommet& GPHgetSommet(unsigned int inumero);

/**************************************************
* GPHgetListeSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CSommet const * const * const GPHgetListeSommet() const;

/**************************************************
* GPHgetTotalSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	unsigned int GPHgetTotalSommet() const;

/**************************************************
* GPHprintGraphe
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
    void GPHprintGraphe();
};

/**************************************************
* GPHgetTotalSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
inline unsigned int CGraphe::GPHgetTotalSommet() const
{
	return uiGPHtotalSommet;
}

#endif
