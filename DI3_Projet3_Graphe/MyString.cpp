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
Corps de la classe CMyString.
Permet de r�aliser des op�rations sp�cifiques sur les
char*.
**************************************************/

#include "MyString.h"
#include <string.h>

/**************************************************
* MSTsuppEspace
* *************************************************
* Supprime les espaces d'une chaine de caract�re
* *************************************************
* Entr�e: tableau de caract�res
* Pr�-condition :
* Sortie : 
* Post-condition : Les espaces de la cha�ne sont supprim�s
* ************************************************/
void CMyString::MSTsuppEspace(char * const pcchaine)
{
	char* pcFirstIndex = pcchaine;
	char* pcSecIndex = pcchaine;

	while(*pcSecIndex != 0)
	{
		*pcFirstIndex = *pcSecIndex++;
		if(*pcFirstIndex != ' ')
			pcFirstIndex++;
	}

	*pcFirstIndex = '\0';
}

/**************************************************
* MSTtrouverChar
* *************************************************
* Renvoie l'indice de la 1�re occurence d'un char
* *************************************************
* Entr�e: chaine de caract�re, char cherch�
* Pr�-condition :
* Sortie : indice du char, -1 si non trouv�
* Post-condition : 
* ************************************************/
int CMyString::MSTtrouverChar(char const * const ch1, char const c)
{
    int iboucle = 0;
    while(ch1[iboucle] != 0)	//Tant qu'on est pas � la fin de la cha�ne
    {
        if(ch1[iboucle] == c)	//Si on trouve le caract�re
            return iboucle;		//on retourne l'indice
        iboucle++;
    }
    return -1;
}
