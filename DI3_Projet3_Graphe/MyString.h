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
Titre: Classe de gestion de char*
***************************************************
Interface de la classe CMyString.
Permet de réaliser des opérations spécifiques sur les
char*.
**************************************************/

#ifndef MYSTRING_H
#define MYSTRING_H

//Classe qui fournit des opérations spéciales nous permettant de manipuler des strings
class CMyString
{
public:
/**************************************************
* MSTsuppEspace
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
    static void MSTsuppEspace(char * const pcchaine);

/**************************************************
* MSTtrouverChar
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
    static int MSTtrouverChar(char const * const ch1, char const c);
};

#endif