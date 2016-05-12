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

#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "ObjetRemplisseur.h"

#define EXCEPTION_UNABLE_TO_OPEN_FILE 4 
#define EXCEPTION_UNABLE_TO_PARSE_FILE 5

class CParseur
{
public:
	/* CParseur ne garde pas de copie du CObjectRemplisseur,
	donc veillez à sa conservation en mémoire pour parse() */
	CParseur(CObjetRemplisseur* remplisseur);

	void PRSparse(const char* emplacement, void* objetARemplir);

private:
	void PRSparseLine(char* line);
	void PRSparseArray(char* line, int equalPos);
	void PRSparseVariable(char* line, int equalPos);

private:
	CObjetRemplisseur* remplisseur;
	bool tableauEnParsement;
};

#endif