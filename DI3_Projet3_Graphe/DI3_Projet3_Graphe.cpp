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

#include <iostream>
#include "GrapheOperation.h"
#include "Graphe.h"
#include "Cexception.h"
#include "Parseur.h"
#include "UnitTest.h"

using namespace std;

int main(int argc, char* argv[])
{
	#ifdef _DEBUG
	CUnitTest unitTests;
	unitTests.run();
	#endif

	if(argc != 2)
		cerr << "Veuillez specifier en unique argument l'emplacement du "
			 << "fichier graphe a ouvrir" << endl;
	else
	{
		try
		{
			CGraphe graphe(argv[1]);
			cout << "Graphe :" << endl;
			graphe.GPHprintGraphe();

			CGraphe* grapheInverse = CGrapheOperation::GOPinverserGraphe(graphe);
			cout << endl << "Graphe inverse :" << endl;
			grapheInverse->GPHprintGraphe();
		}
		catch(const Cexception& e)
		{
			switch(e.EXClire_valeur())
			{
			case EXCEPTION_SOMMET_INTROUVABLE:
				cerr << "Sommet introuvable" << endl;
				break;

			case EXCEPTION_SOMMET_EXISTANT:
				cerr << "Sommet deja existant" << endl;
				break;

			case EXCEPTION_ARC_EXISTANT:
				cerr << "Arc deja existant" << endl;
				break;

			case EXCEPTION_UNABLE_TO_OPEN_FILE:
				cerr << "Impossible d'ouvrir le fichier." << endl;
				break;

			case EXCEPTION_UNABLE_TO_PARSE_FILE:
				cerr << "Impossible de parser le fichier car il est corrompu." << endl;
				break;

			default:
				cerr << "Erreur inconnue" << endl;
				break;
			}
		}
	}

	system("PAUSE");
	return 0;
}

