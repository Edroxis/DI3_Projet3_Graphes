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
Permet de cr�er un graphe, ajouter, supprimer un sommet
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
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Construction d'un CGraphe vide
* ************************************************/
	CGraphe();

/**************************************************
* CGraphe
* *************************************************
* Initialise un graphe � partir d'un fichier
* *************************************************
* Entr�e: chemin vers le fichier
* Pr�-condition : le fichier est valide
* Sortie :
* Post-condition : un graphe est cr�er suivant les 
* donn�es du fichier
* ************************************************/
	CGraphe(char const * const chemin);

/**************************************************
* ~CGraphe
* *************************************************
* Destructeur de CGraphe
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : le Graphe est correctement d�truit
* ************************************************/
	~CGraphe();

/**************************************************
* GPHajouterSommet
* *************************************************
* Permet d'ajouter un sommet au graphe
* *************************************************
* Entr�e: pointeur sur un CSommet, allou� par new
* Pr�-condition :
* Sortie :
* Post-condition : le Sommet � �t� ajout� au graphe
* ************************************************/
	void GPHajouterSommet(CSommet* SMTparam);

/**************************************************
* GPHsupprimerSommet
* *************************************************
* Permet de Supprimer un Sommet
* *************************************************
* Entr�e: r�f�rence du sommet � supprimer
* Pr�-condition :
* Sortie :
* Post-condition : le sommet � correctement �t� sipprim�
* ************************************************/
	void GPHsupprimerSommet(CSommet& SMTparam);

/**************************************************
* GPHexistantSommet
* *************************************************
* Test l'existance d'un sommet dans le graphe � partir
* de son num�ro
* *************************************************
* Entr�e: num�ro du sommet
* Pr�-condition :
* Sortie : true si le Sommet est pr�sent, faux sinon
* Post-condition : 
* ************************************************/
	bool GPHexistantSommet(unsigned int inumero) const;

/**************************************************
* GPHgetSommet
* *************************************************
* Obtenir la r�frence d'un sommet � partir de son num�ro
* *************************************************
* Entr�e: num�ro du noeud cherch�
* Pr�-condition :
* Sortie : r�f�rence vers le sommet portant le num�ro 
* en param�tre
* Post-condition : renvoie une exception si sommet introuvable
* ************************************************/
	CSommet& GPHgetSommet(unsigned int inumero);

/**************************************************
* GPHgetListeSommet
* *************************************************
* Obtenir la liste des sommets
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : retourne la liste des sommets
* Post-condition : 
* ************************************************/
	CSommet const * const * const GPHgetListeSommet() const {return ppSMTGPHliste;}

/**************************************************
* GPHgetTotalSommet
* *************************************************
* Obtenir le nombre total de Sommets
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : nombre total de sommets
* Post-condition : 
* ************************************************/
	unsigned int GPHgetTotalSommet() const {return uiGPHtotalSommet;}

/**************************************************
* GPHprintGraphe
* *************************************************
* Affiche la Structure enti�re du graphe
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : La structure du graphe est affich�e 
* dans la console
* ************************************************/
    void GPHprintGraphe();
};

#endif
