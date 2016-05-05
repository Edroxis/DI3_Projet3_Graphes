#ifndef GRAPHE_H
#define GRAPHE_H

#include "Sommet.h"

class CGraphe
{
private:
	CSommet ** ppSMTGPHliste;
	unsigned int uiGPHtotalSommet;

public:
	CGraphe();
	CGraphe(char const * const chemin);
	~CGraphe();

	void GPHajouterSommet(CSommet* SMTparam);
	void GPHsupprimerSommet(CSommet& SMTparam);
	CSommet& GPHgetSommet(unsigned int inumero);
	unsigned int GPHgetTotalSommet() const;
    //TODO fonction pour afficher graphe
};

inline unsigned int CGraphe::GPHgetTotalSommet() const
{
	return uiGPHtotalSommet;
}

#endif
