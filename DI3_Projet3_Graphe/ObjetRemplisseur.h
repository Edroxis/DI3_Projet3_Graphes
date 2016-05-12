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
Titre: CObjetRemplisseur
***************************************************
Classe abstraite pour implémenter la construction
d'un objet à partir de CParseur
**************************************************/

#ifndef COBJETREMPLISSEUR_H
#define COBJETREMPLISSEUR_H

#include "ParseurStructures.h"

class CObjetRemplisseur
{
public:
	/**************************************************
	* Destructeur de CObjetRemplisseur
	* *************************************************
	* Il est simplement déclaré pour appelé les destructeurs
	* des classes dérivées en cas de polymotphisme
	* *************************************************
	* Entrée:
	* Pré-condition :
	* Sortie : 
	* Post-condition : Les destructeurs spécialisés sont
	*                  appelés
	* ************************************************/
	virtual ~CObjetRemplisseur() {};
	
	/**************************************************
	* registerObject2Modify
	* *************************************************
	* Permet aux classes fille de faire référence à l'
	* objet destiné à être modifié
	* *************************************************
	* Entrée: l'objet à modifier en question
	* Pré-condition : obj != null
	* Sortie : 
	* Post-condition :
	* ************************************************/
	virtual void registerObject2Modify(void* obj) = 0;
	
	/**************************************************
	* handleVariable
	* *************************************************
	* Est exécuté par le parseur quand une variable
	* est disponible
	* *************************************************
	* Entrée: la variable du fichier en question
	* Pré-condition :
	* Sortie : 
	* Post-condition :
	* ************************************************/
	virtual void handleVariable(const CParseurVariable& var) = 0;

	/**************************************************
	* handleArray
	* *************************************************
	* Est exécuté par le parseur quand un tableau est
	* disponible
	* *************************************************
	* Entrée: le tableau du fichier en question
	* Pré-condition :
	* Sortie : 
	* Post-condition :
	* ************************************************/
	virtual void handleArray(const CParseurTableau& arr) = 0;
};

#endif