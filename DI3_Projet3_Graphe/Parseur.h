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
Titre: CParseur
***************************************************
C'est le parseur associé à un certain formattage
de document. Il délègue la création de l'objet à
une instance de la classe abstraite CObjetRemplisseur
**************************************************/

#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "ObjetRemplisseur.h"

#define EXCEPTION_UNABLE_TO_OPEN_FILE 4 
#define EXCEPTION_UNABLE_TO_PARSE_FILE 5

class CParseur
{
public:
	/**************************************************
	* CParseur
	* *************************************************
	* Constructeur de CParseur
	* *************************************************
	* Entrée: instance d'un CObjetRemplisseur
	* Pré-condition : remplisseur != null
	* Sortie :
	* Post-condition : l'objet est crééer
	* ************************************************/
	CParseur(CObjetRemplisseur* remplisseur);
	
	/**************************************************
	* PRSparse
	* *************************************************
	* Lance le parsage
	* *************************************************
	* Entrée: emplacement: localisation absolu sur le
	*                      disque dur
	*         objetARemplir: un pointeur vers l'objet
	*                        qui doit être construit
	* Pré-condition : aucun pointeur paramètre null
	* Sortie :
	* Post-condition : objetARemplir est complété
	* ************************************************/
	void PRSparse(const char* emplacement, void* objetARemplir);

private:
	/**************************************************
	* PRSparseLine
	* *************************************************
	* S'occupe de parser juste une ligne
	* *************************************************
	* Entrée: line: la ligne à parser
	* Pré-condition : line != null
	* Sortie :
	* Post-condition :
	* ************************************************/
	void PRSparseLine(char* line);

	/**************************************************
	* PRSparseArray
	* *************************************************
	* Est éxécuté quand la ligne est contenu dans un
	* tableau
	* *************************************************
	* Entrée: line: la ligne à parser ; equalPos : l'index
	*         du symbole '='
	* Pré-condition : line != null
	* Sortie :
	* Post-condition :
	* ************************************************/
	void PRSparseArray(char* line, int equalPos);

	/**************************************************
	* PRSparseVariable
	* *************************************************
	* Est éxécuté quand la ligne est une déclaration de
	* variable
	* *************************************************
	* Entrée: line: la ligne à parser ; equalPos : l'index
	*         du symbole '='
	* Pré-condition : line != null
	* Sortie :
	* Post-condition :
	* ************************************************/
	void PRSparseVariable(char* line, int equalPos);

private:
	CObjetRemplisseur* remplisseur;
	bool tableauEnParsement;
};

#endif