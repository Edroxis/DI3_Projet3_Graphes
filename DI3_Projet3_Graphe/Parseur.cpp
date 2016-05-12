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

#include "Parseur.h"
#include "Cexception.h"
#include "MyString.h"
#include <fstream>

using namespace std;

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
CParseur::CParseur(CObjetRemplisseur* objRemplisseur)
{
	remplisseur = objRemplisseur;
	tableauEnParsement = false;
}

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
void CParseur::PRSparse(const char* emplacement, void* objetARemplir)
{
	remplisseur->registerObject2Modify(objetARemplir);

	ifstream file(emplacement, ifstream::in);

	if(!file.is_open())
		throw Cexception(EXCEPTION_UNABLE_TO_OPEN_FILE);

	char buffer[BUFSIZ];

	while(!file.eof())
	{
		file.getline(buffer, BUFSIZ);
		PRSparseLine(buffer);
	}

	file.close();
}

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
void CParseur::PRSparseLine(char* line)
{
	CMyString::MSTsuppEspace(line);
	int index = CMyString::MSTtrouverChar(line, '=');

	//En gros, si y'a pas de = et qu'on est pas dans un tableau, y'a un soucis
	if(!tableauEnParsement && index == -1)
		throw Cexception(EXCEPTION_UNABLE_TO_PARSE_FILE);

	if(tableauEnParsement || line[index + 1] == '[')
		PRSparseArray(line, index);
	else
		PRSparseVariable(line, index);
}

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
void CParseur::PRSparseArray(char * line, int equalPos)
{
	static CParseurTableau tab;

	//Si on rentre dans un tableau
	if(!tableauEnParsement)
	{
		tableauEnParsement = true;

		size_t keyLength = equalPos + 1;
		tab.key = new char[keyLength];
		strncpy_s(tab.key, keyLength, line, equalPos);
		tab.nbVariables = 0;
		tab.variables = 0;
	}
	
	//Si on quitte un tableau
	else if(CMyString::MSTtrouverChar(line, ']') != -1)
	{
		tableauEnParsement = false;
		remplisseur->handleArray(tab);

		//On lib�re ce qui a �t� allou� dynamiquement
		for(unsigned int uiVar = 0; uiVar < tab.nbVariables; uiVar++)
		{
			delete[] tab.variables[uiVar].key;
			delete[] tab.variables[uiVar].value;
		}
		free(tab.variables);
		delete[] tab.key;
	}

	//Sinon, on traite les donn�es
	else
	{
		int prochaineVirgule = -1;
		char * subStr = line;

		//Tant qu'il y a des �l�ments sur la m�me ligne (s�par�s par une virgule)
		do
		{
			subStr = subStr + prochaineVirgule + 1;
			unsigned int indexNewVar = tab.nbVariables;

			tab.nbVariables++;
			tab.variables = (CParseurVariable*)realloc(tab.variables, sizeof(CParseurVariable) * tab.nbVariables);

			int equalPos = CMyString::MSTtrouverChar(subStr, '=');
			if(equalPos == -1)
				throw Cexception(EXCEPTION_UNABLE_TO_PARSE_FILE);

			//Rempli la cl�
			int keyLength = equalPos + 1;
			tab.variables[indexNewVar].key = new char[keyLength];
			strncpy_s(tab.variables[indexNewVar].key, keyLength, subStr, keyLength - 1);
			
			//Rempli la valeur
			subStr = subStr + equalPos + 1;
			int valLength;
			prochaineVirgule = CMyString::MSTtrouverChar(subStr, ',');
			if(prochaineVirgule == -1)
				valLength = strlen(subStr) + 1;
			else
				valLength = prochaineVirgule + 1;
			tab.variables[indexNewVar].value = new char[valLength];
			strncpy_s(tab.variables[indexNewVar].value, valLength, subStr, valLength - 1);

		} while(prochaineVirgule != -1);
	}
}

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
void CParseur::PRSparseVariable(char* line, int equalPos)
{
	char key[64];
	char value[256];

	strncpy_s(key, line, equalPos);
	strcpy_s(value, line + equalPos + 1);

	CParseurVariable var;
	var.key = key;
	var.value = value;

	remplisseur->handleVariable(var);
}