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
Titre: CGrapheRemplisseur
***************************************************
Interface de CGrapheRemplisseur.
Construction d'un CGraphe à partir d'un parseur
**************************************************/

#ifndef CGRAPHEREMPLISSEUR_H
#define CGRAPHEREMPLISSEUR_H

#include "ObjetRemplisseur.h"
#include "ParseurStructures.h"

//Déclaration anticipée pour éviter l'inclusion circulaire
class CGraphe;

class CGrapheRemplisseur: public CObjetRemplisseur
{
public:
/**************************************************
* ~CGrapheRemplisseur
* *************************************************
* Destructeur de CGrapheRemplisseur
* *************************************************
* Entrée : 
* Pré-condition : 
* Sortie : 
* Post-condition : Appel des destructeurs
* ************************************************/
	~CGrapheRemplisseur();

/**************************************************
* registerObject2Modify
* *************************************************
* Garder la référence de l'objet à modifier
* *************************************************
* Entrée : objet à modifier
* Pré-condition : 
* Sortie : 
* Post-condition : la référence de l'objet est dans 
* la variable graphe
* ************************************************/
	void registerObject2Modify(void* obj);

/**************************************************
* handleVariable
* *************************************************
* Ne fait rien
* *************************************************
* Entrée : la variable du fichier en question
* Pré-condition : 
* Sortie : 
* Post-condition : 
* ************************************************/
	void handleVariable(const CParseurVariable& var);

/**************************************************
* handleArray
* *************************************************
* Est exécuté par le parseur quand un tableau est
* disponible
* *************************************************
* Entrée : le tableau du fichier en question
* Pré-condition : 
* Sortie : 
* Post-condition : 
* ************************************************/
	void handleArray(const CParseurTableau& arr);

private:
	CGraphe* graphe; //Objet graphe construit
};

#endif