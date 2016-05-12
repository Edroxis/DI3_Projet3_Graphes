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
Interface de la classe CSommet.
Permet de créer, détruire, un sommet et obtenir son numéro, 
ajouter, supprimer un Arc, obtenir la liste des arcs 
arrivant et partant ainsi que leur nombre et afficher
sur la console la structure du sommet courant.
**************************************************/

#ifndef SOMMET_H
#define SOMMET_H

#include "Arc.h"

#define EXCEPTION_ARC_EXISTANT 3

class CSommet
{
private:
    unsigned int uiSMTnumero;	//Numéro du sommet
	unsigned int uiSMTnbArrivant;	//Nombre d'Arcs Arrivant
	unsigned int uiSMTnbPartant;	//Nombre d'Arcs Partant
	CArc ** ppARCSMTarrivant;	//Liste des Arcs arrivant, tableau dynamique
	CArc ** ppARCSMTpartant;	//Liste des Arcs partant, tableau dynamique

public:
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
	CSommet(const CSommet& SMTparam);

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
	CSommet(unsigned int uiParam);

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
	~CSommet();

public:
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
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);

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
	static void SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant);

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
	static CArc const * const SMTgetArc(const CSommet& SMTpartant, const CSommet& SMTarrivant);

/**************************************************
* SMTgetNumero
* *************************************************
* Obtenir le numéro du sommet courant
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : numéro du sommet
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNumero() const {return uiSMTnumero;}

/**************************************************
* SMTgetPartant
* *************************************************
* Obtenir la liste des Arcs partant
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : tableau des Arcs partant
* Post-condition : 
* ************************************************/
	CArc const * const * SMTgetPartant() const {return ppARCSMTpartant;}

/**************************************************
* SMTgetArrivant
* *************************************************
* Obtenir la liste des arcs arrivant
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : tableau des Arcs arrivant
* Post-condition : 
* ************************************************/
	CArc const * const * SMTgetArrivant() const {return ppARCSMTarrivant;}

/**************************************************
* SMTgetNbArrivant
* *************************************************
* Obtenir le nombre d'arcs arrivant
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : nombre d'arcs arrivant
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNbArrivant() const {return uiSMTnbArrivant;}

/**************************************************
* SMTgetNbPartant
* *************************************************
* Obtenir nombre d'arcs partant
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : nombre d'arcs partant
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNbPartant() const {return uiSMTnbPartant;}

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
    void SMTprintSommet() const;

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
	void operator=(const CSommet&);

private:
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
	void SMTajouterArcPartant(CSommet& SMTdest);

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
	void SMTajouterArcArrivant(CSommet& SMTdest);

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
	void SMTsupprimerArcPartant(CSommet& SMTdest);

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
	void SMTsupprimerArcArrivant(CSommet& SMTdest);
};

#endif
