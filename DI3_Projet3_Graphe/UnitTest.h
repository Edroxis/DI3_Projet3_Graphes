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
* 
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
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void run();

private:
/**************************************************
* test_GPH_getTotalSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_GPH_getTotalSommet();

/**************************************************
* test_GPH_getSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_GPH_getSommet();

/**************************************************
* test_GPH_existantSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_GPH_existantSommet();

/**************************************************
* test_GPH_ajouterSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_GPH_ajouterSommet();

/**************************************************
* test_GPH_supprimerSommet
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_GPH_supprimerSommet();

/**************************************************
* test_SMT_getNumero
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_getNumero();

/**************************************************
* test_SMT_getPartant
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_getPartant();

/**************************************************
* test_SMT_getArrivant
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_getArrivant();

/**************************************************
* test_SMT_ajouterArc
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_ajouterArc();

/**************************************************
* test_SMT_supprimerArc
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_supprimerArc();

/**************************************************
* test_SMT_getArc
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_getArc();

/**************************************************
* test_SMT_getNbArrivant
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_getNbArrivant();

/**************************************************
* test_SMT_getNbPartant
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_SMT_getNbPartant();

/**************************************************
* test_ARC
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
	void test_ARC();
};

#endif