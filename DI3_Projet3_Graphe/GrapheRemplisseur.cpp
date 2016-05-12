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

#include "Graphe.h"
#include "GrapheRemplisseur.h"
#include "Cexception.h"
#include "Parseur.h"

CGrapheRemplisseur::~CGrapheRemplisseur() {}

void CGrapheRemplisseur::registerObject2Modify(void* obj)
{
	graphe = (CGraphe*)obj;
}

void CGrapheRemplisseur::handleVariable(const CParseurVariable& var)
{
	/* On n'a pas besoin des variables, seul la liste des sommets
	et des arcs nous intéresse */
}

void CGrapheRemplisseur::handleArray(const CParseurTableau& arr)
{
	if(strcmp(arr.key, "Sommets") == 0)
	{
		for(unsigned int uiSommetIndex = 0; uiSommetIndex < arr.nbVariables; uiSommetIndex++)
		{
			int num = atoi(arr.variables[uiSommetIndex].value);
			CSommet* sommet = new CSommet(num);

			graphe->GPHajouterSommet(sommet);
		}
	}

	else if(strcmp(arr.key, "Arcs") == 0)
	{
		CParseurVariable* var;
		unsigned int uiArcIndex = 0;

		while(uiArcIndex < arr.nbVariables)
		{
			var = &arr.variables[uiArcIndex];
			if(strcmp(var->key, "Debut") != 0)
				throw Cexception(EXCEPTION_UNABLE_TO_PARSE_FILE);
			CSommet& src = graphe->GPHgetSommet(atoi(var->value));

			uiArcIndex++;
			
			var = &arr.variables[uiArcIndex];
			if(strcmp(var->key, "Fin") != 0)
				throw Cexception(EXCEPTION_UNABLE_TO_PARSE_FILE);
			CSommet& dst = graphe->GPHgetSommet(atoi(var->value));

			uiArcIndex++;

			CSommet::SMTajouterArc(src, dst);
		}
	}
}