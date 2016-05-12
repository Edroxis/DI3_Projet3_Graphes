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
* Supprime les espaces d'une chaine de caractère
* *************************************************
* Entrée: tableau de caractères
* Pré-condition :
* Sortie : 
* Post-condition : Les espaces de la chaîne sont supprimés
* ************************************************/
    static void MSTsuppEspace(char * const pcchaine);

/**************************************************
* MSTtrouverChar
* *************************************************
* Renvoie l'indice de la 1ère occurence d'un char
* *************************************************
* Entrée: chaine de caractère, char cherché
* Pré-condition :
* Sortie : indice du char, -1 si non trouvé
* Post-condition : 
* ************************************************/
    static int MSTtrouverChar(char const * const ch1, char const c);
};

#endif