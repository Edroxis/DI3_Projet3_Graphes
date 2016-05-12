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
Construction d'un CGraphe � partir d'un parseur
**************************************************/

#ifndef CGRAPHEREMPLISSEUR_H
#define CGRAPHEREMPLISSEUR_H

#include "ObjetRemplisseur.h"
#include "ParseurStructures.h"

//D�claration anticip�e pour �viter l'inclusion circulaire
class CGraphe;

class CGrapheRemplisseur: public CObjetRemplisseur
{
public:
/**************************************************
* ~CGrapheRemplisseur
* *************************************************
* Destructeur de CGrapheRemplisseur
* *************************************************
* Entr�e : 
* Pr�-condition : 
* Sortie : 
* Post-condition : Appel des destructeurs
* ************************************************/
	~CGrapheRemplisseur();

/**************************************************
* registerObject2Modify
* *************************************************
* Garder la r�f�rence de l'objet � modifier
* *************************************************
* Entr�e : objet � modifier
* Pr�-condition : 
* Sortie : 
* Post-condition : la r�f�rence de l'objet est dans 
* la variable graphe
* ************************************************/
	void registerObject2Modify(void* obj);

/**************************************************
* handleVariable
* *************************************************
* Ne fait rien
* *************************************************
* Entr�e : la variable du fichier en question
* Pr�-condition : 
* Sortie : 
* Post-condition : 
* ************************************************/
	void handleVariable(const CParseurVariable& var);

/**************************************************
* handleArray
* *************************************************
* Est ex�cut� par le parseur quand un tableau est
* disponible
* *************************************************
* Entr�e : le tableau du fichier en question
* Pr�-condition : 
* Sortie : 
* Post-condition : 
* ************************************************/
	void handleArray(const CParseurTableau& arr);

private:
	CGraphe* graphe; //Objet graphe construit
};

#endif