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

#ifndef PARSEURSTRUCTURES_H
#define PARSEURSTRUCTURES_H

/**************************************************
Titre: CParseurVariable
***************************************************
C'est la structure qui correspond, dans un fichier
� ce type d'�l�ment "key=value"
**************************************************/
struct CParseurVariable
{
	char * key;
	char * value;
};

/**************************************************
Titre: CParseurTableau
***************************************************
C'est la structure qui correspond, dans un fichier
� ce type d'�l�ment "key=[key=value,key=value]"
**************************************************/
struct CParseurTableau
{
	char * key;
	unsigned int nbVariables;
	CParseurVariable* variables;
};

#endif