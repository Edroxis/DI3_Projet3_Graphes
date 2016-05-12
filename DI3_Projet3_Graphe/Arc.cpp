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
Titre: Classe de Gestion des Arcs
***************************************************
Corps de la classe CArc.
Permet de gérer les objets CArc.
**************************************************/

#include "Arc.h"

/**************************************************
* CArc
* *************************************************
* Constructeur de Carc
* *************************************************
* Entrée: sommet de destination (ou d'origine)
* Pré-condition :
* Sortie :
* Post-condition : l'arc est créé
* ************************************************/
CArc::CArc(CSommet& SMTparam)
{
    pSMTARCdest = &SMTparam;
}

/**************************************************
* ~CArc
* *************************************************
* Destructeur de CArc
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : CArc est détruit
* ************************************************/
CArc::~CArc()
{

}

/**************************************************
* ARCgetDest
* *************************************************
* Obtenir la destination (ou l'origine) de l'arc
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : Destination (ou origine) de l'arc
* Post-condition : 
* ************************************************/
CSommet& CArc::ARCgetDest() const
{
    return *pSMTARCdest;
}
