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
Interface de la classe CArc.
Permet de g�rer les objets CArc.
**************************************************/

#ifndef ARC_H
#define ARC_H

//D�claration anticip�e pour �viter une d�pendance circulaire
class CSommet;

class CArc
{
private:
	CSommet * pSMTARCdest;	//pointeur sur l'arc de destination, 
		//Sommet d'origine si l'arc est dans la liste des arrivant,
		//Sommet de destination si l'arc est dans la liste des partant

public:
/**************************************************
* CArc
* *************************************************
* Constructeur de Carc
* *************************************************
* Entr�e: sommet de destination (ou d'origine)
* Pr�-condition :
* Sortie :
* Post-condition : l'arc est cr��
* ************************************************/
	CArc(CSommet& SMTparam);

/**************************************************
* ~CArc
* *************************************************
* Destructeur de CArc
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : CArc est d�truit
* ************************************************/
	~CArc(void);

/**************************************************
* ARCgetDest
* *************************************************
* Obtenir la destination (ou l'origine) de l'arc
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : Destination (ou origine) de l'arc
* Post-condition : 
* ************************************************/
	CSommet& ARCgetDest() const;
};

#endif