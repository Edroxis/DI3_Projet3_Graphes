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
Interface de la classe CUnitTest.
Permet de tester nos classes et leurs fonctions.
**************************************************/

#ifndef UNITTEST_H
#define UNITTEST_H

class CUnitTest
{
public:
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
	CUnitTest();

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
	void run();

private:
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
	void test_GPH_getTotalSommet();

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
	void test_GPH_getSommet();

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
	void test_GPH_existantSommet();

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
	void test_GPH_ajouterSommet();

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
	void test_GPH_supprimerSommet();
	
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
	void test_GPH_fichier();

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
	void test_SMT_getNumero();

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
	void test_SMT_getPartant();

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
	void test_SMT_getArrivant();

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
	void test_SMT_ajouterArc();

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
	void test_SMT_supprimerArc();

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
	void test_SMT_getArc();

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
	void test_SMT_getNbArrivant();

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
	void test_SMT_getNbPartant();

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
	void test_ARC();
};

#endif