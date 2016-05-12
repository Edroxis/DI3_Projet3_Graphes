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
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CSommet(const CSommet& SMTparam);

/**************************************************
* CSommet
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CSommet(unsigned int uiParam);

/**************************************************
* ~CSommet
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	~CSommet();

public:
/**************************************************
* SMTajouterArc
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	static void SMTajouterArc(CSommet& SMTpartant, CSommet& SMTarrivant);

/**************************************************
* SMTsupprimerArc
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	static void SMTsupprimerArc(CSommet& SMTpartant, CSommet& SMTarrivant);

/**************************************************
* SMTgetArc
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	static CArc const * const SMTgetArc(const CSommet& SMTpartant, const CSommet& SMTarrivant);

/**************************************************
* SMTgetNumero
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNumero() const;

/**************************************************
* SMTgetPartant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CArc const * const * SMTgetPartant() const;

/**************************************************
* SMTgetArrivant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	CArc const * const * SMTgetArrivant() const;

/**************************************************
* SMTgetNbArrivant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNbArrivant() const;

/**************************************************
* SMTgetNbPartant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	unsigned int SMTgetNbPartant() const;

/**************************************************
* SMTprintSommet
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
    void SMTprintSommet();

/**************************************************
* operator=
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void operator=(const CSommet&);

private:
/**************************************************
* SMTajouterArcPartant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void SMTajouterArcPartant(CSommet& SMTdest);

/**************************************************
* SMTajouterArcArrivant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void SMTajouterArcArrivant(CSommet& SMTdest);

/**************************************************
* SMTsupprimerArcPartant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void SMTsupprimerArcPartant(CSommet& SMTdest);

/**************************************************
* SMTsupprimerArcArrivant
* *************************************************
* 
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void SMTsupprimerArcArrivant(CSommet& SMTdest);
};

#endif
