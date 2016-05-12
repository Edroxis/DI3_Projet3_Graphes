#include "Parseur.h"
#include "Cexception.h"
#include "MyString.h"
#include <fstream>

using namespace std;

CParseur::CParseur(CObjetRemplisseur* objRemplisseur)
{
	remplisseur = objRemplisseur;
	tableauEnParsement = false;
}

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

		//On libère ce qui a été alloué dynamiquement
		for(unsigned int uiVar = 0; uiVar < tab.nbVariables; uiVar++)
		{
			delete[] tab.variables[uiVar].key;
			delete[] tab.variables[uiVar].value;
		}
		free(tab.variables);
		delete[] tab.key;
	}

	//Sinon, on traite les données
	else
	{
		int prochaineVirgule = -1;
		char * subStr = line;

		//Tant qu'il y a des éléments sur la même ligne (séparés par une virgule)
		do
		{
			subStr = subStr + prochaineVirgule + 1;
			unsigned int indexNewVar = tab.nbVariables;

			tab.nbVariables++;
			tab.variables = (CParseurVariable*)realloc(tab.variables, sizeof(CParseurVariable) * tab.nbVariables);

			int equalPos = CMyString::MSTtrouverChar(subStr, '=');
			if(equalPos == -1)
				throw Cexception(EXCEPTION_UNABLE_TO_PARSE_FILE);

			//Rempli la clé
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