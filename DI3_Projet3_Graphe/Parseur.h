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
C'est le parseur associ� � un certain formattage
de document. Il d�l�gue la cr�ation de l'objet �
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
	* Entr�e: instance d'un CObjetRemplisseur
	* Pr�-condition : remplisseur != null
	* Sortie :
	* Post-condition : l'objet est cr��er
	* ************************************************/
	CParseur(CObjetRemplisseur* remplisseur);
	
	/**************************************************
	* PRSparse
	* *************************************************
	* Lance le parsage
	* *************************************************
	* Entr�e: emplacement: localisation absolu sur le
	*                      disque dur
	*         objetARemplir: un pointeur vers l'objet
	*                        qui doit �tre construit
	* Pr�-condition : aucun pointeur param�tre null
	* Sortie :
	* Post-condition : objetARemplir est compl�t�
	* ************************************************/
	void PRSparse(const char* emplacement, void* objetARemplir);

private:
	/**************************************************
	* PRSparseLine
	* *************************************************
	* S'occupe de parser juste une ligne
	* *************************************************
	* Entr�e: line: la ligne � parser
	* Pr�-condition : line != null
	* Sortie :
	* Post-condition :
	* ************************************************/
	void PRSparseLine(char* line);

	/**************************************************
	* PRSparseArray
	* *************************************************
	* Est �x�cut� quand la ligne est contenu dans un
	* tableau
	* *************************************************
	* Entr�e: line: la ligne � parser ; equalPos : l'index
	*         du symbole '='
	* Pr�-condition : line != null
	* Sortie :
	* Post-condition :
	* ************************************************/
	void PRSparseArray(char* line, int equalPos);

	/**************************************************
	* PRSparseVariable
	* *************************************************
	* Est �x�cut� quand la ligne est une d�claration de
	* variable
	* *************************************************
	* Entr�e: line: la ligne � parser ; equalPos : l'index
	*         du symbole '='
	* Pr�-condition : line != null
	* Sortie :
	* Post-condition :
	* ************************************************/
	void PRSparseVariable(char* line, int equalPos);

private:
	CObjetRemplisseur* remplisseur;
	bool tableauEnParsement;
};

#endif