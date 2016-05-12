#include "UnitTest.h"
#include "Graphe.h"
#include "Cexception.h"
#include "Arc.h"
#include <cassert>

CUnitTest::CUnitTest()
{
}

void CUnitTest::run()
{
	test_GPH_getTotalSommet();
	test_GPH_getSommet();
	test_GPH_existantSommet();
	test_GPH_ajouterSommet();
	test_GPH_supprimerSommet();

	test_GPH_fichier();

	test_SMT_getNumero();
	test_SMT_getPartant();
	test_SMT_getArrivant();
	test_SMT_ajouterArc();
	test_SMT_supprimerArc();
	test_SMT_getArc();
	test_SMT_getNbArrivant();
	test_SMT_getNbPartant();

	test_ARC();
}

void CUnitTest::test_GPH_getTotalSommet()
{
	CGraphe monGraphe;
	assert(monGraphe.GPHgetTotalSommet() == 0);

	CSommet sommet1(1);
	monGraphe.GPHajouterSommet(&sommet1);
	assert(monGraphe.GPHgetTotalSommet() == 1);
}

void CUnitTest::test_GPH_getSommet()
{
	unsigned int numeroSommet = 56;

	CGraphe monGraphe;
	CSommet monSommet(numeroSommet);
	monGraphe.GPHajouterSommet(&monSommet);

	try
	{
		monGraphe.GPHgetSommet(numeroSommet);
	}
	catch(Cexception& e)
	{
		assert(false && "Le sommet n'a pas été trouvé");
	}

	try
	{
		/* La prochaine ligne devrait lever une exception,
		le sommet numéro 42 n'existe pas dans le graphe */
		monGraphe.GPHgetSommet(42);
		assert(false && "la fonction n'a pas levé d'exception");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_SOMMET_INTROUVABLE &&
			"Mauvaise exception levée");
	}
}

void CUnitTest::test_GPH_existantSommet()
{
	CGraphe monGraphe;
	CSommet monSommet(1);
	monGraphe.GPHajouterSommet(&monSommet);

	assert(monGraphe.GPHexistantSommet(1));
	assert(!monGraphe.GPHexistantSommet(2));
}

void CUnitTest::test_GPH_ajouterSommet()
{
	CGraphe monGraphe;
	assert(monGraphe.GPHgetTotalSommet() == 0);

	CSommet sommet1(1);
	monGraphe.GPHajouterSommet(&sommet1);
	assert(monGraphe.GPHgetTotalSommet() == 1);

	CSommet sommetDuplique(1);
	try
	{
		/* monGraphe contient déjà un sommet avec le numéro 1,
		la prochaine ligne devrait léver une exception */
		monGraphe.GPHajouterSommet(&sommetDuplique);
		assert(false);
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_SOMMET_EXISTANT);
	}

	CSommet sommet2(2);
	monGraphe.GPHajouterSommet(&sommet2);
	assert(monGraphe.GPHgetTotalSommet() == 2);
}

void CUnitTest::test_GPH_supprimerSommet()
{
	CGraphe monGraphe;

	CSommet monSommet1(1);
	monGraphe.GPHajouterSommet(&monSommet1);

	CSommet monSommet2(5);
	monGraphe.GPHajouterSommet(&monSommet2);

	CSommet monSommet3(2);
	monGraphe.GPHajouterSommet(&monSommet3);

	CSommet monSommetPasDansLeGraphe(42);

	monGraphe.GPHsupprimerSommet(monSommet2);
	monGraphe.GPHsupprimerSommet(monSommet1);

	try
	{
		//Si les suppressions ont fonctionnés GPHgetSommet() devrait lèver une exception
		monGraphe.GPHgetSommet(5);
		monGraphe.GPHgetSommet(1);
		assert(false);
	}
	catch(Cexception& e) {}

	try
	{
		//Le seul sommet qui n'a pas été supprimé devrait rester accessible
		monGraphe.GPHgetSommet(2);
	}
	catch(Cexception &e)
	{
		assert(false);
	}

	assert(monGraphe.GPHgetTotalSommet() == 1);

	try
	{
		/*La méthode de suppression de sommet devrait nous annoncer quand
		on lui demande de supprimer un sommet qui n'existe pas */
		monGraphe.GPHsupprimerSommet(monSommetPasDansLeGraphe);
		assert(false && "La methode aurait du lever une exception");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_SOMMET_INTROUVABLE);
	}
}


void CUnitTest::test_GPH_fichier()
{
	//TODO: Tester avec graphe correcte et pas correct (exceptions)
	std::cout << "-----------------" << std::endl;
	CGraphe monGraphe("graphe1.txt");
	monGraphe.GPHprintGraphe();
	std::cout << "-----------------" << std::endl;
}


void CUnitTest::test_SMT_getNumero()
{
	CSommet monSommet1(1);
	CSommet monSommet2(1);
	CSommet monSommet3(8);

	assert(monSommet1.SMTgetNumero() == 1);
	assert(monSommet2.SMTgetNumero() == 1);
	assert(monSommet3.SMTgetNumero() == 8);
}

void CUnitTest::test_SMT_getPartant()
{
	CSommet monSommet1(1);
	CSommet monSommet2(1);
	CSommet monSommet3(2);

	CSommet::SMTajouterArc(monSommet1, monSommet2);
	CSommet::SMTajouterArc(monSommet1, monSommet3);
	
	CArc const * const * arcPartants = monSommet1.SMTgetPartant();

	assert(&arcPartants[0]->ARCgetDest() == &monSommet2);
	assert(&arcPartants[1]->ARCgetDest() == &monSommet3);
}

void CUnitTest::test_SMT_getArrivant()
{
	CSommet monSommet1(1);
	CSommet monSommet2(2);
	CSommet monSommet3(3);

	CSommet::SMTajouterArc(monSommet1, monSommet3);
	CSommet::SMTajouterArc(monSommet2, monSommet3);
	
	CArc const * const * arcArrivants = monSommet3.SMTgetArrivant();
	assert(&arcArrivants[0]->ARCgetDest() == &monSommet1);
	assert(&arcArrivants[1]->ARCgetDest() == &monSommet2);
}

void CUnitTest::test_SMT_ajouterArc()
{
	CSommet sommet1(1);
	CSommet sommet2(2);

	try
	{
		CSommet::SMTajouterArc(sommet1, sommet1);
		assert(sommet1.SMTgetNbArrivant() == 1);
		assert(sommet1.SMTgetNbPartant() == 1);
	}
	catch(...)
	{
		assert(false && "On doit pouvoir ajouter des arcs réflexifs.");
	}
	
	CSommet::SMTajouterArc(sommet1, sommet2);

	try
	{
		CSommet::SMTajouterArc(sommet1, sommet2);
		assert(false && "On n'est pas censé ajouter 2x le même arc entre 2 mêmes sommets");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_ARC_EXISTANT);
	}
}

void CUnitTest::test_SMT_supprimerArc()
{
	CSommet monSommet1(1);
	CSommet monSommet2(2);
	CSommet monSommet3(3);

	CSommet::SMTajouterArc(monSommet1, monSommet2);
	CSommet::SMTajouterArc(monSommet1, monSommet3);

	CSommet::SMTsupprimerArc(monSommet1, monSommet2);
	assert(monSommet1.SMTgetNbPartant() == 1);
	assert(monSommet1.SMTgetNbArrivant() == 0);
	assert(monSommet2.SMTgetNbPartant() == 0);
	assert(monSommet2.SMTgetNbArrivant() == 0);
	assert(monSommet3.SMTgetNbPartant() == 0);
	assert(monSommet3.SMTgetNbArrivant() == 1);
	
	CArc const * const * arcPartants = monSommet1.SMTgetPartant();
	assert(&arcPartants[0]->ARCgetDest() == &monSommet3);
}

void CUnitTest::test_SMT_getArc()
{
	CSommet monSommet1(1);
	CSommet monSommet2(2);

	CSommet::SMTajouterArc(monSommet1, monSommet2);
	assert(&CSommet::SMTgetArc(monSommet1, monSommet2)->ARCgetDest() ==
		&monSommet2);

	//On test si getArc() nous retourne bien 0 si l'arc n'existe pas
	assert(CSommet::SMTgetArc(monSommet1, monSommet1) == 0);
}

void CUnitTest::test_SMT_getNbArrivant()
{
	CSommet monSommet1(1);
	CSommet monSommet2(2);
	CSommet monSommet3(3);

	assert(monSommet2.SMTgetNbArrivant() == 0);

	CSommet::SMTajouterArc(monSommet1, monSommet2);
	assert(monSommet2.SMTgetNbArrivant() == 1);

	CSommet::SMTajouterArc(monSommet3, monSommet2);
	assert(monSommet2.SMTgetNbArrivant() == 2);
}

void CUnitTest::test_SMT_getNbPartant()
{
	CSommet monSommet1(1);
	CSommet monSommet2(2);
	CSommet monSommet3(3);

	assert(monSommet1.SMTgetNbPartant() == 0);

	CSommet::SMTajouterArc(monSommet1, monSommet2);
	assert(monSommet1.SMTgetNbPartant() == 1);

	CSommet::SMTajouterArc(monSommet1, monSommet3);
	assert(monSommet1.SMTgetNbPartant() == 2);
}


void CUnitTest::test_ARC()
{
	CSommet monSommetDestination(2);

	//Test constructeur et du get
	CArc monArc(monSommetDestination);
	assert(&monArc.ARCgetDest() == &monSommetDestination);

	//Test constructeur de recopie
	CArc monArcCopie(monArc);
	assert(&monArcCopie.ARCgetDest() == &monArc.ARCgetDest());
}