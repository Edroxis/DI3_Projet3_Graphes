#include "UnitTest.h"
#include "Graphe.h"
#include "Cexception.h"
#include "Arc.h"
#include <cassert>

/**************************************************
* CUnitTest
* *************************************************
* Constructeur par d�faut de CUnitTest, ne fait rien
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : 
* ************************************************/
CUnitTest::CUnitTest()
{
}

/**************************************************
* run
* *************************************************
* Lance tous les tests
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = tout 
* est fonctionnel
* ************************************************/
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

/**************************************************
* test_GPH_getTotalSommet
* *************************************************
* Test de la fonction CGraphe::getTotalSommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_GPH_getTotalSommet()
{
	CGraphe monGraphe;
	assert(monGraphe.GPHgetTotalSommet() == 0);

	CSommet sommet1(1);
	monGraphe.GPHajouterSommet(&sommet1);
	assert(monGraphe.GPHgetTotalSommet() == 1);
}

/**************************************************
* test_GPH_getSommet
* *************************************************
* Test de la fonction CGraphe::getSommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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
		assert(false && "Le sommet n'a pas �t� trouv�");
	}

	try
	{
		/* La prochaine ligne devrait lever une exception,
		le sommet num�ro 42 n'existe pas dans le graphe */
		monGraphe.GPHgetSommet(42);
		assert(false && "la fonction n'a pas lev� d'exception");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_SOMMET_INTROUVABLE &&
			"Mauvaise exception lev�e");
	}
}

/**************************************************
* test_GPH_existantSommet
* *************************************************
* Test de la fonction CGraphe::existantSommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_GPH_existantSommet()
{
	CGraphe monGraphe;
	CSommet monSommet(1);
	monGraphe.GPHajouterSommet(&monSommet);

	assert(monGraphe.GPHexistantSommet(1));
	assert(!monGraphe.GPHexistantSommet(2));
}

/**************************************************
* test_GPH_ajouterSommet
* *************************************************
* Test de la fonction CGraphe::ajouterSommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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
		/* monGraphe contient d�j� un sommet avec le num�ro 1,
		la prochaine ligne devrait l�ver une exception */
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

/**************************************************
* test_GPH_supprimerSommet
* *************************************************
* Test de la fonction CGraphe::supprimerSommet
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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
		//Si les suppressions ont fonctionn�s GPHgetSommet() devrait l�ver une exception
		monGraphe.GPHgetSommet(5);
		monGraphe.GPHgetSommet(1);
		assert(false);
	}
	catch(Cexception& e) {}

	try
	{
		//Le seul sommet qui n'a pas �t� supprim� devrait rester accessible
		monGraphe.GPHgetSommet(2);
	}
	catch(Cexception &e)
	{
		assert(false);
	}

	assert(monGraphe.GPHgetTotalSommet() == 1);

	try
	{
		/*La m�thode de suppression de sommet devrait nous annoncer quand
		on lui demande de supprimer un sommet qui n'existe pas */
		monGraphe.GPHsupprimerSommet(monSommetPasDansLeGraphe);
		assert(false && "La methode aurait du lever une exception");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_SOMMET_INTROUVABLE);
	}
}

/**************************************************
* test_GPH_fichier
* *************************************************
* Test du chargeur de fichier
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_GPH_fichier()
{
	//TODO: Tester avec graphe correcte et pas correct (exceptions)
	std::cout << "-----------------" << std::endl;
	CGraphe monGraphe("graphe1.txt");
	monGraphe.GPHprintGraphe();
	std::cout << "-----------------" << std::endl;
}

/**************************************************
* test_SMT_getNumero
* *************************************************
* Test de la fonction CSommet::getNumero
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_SMT_getNumero()
{
	CSommet monSommet1(1);
	CSommet monSommet2(1);
	CSommet monSommet3(8);

	assert(monSommet1.SMTgetNumero() == 1);
	assert(monSommet2.SMTgetNumero() == 1);
	assert(monSommet3.SMTgetNumero() == 8);
}

/**************************************************
* test_SMT_getPartant
* *************************************************
* Test de la fonction CSommet::getPartant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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

/**************************************************
* test_SMT_getArrivant
* *************************************************
* Test de la fonction CSommet::getArrivant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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

/**************************************************
* test_SMT_ajouterArc
* *************************************************
* Test de la fonction CSommet::ajouterArc
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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
		assert(false && "On doit pouvoir ajouter des arcs r�flexifs.");
	}
	
	CSommet::SMTajouterArc(sommet1, sommet2);

	try
	{
		CSommet::SMTajouterArc(sommet1, sommet2);
		assert(false && "On n'est pas cens� ajouter 2x le m�me arc entre 2 m�mes sommets");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_ARC_EXISTANT);
	}
}

/**************************************************
* test_SMT_supprimerArc
* *************************************************
* Test de la fonction CSommet::supprimerArc
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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

/**************************************************
* test_SMT_getArc
* *************************************************
* Test de la fonction CSommet::getArc
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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

/**************************************************
* test_SMT_getNbArrivant
* *************************************************
* Test de la fonction CSommet::getNbArrivant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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

/**************************************************
* test_SMT_getNbPartant
* *************************************************
* Test de la fonction CSommet::getNbPartant
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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

/**************************************************
* test_ARC
* *************************************************
* Test du constructeur de CArc et costructeur de recopie
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : aucun assert d�clench� = m�thode 
* fonctionnelle
* ************************************************/
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