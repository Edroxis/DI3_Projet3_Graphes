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
#include "UnitTest.h"

using namespace std;

int main(int argc, char* argv[])
{
	CUnitTest tests;
	tests.run();

	/*CGrapheChargeurFichier test;
	test.GCFchargeFichier("graphe1.txt");
	test.GCFafficherTabs();*/

	//TODO: Supprimer ça ?

	CGraphe grph, *grph2;

	CSommet* som1 = new CSommet(1);
	CSommet* som2 = new CSommet(2);
	CSommet* som3 = new CSommet(3);

	grph.GPHajouterSommet(som1);
	grph.GPHajouterSommet(som2);
	grph.GPHajouterSommet(som3);

    CSommet::SMTajouterArc(*som1, *som2);
    CSommet::SMTajouterArc(*som2, *som3);
    CSommet::SMTajouterArc(*som3, *som1);

    //grph.GPHprintGraphe();
	grph2 = CGrapheOperation::GOPinverserGraphe(grph);
	grph2->GPHprintGraphe();

    CSommet::SMTsupprimerArc(*som1, *som2);
    CSommet::SMTsupprimerArc(*som2, *som3);
    CSommet::SMTsupprimerArc(*som3, *som1);

	try
	{
		grph.GPHsupprimerSommet(grph.GPHgetSommet(1));
		grph.GPHsupprimerSommet(grph.GPHgetSommet(2));
		grph.GPHsupprimerSommet(grph.GPHgetSommet(3));
	}
	catch(Cexception& e)
	{
		cout << "Un des sommets n'a pas été trouvé" << endl;
	}

	int e;
	scanf_s("%d",&e);
	return 0;
}

