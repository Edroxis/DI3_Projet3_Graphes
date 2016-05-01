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
Corps de la Classe Cexception
Permet de créer des objets remontés lors de 
la levée d'exceptions.
**************************************************/

#include "Cexception.h"

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
Cexception::Cexception()
{
	uiEXCvaleur = 0;
}

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
Cexception::Cexception(unsigned int uiValue)
{
	uiEXCvaleur = uiValue;
}