#include <iostream>
#include "GrapheChargeurFichier.h"
#include "Graphe.h"

using namespace std;

int main(int argc, char* argv[])
{
	/*CGrapheChargeurFichier test;
	test.GCFchargeFichier("graphe1.txt");
	test.GCFafficherTabs();*/

	CGraphe grph;

	CSommet* som1 = new CSommet(1);
	CSommet* som2 = new CSommet(2);
	CSommet* som3 = new CSommet(3);

	grph.GPHajouterSommet(som1);
	grph.GPHajouterSommet(som2);
	grph.GPHajouterSommet(som3);

    CSommet::SMTajouterArc(*&*som1, *&*som2);
    CSommet::SMTajouterArc(*&*som2, *&*som3);
    CSommet::SMTajouterArc(*&*som3, *&*som1);

    //cout << grph.GPHgetSommet(1).SMTgetNumero();

    CSommet::SMTsupprimerArc(*&*som1, *&*som2);
    CSommet::SMTsupprimerArc(*&*som2, *&*som3);
    CSommet::SMTsupprimerArc(*&*som3, *&*som1);

    grph.GPHsupprimerSommet(grph.GPHgetSommet(1));
    grph.GPHsupprimerSommet(grph.GPHgetSommet(2));
    grph.GPHsupprimerSommet(grph.GPHgetSommet(3));

	/*int e;
	scanf_s("%d",&e);*/
	return 0;
}

