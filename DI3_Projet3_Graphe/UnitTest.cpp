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
Titre: Classe de Test des fonctions
***************************************************
Corps de la classe CUnitTest.
Permet de tester nos classes et leurs fonctions.
**************************************************/

#include "UnitTest.h"
#include "Graphe.h"
#include "Cexception.h"
#include "Arc.h"
#include "Parseur.h"
#include "MyString.h"
#include "GrapheOperation.h"
#include <cassert>

/**************************************************
* CUnitTest
* *************************************************
* Constructeur par défaut de CUnitTest, ne fait rien
* *************************************************
* Entrée:
* Pré-condition :
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = tout 
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

	test_MST_suppEspaces();
	test_MST_trouverChar();

	test_GOP_inverserGraphe();
}

/**************************************************
* test_GPH_getTotalSommet
* *************************************************
* Test de la fonction CGraphe::getTotalSommet
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
	catch(...)
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

/**************************************************
* test_GPH_existantSommet
* *************************************************
* Test de la fonction CGraphe::existantSommet
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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

/**************************************************
* test_GPH_supprimerSommet
* *************************************************
* Test de la fonction CGraphe::supprimerSommet
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
		//Si les suppressions ont fonctionnés GPHgetSommet() devrait lèver une exception
		monGraphe.GPHgetSommet(5);
		monGraphe.GPHgetSommet(1);
		assert(false);
	}
	catch(...) {}

	try
	{
		//Le seul sommet qui n'a pas été supprimé devrait rester accessible
		monGraphe.GPHgetSommet(2);
	}
	catch(...)
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

/**************************************************
* test_GPH_fichier
* *************************************************
* Test du chargeur de fichier
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_GPH_fichier()
{
	try
	{
		//Ces 2 graphes sont censés fonctionner
		CGraphe monGraphe1("graphe1.txt");
		CGraphe monGraphe2("graphe2.txt");
	}
	catch(...)
	{
		assert(false);
	}

	//Le suivant devrait lever une exception type fichier pas trouvé
	try
	{
		CGraphe monGraphe("monjGdsd.txt");
		assert(false && "L'ouverture de graphe aurait du levé une exception");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_UNABLE_TO_OPEN_FILE);
	}

	//Les suivants devrait lever des exceptions type fichier mal formatté
	try
	{
		CGraphe monGraphe("graphe3_marche_pas.txt");
		assert(false && "Des fichiers mal formattés doivent levés des exceptions");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_UNABLE_TO_PARSE_FILE);
	}

	//Un dernier mal formatté pour la route
	try
	{
		CGraphe monGraphe("graphe4_marche_pas.txt");
		assert(false && "Des fichiers mal formattés doivent levés des exceptions");
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == EXCEPTION_UNABLE_TO_PARSE_FILE);
	}
}

/**************************************************
* test_SMT_getNumero
* *************************************************
* Test de la fonction CSommet::getNumero
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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

/**************************************************
* test_SMT_supprimerArc
* *************************************************
* Test de la fonction CSommet::supprimerArc
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
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

/**************************************************
* test_MST_suppEspaces
* *************************************************
* Test de la méthode de CMyString pour supprimer les espaces
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_MST_suppEspaces()
{
	char text1[] = "     Lorem ipsum sit";
	CMyString::MSTsuppEspace(text1);
	assert(strcmp(text1, "Loremipsumsit") == 0);

	char text2[] = "Lorem ipsum sit     ";
	CMyString::MSTsuppEspace(text2);
	assert(strcmp(text2, "Loremipsumsit") == 0);

	char text3[] = " a b ffd \n fdfdfd\t ";
	CMyString::MSTsuppEspace(text3);
	assert(strcmp(text3, "abffd\nfdfdfd\t") == 0);
}

/**************************************************
* test_MST_trouverChar
* *************************************************
* Test de la méthode de CMyString pour obtenir l'index d'un caractère
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_MST_trouverChar()
{
	char* text1 = " trouver le line feed\n !";
	assert(CMyString::MSTtrouverChar(text1, '\n') == 21);
	assert(CMyString::MSTtrouverChar(text1, '!') == 23);
	assert(CMyString::MSTtrouverChar(text1, 'e') == 6);
}

/**************************************************
* test_GOP_inverserGraphe
* *************************************************
* Test de la méthode de CGrapheOperation pour l'inversion de graphe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = méthode 
* fonctionnelle
* ************************************************/
void CUnitTest::test_GOP_inverserGraphe()
{
	CGraphe monGraphe;
	CSommet sommet1(1), sommet2(2), sommet3(3);

	monGraphe.GPHajouterSommet(&sommet1);
	monGraphe.GPHajouterSommet(&sommet2);
	monGraphe.GPHajouterSommet(&sommet3);

	/* 1 -> 2
		* 2 -> 3
		* 3 -> 3 */
	CSommet::SMTajouterArc(sommet1, sommet2);
	CSommet::SMTajouterArc(sommet2, sommet3);
	CSommet::SMTajouterArc(sommet3, sommet3);

	CGraphe* grapheInverse = CGrapheOperation::GOPinverserGraphe(monGraphe);
	CSommet& sommet1Inv = grapheInverse->GPHgetSommet(1);
	CSommet& sommet2Inv = grapheInverse->GPHgetSommet(2);
	CSommet& sommet3Inv = grapheInverse->GPHgetSommet(3);

	/* 2 -> 1
	 * 3 -> 2
	 * 3 -> 3 */
	assert(sommet1Inv.SMTgetNbPartant() == 0);
	assert(sommet1Inv.SMTgetNbArrivant() == 1);
	assert(sommet2Inv.SMTgetNbPartant() == 1);
	assert(sommet2Inv.SMTgetNbArrivant() == 1);
	assert(sommet3Inv.SMTgetNbPartant() == 2);
	assert(sommet3Inv.SMTgetNbArrivant() == 1);

	assert(CSommet::SMTgetArc(sommet2Inv, sommet1Inv) != 0);
	assert(CSommet::SMTgetArc(sommet3Inv, sommet2Inv) != 0);
	assert(CSommet::SMTgetArc(sommet3Inv, sommet3Inv) != 0);
}