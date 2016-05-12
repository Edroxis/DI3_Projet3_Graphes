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
Titre: Classe de Stockage des fonctions liées aux graphes
***************************************************
Interface de la classe CGrapheOperation.
Contient toutes les fonctions spécifiques relatives 
aux graphes.
**************************************************/

#ifndef GRAPHEOPERATION_H
#define GRAPHEOPERATION_H

#include "Graphe.h"

class CGrapheOperation
{
public:
/**************************************************
* GOPinverserGraphe
* *************************************************
* 
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : 
* ************************************************/
    static CGraphe* GOPinverserGraphe(CGraphe& GPHparam);
};

#endif