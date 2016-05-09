#include "UnitTest.h"
#include "Graphe.h"
#include "Cexception.h"
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