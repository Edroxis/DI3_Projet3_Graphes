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
Titre: Classe pour la gestion des exceptions
***************************************************
Interface de la Classe Cexception
Permet de créer des objets remontés lors de
la levée d'exceptions.
**************************************************/

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

class Cexception
{
	//Attribut
private:
	unsigned int uiEXCvaleur; //Contient la valeur de l'exception

	//Constructeur et destructeur
public:
/**************************************************
* CException
* *************************************************
* Constructeur par défaut
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Exception initialisé à 0
* ************************************************/
	Cexception();

/**************************************************
* CException
* *************************************************
* Constructeur
* *************************************************
* Entrée: Valeur associée à l'exception
* Pré-condition :
* Sortie :
* Post-condition : Exception initialisé à la valeur en entrée
* ************************************************/
	Cexception(unsigned int);

/**************************************************
* ~CException
* *************************************************
* Destructeur de la classe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : exception détruite
* ************************************************/
	~Cexception() {}

	//Methode
/**************************************************
* Excmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entrée: nouvelle valeur
* Pré-condition :
* Sortie :
* Post-condition : valeur de l'exception modifiée
* ************************************************/
	void EXCmodifier_valeur(unsigned int);

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : valeur de l'exception
* Post-condition : valeur de l'exception retournée
* ************************************************/
	unsigned int EXClire_valeur();
};

/**************************************************
* Excmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entrée: nouvelle valeure
* Pré-condition :
* Sortie :
* Post-condition : valeure de l'exception modifiée
* ************************************************/
inline void Cexception::EXCmodifier_valeur(unsigned int val)
{
	uiEXCvaleur = val;
}

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : valeur de l'exception
* Post-condition : valeur de l'exception retournée
* ************************************************/
inline unsigned int Cexception::EXClire_valeur()
{
	return uiEXCvaleur;
}

#endif
