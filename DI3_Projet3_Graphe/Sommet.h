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
Permet de cr�er, d�truire, un sommet et obtenir son num�ro, 
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
    unsigned int uiSMTnumero;	//Num�ro du sommet
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
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Cr�� un CSommet vide
* ************************************************/
	CSommet(const CSommet& SMTparam);

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
	CSommet(unsigned int uiParam);

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
	~CSommet();

public:
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
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);

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
	static void SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant);

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
	static CArc const * const SMTgetArc(const CSommet& SMTpartant, const CSommet& SMTarrivant);

/**************************************************
* SMTgetNumero
* *************************************************
* Obtenir le num�ro du sommet courant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : num�ro du sommet
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNumero() const {return uiSMTnumero;}

/**************************************************
* SMTgetPartant
* *************************************************
* Obtenir la liste des Arcs partant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : tableau des Arcs partant
* Post-condition : 
* ************************************************/
	CArc const * const * SMTgetPartant() const {return ppARCSMTpartant;}

/**************************************************
* SMTgetArrivant
* *************************************************
* Obtenir la liste des arcs arrivant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : tableau des Arcs arrivant
* Post-condition : 
* ************************************************/
	CArc const * const * SMTgetArrivant() const {return ppARCSMTarrivant;}

/**************************************************
* SMTgetNbArrivant
* *************************************************
* Obtenir le nombre d'arcs arrivant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : nombre d'arcs arrivant
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNbArrivant() const {return uiSMTnbArrivant;}

/**************************************************
* SMTgetNbPartant
* *************************************************
* Obtenir nombre d'arcs partant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : nombre d'arcs partant
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNbPartant() const {return uiSMTnbPartant;}

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
    void SMTprintSommet() const;

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
	void operator=(const CSommet&);

private:
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
	void SMTajouterArcPartant(CSommet& SMTdest);

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
	void SMTajouterArcArrivant(CSommet& SMTdest);

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
	void SMTsupprimerArcPartant(CSommet& SMTdest);

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
	void SMTsupprimerArcArrivant(CSommet& SMTdest);
};

#endif
