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
* Constructeur de Cgraphe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Construction d'un CGraphe vide
* ************************************************/
	CGraphe();

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
	CGraphe(char const * const chemin);

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
	~CGraphe();

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
	void GPHajouterSommet(CSommet* SMTparam);

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
	void GPHsupprimerSommet(CSommet& SMTparam);

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
	bool GPHexistantSommet(unsigned int inumero) const;

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
	CSommet& GPHgetSommet(unsigned int inumero);

/**************************************************
* GPHgetListeSommet
* *************************************************
* Obtenir la liste des sommets
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : retourne la liste des sommets
* Post-condition : 
* ************************************************/
	CSommet const * const * const GPHgetListeSommet() const {return ppSMTGPHliste;}

/**************************************************
* GPHgetTotalSommet
* *************************************************
* Obtenir le nombre total de Sommets
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : nombre total de sommets
* Post-condition : 
* ************************************************/
	unsigned int GPHgetTotalSommet() const {return uiGPHtotalSommet;}

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
    void GPHprintGraphe();
};

#endif
